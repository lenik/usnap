
#include "stdafx.h"

#include "cg_LALR.h"


// 指向产生式的产生式指针数组, C@speed;
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
			// 非终结符 s 有 >0 个产生式
			si = ssi->front();

			if (si->size() > 0) {
				// 该产生式不直接导出空
				_s = si->front();

				if (IS_NTS(_s)) {
					// 产生式以非终结符开始
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

// LALR文法的 FFP 集合产生方法


int main(int argc, char* argv[])
{
	return 0;
}
