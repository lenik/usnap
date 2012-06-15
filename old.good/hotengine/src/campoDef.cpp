
#include "stdafx.h"

#include "campoDef.h"

// 应用程序回调函数 用于控制流程的 返回值
#define ENUMLIST_BREAK			0			// 取消枚举
#define ENUMLIST_NEXT			1			// 枚举下一个
#define ENUMLIST_PREVIOUS		2			// 枚举前一个
#define ENUMLIST_REUSE			3			// 再枚举一次
#define ENUMLIST_GOHEAD			4			// 回到头部 枚举
#define ENUMLIST_GOEND			5			// 枚举最后一个

#define ENUMLIST_ERRORED		10			// 枚举时错误

// EnumElements 方法的返回值
#define ENUMLIST_ERROROCCURED		FALSE			// 枚举时发生错误

#define ENUMLIST_ALLPASSED		100			// 全部通过
#define ENUMLIST_BREAKED		101			// 枚举被取消
#define ENUMLIST_COMPLEX		103			// 是一个复杂枚举 (包括除了_BREAK, _ERRORED的其它控制)

// 指针列表的枚举过程
int cPtrList::EnumElements(PTRENUMFUNC enumFunc, LPVOID param) {
	POSITION	position;
	LPVOID		element;
	int			control;
	BOOL		bComplex = FALSE;

	for (position = GetHeadPosition(); position != NULL; ) {
		element = GetAt(position);
		// 调用会调过程并获取返回值
		if ((control = enumFunc(element, param)) == ENUMLIST_NEXT) {
			GetNext(position);
			continue;
		}
		switch (control) {
		case ENUMLIST_BREAK:
			return ENUMLIST_BREAKED;
		case ENUMLIST_PREVIOUS:
			GetPrev(position);
			bComplex = TRUE;
			continue;
		case ENUMLIST_REUSE:
			bComplex = TRUE;
			continue;
		case ENUMLIST_GOHEAD:
			position = GetHeadPosition();
			bComplex = TRUE;
			continue;
		case ENUMLIST_GOEND:
			position = this->GetTailPosition();
			bComplex = TRUE;
			continue;
		case ENUMLIST_ERRORED:
		default:
			return ENUMLIST_ERROROCCURED;
		}
	}
	return bComplex ? ENUMLIST_COMPLEX : ENUMLIST_ALLPASSED;
}
