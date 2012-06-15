
#include "stdafx.h"

#include "campoFunc.h"


CString cGetCommandString(CString strFrom, CString strTo) {
	BOOL bControling = FALSE;
	int nSize = strFrom.GetLength();
	int i;

	for (i = 0; i < nSize; i++) {
		if (strFrom[i] == CCGENERAL_COMMANDCHAR && !bControling) {
			bControling = TRUE;
			continue;
		}
		bControling = FALSE;
		strTo += strFrom[i];
	}
	return strTo;
}

CString cMakeCommandString(TCHAR first, ...) {
	va_list arglist;
	TCHAR c = first;
	CString str;
	LPCTSTR lpStr;

	va_start(arglist, first);
	while (c != '\0') {
		if (c != CCGENERAL_STRINGCODE)
			str += c;
		else {
			lpStr = va_arg(arglist, LPCTSTR);
			str += lpStr;
		}
		c = va_arg(arglist, TCHAR);
	}
	va_end(arglist);
	return *(new CString(str));
}

cResourceType cGetResourceType(CString strHead) {
	int i = 0;
	int nSize = strHead.GetLength();

	if (strHead[0] != CCGENERAL_COMMANDCHAR ||
		strHead[1] != CCGENERAL_TYPE)
		return crInvalid;

	strHead = strHead.Right(nSize - 2);

	if (strHead.Compare(CCTYPE_TEXT)	== 0) return crText;
	if (strHead.Compare(CCTYPE_IMAGE)	== 0) return crImage;
	if (strHead.Compare(CCTYPE_ISEQ)	== 0) return crISeq;
	if (strHead.Compare(CCTYPE_SPRITE)	== 0) return crSprite;
	if (strHead.Compare(CCTYPE_IMAGE3D) == 0) return crImage3D;
	if (strHead.Compare(CCTYPE_ISEQ3D)	== 0) return crISeq3D;
	if (strHead.Compare(CCTYPE_SPRITE3D)== 0) return crSprite3D;
	if (strHead.Compare(CCTYPE_SOUND)	== 0) return crSound;

	return crElse;

}
