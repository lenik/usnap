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
        Module Name:    ISO9660 CDROM File System Layout
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-8-27       ZD|system files
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

struct DirTime {
    BYTE    Year;                       // +00 since 1900
    BYTE    Month;                      // +01 1=January
    BYTE    Day;                        // +02 [1,31]
    BYTE    Hour;                       // +03 0,23]
    BYTE    Minute;                     // +04 [0,59]
    BYTE    Second;                     // +05 [0,59]
    // positive for time zones east of Greenwich, and negative for west.
    char    GMT;                        // +06 15-minute intervals, 2-complement signed number.

    inline int GMTMinutes()             { return (int)GMT * 15; }
};




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
    Directory Record
    - Unlike path records, directory records may not straddle sector boundaries
*/
struct DirRecord {
    BYTE    Size;                       // +00 Record size, aligned to WORD (R)
    BYTE    _res1;                      // +01 Number of sectors in EA record
    INT64   secData;                    // +02 [both endian] first sector of data
    INT64   cbData;                     // +0A [both endian] bytes of file or directory, excluding EA record.
    DirTime Time;                       //
    BYTE    Flags;                      //

    BYTE    UnitSize;                   // For interleaved file. Otherwise 0.
    BYTE    GapSize;                    // For interleaved file. Otherwise 0.
    DWORD   VolumeSN;                   // [both endian] (= 1)
    BYTE    IdentifierLength;           //
    BYTE    Identifier[1];              // length: IdentifierLength
    // Padding bytes.

    inline BOOL IsHidden()              { return Flags & 0x01; }
    inline BOOL IsDirectory()           { return Flags & 0x02; }
    inline BOOL IsAssociated()          { return Flags & 0x04; }
    inline BOOL HasRecordFormat()       { return Flags & 0x10; }
    inline BOOL HasPermissions()        { return Flags & 0x20; }
    inline BOOL IsFinal()               { return !(Flags & 0x80); }
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
