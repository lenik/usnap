
#include <stdio.h>
#include <conio.h>

// ISets

#define interface struct

template <class oTYPE>
interface tc {
	tc<oTYPE> operator = (oTYPE) const = 0;
	tc& operator + (oTYPE) const = 0;
	tc& operator - (tc&) const = 0;
};

#define coVF(type)	virtual type pascal

template<class oTYPE>
struct coSet {
	coVF(coSet&)	operator = (coSet&);		// ¸³Öµ
	coVF(coSet&)	operator += (coSet&);		// ×·¼Ó
	coVF(coSet&)	operator += (oTYPE&);		// ×·¼Ó
	coVF(coSet&)	operator -= (coSet&);		// É¾¼õ
	coVF(coSet&)	operator -= (oTYPE&);		// É¾¼õ

	coVF(coSet) 	operator + (coSet&) const;		// ²¢
	coVF(coSet)	operator + (oTYPE&) const;		// ²¢
	coVF(coSet) 	operator - (coSet&) const;		// ²î
	coVF(coSet) 	operator - (oTYPE&) const;		// ²î
};

template<class oTYPE>
coSet<oTYPE> pascal	coSet<oTYPE>::operator + (coSet<oTYPE>& ) const {
	return NULL;
}

class cIntSet : public coSet<int> {
	int m_data;
};

interface ISets {
//private:
	int data;
	int tag;
//public:
	void virtual pascal Fi() { printf("Hello, world!\n"); }

	ISets& operator = (ISets& s) {
		data = s.data;
		return *this;
	}
	int operator = (int i) {
		data = i;
		return data;
	}
/*
	ISets operator + (ISets& s) {
		ISets *tmp = new ISets;
		tmp->tag = 999;
		printf("tmp -> %08lx\n", tmp);
		tmp->data = data + s.data;
		return *tmp;
	}
*/
	ISets operator + (ISets& s) {
		ISets tmp;
		ISets tmp2;
		tmp.tag = 999;
		printf("tmp -> %08lx\n", tmp);
		tmp.data = data + s.data;
		return tmp;
	}

	// N@
#ifdef tasdf
	operator ISets() {
		printf("ISets:: -> ISets translation called!\n");
		return *this;
	}
#endif
	operator int() {
		int &i = data;
		return i; }
public:
	ISets() {
		tag = data = 0;
	}
	~ISets() {
		printf("releasing (data=%4d) ", data);
		if (tag == 999) {
			printf(" note:: a tmp object");
		}
		printf("\n");
		tag = data = -1;
	}
};

interface ii {
	virtual operator + (int i) const = 0;
};

interface ISets2 {
	int data;
	int tag;
	operator ISets() {
		printf("ISets2:: -> ISets translation called!\n");
		return *(ISets *)this;
	}
	operator int() {
		return data;
	}
};

void main() {
	clrscr();
	ISets s1, s2;
	s1 = 100;
	s2 = 200;
	ISets s3;
	s3 = (s1 + s2);
	ISets s4;
	s4 = ((s1 + s2) + s3);

	ISets2 si2;
	si2.data = 760;
	ISets *psi;
	psi = &(  ISets(si2)  );
	psi->data++;

	printf("----------3------\n\
		s1 = %d\n\
		s2 = %d\n\
		s3 = %d\n\
		s4 = %d\n\
		si2= %d\n\
		psi> %d\n",
		(int)s1, (int)s2, (int)s3, (int)s4,
		(int)si2, (int)*psi);

}
