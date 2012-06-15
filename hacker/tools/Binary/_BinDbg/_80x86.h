
#pragma once


DWORD	_HCID_GetWordMask(int word_size) {
	return (DWORD)((((__int64)1) << word_size) - 1);
}

template<class T>
class Cpu80x86;

typedef Cpu80x86<WORD>	Cpu80x86_16;
typedef Cpu80x86<DWORD>	Cpu80x86_32;

template<class T>
class Cpu80x86 {
public:
	typedef T WORDTYPE;

	void BSF(WORDTYPE& d, WORDTYPE s);

	size_t WORDSIZE;
	WORDTYPE WORDMASK;

public:
	Cpu80x86<T>();
};


template<class T>
Cpu80x86<T>::Cpu80x86<T>() {
	WORDSIZE	= sizeof(Cpu80x86<T>::WORDTYPE) * 8;
	WORDMASK	= _HCID_GetWordMask(Cpu80x86<T>::WORDSIZE);
}

template<class T>
void
Cpu80x86<T>::BSF(Cpu80x86<T>::WORDTYPE& d, Cpu80x86<T>::WORDTYPE s) {
	WORDTYPE	search_bit	= 1;
	int		bit_offset	= 0;

	while (search_bit & WORDMASK) {
		//
		if (s & search_bit) {
			d	= bit_offset;
			return;
		}
		search_bit <<= 1;
		bit_offset++;
	}
	d	= 0;
}
