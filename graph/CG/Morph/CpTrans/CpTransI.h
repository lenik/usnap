
#ifndef __CPTRANSI_H
#define __CPTRANSI_H

#include "stdtypes.h"

/* ������ */
typedef struct _POINTR {
	INT	ref;		/* ���������� */
	INT	obj;		/* ������������ */
	REAL	dist;		/* ����Ȩֵ */
} POINTR, *PPOINTR, *LPPOINTR;

/* ��������ص����� */
typedef REAL (STDCALL *DISTANCEPROC)(LPPOINT pA, LPPOINT pB);
/* ���������ص����� */
typedef BOOL (STDCALL *CPREFERPROC)(LPPOINTR		rt,
				    INT			nt,
				    LPPOINT		cpSrc,
				    INT			nSrc,
				    LPPOINT		cpDst,
				    INT			nDst,
				    LPINT		cpDstEx,
				    INT			nDstEx,
				    INT			ref,
				    INT			obj,
				    REAL		dist,
				    DISTANCEPROC	distProc);
/* ��ֵ���̻ص����� */
typedef BOOL (STDCALL *CPTRANSFORMPROC)(REAL		slider,
					LPPOINT		cp,
					INT		ncp,
					DWORD		dwParam);
/* ˫���������ص����� */
typedef BOOL (STDCALL *CPRELATIONPROC)(LPPOINTR		rtSrc,
				       INT		nSrc,
				       LPPOINTR		rtDst,
				       INT		nDst,
				       DWORD		dwParam);

/* distance_e		ŷ�Ͼ���: Ԥ�����������ص����� */
REAL	STDCALL distance_e(LPPOINT pA, LPPOINT pB);

BOOL	STDCALL draw_on_screen(REAL, LPPOINT, INT, DWORD);

/* cp_refer		��������
 * ����
 *	����ָ���Ĺ���, ���ڱ�Ҫ��ʱ�����¹�����ָ��������ͻ�Ĺ���
 * ����
 *	rTable		������
 *	nTable		������Ĵ�С
 *	cpSrc, nSrc	Դ���Ƶ�
 *	cpDst, nDst	Ŀ����Ƶ�
 *	cpDstEx		�ų�Ŀ��������
 *	nDstEx		�ų�Ŀ����������Ԫ��
 *	ref		ָ�������Ĺ�����
 *	obj		ָ�������ı�������
 *	dist		�����ľ���Ȩֵ
 *	distProc	�����ص�
 * ���
 *	rTable		�޸ĺ�Ĺ�����
 * ����
 *	�����ɹ�����TRUE, ���򷵻�FALSE
 */
BOOL	STDCALL	cp_refer(LPPOINTR	rTable,
			 INT		nTable,
			 LPPOINT	cpSrc,
			 INT		nSrc,
			 LPPOINT	cpDst,
			 INT		nDst,
			 LPINT		cpDstEx,
			 INT		nDstEx,
			 INT		ref,
			 INT		obj,
			 REAL		dist,
			 DISTANCEPROC	distProc
			 );

/* cp_transform		���Ƶ�ת������
 * ����
 *	��Դ���Ƶ㼯��ת����Ŀ����Ƶ㼯
 * ����
 *	cpSrc		Դ���Ƶ�����
 *	nSrc		Դ���Ƶ���Ŀ
 *	cpDst		Ŀ����Ƶ�
 *	nDst		Ŀ����Ƶ���Ŀ
 *	sample		ת����ֵ���, ������(0,1], ԽСת������Խƽ��, Ĭ��0.1
 *	distProc	���������ص�, Ĭ��Ϊŷ������
 *	transProc	��ֵ���̻ص�, Ĭ��Ϊ��ȱʡ����豸����ͼ
 *	transParam	���ݸ���ֵ���̻ص��Ĳ���
 *	relProc		˫���������ص�, Ĭ��NULL����
 *	relParam	���ݸ�˫���������ص��Ĳ���
 *	relDemonstrate	��ʾ�����������
 * ����
 *	ת���ɹ�TRUE, ����ת��ʧ��
 */
BOOL	STDCALL cp_transform(LPPOINT		cpSrc,
			     INT		nSrc,
			     LPPOINT		cpDst,
			     INT		nDst,
			     REAL		sample		DEFAULT(0.1),
			     DISTANCEPROC	distProc	DEFAULT(distance_e),
			     CPTRANSFORMPROC	transProc	DEFAULT(draw_on_screen),
			     DWORD		transParam	DEFAULT(0),
			     CPRELATIONPROC	relProc		DEFAULT(NULL),
			     DWORD		relParam	DEFAULT(0),
			     BOOL		relDemonstrate	DEFAULT(FALSE),
			     CPREFERPROC	referProc	DEFAULT(cp_refer)
			     );

/* cp_setrefer		���ù���
 * ����
 *	���ù������뱻������(Ŀ���)�Ĺ���
 * ����
 *	rTable		������
 *	nTable		�������к��еĹ�����Ŀ
 *	ref		����������
 *	obj		������������
 *	dist		�����ľ���
 *	initp		��������������, ���ڼ���, Ĭ��Ϊ��ͷ��ʼ����
 * ���
 *	rTable		�����µĹ�����Ĺ�����
 * ����
 *	���ù����ɹ�TRUE, ����ʧ��
 */
BOOL	STDCALL cp_setrefer(LPPOINTR	rTable,
			    INT		nTable,
			    INT		ref,
			    INT		obj,
			    REAL	dist,
			    INT		initp		DEFAULT(0)
			    );

/* ���ع�������ʵ��ʹ�õĹ����� */
INT	STDCALL cp_rtcounts(LPPOINTR rTable, INT nTable);


#endif
