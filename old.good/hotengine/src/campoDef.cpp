
#include "stdafx.h"

#include "campoDef.h"

// Ӧ�ó���ص����� ���ڿ������̵� ����ֵ
#define ENUMLIST_BREAK			0			// ȡ��ö��
#define ENUMLIST_NEXT			1			// ö����һ��
#define ENUMLIST_PREVIOUS		2			// ö��ǰһ��
#define ENUMLIST_REUSE			3			// ��ö��һ��
#define ENUMLIST_GOHEAD			4			// �ص�ͷ�� ö��
#define ENUMLIST_GOEND			5			// ö�����һ��

#define ENUMLIST_ERRORED		10			// ö��ʱ����

// EnumElements �����ķ���ֵ
#define ENUMLIST_ERROROCCURED		FALSE			// ö��ʱ��������

#define ENUMLIST_ALLPASSED		100			// ȫ��ͨ��
#define ENUMLIST_BREAKED		101			// ö�ٱ�ȡ��
#define ENUMLIST_COMPLEX		103			// ��һ������ö�� (��������_BREAK, _ERRORED����������)

// ָ���б��ö�ٹ���
int cPtrList::EnumElements(PTRENUMFUNC enumFunc, LPVOID param) {
	POSITION	position;
	LPVOID		element;
	int			control;
	BOOL		bComplex = FALSE;

	for (position = GetHeadPosition(); position != NULL; ) {
		element = GetAt(position);
		// ���û�����̲���ȡ����ֵ
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
