// struct_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#define TEMPLATE_IMPL
//#define TEMPLATE_2
#define COCLASS_1

CComModule _Module;

#if defined(CREATE_DESTROY_COUNTS)
	struct product {
		static int objs;	// instance objects
		static int cops;	// construct operations
		static int dops;	// deconstruct operations
		int	i;
		int	j;

		product(int _i, int _j) : i(_i), j(_j) {
			objs++;
			cops++;
		}
		~product() {
			objs--;
			dops++;
		}
	};

	int	product::objs	= 0;
	int	product::cops	= 0;
	int	product::dops	= 0;

	product getproduct() {
		return product(3, 4);
	}

	int main(int argc, char* argv[])
	{
		product	myprod = getproduct();
		myprod.i++;
		myprod.j--;
		return 0;
	}

#elif defined(TEMPLATE_IMPL)
	template<typename T = int>
	class CA {
	public:
		T init(T i);
	};

	void main() {
		CA<> intC;
		intC.init(3);
	}

	template<typename T>
	T CA<T>::init(T i) {
		return i;
	}

#elif defined(TEMPLATE_2)
	template <typename T>
	class CT : public T {
	public:
		T *member;
	};

	class C1;
	class C2;
	typedef CT<C1>	CC1;
	typedef CT<C2>	CC2;


	class C1 {
	public:
		//CC1	anc1;
		CC2	anc2;
	};

	class C2 {
	public:
		CC1	bnc1;
		//CC2	bnc2;
	};

	void main() {
		CC1	v;
	};
#elif defined(COCLASS_1)
	interface DECLSPEC_UUID("00000000-0001-0001-0001-486954656368") I1 {
		virtual void f1() = 0;
	};
	class C1 : public CComObjectRoot, public I1 {
	public:
		virtual void f1() {}
		BEGIN_COM_MAP(C1)
			COM_INTERFACE_ENTRY(I1)
		END_COM_MAP()
		DECLARE_NOT_AGGREGATABLE(C1)

	};
	typedef CComObject<C1>	CC1;
	void f_I1(I1 *){}
	void f_C1(C1 *){}
	void f_CC1(CC1 *){}
	void g_I1(I1 **){}
	void g_C1(C1 **){}
	void g_CC1(CC1 **){}
	void main() {
		CC1	*m_c1	= NULL;
		I1	*pI1	= (I1 *)m_c1;
		C1	*pC1	= (C1 *)m_c1;

		I1	*m_i1	= NULL;
		CC1	*pCC1	= (CC1 *)m_i1;
			pC1	= (C1 *)m_i1;

		C1	*m_1	= NULL;
			pCC1	= (CC1 *)m_1;
			pI1	= (I1 *)m_1;

		f_I1(pI1);
		f_I1(pC1);
		f_I1(pCC1);

		f_C1((C1 *)pI1);
		f_C1(pC1);
		f_C1(pCC1);

		f_CC1((CC1 *)pI1);
		f_CC1((CC1 *)pC1);
		f_CC1(pCC1);

		g_I1(&pI1);
		g_I1((I1 **)&pC1);
		g_I1(&((I1 *)pCC1));

		g_C1(&pI1);
		g_C1(&pC1);
		g_C1(&pCC1);

		g_CC1(&pI1);
		g_CC1(&pC1);
		g_CC1(&pCC1);

	}
#endif
