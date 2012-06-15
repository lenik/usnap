
#pragma once

// forward declarations...
	struct DOS_Header;
	struct PE_Header;
	struct Opt_Header;
	struct Data_Export;
	struct Data_Import;
	struct Data_Resource;
	struct Data_Exception;
	struct Data_Security;
	struct Data_BaseReloc;
	struct Data_Debug;
	struct Data_Copyright;
	struct Data_GlobalPointer;
	struct Data_TLS;
	struct Data_LoadConfig;
	struct Data_BoundImport;
	struct Data_IAT;
	struct Datas;
	struct Section;
	struct PEFile;

#include <pos/config.h>
#include <pos/bdt.h>
#include <pos/util_vars.h>
using namespace pos;

typedef bdt::list_t<Section *> Sections;


#pragma pack(push, 4)

struct DOS_Header {
	void *	_stack_initial;
	void *	_csip_initial;
	void *	_relocation_table;
	void *	_new_hdr;

	struct _FILE {
		u16_t	e_magic;			// Magic number
		u16_t	e_cblp;				// Bytes on last page of file
		u16_t	e_cp;				// Pages in file
		u16_t	e_crlc;				// Relocations
		u16_t	e_cparhdr;			// Size of header in paragraphs
		u16_t	e_minalloc;			// Minimum extra paragraphs needed
		u16_t	e_maxalloc;			// Maximum extra paragraphs needed
		u16_t	e_ss;				// Initial (relative) SS value
		u16_t	e_sp;				// Initial SP value
		u16_t	e_csum;				// Checksum
		u16_t	e_ip;				// Initial IP value
		u16_t	e_cs;				// Initial (relative) CS value
		u16_t	e_lfarlc;			// File address of relocation table
		u16_t	e_ovno;				// Overlay number
		u16_t	e_res[4];			// Reserved u16_ts
		u16_t	e_oemid;			// OEM identifier (for e_oeminfo)
		u16_t	e_oeminfo;			// OEM information; e_oemid specific
		u16_t	e_res2[10];			// Reserved u16_ts
		u32_t	e_lfanew;			// File address of new exe header
	} *_file;
};

struct PE_Header {
	union {
		u32_t	dwChars;
		struct {
			int bRelocsStripped: 1;			// Relocation info stripped from file.
			int bExecutableImage: 1;		// File is executable  (i.e. no unresolved externel references).
			int bLineNumsStripped: 1;		// Line nunbers stripped from file.
			int bLocalSymsStripped: 1;		// Local symbols stripped from file.
			int bAgresiveWsTrim: 1;			// Agressively trim working set
			int bLargeAddressAware: 1;		// App can handle >2gb addresses
			int _reserved: 1;
			int bBytesReversedLo: 1;		// Bytes of machine u16_t are reversed.
			int b32BitMachine: 1;			// 32 bit u16_t machine.
			int bDebugStripped: 1;			// Debugging info stripped from file in .DBG file
			int bRemovableRunFromSwap: 1;		// If Image is on removable media, copy and run from the swap file.
			int bNetRunFromSwap: 1;			// If Image is on Net, copy and run from the swap file.
			int bSystem: 1;				// System File.
			int bDll: 1;				// File is a DLL.
			int bUpSystemOnly: 1;			// File should only be run on a UP machine
			int bBytesReversedHi: 1;		// Bytes of machine u16_t are reversed.
		} _Chars;
	};

	struct _FILE {
		u32_t	Signature;
		u16_t	Machine;
		u16_t	NumberOfSections;
		u32_t	TimeDateStamp;
		u32_t	PointerToSymbolTable;
		u32_t	NumberOfSymbols;
		u16_t	SizeOfOptionalHeader;
		u16_t	Characteristics;
	} *_file;
};

struct Opt_Header {
	struct _FILE {
		u16_t	Magic;
		u8_t	MajorLinkerVersion;
		u8_t	MinorLinkerVersion;
		u32_t	SizeOfCode;
		u32_t	SizeOfInitializedData;
		u32_t	SizeOfUninitializedData;
		u32_t	AddressOfEntryPoint;
		u32_t	BaseOfCode;
		u32_t	BaseOfData;
		// NT additional fields.
		u32_t   ImageBase;
		u32_t	SectionAlignment;
		u32_t	FileAlignment;
		u16_t	MajorOperatingSystemVersion;
		u16_t	MinorOperatingSystemVersion;
		u16_t	MajorImageVersion;
		u16_t	MinorImageVersion;
		u16_t	MajorSubsystemVersion;
		u16_t	MinorSubsystemVersion;
		u32_t	Win32VersionValue;
		u32_t	SizeOfImage;
		u32_t	SizeOfHeaders;
		u32_t	CheckSum;
		u16_t	Subsystem;
		u16_t	DllCharacteristics;
		u32_t	SizeOfStackReserve;
		u32_t	SizeOfStackCommit;
		u32_t	SizeOfHeapReserve;
		u32_t	SizeOfHeapCommit;
		u32_t	LoaderFlags;
		u32_t	NumberOfRvaAndSizes;
	} *_file;
};

struct Data_Export {
	asz_t		_dll_name;

	struct _ITEM {
		void *		_func_body;	// to raw data of execution body.
		asz_t		_forward;
		u32_t		_ordinal;
		asz_t		_name;
		util::v32_t	_ctx;
	};
	_ITEM *		_funcs;

	struct _NAMES {
		u32_t	ordinal;		// index to _functions
		asz_t	name;
	};
	_NAMES *	_names;			// index to _names is called "hint"

	struct _FILE {
		u32_t	Characteristics;	// not used
		u32_t	TimeDateStamp;
		u16_t	MajorVersion;
		u16_t	MinorVersion;
		u32_t	Name;			// rva to a name (different from dll.file-name).
		u32_t	Base;			// ordinnal number base
		u32_t	NumberOfFunctions;
		u32_t	NumberOfNames;
		u32_t	AddressOfFunctions;	// RVA from base of image
		u32_t	AddressOfNames;		// RVA from base of image
		u32_t	AddressOfNameOrdinals;	// RVA from base of image
	} *_file;
	u32_t	_length;
};

struct Data_Import {
	struct _ITEM {
		asz_t	_libname;
		b8_t	bBound;

	};

	struct _FILE {
		struct _LIBITEM {
			union {
				u32_t   Characteristics;		// 0 for terminating null import descriptor
				u32_t   OriginalFirstThunk;		// RVA to original unbound IAT (PIMAGE_THUNK_DATA)
			};
			u32_t   TimeDateStamp;				// 0 if not bound,
									// -1 if bound, and real date\time stamp
									//     in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
									// O.W. date/time stamp of DLL bound to (Old BIND)

			u32_t   ForwarderChain;				// -1 if no forwarders
			u32_t   Name;
			u32_t   FirstThunk;				// RVA to IAT (if bound this IAT has actual addresses)
		};
		struct _THUNKITEM {
			union {
				u32_t	ForwarderString;		// -> asz_t: libname.funcname
				u32_t	Function;			// loaded function
				u32_t	Ordinal;			// select this if MSB set.
				u32_t	AddressOfData;			// -> [Hint16] asz_t padded.
			};
		};
		_LIBITEM	Items[1];
	} *_file;
	u32_t	_length;				// size of all data for import-data

	struct IMPITEM {
		struct {
			int bForward: 1;		// is forwarded?
			int bForwardByOrd: 1;		// forward to a lib's ordinal function.
			int bByOrd: 1;			// by name or by ordinal.
			int bByBound: 1;		// by bound, this is prior.
		};
		asz_t	_fwd_libname;			// lib's name of forward import.
		union {
			asz_t	_fwd_name;		// func's name in forward lib.
			u32_t	_fwd_ord;
		};

		asz_t	_name;			// name of import function item.
		u32_t	_name_hint;
		u32_t	_ord;			// valid when bByOrd
		u32_t	_bound_addr;		// valid when bByBound
		u32_t	_bound_timestamp;	// valid when bByBound

		void *	_loaded_body;			// pointer to imp' func-body, if loaded.
	};
	struct LIBITEM {
		asz_t		_name;
		u32_t		_imports;
		IMPITEM *	_items;
	};

	typedef bdt::list_t<LIBITEM *> LIBITEMS;
	LIBITEMS *	_libs;				// the first import-lib
};

struct Data_Resource {
	struct _FILE {
		u32_t	Characteristics;
		u32_t	TimeDateStamp;
		u16_t	MajorVersion;
		u16_t	MinorVersion;
		u16_t	NumberOfNamedEntries;
		u16_t	NumberOfIdEntries;
		struct _ENTRY {
			union {
				struct {
					int NameOffset:31;
					int NameIsString:1;
				};
				u32_t	Name;
				u16_t	Id;
			};
			union {
				u32_t	OffsetToData;
				struct {
					int OffsetToDirectory:31;
					int DataIsDirectory:1;
				};
			};
		};
		_ENTRY Entries[1];
	} *_file;
	u32_t	_length;
};
struct Data_Exception {
	struct _FILE {
	} *_file;
	u32_t	_length;
};
struct Data_Security {
	struct _FILE {
	} *_file;
	u32_t	_length;
};
struct Data_BaseReloc {
	struct _FILE {
		u32_t	VirtualAddress;
		u32_t	SizeOfBlock;
		u16_t	TypeOffset[1];
		/*struct _Relocation {
			union {
				u32_t	VirtualAddress;
				u32_t	RelocCount;		// Set to the real count when IMAGE_SCN_LNK_NRELOC_OVFL is set
			};
			u32_t	SymbolTableIndex;
			u16_t	Type;
		};
		*/
	} *_file;
	u32_t	_length;
};
struct Data_Debug {
	struct _FILE {
		u32_t	Characteristics;
		u32_t	TimeDateStamp;
		u16_t	MajorVersion;
		u16_t	MinorVersion;
		u32_t	Type;
		u32_t	SizeOfData;
		u32_t	AddressOfRawData;
		u32_t	PointerToRawData;
	} *_file;
	u32_t	_length;
};
struct Data_Copyright {
	struct _FILE {
	} *_file;
	u32_t	_length;
};
struct Data_GlobalPointer {
	struct _FILE {
	} *_file;
	u32_t	_length;
};
struct Data_TLS {
	typedef void (_stdcall *_TLS_PROC)(void *handle, u32_t reason, void *reserved);

	struct _FILE {
		u32_t	StartAddressOfRawData;
		u32_t	EndAddressOfRawData;
		u32_t *	AddressOfIndex;			// loaded ? u32_t *
		_TLS_PROC **AddressOfCallBacks;		// loaded ?
		u32_t	SizeOfZeroFill;
		u32_t	Characteristics;
	} *_file;
	u32_t	_length;
};
struct Data_LoadConfig {
	struct _FILE {
		u32_t	Characteristics;
		u32_t	TimeDateStamp;
		u16_t	MajorVersion;
		u16_t	MinorVersion;
		u32_t	GlobalFlagsClear;
		u32_t	GlobalFlagsSet;
		u32_t	CriticalSectionDefaultTimeout;
		u32_t	DeCommitFreeBlockThreshold;
		u32_t	DeCommitTotalFreeThreshold;
		u32_t	LockPrefixTable;			// loaded void *
		u32_t	MaximumAllocationSize;
		u32_t	VirtualMemoryThreshold;
		u32_t	ProcessHeapFlags;
		u32_t	ProcessAffinityMask;
		u16_t	CSDVersion;
		u16_t	Reserved1;
		u32_t	EditList;				// loaded void *
		u32_t	Reserved[ 1 ];
	} *_file;
	u32_t	_length;
};
struct Data_BoundImport {
	struct _FILE {
		u32_t	TimeDateStamp;
		u16_t	OffsetModuleName;
		u16_t	NumberOfModuleForwarderRefs;
		struct _ITEM {
			u32_t	TimeDateStamp;
			u16_t	OffsetModuleName;
			u16_t	Reserved;
		} Items[1];
	} *_file;
	u32_t	_length;
};
struct Data_IAT {
	struct _FILE {
	} *_file;
	u32_t	_length;
};

struct Datas {
	struct _FILE {
		struct _ITEM {
			u32_t	VirtualAddress;
			u32_t	Size;
		} DataDirectory[16];
	} *_file;

	struct Data_Export *		_Export;
	struct Data_Import *		_Import;
	struct Data_Resource *		_Resource;
	struct Data_Exception *		_Exception;
	struct Data_Security *		_Security;
	struct Data_BaseReloc *		_BaseReloc;
	struct Data_Debug *		_Debug;
	struct Data_Copyright *		_Copyright;
	struct Data_GlobalPointer *	_GlobalPointer;
	struct Data_TLS *		_TLS;
	struct Data_LoadConfig *	_LoadConfig;
	struct Data_BoundImport *	_BoundImport;
	struct Data_IAT *		_IAT;

};

struct Section {
	asz_t	_name;
	void *	_raw;
	void *	_reloc;
	void *	_lines;

	union {
		u32_t	dwChars;
		struct {
			//
			int bTypeDsect: 1;
			int bTypeNoload: 1;
			int bTypeGroup: 1;
			int bTypeNoPad: 1;
			int bTypeCopy: 1;
			int bCntCode: 1;			// Section contains code.
			int bCntInit: 1;			// Section contains initialized data.
			int bCntUninit: 1;			// Section contains uninitialized data.

			int bLnkOther: 1;
			int bLnkInfo: 1;			// Section contains comments or some other type of information.
			int bTypeOver: 1;
			int bLnkRemove: 1;			// Section contents will not become part of image.
			int bLnkComdat: 1;			// Section contents comdat.
			int _reserved: 1;
			//int bMemProtected: 1;			// obsolute
			int bNoDeferSpecExc: 1;			// Reset speculative exceptions handling bits in the TLB entries for this section.
			int bGprel: 1;				// Section content can be accessed relative to GP
								// also MEM_FARDATA.
			int bMemSysheap: 1;
			int bMemPurgeable: 1;			// also 16-BIT
			//int bMem16Bit: 1;
			int bMemLocked: 1;
			int bMemPreload: 1;
			enum {
				Align_1 = 1,
				Align_2,
				Align_4,
				Align_8,
				Align_16,			// default
				Align_32,
				Align_64,
				Align_128,
				Align_256,
				Align_512,
				Align_1024,
				Align_2048,
				Align_4096,
				Align_8192,
				Align_Mask = 15
			} _align: 4;

			int bLnkNrelocOvfl: 1;			// Section contains extended relocations.
			int bMemDiscardable: 1;
			int bMemNotCached: 1;
			int bMemNotPaged: 1;
			int bMemShared: 1;
			int bMemExecute: 1;
			int bMemRead: 1;
			int bMemWrite: 1;
		} _Chars;
	};

	struct _FILE {
		u8_t	Name[IMAGE_SIZEOF_SHORT_NAME];
		union {
			u32_t	PhysicalAddress;
			u32_t	VirtualSize;
		};
		u32_t	VirtualAddress;			// rva to section loaded in memory.
		u32_t	SizeOfRawData;
		u32_t	PointerToRawData;		// file offset, must aligned FileAlignment.
		u32_t	PointerToRelocations;
		u32_t	PointerToLinenumbers;
		u16_t	NumberOfRelocations;
		u16_t	NumberOfLinenumbers;
		u32_t	Characteristics;
	} *_file;
};

struct PEFile {
	void *		_image;
	asz_t		_name;
	DOS_Header *	_hdr_DOS;
	PE_Header *	_hdr_PE;
	Opt_Header *	_hdr_Opt;
	Datas *		_Datas;
	Sections *	_Sections;
};

#pragma pack(pop)
