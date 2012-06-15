#pragma once

#pragma pack(push, 1)


#include <pos/pos.h>
using pos::u64_t;


struct MBR;
struct PartitionRecord;
struct FATx_BootSector;
struct FATx_FileSystemInfo;
struct FATx_DirEntry;
struct FATx_LFNPartEntry;
union FATx_DateFmt;
union FATx_TimeFmt;
class FATx;
class FATx_Directory;


// 16*4
struct MBR {
	BYTE	_pad[0x01BE];
	PartitionRecord	Partition[4];
	WORD	Signature;		// 55 AA
};

// 16
struct PartitionRecord {
	BYTE	BootIndicator;
	BYTE	BeginHead;
	BYTE	BeginSector_Cy2;
	BYTE	BeginCylinder8;
	BYTE	SystemIndicator;
	BYTE	EndHead;
	BYTE	EndSector_Cy2;
	BYTE	EndCylinder8;
	DWORD	SectorsPreceding;
	DWORD	SectorsOfPartition;
};



/*
	Sector #
	0		BootSector
	0+ReservedSectors
			FAT
	0+Reserved+SectorsPerFAT*2
			Data (Start with Cluster #2)
*/

// 72
struct FATx_BootSector {
	BYTE	_JumpCode[3];	    	// [+0h]
	BYTE	_OEMName[8];
	WORD	BytesPerSector;	    	//+0Bh
	BYTE	SectorsPerCluster;	    //+0Dh
	WORD	SectorsReserved;	    //+0Eh  starting at 0
	BYTE	FATCopies;		        //+10h
	WORD	MaxRootEntries;		    // root directory size, N/A for FAT32
	WORD	TotalSectors1;		    // 0 if partition > 32M
	BYTE	Media;			        // useful for floppy disk
	WORD	SectorsPerFAT1;		    //+16h
	WORD	SectorsPerTrack;	    // DOS 3.0+
	WORD	Heads;			        // DOS 3.0+
	DWORD	HiddenSectors;		    // DOS 3.0+  (Same as the Relative Sector field in the Partition Table)
	DWORD	TotalSectors;		    //+20h  in the partition, DOS 4+, if nTotalSectors1 == 0
	DWORD	SectorsPerFAT;
	WORD	Flags;			        // Bits 0-4: Active FAT Copy, Bit 7: FAT Mirroring
	WORD	DriveVersion;		    // "minor major" as byte order
	DWORD	clusterRoot;		    //+2Ch  Cluster of Root directory entry
	WORD	sectorFileSystemInfo;	//+30h  referenced from the start of partition.
	WORD	sectorBootBackup;
	BYTE	_res1[12];
	BYTE	PhysicalDriveNumber;	//+40h  The value is typically 0x80 for hard disks
	BYTE	_res2;
	BYTE	SignEx;			        //+42h  == 29h, so nTotalSectors and on are available.
	DWORD	VolumeSerial;
	BYTE	VolumeLabel[11];
	BYTE	FATName[8];		        // "FAT32   "
	BYTE	_Executable[420];
	WORD	Signature;	        	// 55 AA
};

// 8
struct FATx_FileSystemInfo {
	DWORD	Sign1;			    // 41 61 52 52
	BYTE	_res1[480];
	DWORD	Sign2;			    // 61 41 72 72
	DWORD	nFreeClusters;		// set to -1 if unknown
	DWORD	clusterRecentAlloc;	// most recently allocated.
	BYTE	_res2[12];
	BYTE	_res3[2];
	WORD	Signature;		    // 55 AA
};


struct FATx_DirEntry {
	union {					//+0h
		// 00 Never used
		// 05 Escaped to E5
		// E5 Be erased
		// 2E This is a subdirectory (not root)
		BYTE	FileStatus;
		struct {
			BYTE	ShortFileName[11];
		};
	};
	union {
		BYTE	Attributes;		// for LFN data, this is 0Fh
		struct {
			int bReadOnly: 1;
			int bHidden: 1;
			int bSystem: 1;
			int bVolumeLabel: 1;
			int bSubDirectory: 1;
			int bArchive: 1;
            int _res1: 2;
		};
	};
	BYTE	_res2;
	BYTE	tsCreated;			// tenth of a second
	WORD	timeCreated;
	WORD	dateCreated;
	WORD	dateLastAccessed;
	WORD	clusterHigh;			//+0Ah
	WORD	timeLastUpdated;
	WORD	dateLastUpdated;
	WORD	clusterLow;			//+10h
	DWORD	dwSize;
};

// 13 characters per entry.
struct FATx_LFNPartEntry {
	union {
		BYTE	LFNStatus;
		struct {
			int iPart: 6;
			int bLastEntry: 1;
			int bRes1;
		};
	};
	WORD	Subpart_1[5];
	BYTE	LFNSignature;			// == 0Fh, RSHV set
	BYTE	_res2;
	BYTE	Checksum;
	WORD	Subpart_2[6];
	WORD	_res3;				// == 0
	WORD	Subpart_3[2];
};

union FATx_DateFmt {
	WORD	Date;
	struct {
		int Day: 5;
		int Month: 4;
		int Year: 7;			// 1980-2107
	};
};

union FATx_TimeFmt {
	WORD	Time;
	struct {
		int Second: 5;			// sec / 2
		int Minute: 6;
		int Hour: 5;
	};
};



class FATx {
protected:
	BYTE *		        _raw;
	BYTE *		        _cluster_base;
public:
	FATx_BootSector *   Boot;
	FATx_FileSystemInfo *FSInfo;
	DWORD *		        FAT;
	DWORD *		        FAT_Copy;
	FATx_Directory *    Root;
	DWORD		        ClusterSize;
	u64_t		        ClustersArea;
	u64_t		        SystemSize;

public:
	void	Init(void *ImageBase);
	void *	ClusterAt(DWORD ClusterNumber) const;
	u64_t	ClusterToLinear(DWORD ClusterNumber) const;
	DWORD	LinearToCluster(u64_t LinearAddress) const;

	BOOL	ClusterValid(DWORD ClusterNumber) const;
	DWORD	NextCluster(DWORD ClusterNumber) const;
	BOOL	GetClusterChain(DWORD StartingClusterNumber, DWORD *Clusters, DWORD Units, DWORD *UnitsFetched) const;

	void *	ClustersOffset(DWORD *Clusters, DWORD Units, u64_t Position);
	BOOL	ClustersRead(DWORD *Clusters, DWORD Units, u64_t Position, u64_t Size, void *Buffer);
};


inline BOOL IsClusterFree(DWORD c) { return c == 0; }
inline BOOL IsClusterBad(DWORD c) { return c == 0x0FFFFFF7; }
inline BOOL IsClusterEnd(DWORD c) { return (c & 0xFFFFFFF8) == 0x0FFFFFF8; /* ffffff8 .. fffffff */}



class FATx_Directory {
protected:
	BYTE *		Page0;

	DWORD		n_clusters;
	DWORD *		_clusters;

	// iValidEntry -> iRawEntry
	typedef std::vector<DWORD> EntriesList;
	EntriesList	_entries;

public:
	FATx *		System;

	DWORD		ValidEntries;
	DWORD		EntriesPerPage;

public:
	BOOL		EntryValid(DirEntry *Entry) const;

	// Get raw page
	FATx_DirEntry *	GetPage(int iPage) const;
	// Get raw entry
	FATx_DirEntry *	GetEntry(int iEntry) const;

	FATx_DirEntry *	GetValidEntry(int iEntry) const;

	// Return the entry index, -1 when not found.
	int		FindShortName(char *ShortName, BOOL Case = FALSE) const;
	BOOL    GetLongFileName(int iEntry, wchar_t *LFNBuf, DWORD cbBufSize) const;

public:
	void		Init(FAT32 *FileSystem, DWORD SCN);
	Directory() { _clusters = NULL; }
	~Directory() { SAFE_DELETE_ARRAY(_clusters); }
};
