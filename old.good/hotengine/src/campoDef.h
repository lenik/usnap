

// 草原游戏开发平台

// dansei, 2000.9 中国浙江

// campoDef.h 定义文件

// campo类命名法:
//		c	campo相对独立类			dc		campo相对非独立类
//		cs(dcs)	campo结构类(结构形式的类)
//

// 声明

#pragma once

#include <stdarg.h>

// 定义campo类的通用宏
// 用于将 对象类 转换成 类型


#define declare_c_tag_type(cType)		_##cType
#define declare_c_def_type(priType, cType)	typedef priType	cType;	declarec_type(cType)
#define declare_c_type(cType)				\
	typedef cType			*cType##_r;	\
	typedef cType			*cType##_a;	\
	typedef cType##_r		*cType##_ra;	\
//	typedef cType			&cType##_R;

#define declare_c_interface(i)				\
	interface i;					\
	declare_c_type(i);
#define declare_c_struct(i)				\
	struct i; 					\
	declare_c_type(i);
#define declare_c_class(i)				\
	class i;					\
	declare_c_type(i);


// general campo datatypes

// cColor颜色类
class cColor {
	enum _ecColor {
		RGB,
		YUV,
		GRAY,
		CMYK,
		HSB
	} colorType;
	unsigned long color;
public:
	cColor() : colorType(RGB), color(0) {}
public:
	COLORREF getWinColor() {
		// get color in COLORREF type
		// current only RGB is valid
		if (colorType == RGB) return color;
		return 0x00000000L;
	}
};


// (非独立) 指针列表类
typedef int (*PTRENUMFUNC)(LPVOID, LPVOID);
class dcPtrList : public CPtrList {
public:
	int EnumElements(PTRENUMFUNC enumFunc, LPVOID content);
};

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

#endif //__CAMPODEF_H
