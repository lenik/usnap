
#pragma once




enum UnitClassType {
    ucSector = 0,
    ucCluster,
    ucFile,
    ucDirectory,
    ucBytes,
};


enum ucSectorType {
    stUnknown,
    stBad,
    stIgnore,
    stBoot,                 // Boot or Part of boot.
    stFAT,                  // Part of FAT
    stData,                 // Part of Data of some type, with meaningful contents.
};
enum ucClusterType {
    ctUnknown,
    ctBad,
    ctFree,
    ctLost,
    ct
};
enum ucFileType {
    ftUnknown,
    ftLost,                 // File isn't referenced in the system. (maybe deleted)
    ftNormal,
    ftDirectory,
};

struct UnitInfo {
    int Class: 4;
    int Type: 4;
    int bComplexWeight: 1;
    int bLock: 1;
};

struct UI_ : public UnitInfo {

};



/*
struct UnitWeight {
    // Overview, determined in the initial scan.
    float Wo;

    // chain weight
    float Wc;

    // anchor weight
    float Wa;

    // recognized weight
    float Wr;
};
*/

// Atom knowledge of node.
enum AKTypeConstants {
    aktChain,
    aktAnchor,
    aktRecognized,
};

enum NodeTypeConstants {
    ntFree = 0,

    // Boot record.
    ntBoot,

    // A general type, includes "File", "Directory", etc.
    ntBlock,

    ntFile,
    ntDirectory,

    // Stream data, for NTFS.
    ntStream,
    // FAT data, FSI, etc.
    ntSystem,
};


struct AK_Node {
    int AKType: 4;
    int NodeType: 4;
    // Weight from 0 to 255.
    BYTE Weight;
};

struct NodeK {
    // weight: initial overview.
    WEIGHT Wo;

    WEIGHT W;
    int AKCount: 4;
    int W_Updated: 1;

    AK_Node AK[1];
};


#define WEIGHT(by)          ((float)((by) / 255.0))

inline float NodeWeight(NodeK *_N) {
    float w = WEIGHT(_N->Wo);
    for (int i = 0; i < _N->AKCount; i++) {
        w += WEIGHT(_N->AK[i].Weight);
    }
    return w / (1 + _N->AKCount);
}


inline int TestSectorType(CacheBlock *pBlock) {
    pBlock->bLock = true;

    pBlock->pbMemory;
    // FATx Boot:
        // ...

    return ntFree;
}



class FATxAnalyse {
protected:

    // 12, 16, 32
    int         m_FATx;

    DWORD       m_cbFATOffset;

protected:
    BYTE	SectorsPerCluster;	    //+0Dh
	WORD	SectorsReserved;	    //+0Eh  starting at 0
	WORD	MaxRootEntries;		    // root directory size, N/A for FAT32
	BYTE	Media;			        // useful for floppy disk
	WORD	SectorsPerTrack;	    // DOS 3.0+
	WORD	Heads;			        // DOS 3.0+
	DWORD	HiddenSectors;		    // DOS 3.0+
	DWORD	TotalSectors;		    //+20h  in the partition, DOS 4+, if nTotalSectors1 == 0
	DWORD	SectorsPerFAT;
	WORD	Flags;			        // Bits 0-4: Active FAT Copy, Bit 7: FAT Mirroring
	WORD	DriveVersion;		    // "minor major" as byte order
	DWORD	clusterRoot;		    //+2Ch  Cluster of Root directory entry
	WORD	sectorFileSystemInfo;	//+30h  referenced from the start of partition.
	WORD	sectorBootBackup;
};


protected:
    BOOL        m_bDetectClusterSize;
    BOOL        m_bDetectFATOffset;
    BOOL        m_bSearchRootDirectory;         // not at cluster#2
    BOOL        m_bDetectLostClusters;

    BOOL        m_bCrossLinkEnabled;
    BOOL        m_bTryFATCopies;

/*
    Detect following parameters:
    -------------------------------------------------------------------------------
	BYTE	SectorsPerCluster;	    //+0Dh
	WORD	SectorsReserved;	    //+0Eh  starting at 0
	BYTE	FATCopies;		        //+10h
	WORD	MaxRootEntries;		    // root directory size, N/A for FAT32
	BYTE	Media;			        // useful for floppy disk
	WORD	SectorsPerTrack;	    // DOS 3.0+
	WORD	Heads;			        // DOS 3.0+
	DWORD	HiddenSectors;		    // DOS 3.0+  (Same as the Relative Sector field in the Partition Table)
	DWORD	TotalSectors;		    //+20h  in the partition, DOS 4+, if nTotalSectors1 == 0
	DWORD	SectorsPerFAT;
	WORD	Flags;			        // Bits 0-4: Active FAT Copy, Bit 7: FAT Mirroring
	DWORD	clusterRoot;		    //+2Ch  Cluster of Root directory entry
	WORD	sectorFileSystemInfo;	//+30h  referenced from the start of partition.
	WORD	sectorBootBackup;
	BYTE	FATName[8];		        // "FAT32   "
*/

public:



};


