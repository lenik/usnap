/*
                                                                  * CVI DRAFT *
    POS - Practice-Oriented Structure (System)                        Version 1
    ---------------------------------------------------------------------------
                                Power Of the Software !

    License:    POS.LCL
    See Also:   X@A LaS PoX EPFS HFVC 1/bios HAS/HAD Aipos

    Ci Virtuality Integrated,
    Copyright 1997-2003, CHINA. All rights reserved.

    File:
        Module Name:    HPFS Layout
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-8-26       ZD|system files
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __HPFS_Layout_INCLUDED__
#define __HPFS_Layout_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

//#include "pos/config.h"



namespace HPFS {



///////////////////////////////////////////////////////////////////////////////
//
// Constants
// ----------------------------------------------------------------------------
/*
    FileAttributeType
*/
enum FileAttributeType {
    attrReadOnly            = 0x01,
    attrHidden              = 0x02,
    attrSystem              = 0x04,
    attrVolume              = 0x08,
    attrDirectory           = 0x10,
    attrArchive             = 0x20,
    attrLongName            = 0x40,
    attrReserved            = 0x80,
};
enum FilenameNamespaceType {
    fnsPosix                = 0,        // all chars except '\0' and '/'
    fnsWin32                = 1,        // Posix - { " \ * / : < > ? \ | }
    fnsDOS                  = 2,        // Win32 - { [a-z] (space) + ; = }
    fnsWin32DOS             = 3,
};





///////////////////////////////////////////////////////////////////////////////
//
// Kernel utility struct
// ----------------------------------------------------------------------------

typedef INT64   TIME64;




///////////////////////////////////////////////////////////////////////////////
//
// System Attributes
// ----------------------------------------------------------------------------
/*
*/



///////////////////////////////////////////////////////////////////////////////
//
// Structurs
// ----------------------------------------------------------------------------
/*
    SuperBlock
    SpareBlock
*/

/*
    LSN 16: SuperBlock
*/
struct SuperBlock {
    BYTE    Signature[8];               // +00 F995E849h FA53E9C5h
    BYTE    Version;                    // +08 HPFS Version
    BYTE    FunctionalVer;              // +09
    WORD    _res1;
    DWORD   lsnRootFn;                  // +0C LSN of Root directory Fnode
    DWORD   TotalSectors;               // +10 Sectors in partition
    DWORD   BadSectors;                 // +14
    DWORD   lsnBitmapSectors;           // +18 List of Bitmap Sectors
    DWORD   BitmapSecList;              // +1C (spare, = 0)
    DWORD   lsnBadSectors;              // +20
    DWORD   BadSecList;                 // +24 (spare, = 0)
    DWORD   timeLastChkdsk;             // +28 Seconds since 0:00 1-1-1970
    DWORD   timeLastOptimised;          // +2C
    DWORD   lsnDirBandSectors;          // +30
    DWORD   lsnDirBandStart;            // +34
    DWORD   lsnDirBandEnd;              // +38
    DWORD   lsnDirBandBitmap;           // +3C
    BYTE    _res2[32];                  // +40
    DWORD   lsnFirstUserID;             // +60 HPFS386: 8 sectors of ACLs.
};


/*
    LSN 17: SpareBlock
*/
struct SpareBlock {
    BYTE    Signature[8];               // +00 F9911849h FA5229C5h
    BYTE    Status;                     // +08 Partition Status
    BYTE    _res1[3];
    DWORD   HotfixListStart;            // +0C
    DWORD   HotfixEntriesUsed;          // +10
    DWORD   TotalHotfixEntries;         // +14
    DWORD   SpareDirBlocksCount;        // +18
    DWORD   FreeSpareDirBlocks;         // +1C
    DWORD   lsnCodePageDir;             // +20
    DWORD   CodePagesCount;             // +24
    DWORD   crc32SuperBlock;            // +28 HPFS386
    DWORD   crc32SpareBlock;            // +2C HPFS386
    BYTE    _res2[60];
    DWORD   FirstSpareDirBlock;         // +6C (?)

    inline BOOL IsDirty()               { return Status & 0x01; }
    inline BOOL UsedSpareDirBlocks()    { return Status & 0x02; }
    inline BOOL UsedHotfixSectors()     { return Status & 0x04; }
    inline BOOL IsBadSector()           { return Status & 0x08; }
    inline BOOL IsBadBitmap()           { return Status & 0x10; }
    inline BOOL IsFastFormatted()       { return Status & 0x20; }
    inline BOOL IsWrittenByOldIFS()     { return Status & 0x80; }
};



struct DirEntry {
    WORD    Size;                       // +00 Entry's size, align to 4.
    BYTE    Flags;                      // +02
    BYTE    Attributes;                 // +03 See FileAttributeType
    DWORD   lsnFnode;                   // +04 FNode of this entry.
    DWORD   timeLastModified;           // +08 Seconds since 00:00 1-1-70
    DWORD   FileSize;                   // +10
    DWORD   timeLastAccess;             // +14
    DWORD   timeCreated;                // +18
    DWORD   EASize;                     // +1C Size of internal or external EAs.
    BYTE    Flex;                       // +20
    BYTE    CodePageInfo;               // +21
    BYTE    NameSize;                   // +22 (N)
    BYTE    Name[1];                    // +23
    // +23      Name...
    // +23+N    ACLs...
    // +...     (align to DWORD)
    //          DWORD Down-Pointer

    inline void *GetAcl()               { return (void *)((BYTE *)this + 0x23 + NameSize); }

    /* Special ".." entry */
    inline BOOL IsToParent()            { return Flags & 0x01; }
    inline BOOL HasACL()                { return Flags & 0x02; }
    /* Has a B-tree down-pointer */
    inline BOOL HasBTreeDownPointer()   { return Flags & 0x04; }
    inline BOOL IsEnd()                 { return Flags & 0x08; }
    inline BOOL HasEAList()             { return Flags & 0x10; }
    /* Has an extended permission list */
    inline BOOL HasExtPermissions()     { return Flags & 0x20; }
    inline BOOL HasExplicitAcl()        { return Flags & 0x40; }
    /* Has "needed" EA */
    inline BOOL HasNeededEAs()          { return Flags & 0x80; }

    inline int GetAclCount()            { return Flex & 0x07; }
    inline int GetCodePageIndex()       { return CodePageIndex & 0x7F; }
    inline BOOL IsDCBSPresent()         { return CodePageIndex & 0x80; }
};

struct DirBlock {
    DWORD   Signature;                  // +00 77E40AAEh
    DWORD   NextEntryOffset;            // +04 Offset within DIRBLK to 1st free entry.
    DWORD   Change;                     // +08 Low bit indicates whether this is topmost DIRBLK in B-tree.
    DWORD   lsnParent;                  // +0C to this, if topmost.
    DWORD   lsnSelf;                    // +10

    inline DirEntry *GetEntry(int Index) {
        if (Index < 0) return NULL;
        DirEntry *pEntry = (DirEntry *)((BYTE *)this + 0x10);
        while (Index-- && !pEntry->IsEnd()) {
            pEntry = (DirEntry *)((BYTE *)pEntry + pEntry->Size);
        }
        if (pEntry->IsEnd()) return NULL;
        return pEntry;
    }
};



///////////////////////////////////////////////////////////////////////////////
//
// Inline Utilities
// ----------------------------------------------------------------------------
/*
    VcnToLcn:   Translate VCN to LCN, according to pbDataRuns.
*/



} // namespace HPFS

#endif



///////////////////////////////////////////////////////////////////////////////
//
// The Developing Procedure
// ----------------------------------------------------------------------------
/*
        Summary:
                _____________________________________________
                _____________________________________________
        Motivation:
                ___________________________________________________________
        Objective:
                ___________________________________________
                ___________________________________________
                ___________________________________________
        Sandbox, Problems, Warnings:
                _______________________________________
                _______________________________________
                _______________________________________
                _______________________________________
        Development:
                ___________________________________________________________
                ___________________________________________________________
                ___________________________________________________________
        References:
                _________________________________________________
        Achievement:
                ________________________________________
        Outgrowth & Babies, Abbreviations:
                _____________________________
                _____________________________
                _____________________________
        Acknowledgement:
                _____________________________________________
*/
