

#include "stdafx.h"
#include "fat_type.h"

#include <time.h>

void	FAT32::Init(void *ImageBase) {
	_raw = (BYTE *)ImageBase;
	Boot = (BootSector *)_raw;
	ClusterSize = Boot->SectorsPerCluster * Boot->BytesPerSector;

	DWORD clusterRoot = 2;
	FSInfo = NULL;
	if (Boot->SignEx == 0x29) {
		clusterRoot = Boot->clusterRoot;
		FAT = (DWORD *)(_raw +
			Boot->SectorsReserved * Boot->BytesPerSector);
		FAT_Copy = (DWORD *)(_raw +
			(Boot->SectorsReserved + Boot->SectorsPerFAT) * Boot->BytesPerSector);
		FSInfo = (FileSystemInfo *)(_raw +
			Boot->sectorFileSystemInfo * Boot->BytesPerSector);

		ClustersArea = (Boot->SectorsReserved + Boot->SectorsPerFAT * 2) * Boot->BytesPerSector;

		SystemSize = Boot->TotalSectors * Boot->BytesPerSector - ClustersArea;
	} else {
		FAT = (DWORD *)(_raw +
			Boot->SectorsReserved * Boot->BytesPerSector);
		FAT_Copy = (DWORD *)(_raw +
			(Boot->SectorsReserved + Boot->SectorsPerFAT1) * Boot->BytesPerSector);

		ClustersArea = (Boot->SectorsReserved + Boot->SectorsPerFAT1 * 2) * Boot->BytesPerSector;

		SystemSize = Boot->TotalSectors1 * Boot->BytesPerSector - ClustersArea;
	}

	_cluster_base = _raw + ClustersArea;
}

void *	FAT32::ClusterAt(DWORD ClusterNumber) const {
	return _cluster_base + ClusterNumber * ClusterSize;
}

u64_t	FAT32::ClusterToLinear(DWORD ClusterNumber) const {
	return ClustersArea + ClusterNumber * ClusterSize;
}

DWORD	FAT32::LinearToCluster(u64_t LinearAddress) const {
	return (LinearAddress - ClustersArea) / ClusterSize;
}

BOOL	FAT32::ClusterValid(DWORD ClusterNumber) const {
	switch (ClusterNumber) {
	case 0:			// reserved for "unused #"
	case 1:			// never used
	case 0x0FFFFFF7:	// reserved for "bad cluster"
	case 0x0FFFFFF8:
	case 0x0FFFFFF9:
	case 0x0FFFFFFA:
	case 0x0FFFFFFB:
	case 0x0FFFFFFC:
	case 0x0FFFFFFD:
	case 0x0FFFFFFE:
	case 0x0FFFFFFF:	// these were reserved for "end mark"
		return FALSE;
	}

	DWORD MaxSector = Boot->TotalSectors1 - Boot->SectorsReserved;
	if (Boot->TotalSectors == 0 || Boot->SignEx == 0x29) {
		MaxSector = Boot->TotalSectors;
		MaxSector -= Boot->SectorsPerFAT;
	} else {
		MaxSector -= Boot->SectorsPerFAT1;
	}

	return ClusterNumber < MaxSector / Boot->SectorsPerCluster;
}

DWORD	FAT32::NextCluster(DWORD ClusterNumber) const {
	return FAT[ClusterNumber];
}

BOOL	FAT32::GetClusterChain(DWORD SCN, DWORD *Clusters, DWORD Units, DWORD *UnitsFetched) const {
	if (UnitsFetched) *UnitsFetched = 0;
	if (!ClusterValid(SCN)) return FALSE;

	DWORD iCluster = 0;
	if (!Clusters && Units == 0 && UnitsFetched) {
		// get counts
		for (; ClusterValid(SCN); iCluster++) SCN = NextCluster(iCluster);
		*UnitsFetched = iCluster;
	} else {
		for (; ClusterValid(SCN); iCluster++) {
			if (iCluster < Units) {
				Clusters[iCluster] = SCN;
			} else {
				if (UnitsFetched) {
					*UnitsFetched = iCluster;
					break;
				}
			}
		}
	}
	return TRUE;
}

void *	FAT32::ClustersOffset(DWORD *Clusters, DWORD Units, u64_t Position) {
	DWORD Offset = Position % ClusterSize;
	DWORD iCluster = (Position - Offset) / ClusterSize;

	if (iCluster < Units) {
		BYTE *At = (BYTE *)ClusterAt(Clusters[iCluster]);
		return At + Offset;
	}
	return NULL;
}

BOOL	FAT32::ClustersRead(DWORD *Clusters, DWORD Units, u64_t Position, u64_t Size, void *Buffer) {
	DWORD prefixCluster, prefixOffset, prefixSize;
	DWORD clusterMain, clusters;
	DWORD postfixCluster, postfixSize;

	// Calculate 3 parts of the related clusters.

	if (Position % ClusterSize) {
		clusterMain = (Position + (ClusterSize - 1)) / ClusterSize;
		prefixSize = Position - clusterMain * ClusterSize;
		prefixOffset = ClusterSize - prefixSize;
		prefixCluster = clusterMain - 1;
	} else {
		clusterMain = Position / ClusterSize;
		prefixSize = 0;
		prefixOffset = 0;
		prefixCluster = 0;
	}

	u64_t Before = Position + Size;
	if (Before % ClusterSize) {
		postfixCluster = Before / ClusterSize;
		postfixSize = Before % ClusterSize;
		clusters = postfixCluster - clusterMain;
	} else {
		postfixCluster = 0;
		postfixSize = 0;
		clusters = Before / ClusterSize - clusterMain;
	}

	DWORD Cluster;
	BYTE *pBuffer = (BYTE *)Buffer;

	// Copy the 3 parts

	if (prefixCluster) {
		ASSERT(prefixCluster < Units);
		if (prefixCluster >= Units) return FALSE;

		Cluster = Clusters[prefixCluster];
		ASSERT(ClusterValid(Cluster));
		if (!ClusterValid(Cluster)) return FALSE;

		memcpy(pBuffer, (BYTE *)ClusterAt(Cluster) + prefixOffset, prefixSize);
		pBuffer += prefixSize;
	}

	ASSERT(clusterMain + clusters - 1 < Units);
	if (clusterMain + clusters - 1 >= Units) return FALSE;

	for (int iCluster = 0; iCluster < clusters; iCluster++) {
		Cluster = Clusters[clusterMain + iCluster];
		ASSERT(ClusterValid(Cluster));
		if (!ClusterValid(Cluster)) return FALSE;

		memcpy(pBuffer, ClusterAt(Cluster), ClusterSize);
		pBuffer += ClusterSize;
	}

	if (postfixCluster) {
		ASSERT(postfixCluster < Units);
		if (postfixCluster >= Units) return FALSE;

		Cluster = Clusters[postfixCluster];
		ASSERT(ClusterValid(Cluster));
		if (!ClusterValid(Cluster)) return FALSE;

		memcpy(pBuffer, ClusterAt(Cluster), postfixSize);
		pBuffer += postfixSize;
	}

	return TRUE;
}



////////////////////////////////////////////////////////////////////////////////////////
//
//
//
void	Directory::Init(FAT32 *_System, DWORD SCN) {
	BOOL b;
	System = _System;

	SAFE_DELETE_ARRAY(_clusters);

	Page0 = (BYTE *)System->ClusterAt(SCN);
	EntriesPerPage = System->ClusterSize / sizeof(DirEntry);

	if (System->GetClusterChain(SCN, NULL, 0, &n_clusters)) {
		_clusters = new DWORD[n_clusters];
		b = System->GetClusterChain(SCN, _clusters, n_clusters, &n_clusters);
		ASSERT(b);
	}

	int iValidEntry = 0;
	_entries.clear();
	for (int iPage = 0; iPage < n_clusters; iPage++) {
		int iOffEntry;
		DirEntry *pEntry = GetPage(iPage);
		ASSERT(pEntry);
		for (iOffEntry = 0; iOffEntry < EntriesPerPage; iOffEntry++, pEntry++) {
			if (!EntryValid(pEntry)) continue;
			_entries.push_back(iOffEntry + EntriesPerPage * iPage);
			iValidEntry++;
		}
	}

	ValidEntries = iValidEntry;
}


BOOL	Directory::EntryValid(DirEntry *pEntry) const {
	if (!pEntry) return FALSE;

	// Never used item
	if (pEntry->FileStatus == 0) return FALSE;

	// Long file item
	if (pEntry->Attributes == 0x0F) return FALSE;

	// Invalid file name
	if (memchr(pEntry->ShortFileName, 0, 11)) return FALSE;

	// Invalid cluster
	DWORD cluster = (((DWORD)pEntry->clusterHigh) << 16) | pEntry->clusterLow;
	if (!System->ClusterValid(cluster)) return FALSE;

	// Exceeds system size.
	if (pEntry->dwSize > System->SystemSize) return FALSE;

	// Invalid date/time format
		FAT_DateFmt *_date;
		FAT_TimeFmt *_time;
		time_t the_time;
		tm *_tm;
		_date = (FAT_DateFmt *)&pEntry->dateLastUpdated;
		_time = (FAT_TimeFmt *)&pEntry->timeLastUpdated;
		time(&the_time);
		_tm = gmtime(&the_time);
	if ((_date->Year + 1980 > _tm->tm_year + 10)
		|| (_date->Month > 12)
		|| (_date->Day > 31)
		|| (_time->Hour > 24)
		|| (_time->Minute > 60)
		|| (_time->Second > 60)
		) return FALSE;

	// So the item seems be valid.
	return TRUE;
}


DirEntry *Directory::GetPage(int iPage) const {
	ASSERT(iPage >= 0 && iPage < n_clusters);
	if (iPage < 0 || iPage >= n_clusters) return NULL;

	return (DirEntry *)System->ClusterAt(_clusters[iPage]);
}

DirEntry *Directory::GetEntry(int iEntry) const {
	ASSERT(iEntry >= 0 && iEntry < n_clusters * EntriesPerPage);
	if (iEntry < 0 || iEntry < n_clusters * EntriesPerPage) return NULL;

	int iOffsetEntry = iEntry % EntriesPerPage;
	int iPage = (iEntry - iOffsetEntry) / EntriesPerPage;
	return GetPage(iPage) + iOffsetEntry;
}

DirEntry *Directory::GetValidEntry(int iEntry) const {
	ASSERT(iEntry >= 0 && iEntry < ValidEntries);
	if (iEntry < 0 || iEntry >= ValidEntries) return NULL;

	return (DirEntry *)_entries[iEntry];
}

int	Directory::FindShortName(char *ShortName, BOOL Case) const {
	char cbuf[11], ic = 0;
	memset(cbuf, ' ', 11);
	while (*ShortName) {
		if (*ShortName == '.' && ic < 8) {
			ic = 8;
			ShortName++;
		} else {
			cbuf[ic] = *ShortName;
			ic++;
			ShortName++;
		}
		if (ic >= 11) break;
	}
	if (!Case) strupr(cbuf);

	for (int iValidEntry = 0; iValidEntry < _entries.size(); iValidEntry++) {
		DWORD iRawEntry = _entries[iValidEntry];
		DirEntry *pEntry = GetEntry(iRawEntry);
		ASSERT(pEntry != NULL);

		if (memcmp(pEntry->ShortFileName, cbuf, 11) == 0)
			return iRawEntry;
	}

	return -1;
}

BOOL	Directory::GetLongFileName(int iEntry, wchar_t *LFNBuf, DWORD cbBufSize) const {
	ASSERT(LFNBuf);

	DirEntry *pEntry = GetEntry(iEntry);

	ASSERT(pEntry);
	if (!pEntry) return FALSE;

	ASSERT(EntryValid(pEntry));
	if (!EntryValid(pEntry)) return FALSE;

	wchar_t _buf[300];	// generally, long file name never exceeds 260 characters.
	memset(_buf, 0, sizeof(_buf));

	int iLFNEntry = iEntry;
	LFNPartEntry *pLFNEntry;
	while (iLFNEntry >= 0) {
		iLFNEntry--;
		pLFNEntry = (LFNPartEntry *)GetEntry(iLFNEntry);

		if (pLFNEntry->LFNSignature != 0x0F) continue;
		wchar_t *wcsPart = _buf + pLFNEntry->iPart * 13;

		memcpy(wcsPart + 0, pLFNEntry->Subpart_1, 10);
		memcpy(wcsPart + 5, pLFNEntry->Subpart_2, 12);
		memcpy(wcsPart + 11, pLFNEntry->Subpart_3, 4);

		if (pLFNEntry->bLastEntry) {
			for (int iwcsPart = 0; iwcsPart < 13; iwcsPart++) {
				if (wcsPart[iwcsPart] == 0xFFFF) {
					wcsPart[iwcsPart] = 0;
					break;
				}
			}
			break;
		}
	}

	int ActualLength = (wcslen(_buf) + 1) * 2;
	if (cbBufSize < ActualLength) ActualLength = cbBufSize;
	wcsncpy(LFNBuf, _buf, ActualLength / 2 - 1);

	return TRUE;
}
