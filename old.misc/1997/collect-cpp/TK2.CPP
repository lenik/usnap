
// Article Test King 	Ver 1.00  // By DanSei  46K MEM
//1996

#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<conio.h>
#include<stdlib.h>
#include<TDVideoA.cpp>
#include"TKFont.Dat"

static int _num_info_lost = 0;

// ��������ڴ�
static void stream_comp_memreset(void *mem, size_t size) {
	register size_t p = 0;
	for (; p < size; p += sizeof(long))
		*(long *)((int)mem + p) = 0;
	for (; p < size; p++)
		*(char *)((int)mem + p) = 0;
}

// ���Ƚ�
// ref[]	�ο���, ����size_ref
// obj[]	ʵ����, ����size_obj
// search_depth	�Ƚ���� (�������0)
// same_size	��Ϊ������ͬ����С����
// cr		�ȽϽ�����ݵ��б�, ���ΪNULL�򲻴洢�ȽϽ��
//			�洢�ȽϽ��, ��Ϊ��������:
//				��ͬ(1): ����Ϊ�ǲ���ͬ������
//				����(2): ����Ϊ�Ƕ��������
//				ȱ��(3): ����Ϊ��ȱ�ٵ�����
//				����(0): ��ʾ�б�����
//			����ʱ�� (����, refλ��, objλ��, ����, refλ��, objλ��...), ���б������4���������ڴ��
//				��ͬ�� ��ͬ�� ������ ȱ����
//			������ռ������λ��
// psize_cr	cr�ṩ�ĳ���, ͬʱ���ڷ���ʵ��ʹ�õĳ���(����������)
//
// ��������ʱ����STREAM_COMP_ERROR, ���򷵻� 0

// ���ڲ�ͬ���͵�������, Ӧ���ṩ��ͬ���ͼ�����(==)������Ķ���
// ������������(��Ƕ�����, ϡ�������), �����ṩ��������Ԫ����ȡ����([])�����ͼ�����(==)����

#define STREAM_COMP_UNMATCH		0x1
#define STREAM_COMP_EXTRA		0x2
#define STREAM_COMP_LOST		0x3

#define STREAM_COMP_UNMATCH_C		'x'
#define STREAM_COMP_EXTRA_C		'e'
#define STREAM_COMP_LOST_C		'l'

#define STREAM_COMP_FILLBLANK_C		' '

#define STREAM_COMP_ERROR		-1

int  far InfoHeight=7;

void CLVersion(int k);

typedef long		LONG;
typedef unsigned char	BYTE;
typedef BYTE		*LPBYTE;
typedef char 		CHAR;
typedef CHAR		*LPSTR, *LPCTSTR, *LPTSTR;
typedef unsigned long	DWORD;

// ���Ƚ� Ex

// ���ֽڴ����ִ������͡����ڱȽ϶����Լ����ִ�
struct MBCS {
	LPBYTE	_str;

	LONG operator =(LPBYTE o_o) { return (LONG)(_str = o_o); }
	LONG operator =(LPCTSTR o_o) { return (LONG)(_str = (LPBYTE)o_o); }
	LONG operator [](int index);

	MBCS(LPBYTE o_o) { _str = o_o; }
	MBCS(LPCTSTR o_o) { _str = (LPBYTE)o_o; }
};

LONG MBCS::operator [](int index) {
	DWORD r;
	LPBYTE p = _str;

	if (index != 0) {
		if (index > 0) for (int i = 0; i < index; i++) {
			if (p[0] & 0x80) p++;
			p++;
		} else for (int i = 0; i > index; i--) {
			if (p[-1] & 0x80) p--;
			p--;
		}
	}
	r = p[0];
	if (r & 0x80) r = (r << 8) | p[1];

	return (LONG)r;
}

int pascal stream_comp_pretty_result(size_t *cr, size_t size_cr, char *rbuf, size_t *psize_rbuf, char *obuf, size_t *psize_obuf);

int pascal reset_num_info_lost();

#include <stddef.h>

int stream_comp(MBCS ref, MBCS obj, size_t size_ref, size_t size_obj, size_t search_depth, size_t same_size, size_t *cr, size_t *psize_cr) {
	size_t	pr_press = 0;		// ref��ȷ��λ�� (��δʹ��)
	size_t	po_press = 0;		// obj��ȷ��λ�� (��δʹ��)
	size_t	pr_cur = 0;		// ref�ĵ�ǰλ��
	size_t	po_cur = 0;		// obj�ĵ�ǰλ��
	LONG	rd;			// ref�ĵ�ǰ����
	LONG	od;			// obj�ĵ�ǰ����
	size_t	pr_f, po_f;		// ���ڲ��ҵ�λ�ñ���
	size_t	pcr = 0;		// �б��ĵ�ǰλ��
	int	same = 0;
	size_t	*save_match	= cr;
	size_t	*save_unmatch	= cr + 1;
	size_t	*save_extra	= cr + 2;
	size_t	*save_lost	= cr + 3;
	size_t	size_cr = 0;
	size_t	cr_used = 0;

	// ��ʼ������

	if (psize_cr) size_cr = *psize_cr;
	if (search_depth < 1) return STREAM_COMP_ERROR;

	switch (size_cr) {
	case 0: save_match	= NULL;
	case 1: save_unmatch	= NULL;
	case 2: save_extra	= NULL;
	case 3: save_lost	= NULL;
		cr = NULL;
		cr_used = size_cr;
	default:
		cr_used = 4;
		pcr = 4;
	}
	if (pcr + 3 >= size_cr) cr = NULL;
	if (save_lost)		*save_lost	= 0;
	if (save_extra)		*save_extra	= 0;
	if (save_unmatch)	*save_unmatch	= 0;
	if (save_match)		*save_match	= 0;

	// �Ƚϸ��ǲ��� (���������ص����ֲ�����min(size_ref,size_obj), ��Ҫ����ʵ�����)

	while (pr_cur < size_ref && po_cur < size_obj) {
		rd = ref[pr_cur];
		od = obj[po_cur];

		if (rd == (LONG)od) {
			if (save_match) (*save_match)++;
			goto moveright;
		}

		// �Ƿ�ȱ��?
		for (pr_f = pr_cur; pr_f < pr_cur + search_depth && pr_f < size_ref; pr_f++) {
			LONG rd = ref[pr_f];
			if (rd == (LONG)od) {
				// �ҵ�һ����ͬ��, �жϸõ㸽���Ƿ���ͬ
				same = 1;
				for (size_t pr_f2 = pr_f; pr_f2 < pr_f + same_size && pr_f2 < size_ref; pr_f2++) {
					LONG rd = ref[pr_f2];
					LONG od = obj[po_cur + pr_f2 - pr_f];
					if (!(rd == (LONG)od)) same = 0;
				}
				if (same) {
					// ��ָ��������ҵ�����ͬ��, ��Ϊȱ��.
					// ȱ�ٵĲ�����pr_cur...pr_f(����pr_cur)
					for (pr_f2 = pr_cur; pr_f2 < pr_f; pr_f2++) {
						if (save_lost) (*save_lost)++;
						if (cr != NULL) {
							cr[pcr++] = STREAM_COMP_LOST;
							cr[pcr++] = pr_f2;
							cr[pcr++] = po_cur;
							cr_used += 3;
							if (pcr + 3 >= size_cr) cr = NULL;
						} else _num_info_lost++;
					}
					// ��Ϊ�ⲿ��ȱ��, ��������ȥ
					pr_cur = pr_f;
					goto moveright;
				}
				// ������ͬ
				continue;
			}
		}

		// �Ƿ����?
		for (po_f = po_cur; po_f < po_cur + search_depth && po_f < size_obj; po_f++) {
			LONG od = obj[po_f];
			if (rd == (LONG)od) {
				// �ҵ�һ����ͬ��, �жϸõ㸽���Ƿ���ͬ
				same = 1;
				for (size_t po_f2 = po_f; po_f2 < po_f + same_size && po_f2 < size_obj; po_f2++) {
					LONG od = obj[po_f2];
					LONG rd = ref[pr_cur + po_f2 - po_f];
					if (!(rd == (LONG)od)) same = 0;
				}
				if (same) {
					// ��ָ��������ҵ�����ͬ��, ��Ϊ����.
					// ����Ĳ�����po_cur...po_f(����po_cur)
					for (po_f2 = po_cur; po_f2 < po_f; po_f2++) {
						if (save_extra) (*save_extra)++;
						if (cr != NULL) {
							cr[pcr++] = STREAM_COMP_EXTRA;
							cr[pcr++] = pr_cur;
							cr[pcr++] = po_f2;
							cr_used += 3;
							if (pcr + 3 >= size_cr) cr = NULL;
						} else _num_info_lost++;
					}
					// ��Ϊ�ⲿ�ֶ���, ���زο�����ȥ
					po_cur = po_f;
					goto moveright;
				}
				// ������ͬ
				continue;
			}
		}

		// ������
		if (save_unmatch) (*save_unmatch)++;
		if (cr != NULL) {
			cr[pcr++] = STREAM_COMP_UNMATCH;
			cr[pcr++] = pr_cur;
			cr[pcr++] = po_cur;
			cr_used += 3;
			if (pcr + 3 >= size_cr) cr = NULL;
		} else _num_info_lost++;

moveright:	// ����ȷ��
		pr_cur++;
		po_cur++;
		if (pr_press + search_depth <= pr_cur) {
			pr_press++;
			po_press++;
		}
	} // while

	// ���ǲ��ֱȽ����, Ȼ��ȽϽ�β

	if (pr_cur < size_ref) {
		// �ο������ж���, ��ȱ�ٴ���
		// ȱ�ٵĲ�����pr_cur...size_ref(����pr_cur, ������size_ref)
		for (pr_f = pr_cur; pr_f < size_ref; pr_f++) {
			if (save_lost) (*save_lost)++;
			if (cr != NULL) {
				cr[pcr++] = STREAM_COMP_LOST;
				cr[pcr++] = pr_f;
				cr[pcr++] = po_cur;
				cr_used += 3;
				if (pcr + 3 >= size_cr) cr = NULL;
			} else _num_info_lost++;
		}
	}
	if (po_cur < size_obj) {
		// ʵ�������ж���, �����ദ��
		// ����Ĳ�����po_cur...size_obj(����po_cur, ������size_obj)
		for (po_f = po_cur; po_f < size_obj; po_f++) {
			if (save_extra) (*save_extra)++;
			if (cr != NULL) {
				cr[pcr++] = STREAM_COMP_EXTRA;
				cr[pcr++] = pr_cur;
				cr[pcr++] = po_f;
				cr_used += 3;
				if (pcr + 3 >= size_cr) cr = NULL;
			} else _num_info_lost++;
		}
	}

	// ���ӽ�����
	if (cr != NULL) {
		cr[pcr++] = 0;
		cr[pcr++] = 0;
		cr[pcr++] = 0;
		cr_used += 3;
		if (pcr + 3 >= size_cr) cr = NULL;
	} else _num_info_lost++;

	if (psize_cr) *psize_cr = cr_used;
	return 0;
}

/*
 * �������ȽϽ��
 *
 * cr		���ȽϽ��
 * size_cr	���ȽϽ���ĳ���(����ͷ��4����Ԫ�ͽ�����3����Ԫ)
 * rbuf		�ο����������ȽϽ��
 * psize_rbuf	rbuf�ṩ�ĳ���, ͬʱ���ڷ���ʵ��ʹ�õĳ���. ��� <= 0 ������Ҫ�ĳ���
 * obuf		ʵ�����������ȽϽ��
 * psize_obuf	obuf�ṩ�ĳ���, ͬʱ���ڷ���ʵ��ʹ�õĳ���. ��� <= 0 ������Ҫ�ĳ���
 *
 * �����ȽϽ���и��ӽ�����'\0'
 */
int	pascal stream_comp_pretty_result(size_t *cr, size_t size_cr, char *rbuf, size_t *psize_rbuf, char *obuf, size_t *psize_obuf) {
	size_t size_rbuf, size_obuf;
	size_t size_rbuf_used = 0, size_obuf_used = 0;
	size_t size_rbuf_needed = 0, size_obuf_needed = 0;
	size_t pcr;

	if (cr == NULL) return STREAM_COMP_ERROR;
	if (psize_rbuf == NULL || psize_obuf == NULL) return STREAM_COMP_ERROR;

	size_rbuf = *psize_rbuf;
	size_obuf = *psize_obuf;

	pcr = 4;

	if ((size_rbuf == 0) || (size_obuf == 0)) {
		while (pcr + 2 < size_cr && cr[pcr] != 0) {
			size_t rp	= cr[pcr + 1];
			size_t op	= cr[pcr + 2];
			if (size_rbuf_needed < rp) size_rbuf_needed = rp;
			if (size_obuf_needed < op) size_obuf_needed = op;
			pcr += 3;
		}
		*psize_rbuf = size_rbuf_needed + 1;
		*psize_obuf = size_obuf_needed + 1;
		return 0;
	}

	if (rbuf != NULL) stream_comp_memreset(rbuf, sizeof(char) * size_rbuf);
	if (obuf != NULL) stream_comp_memreset(obuf, sizeof(char) * size_obuf);
	if (size_cr < 7) return 0;

	while (pcr + 2 < size_cr && cr[pcr] != 0) {
		size_t type	= cr[pcr];
		size_t rp	= cr[pcr + 1];
		size_t op	= cr[pcr + 2];
		switch (type) {
		case STREAM_COMP_UNMATCH:
			if (rp < size_rbuf) {
				rbuf[rp] = STREAM_COMP_UNMATCH_C;
				if (size_rbuf_used < rp) size_rbuf_used = rp;
			} else _num_info_lost++;
			if (op < size_obuf) {
				obuf[op] = STREAM_COMP_UNMATCH_C;
				if (size_obuf_used < op) size_obuf_used = op;
			} else _num_info_lost++;
			break;
		case STREAM_COMP_EXTRA:
			if (rp < size_rbuf) {
				rbuf[rp] = STREAM_COMP_LOST_C;
				if (size_rbuf_used < rp) size_rbuf_used = rp;
			} else _num_info_lost++;
			if (op < size_obuf) {
				obuf[op] = STREAM_COMP_EXTRA_C;
				if (size_obuf_used < op) size_obuf_used = op;
			} else _num_info_lost++;
			break;
		case STREAM_COMP_LOST:
			if (rp < size_rbuf) {
				rbuf[rp] = STREAM_COMP_EXTRA_C;
				if (size_rbuf_used < rp) size_rbuf_used = rp;
			} else _num_info_lost++;
			if (op < size_obuf) {
				obuf[op] = STREAM_COMP_LOST_C;
				if (size_obuf_used < op) size_obuf_used = op;
			} else _num_info_lost++;
			break;
		default: ;
		}
		pcr += 3;
	}

	for (pcr = 0; pcr < size_rbuf_used; pcr++)
		if (rbuf[pcr] == 0) rbuf[pcr] = STREAM_COMP_FILLBLANK_C;
	for (pcr = 0; pcr < size_obuf_used; pcr++)
		if (obuf[pcr] == 0) obuf[pcr] = STREAM_COMP_FILLBLANK_C;

	// ������'\0' (�����Ѿ�������memset����, ����ֻ�����Ӽ���
	if (size_rbuf_used < size_rbuf) size_rbuf_used++;
	if (size_obuf_used < size_obuf) size_obuf_used++;

	*psize_rbuf = size_rbuf_used;
	*psize_obuf = size_obuf_used;

	return 0;
}

int pascal stream_comp_mbcs(LPBYTE ref, LPBYTE obj, size_t size_ref, size_t size_obj, size_t search_depth, size_t same_size, size_t *cr, size_t *psize_cr) {
	MBCS _ref(ref);
	MBCS _obj(obj);
	return stream_comp
		(_ref, _obj, size_ref, size_obj, search_depth, same_size, cr, psize_cr);
}

int	pascal reset_num_info_lost() {
	int i = _num_info_lost;
	_num_info_lost = 0;
	return i;
}

int main(int argc, char **argv) {
	FILE *feach, *ftmpl;
	CResult r;
	CInfo itmpl, ieach;

	if ((argc <= 1) || (argc >= 4)) { CLVersion(0); return 2; }
	if (argc >= 3) {
		if ((ftmpl = fopen(argv[2], "rb")) == NULL) {
			perror("Error in source file ");
			return 4;
		}
	} else {
		if ((ftmpl = fopen("TKSource.TXT", "rb"))== NULL) {
			perror("Error in open TKSource.TXT\n");
			return 5;
		}
	}
n:
	if ((feach = fopen(argv[1], "rb")) == NULL) {
		perror("Error in test file ");
		return 10;
	}

	textattr(159); cprintf("W a i t i n g . . .");
 //fsrc

	compfile(ftmpl, feach, r, itmpl, ieach);

	fclose(ftmpl);
	fclose(feach);

	float ss = 0.00;
	itmpl.ntot -= itmpl.nsp + itmpl.not;
	ieach.ntot -= ieach.nsp + ieach.not;
	r.rtot -= r.rsp + r.rot;
	r.wtot -= r.wsp + r.wot;
	r.etot -= r.esp + r.eot;
	r.ltot -= r.lsp + r.lot;
	if (itmpl.ntot > 0)
		ss =
			(float)(r.rtot) / itmpl.ntot -
			(float)(r.wtot + r.etot + r.ltot) / itmpl.ntot * 5;
	ss *= 100;
	if (ss < 0) ss = 0;

 //Print Result...
 textattr(31);
 clrscr();
 TextFont16(C_Mb_2,0x80); TextFont16(C_Hu_2,0x82); TextFont16(C_Bi_3,0x84); TextFont16(C_Jc_4,0x86);
 TextFont16(C_Yi_1,0x88); TextFont16(C_Dai4,0x8a);
 TextFont16(C_Zuo4,0xe0); TextFont16(C_Zhe3,0xe2);
 TextFont16(C_Xie4,0xf0); TextFont16(C_Ji_4,0xf2); TextFont16(C_Lei2,0xf4);
 TextFont16(C_Yr_2,0x90); TextFont16(C_Ce_4,0x92); TextFont16(C_Shi4,0x94); TextFont16(C_Wen2,0x96); TextFont16(C_Jm_4,0x98);
 TextFont16(C_Ks_1,0xa0); TextFont16(C_Ge_2,0xa2); TextFont16(C_Zi_4,0xa4); TextFont16(C_Fu_3,0xa6); TextFont16(C_Hao4,0xa8);
 TextFont16(C_Vs_1,0xb0); TextFont16(C_Yy_1,0xb2);
 TextFont16(C_Vg_4,0xb4); TextFont16(C_Qt_4,0xb6); TextFont16(C_Cuo4,0xb8); TextFont16(C_Wu_4,0xba);
 TextFont16(C_Zg_1,0xc0); TextFont16(C_Lou4,0xc2);
 TextFont16(C_Qi_2,0xc4); TextFont16(C_Ta_1,0xc6); TextFont16(C_He_2,0xc8); TextFont16(C_Ji_d,0xca);
 TextFont16(C_Xc_3,0xcc); TextFont16(C_Py_2,0xce);
 TextFont16(C_Shi3,0xd0); TextFont16(C_Ys_4,0xd2);
 TextFont16(C_Bg_3,0xd4); TextFont16(C_Rr_3,0xd6);//Jm=0x98
 TextFont16(C_Bc_1,0xd8); TextFont16(C_Vun3,0xda); TextFont16(C_Fen1,0xdc);

 printf("\n\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\t\xf0\xf1\xf2\xf3\xf4\xf5, 1996 z.j.china\n");
 printf("\n\t\t\x90\x91\x96\x97\x98\x99:%11s\t\x92\x93\x94\x95\x96\x97\x98\x99:%11s\n",(argc==3)?argv[2]:"TKSource.TXT",argv[1]);
 printf("\xb2\xb3\x96\x97\xa6\xa7\xa8\xa9=\t%d\t\t\t%d\n",itmpl.nes,ieach.nes);
 printf("\xb2\xb3\x96\x97\xa4\xa5\xa6\xa7=\t%d\t\t\t%d\n",itmpl.nec,ieach.nec);
 printf("\xb0\xb1\x96\x97\xa6\xa7\xa8\xa9=\t%d/2\t\t\t%d/2\n",itmpl.ncs,ieach.ncs);
 printf("\xb0\xb1\x96\x97\xa4\xa5\xa6\xa7=\t%d/2\t\t\t%d/2\n",itmpl.ncc,ieach.ncc);
 printf("\xc8\xc9\xca\xcb\t=\t%d\t\t\t%d\n\n",itmpl.ntot,ieach.ntot);
 printf("\xa0\xa1\xa2\xa3\t=\t%d\t\t\t%d\n",itmpl.nsp,ieach.nsp);
 printf("\xc4\xc5\xc6\xc7\t=\t%d\t\t\t%d\n",itmpl.not,ieach.not);

 printf("\n\t\t\xb4\xb5\xb6\xb7\t\xb8\xb9\xba\xbb\t\xba\xbb\xc0\xc1\t\xc2\xc3\xa4\xa5\t\t  \xcc\xcd  \xce\xcf\n");
 printf("\xb2\xb3\x96\x97\xa6\xa7\xa8\xa9=\t%d\t%d\t%d\t%d\t\t\xb4\xb5 \x4 %d\n",  r.res, r.wes, r.ees, r.les, r.rtot);
 printf("\xb2\xb3\x96\x97\xa4\xa5\xa6\xa7=\t%d\t%d\t%d\t%d\t\t\xba\xbb \x4 %d\n",  r.rec, r.wec, r.eec, r.lec, r.wtot);
 printf("\xb0\xb1\x96\x97\xa6\xa7\xa8\xa9=\t%d/2\t%d\t%d\t%d\t\t\xc0\xc1 \x4 %d\n",r.rcs, r.wcs, r.ecs, r.lcs, r.etot);
 printf("\xb0\xb1\x96\x97\xa4\xa5\xa6\xa7=\t%d/2\t%d\t%d\t%d\t\t\xc2\xc3 \x4 %d\n",r.rcc, r.wcc, r.ecc, r.lcc, r.ltot);
 printf("\xc8\xc9\xca\xcb\t=\t%d\t%d\t%d\t%d\t\t  \xd8\xd9\xda\xdb\xdc\xdd\n\t\t\t\t\t\t\t%f\xdc\xdd\n",
	r.rtot, r.wtot, r.etot, r.ltot,
	ss);
 printf("\xa0\xa1\xa2\xa3\t=\t%d\t%d\t%d\t%d\n",r.rsp, r.wsp, r.esp, r.lsp);
 printf("\xc4\xc5\xc6\xc7\t=\t%d\t%d\t%d\t%d\n",  r.rot, r.wot, r.eot, r.lot);

 printf("\n\xf0\xf1\xf0\xf1\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\x98\x99!!!\n");

 return (int)ss;
}

void CLVersion(int k)
{text_info FirstScreen,TempScreen;
 gettextinfo(&FirstScreen);
 TextFont16(C_Mb_2,0x80); TextFont16(C_Hu_2,0x82); TextFont16(C_Bi_3,0x84); TextFont16(C_Jc_4,0x86);
 TextFont16(C_Yi_1,0x88); TextFont16(C_Dai4,0x8a);
 TextFont16(C_Ge_2,0x90); TextFont16(C_Shi4,0x92);
 TextFont16(C_Yr_2,0x94); TextFont16(C_Bei4,0x96); TextFont16(C_Wen2,0x98); TextFont16(C_Jm_4,0x9a);
 TextFont16(C_Zuo4,0xe0); TextFont16(C_Zhe3,0xe2);
 TextFont16(C_Xie4,0xf0); TextFont16(C_Ji_4,0xf2); TextFont16(C_Lei2,0xf4);
 printf("\n\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\t\xe0\xe1\xe2\xe3:\xf0\xf1\xf2\xf3\xf4\xf5\nCopyright 1996\tTopCroakSoftware. All rights reserved.\n");
 if (k==1) return;
 printf("\n\x90\x91\x92\x93:\n\t\tTKing <\x96\x97\x84\x85\x86\x87\x98\x99\x9a\x9b> [\x94\x95\x98\x99\x9a\x9b=\x22TKSource.TXT\x22]\n");
 gettextinfo(&TempScreen);
 getch();
 gotoxy(1,(FirstScreen.winbottom-FirstScreen.cury<=InfoHeight)?FirstScreen.winbottom-InfoHeight+2:FirstScreen.cury+1);
 printf("IT Test King I\tAuthor / DanSei, 1996\n");
 gotoxy(1,(FirstScreen.winbottom-FirstScreen.cury<=InfoHeight)?FirstScreen.winbottom-InfoHeight+5:FirstScreen.cury+4);
 printf("Usage:\n\t\tTKing <Test File> [Source File=\x22TKSource.TXT\x22]\n");
 gotoxy(1,TempScreen.cury);
 TResetCharMap();
}