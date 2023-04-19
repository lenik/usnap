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
        Module Name:    NTFS Layout
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-8-23       ZD|started, system attributes
        2003-8-24       ZD|system files
        2003-8-25       ZD|locs - lot of changes, or LOCs-many of LOC. :)
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __NTFS_Layout_INCLUDED__
#define __NTFS_Layout_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

//#include "pos/config.h"



namespace NTFS {



///////////////////////////////////////////////////////////////////////////////
//
// Constants
// ----------------------------------------------------------------------------
/*
    Mft Record ID
    AttributeType
    AttributeTypeNT
    FilePermissionType
    VolumeInformationType
    ReparsePointType_Predefined
    CollationRuleType
*/
enum MftRecordID {
    mrMftSelf = 0,
    mrMftMirr,
    mrLogFile,
    mrVolume,
    mrAttrDef,
    mrRootIndex,
    mrBitmap,
    mrBoot,
    mrBadClus,
    mrSecure,
    mrUpcase,
    mrExtend,
};

enum AttributeType {
    atStandardInformation   = 0x10,
    atAttributeList         = 0x20,
    atFileName              = 0x30,
    atObjectID              = 0x40,     // 2000+
    atSecurityDescriptor    = 0x50,
    atVolumeName            = 0x60,
    atVolumeInformation     = 0x70,
    atData                  = 0x80,
    atIndexRoot             = 0x90,
    atIndexAllocation       = 0xA0,
    atBitmap                = 0xB0,
    atReparsePoint          = 0xC0,     // 2000+
    atEAInformation         = 0xD0,
    atEA                    = 0xE0,     // Extend Attributes
    atLoggedUtilityStream   = 0x100,    // 2000+
    atEnd                   = 0xFFFFFFFF,
};

enum AttributeTypeNT {
    atVolumeVersion         = 0x40,     // NTFS v1.2 (obsoluted)
    atSymbolicLink          = 0xC0,     // NTFS v1.2 (obsoluted)
    atPropertySet           = 0xF0,     // NTFS v1.2 (obsoluted)
};

enum FilePermissionType {
    fptReadOnly             = 0x0001,
    fptHidden               = 0x0002,
    fptSystem               = 0x0004,
    fptArchive              = 0x0020,
    fptDevice               = 0x0040,
    fptNormal               = 0x0080,
    fptTemporary            = 0x0100,
    fptSparseFile           = 0x0200,
    fptReparsePoint         = 0x0400,
    fptCompressed           = 0x0800,
    fptOffline              = 0x1000,
    fptNotContentIndexed    = 0x2000,
    fptEncrypted            = 0x4000,
};

enum VolumeInformationType {
    vitDirty                = 0x0001,   // must perform chkdsk /F on the volume when next boots.
    vitResizeLogFile        = 0x0002,
    vitUpgradeOnMount       = 0x0004,
    vitMountedOnNT4         = 0x0008,
    vitDeleteUSNUnderway    = 0x0010,
    vitRepairObjectIds      = 0x0020,
    vitModifiedByChkdsk     = 0x8000,
};

enum ReparsePointType_Predefined {
    rptNSS                  = 0x68000005,
    rptNSSRecovet           = 0x68000006,
    rptSIS                  = 0x68000007,
    rptDFS                  = 0x68000008,
    rptMountPoint           = 0x88000003,
    rptHSM                  = 0xA8000004,
    rptSymbolicLink         = 0xE8000000,
};

enum CollationRuleType {
    crBinary                = 0,
    crFileName              = 1,
    crUnicodeString         = 2,
    crDWORD                 = 0x10,
    crSID                   = 0x11,
    crSecurityHash          = 0x12,
    crDWORDs                = 0x13,
};

enum FilenameNamespaceType {
    fnsPosix                = 0,        // all chars except '\0' and '/'
    fnsWin32                = 1,        // Posix - { " \ * / : < > ? \ | }
    fnsDOS                  = 2,        // Win32 - { [a-z] (space) + ; = }
    fnsWin32DOS             = 3,
};

enum AccessControlEntryType {
    aceAccessAllowed        = 0,
    aceAccessDenied         = 1,
    aceSystemAudit          = 2,
};

enum SidIdentifierAuthorityType {
    siaNull                 = 0,        // S-1-0
    siaWorld                = 1,        // S-1-1
    siaLocal                = 2,        // S-1-2
    siaCreator              = 3,        // S-1-3
    siaNonUnique            = 4,        // S-1-4
    siaNT                   = 5,        // S-1-5
};

enum SidRelativeSubAuthorityType {
    sraAdmin                = 500,
    sraGuest                = 501,
    sraKerberosTarget       = 502,
    sraAdmins               = 512,
    sraUsers                = 513,
    sraGuests               = 514,
    sraComputers            = 515,
    sraControllers          = 516,
    sraAdminsCert           = 517,
    sraAdminsSchema         = 518,
    sraAdminsEnterprise     = 519,
    sraAdminsPolicy         = 520,
    sraDomainAdmins         = 544,
    sraDomainUsers          = 545,
    sraDomainGuests         = 546,
    sraDomainPowerUsers     = 547,
    sraDomainAccountOps     = 548,
    sraDomainSystemOps      = 549,
    sraDomainPrintOps       = 550,
    sraDomainBackupOps      = 551,
    sraDomainReplicator     = 552,
    sraDomainRASServers     = 553,
};





///////////////////////////////////////////////////////////////////////////////
//
// Kernel utility struct
// ----------------------------------------------------------------------------
typedef struct _FILE_REFERENCE {
    BYTE    RecordNumber[6];
    // If the filesystem is consistent, this number must match the sequence
    // number of the FILE record referenced by the FILE record number.
    WORD    SequenceNumber;
} FILE_REFERENCE;

typedef struct _SID {
    BYTE    RevisionLevel;
    BYTE    SubAuthoritiesCount;
    BYTE    IdentifierAuthority[6];     // big-endian, see IdentifierAuthorityType
    DWORD   SubAuthorities[1];          // [SubAuthoritiesCount]

    inline DWORD GetIA32() {
        return  (((DWORD)IdentifierAuthority[5]) << 24) |
                (((DWORD)IdentifierAuthority[4]) << 16) |
                (((DWORD)IdentifierAuthority[3]) << 8 ) |
                (((DWORD)IdentifierAuthority[2])      );
    }
} SID;

typedef INT64   TIME64;




///////////////////////////////////////////////////////////////////////////////
//
// System Attributes
// ----------------------------------------------------------------------------
/*
    Attribute
        ResidentHeader
        NonResidentHeader
    AttrStandardInformation
    AttrAttributeList
    AttrFileName
    AttrObjectId
    AttrSecurityDescriptor
    AttrVolumeName
    AttrVolumeInformation
    AttrData
    AttrIndexRoot
        IndexRoot
        IndexHeader
        IndexEntry
    AttrIndexAllocation
    AttrBitmap
    AttrReparsePoint
    AttrEAInformation
    AttrEA
    AttrLoggedUtilityStream
*/
struct Attribute {
    /*
        Resident & Non-Resident Standard Attribute Header

            - Only the data attribute can be compressed, or sparse, and only when it is non-resident.
            - Name isn't Null-Terminated.
            - (?) Only resident attributes can be indexed?
            - (?) For Non-Resident header, +40h may be INT64 CompressedSize, and aligned to cluster.
    */
    struct ResidentHeader {
        DWORD   Type;                   // +00 AttributeType
        DWORD   Length;                 // +04 include this header.
        BYTE    bNonResident;           // +08 = 0
        BYTE    NameLength;             // +09 (N)
        WORD    NameOffset;             // +0A
        WORD    Flags;                  // +0C bit 0:Compressed, bit 14:Encrypted, bit 15:Sparse.
        WORD    AttributeId;            // +0E each attribute has a unique identifier
        DWORD   AttributeLength;        // +10
        WORD    AttributeOffset;        // +14 = 0018h+2N
        BYTE    bIndexed;               // +16
        BYTE    _res1;                  // +17
        // +18: Name... (if Named attribute)
        // +18+2N, aligned to DWORD: Attributes...
    };

    struct NonResidentHeader {
        DWORD   Type;                   // +00 AttributeType
        DWORD   Length;                 // +04 include this header.
        BYTE    bNonResident;           // +08 = 1
        BYTE    NameLength;             // +09 (N)
        WORD    NameOffset;             // +0A
        WORD    Flags;                  // +0C bit 0:Compressed, bit 14:Encrypted, bit 15:Sparse.
        WORD    AttributeId;            // +0E each attribute has a unique identifier
        INT64   vcnStart;               // +10 Starting VCN
        INT64   vcnLast;                // +18 Last VCN
        WORD    DataOffset;             // +20 = 40h+2N
        WORD    CompressionUnitSize;    // +22 0:uncompressed, unit size = 2^x
        DWORD   _res1;                  // +24
        INT64   AllocatedSize;          // +28 (bytes) allocated size of the attribute, aligned to cluster.
        INT64   RealSize;               // +30 (bytes)
        INT64   StreamInitedDataSize;   // +38 (?) for normal file == realsize, for sparse file == meaningful size?
        // +40: Name... (if Named attribute)
        // +40+2L, aligned to DWORD: Attributes...
    };

    /*
    inline WCHAR *GetName() {
        return (WCHAR *)(((BYTE *)GetHeader()) + 0x18);
    }
    inline ResidentHeader *GetSRH() {
        return (ResidentHeader *)(((BYTE *)this) - 0x18);
    }
    */
};



/*
    $STANDARD_INFORMATION, Size: 48-72
    Always Resident
    当NTFS卷从v1.2升级到v3.0时，该属性直到被访问时才更新。
    Version和ClassID似乎从未使用。
*/
struct AttrStandardInformation : public Attribute {
    typedef INT64 TIME64;
    TIME64    timeCreation;               // +00
    TIME64    timeAltered;                // +08
    TIME64    timeMFTChanged;             // +10
    TIME64    timeRead;                   // +18
    DWORD   FilePermission;             // +20 DOS File Permission
    DWORD   MaxVersions;                // +24 0:Disabled.
    DWORD   Version;                    // +28 The file's version, if version enabled.
    DWORD   ClassId;                    // +2C
    DWORD   OwnerId;                    // +30 (2K) 索引到 $Quote 文件的 $O 和 $Q 索引
    DWORD   SecurityId;                 // +34 (2K) 索引到 $Secure 文件的 $SII 和 $SDS 索引
    INT64   QuoteCharged;               // +38 0:Disabled, 否则是文件所有流的总和
    INT64   USN;                        // +40 Updated Sequence Number, 0:Disabled. 索引到 $UsnJrnl 文件
};



/*
    $ATTRIBUTE_LIST
    Always Non-Resident

    (本属性较罕见) 当MFT中属性比较多时，可以把所有属性移到MFT外部，并设置为非驻留。
    如果还不够用，则可以使用属性列表，将其它属性放置到MFT中另一条记录，用$ATTRIBUTE_LIST定位。

    在下列情况可能会用到:
        - 有大量硬链接, 因此需要大量文件名属性
        - 非常零碎, 以至于溢出MFT记录
        - 有复杂的安全描述符 (不是用于 NTFS v3.0+)
        - 有大量命名流

    另外研究发现 vcnStart 按带符号整数操作。
*/
struct AttrAttributeList : public Attribute {
    DWORD   Type;                       // +00
    WORD    Length;                     // +04
    BYTE    NameLength;                 // +06
    BYTE    NameOffset;                 // +07 = 1Ah
    INT64   vcnStart;                   // +08 Always 0 (Starting VCN, or zero if the attribute is resident)
    INT64   BaseFileReference;          // +10 Base File Reference of this attribute
    WORD    AttributeId;                // +18 Each attribute has a unique identifier.
    // +1A Unicode Name ...
};



/*
    $FILE_NAME, Size: 68-578
    NTFS通过建立多文件名属性来实现POSIX风格的硬链接，每个文件名属性有各自的details和parent。
    当删除硬链接文件时，从MFT中移除文件名，直到最后一个移除后删除实际的文件。
    这个属性中除了Parent域外，仅当文件名更改时才更新。而$STANDARD_INFORMATION则总是保持更新。
*/
struct AttrFileName : public Attribute {
    INT64   ParentDirectory;            // +00 指向父目录的记录号
    TIME64    timeCreation;               // +08
    TIME64    timeAltered;                // +10
    TIME64    timeMFTChanged;             // +18
    TIME64    timeRead;                   // +20
    INT64   AllocatedSize;              // +28 allocated size of the file, aligned to cluster.
    INT64   RealSize;                   // +30 仅指未命名流的长度.
    DWORD   FilePermission;             // +38
    DWORD   _used_by_EA_Reparse;        // +3C 可能包含EA长度和Reparse类型。
    BYTE    FilenameLength;             // +40
    BYTE    FilenameNamespace;          // +41
    // +42 Unicode Filename... (Not null-terminated)
};



/*
    $OBJECT_ID, Size: 0-256, Windows 2000+

    - DomainId目前未使用, 将来可能用于Windows 2000域中的计算机。
    - 属性可能只有16字节, 即只有ObjectId有效。
    - 其它三个可能存在但不使用。
*/
struct AttrObjectId : public Attribute {
    GUID    ObjectId;                   // +00 Unique Id assigned to file
    GUID    BirthVolumeId;              // +08 Volume where file was created, Never changes
    GUID    BirthObjectId;              // +10 Original Object Id of file
    GUID    DomainId;                   // +18 Domain in which object was created
};



/*
    $SECURITY_DESCRIPTOR
*/
struct AttrSecurityDescriptor : public Attribute {
    BYTE    Header1;
    BYTE    Header2;
    BYTE    Header3;
    BYTE    Header4;
    DWORD   AclAuditOffset;
    DWORD   AclPermissionOffset;
    DWORD   SidOwnerOffset;
    DWORD   SidGroupOffset;

    struct ACE {
        BYTE    Type;
        BYTE    Flags;
        WORD    Size;
        DWORD   AccessMask;
        SID     Sid;

        inline BOOL IsAboutAccess()     { return Type == aceAccessAllowed || Type == aceAccessDenied; }
        inline BOOL IsAboutAudit()      { return Type == aceSystemAudit; }
        inline BOOL ToObject()          { return (Flags & 0x01) && IsAboutAccess(); }
        inline BOOL ToContainer()       { return (Flags & 0x02) && IsAboutAccess(); }
        inline BOOL NoPropagate()       { return (Flags & 0x04) && IsAboutAccess(); }
        inline BOOL OnlyACE()           { return (Flags & 0x08) && IsAboutAccess(); }
        inline BOOL AuditOnSuccess()    { return (Flags & 0x40) && IsAboutAudit(); }
        inline BOOL AuditOnFailure()    { return (Flags & 0x80) && IsAboutAudit(); }
    };

    struct ACLHeader {
        BYTE    Revision;               // +00
        BYTE    _res1;
        WORD    ACLSize;                // +02
        WORD    ACECount;               // +04
        WORD    _res;

        inline ACE *GetEntry(int Index) {
            if (Index < 0 || Index >= ACECount) return NULL;
            BYTE *pEntry = (BYTE *)this + 8;
            while (Index--) {
                pEntry += ((ACE *)pEntry)->Size;
            }
            return (ACE *)pEntry;
        }
    };

};



/*
    $VOLUME_NAME, Size: 2-256,

    - The length is stored in standard attribute header.
    - A volume's serial number is stored in $Boot.
*/
struct AttrVolumeName : public Attribute {
    // +00: Unicode Name...  127 Unicode characters max.
    WCHAR   VolumeName[1];
};



/*
    $VOLUME_INFORMATION, Size: 12

    - A volume's serial number is stored in $Boot.
*/
struct AttrVolumeInformation : public Attribute {
    INT64   _unknown1;                  // +00 (?) always 0
    WORD    Version;                    // +08 byte order: minor major
    WORD    Flags;                      // +0A see VolumeInformationType enumeration.
    DWORD   _unknown2;                  // +0C (?) always 0
};



/*
    $DATA

    - Must have unnamed data attribute. (at least empty)
    - Common data stream used by Windows:
        . (Unnamed)
        . {4c8cc155-6c1e-11d1-8e41-00c04fb9386d}
        . ^EDocumentSummaryInformation
        . ^ESebiesnrMkudrfcoIaamtykdDa
        . ^ESummaryInformation
        . $MountMgrDatabase
        . $Bad
        . $SDS
        . $J
        . $Max
    - 通过分配多个数据属性, NTFS可以很容易的实现HFS的两部分文件结构(data & resource)
*/
struct AttrData : public Attribute {
    // +00: Any data...
    BYTE    Data[1];
};



/*
    $INDEX_ROOT
    Always Resident
*/
struct IndexEntry {
    INT64   FileReference;          // +00
    WORD    EntryLength;            // +08 total entry size, include this struct.
    WORD    StreamLength;           // +0A for FileName index entry, this is the actual size of
                                    //     AttrFileName attribute, without ResidentHeader.
    BYTE    Flags;                  // +0C
    // +10: if not last entry, stream of StreamLength bytes.
    //      (stream...)
    // +L-8: if sub-node:
    //      INT64 vcnSubNode;       // in the index allocation attribute.

    inline BOOL IsSubNode()         { return Flags & 0x01; }
    inline BOOL IsLastEntry()       { return Flags & 0x02; }
};

struct AttrIndexRoot : public Attribute {
    struct IndexRoot {
        DWORD   Type;                   // +00 Attribute Type
        DWORD   CollationRule;          // +04 校对规则
        DWORD   IAESize;                // +08 Size of Index Allocation Entry
        BYTE    ClustersPerRecord;      // +0C
        BYTE    _res1[3];
    };

    struct IndexHeader {
        DWORD   FirstIndexEntryOffset;  // +00
        DWORD   EntriesTotalSize;       // +04
        DWORD   EntriesAllocatedSize;   // +08
        BYTE    Flags;                  // +0C bit 0: large index(index allocation needed),
        BYTE    _res1[3];               // +0D
    };
};



/*
    $INDEX_ALLOCATION
    Always Non-Resident
*/
struct StandardIndexHeader {
    DWORD   Magic;                  // +00 "INDX"
    WORD    USNOffset;              // +04
    WORD    USNCount;               // +06
    INT64   LSN;                    // +08 $LogFile Seq Number
    INT64   vcnThis;                // +10 VCN of this INDX buffer in the Index Allocation
    DWORD   EntriesOffset;          // +18 These values are relative to 0x18
    DWORD   EntriesSize;            // +18 These values are relative to 0x18
    DWORD   AllocatedSize;          // +18 These values are relative to 0x18
    BYTE    Flags;                  // +24
    BYTE    _res1[3];
    WORD    USN;
    WORD    BackBuffer[1];          // USNCount - 1

    inline IndexEntry *GetEntry(int Index) {
        BYTE *pEntry = (BYTE *)this + EntriesOffset;
        while (Index-- > 0) {
            pEntry = pEntry + ((IndexEntry *)pEntry)->EntryLength;
            if (pEntry - (BYTE *)this >= EntriesSize) return NULL;
        }
        return (IndexEntry *)pEntry;
    }
};
struct AttrIndexAllocation : public Attribute {
    // !! Because of Always Non-Resident, the base Attribute is never used.
    StandardIndexHeader Header;
    // +?? IndexEntry[]
};



/*
    $BITMAP, Size: 0-inf

    目前用于两个方面:
    - 对于索引, 位指出索引分配的一个VCN
    - 对于$MFT, 位指出那个文件记录被使用
*/
struct AttrBitmap : public Attribute {
    // +00: Bit fields...
    BYTE    Bits[1];
};



/*
    $REPARSE_POINT, Size: 0-16384

    The system file FILE_$Extend/$Reparse contains an index named $R listing
    all reparse points on the volume. The index entry keys are as defined
    below. Note, that there is no index data associated with the index entries.

    The index entries are sorted by the index key file_id. The collation rule is
    COLLATION_NTOFS_ULONGS. FIXME: Verify whether the reparse_tag is not the
    primary key / is not a key at all. (AIA)
*/
struct AttrReparsePoint : public Attribute {
    DWORD   Type;                       // +00 Reparse Type and flags, see also ReparsePointType_Predefined.
    WORD    DataLength;                 // +04
    WORD    _res1;                      // +06
    // +08: Reparse Data...

    // 文件是系统中其它对象的一个别名
    inline BOOL IsAlias()           { return Type & 0x20000000; }
    // 访问数据的第一个字节将会有一段延时(如磁带驱动器)
    inline BOOL IsHighLatency()     { return Type & 0x40000000; }
    inline BOOL IsMicrosoft()       { return Type & 0x80000000; }
};


/*
    $EA_INFORMATION

    Used to implement under NTFS the HPFS extended attributes used by the information
    subsystem of OS/2 and OS/2 clients of Windows NT servers.
*/
struct AttrEAInformation : public Attribute {
    WORD    PackedEASize;               // +00
    WORD    EACount;                    // +02
    DWORD   UnpackedEASize;             // +04
};



/*
    $EA, Size: 0-65536
    Maybe Non-Resident.

    - 用于在NTFS下实现HPFS的扩展属性. 参考HPFS文件系统.
*/
struct AttrEA : public Attribute {
    DWORD   NextEAOffset;               // +00 Conversely, is the size of this EA.
    BYTE    Flags;                      // +04 bit 7: "Need EA"
    BYTE    NameLength;
    WORD    ValueLength;
    // +08:     Name... (?) Not Unicode.
    // +08+N:  Value...
};



/*
    $LOGGED_UTILITY_STREAM, Size: 0-65536

    - 做为一个属性和命名流没有什么区别.
    - 在这个属性上的操作将被记入日志($LogFile), 如同一般的元数据更改.
    - 用于EFS, 所有加密的文件有这个属性, 名称为$EFS.
    - (?) 参考 AIA
*/
struct AttrLoggedUtilityStream : public Attribute {
    // +00: Any Data...
    BYTE    Data[1];
};



///////////////////////////////////////////////////////////////////////////////
//
// System Files
// ----------------------------------------------------------------------------
/*
    FileBoot
    FileLogFile
        RestartPageHeader
        RestartArea
        RestartClient
        RecordPageHeader
        LogRecord
    FileAttrDef
    Record
*/

struct FileMFT {
    DWORD   Magic;                      // +00 "FILE"
    WORD    USNOffset;                  // +04 offset to the update sequence
    WORD    USNCount;                   // +06
    INT64   LSN;                        // +08 $LogFile seq number, changed if the record is modified.
    // The increment (skipping zero) is done when the file is deleted.
    // If the sequence number is zero it is assumed that no sequence number
    // consistency checking should be performed.
    WORD    SeqNumber;                  // +10 Number of times this mft record has been reused
    WORD    HardLinkCount;              // +12
    WORD    AttributesOffset;           // +14 offset to the first attribute
    WORD    Flags;                      // +16
    DWORD   RealSize;                   // +18 of the record, aligned to 8-bytes.
    DWORD   AllocatedSize;              // +1C
    // The Base Record contains the information about the Extension Record.
    // This information is stored in an ATTRIBUTE_LIST attribute.
    INT64   FileReference;              // +20 to the base FILE record.
    WORD    NextAttributeID;            // +28 incremented each time it is used.
    WORD    _res1;                      // +2A
    DWORD   Count;                      // +2C
    WORD    USN;                        // +30
    WORD    BackBuffer[1];              // +32 USNCount - 1

    inline BOOL IsRecordInUse()         { return Flags & 0x01; }
    inline BOOL IsDirectory()           { return Flags & 0x02; }

    inline void *GetAttribute(int Index) const {
        DWORD *pAttr = (DWORD *)(((BYTE *)this) + AttributesOffset);
        while (Index-- > 0) {
            if (*pAttr == atEnd) return NULL;
            pAttr = (DWORD *)(((BYTE *)pAttr) + pAttr[1]);
            if ((BYTE *)pAttr - (BYTE *)this >= RealSize) return NULL;
        }
        return (void *)pAttr;
    }
    inline int GetAttributesCount() const {
        DWORD *pAttr = (DWORD *)(((BYTE *)this) + AttributesOffset);
        int Index = 0;
        for (;; Index++) {
            if (*pAttr == atEnd) break;
            pAttr = (DWORD *)(((BYTE *)pAttr) + pAttr[1]);
            // this attribute isn't complete. so ignore.
            if ((BYTE *)pAttr - (BYTE *)this >= RealSize) break;
        }
        return Index;
    }

};


struct FileBoot {
    BYTE    _JumpCode[3];
    BYTE    _OEMName[8];
    WORD    BytesPerSector;             // +0B
    BYTE    SectorsPerCluster;          // +0D
    WORD    ReservedSectors;            // +0E
    BYTE    _res1[3];
    WORD    _NotUsed;
    BYTE    Media;                      // +15
    WORD    _res2;
    WORD    SectorsPerTrack;            // +18
    WORD    Heads;                      // +1A
    DWORD   HiddenSectors;              // +1C
    DWORD   _res3;
    DWORD   _unk;                       // +24 (= 80 00 80 00)
    INT64   TotalSectors;               // +28
    INT64   lcnMFT;                     // +30 Logical Cluster Number for the file $MFT
    INT64   lcnMFTMirr;                 // +38
    DWORD   ClustersPerFRS;             // +40 Clusters per File Record Segment (= F6?)
    DWORD   ClustersPerIndexBlock;      // +44
    INT64   VolumeSerial;               // +48
    DWORD   Checksum;                   // +50 (= 0)
    BYTE    _Executable[426];           // +54
    WORD    Signature;                  // +1FC "55 AA"
};

struct FileLogFile {
    // 2 restart areas present in the first two pages (restart pages). When
    // the volume is unmounted they should be identical.
    struct RestartPageHeader {
        DWORD   Magic;                  // +00 "RSTR"
        DWORD   _unknown;               // +04
        // Log file Seq Number for this restart page.
        // Only used when the magic is changed to "CHKD". = 0
        INT64   ChkdskLSN;              // +08
        // Use this to calculate the required size of the usa.
        // add this to the ntfs.usa_offset value, verify the result < RestartOffset.
        DWORD   SystemPageSize;         // +10 bytes >= 512 and a power of 2.
        DWORD   LogPageSize;            // +14 bytes >= 512 and a power of 2, = 0x1000
        // bytes from the start of the record to the restart record.
        WORD    AreaOffset;             // +18 aligned to 8-bytes, = 0x30
        // Log file minor version. Only check if major version is 1.
        // (=1 but >=1 is treated the same and <=0 is also ok)
        WORD    verMinor;               // +1A
        WORD    verMajor;               // +1C Log file major version (=1 but =0 is ok)
        WORD    USN;                    // +1E
        WORD    BackBuffer[8];          // +20 (?) Always 8 sectors? (4k per record?)
    };

    // assume RestartArea immed follow RestartPageHeader, so starts at +30
    struct RestartArea {
        INT64   CurrentLSN;             // +30
        WORD    LogClients;             // +38
        WORD    ClientFreeList;         // +3A
        WORD    ClientInUseList;        // +3C
        WORD    Flags;                  // +3E
        DWORD   SeqNumBits;             // +40 (= 2Ch, 2Dh)
        WORD    AreaLength;             // +44 RestartOffset + Length <= SystemPageSize, (= 0xD0)
        WORD    ClientArrayOffset;      // +46 ClientArrayOffset + LogClients * A0h <= AreaLength
        INT64   FileSize;               // +48 (= 4000000h)
        DWORD   LastLSNDataLength;      // +50 (= 0, 40h)
        WORD    Length;                 // +54 of this record, aligned to 8-bytes, (= 0x30)
        WORD    LogPageDataOffset;      // +56 (= 40h)
    };

    // assume RestartClient immed follow RestartArea, so starts at +58
    struct RestartClient {
        INT64   OldestLSN;              // +58
        INT64   ClientRestartLSN;       // +60
        WORD    PrevClient;             // +68
        WORD    NextClient;             // +6A
        WORD    SeqNum;                 // +6C
        WORD    ClientName;             // +6E
        INT64   _unk;
        BYTE    _Name;                  // L"NTFS"
    };

    struct RecordPageHeader {
        DWORD   Magic;                  // "RCRD"
        DWORD   _unknown;
        union {
            INT64   LastLSN;
            DWORD   FileOffset;
        } Copy;
        DWORD   Flags;
        WORD    PageCount;
        WORD    PagePosition;
        union {
            struct {
                DWORD   NextRecordOffset;
                DWORD   LastEndLSN;
            } Packed;
        } Header;
    };

    struct LogRecord {
        INT64   ThisLSN;
        INT64   ClientPrevLSN;
        INT64   ClientUndoNextLSN;
        DWORD   ClientDataLength;
        WORD    ClientSeqNum;
        WORD    ClientIndex;
        DWORD   RecordType;
        DWORD   TransactionID;
        WORD    Flags;                  // 1: multi-page
        WORD    _res1[3];
        WORD    RedoOperation;          // +30
        WORD    UndoOperation;
        WORD    RedoOffset;
        WORD    RedoLength;
        WORD    UndoOffset;
        WORD    UndoLength;
        WORD    TargetAttribute;
        WORD    LCNsToFollow;
        WORD    RecordOffset;
        WORD    AttributeOffset;
        DWORD   _res2;
        DWORD   TargetVCN;
        DWORD   _res3;
        struct LCNItem {
            DWORD   LCN;
            DWORD   _res1;
        };
        LCNItem Item[1];
    };
};



struct FileAttrDef {
    struct Record {
        WCHAR   Label[64];
        DWORD   Type;                   // 在MFT中使用的数值
        DWORD   DisplayRule;
        DWORD   CollationRule;          // see CollationRuleType
        DWORD   Flags;
        INT64   MinSize;
        INT64   MaxSize;

        inline BOOL IsIndexed()         { return Flags & 0x02; }
        inline BOOL AlwaysResident()    { return Flags & 0x40; }
        inline BOOL MaybeNonResident()  { return Flags & 0x80; }
    };
    Record  Item[1];
};


/*
    $Secure
        $SDS    ($DATA)
        $SDH    ($INDEX_ROOT, $INDEX_ALLOCATION, $BITMAP)
        $SII    ($INDEX_ROOT, $INDEX_ALLOCATION, $BITMAP)

    - 在NTFS v1.2中每个文件的$SECURITY_DESCRIPTOR 属性记录全部的安全描述，它们都多数相同。
      在NTFS v3.0中每个文件的$STANDARD_INFORMATION属性的SecurityId域指向$Secure中的记录，
      因此存储更有效率。 (?) 在变化的部分补充$SECURITY_DESCRIPTOR属性？
    -
*/
struct FileSecure {
    // The Security Descriptor Stream ($SDS) contains a list of all the
    // Security Descriptors on the volume. Each entry is padded to a 16
    // byte boundary and has a hash for indexing purposes
    struct SDS {
        DWORD   Hash;                   // +00 Hash of Security Descriptor
        DWORD   SecurityId;             // +04
        INT64   ThisOffset;             // +08 offset of this entry in this file
        DWORD   ThisSize;               // +10 size of this entry
        BYTE    SelfRelative[1];        // Self-relative Security Descriptor  has 2 * SID
    };

    // The Security Descriptor Hash ($SDH) Index
    // inherits from StandardIndexHeader.
    struct SDH {
        WORD    DataOffset;             // +00 (= 0x18)
        WORD    DataSize;               // +02 (= 0x14)
        DWORD   _res1;
        WORD    EntrySize;              // +08 (= 0x30) size of index entry
        WORD    KeySize;                // +0A (= 0x08) size of index key
        WORD    Flags;                  // +0C
        WORD    _res2;                  // +0E
        DWORD   KeyHash;                // +10 of security descriptor
        DWORD   KeySecurityId;          // +14
        DWORD   DataHash;               // +18 of security descriptor
        DWORD   DataSecurityId;         // +1C
        INT64   DataOffset1;             // +20 data offset to $SDS.Security Descriptor
        DWORD   DataSize1;               // +28
        DWORD   _res3;                  // +2C (always L"II")
    };

    // The Security Id Index ($SII)
    struct SII {
        WORD    DataOffset;             // +00 (= 0x14)
        WORD    DataSize;               // +02 (= 0x14)
        DWORD   _res1;
        WORD    EntrySize;              // +08 (= 0x30) size of index entry
        WORD    KeySize;                // +0A (= 0x08) size of index key
        WORD    Flags;                  // +0C
        WORD    _res2;                  // +0E
        DWORD   KeySecurityId;          // +10
        DWORD   DataHash;               // +14 of security descriptor
        DWORD   DataSecurityId;         // +18
        INT64   DataOffset1;             // +1C data offset to $SDS.Security Descriptor
        DWORD   DataSize1;               // +24
    };
};





///////////////////////////////////////////////////////////////////////////////
//
// Inline Utilities
// ----------------------------------------------------------------------------
/*
    VcnToLcn:   Translate VCN to LCN, according to pbDataRuns.
*/

/*
    VCN and LCN is defined as 64-bit values; but in practice,
    DWORD is enough, for 4K cluster, DWORD is able for access 16T space.
*/
DWORD VcnToLcn(BYTE *pbDataRuns, DWORD Vcn, int err) {
    ASSERT(pbDataRuns);

    DWORD   lcn = 0;
    DWORD   vcn = 0;
    DWORD   v;

    // 一般方法是解析pbDataRuns并构造结构化, 但pbDataRuns可能不正确(不可靠假设)。
    // 因此这里采用一般的分析方法。

    BYTE b;
    while (b = *pbDataRuns) {
        int cLength = b & 0x0F;
        int cOffset = b >> 4;

        v = 0;
        memcpy(&v, pbDataRuns + 1, cLength);

        // MSB set, a negtive value.
        if (cLength < 4 && (pbDataRuns[cLength] & 0x80)) {
            // xx xx xx FF FF ... FF
            memset(((BYTE *)v) + cLength, 0xFF, 4 - cLength);
        }

        //if (vcn
        // ...
    }

    return 0;
}



template<typename _Ty>
inline BOOL DoFixup(_Ty *pHeader, const int SectorSize = 512) {
    // ASSERT(pHeader) && SectorSize > 0
    WORD *pBuf = (BYTE *)pHeader;
    WORD USN = pHeader->USN;
    WORD Count = pHeader->USNCount;
    WORD *pBack = pHeader->BackBuffer + 0;
    while (Count--) {
        if (pBuf[0xFF] != USN) return FALSE;
        pBuf[0xFF] = *pBack++;
        pBuf += 0x100;
    }
    return TRUE;
}



} // namespace NTFS

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
