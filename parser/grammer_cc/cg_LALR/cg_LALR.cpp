
#include "stdafx.h"

#include "cg_LALR.h"


// ָ�����ʽ�Ĳ���ʽָ������, C@speed;
// symp[symbol_id] -> production.l == symbol_id
production *symp;

// N@lambda symbol
void construct_firsts(symbol s, symbols& firsts) {
	ASSERT(IS_NTS(s));
	productions::iterator pi;
	symbolss::iterator ssi;
	symbols::iterator si;
	symbol _s;

	symbolss& rhs = symp[s]->r;
	for (ssi = rhs.begin(); ssi != rhs.end(); ++ssi) {
		if (ssi->size() > 0) {
			// ���ս�� s �� >0 ������ʽ
			si = ssi->front();

			if (si->size() > 0) {
				// �ò���ʽ��ֱ�ӵ�����
				_s = si->front();

				if (IS_NTS(_s)) {
					// ����ʽ�Է��ս����ʼ
					construct_firsts(_s, firsts);
				} else {
					firsts.push_back(_s);
				}
			}
		}
	}
}

// N@lambda symbol
void construct_follows(symbol s, follows& follows) {

}


//

// LALR�ķ��� FFP ���ϲ�������


int main(int argc, char* argv[])
{
	return 0;
}
