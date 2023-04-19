
// campoFormat.h 数据格式

#pragma once

// 资源格式

#define CCGENERAL_COMMANDCHAR		'!'
#define CCGENERAL_STRINGCODE		'~'

#define CCGENERAL_TYPE			't'
#define CCGENERAL_VERSION		'v'
#define CCGENERAL_AUTHOR		'a'
#define CCGENERAL_DATE			'd'
#define CCGENERAL_COMMENT		'c'

enum cResourceType {
	crText,
	crImage,
	crISeq,
	crSprite,
	crImage3D,
	crISeq3D,
	crSprite3D,
	crSound,
	crElse,
	crInvalid
};

#define CCTYPE_TEXT		"TEXT"
#define CCTYPE_IMAGE		"IMAGE"
#define CCTYPE_ISEQ		"ISEQ"
#define CCTYPE_SPRITE		"SPRITE"
#define CCTYPE_IMAGE3D		"IMAGE3D"
#define CCTYPE_ISEQ3D		"ISEQ3D"
#define CCTYPE_SPRITE3D		"SPRITE3D"
#define CCTYPE_SOUND		"SOUND"

struct csResourceHead {
	cResourceType	type;
	CString			version;
	CString			author;
	CString			date;
	CString			comment;
};

cString		cGetCommandString(cString strFrom, cString strTo);
cString		cMakeCommandString(TCHAR first, ...);
cResourceType	cGetResourceType(cString strHead) ;

#endif //__CAMPO_FORMAT_
