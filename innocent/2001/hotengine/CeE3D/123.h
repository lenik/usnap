#define _SAME0(f)								\
	STDMETHODIMP								\
	CeE3DUtil::f() {							\
		::glu##f();							\
		return NOERROR;							\
	}

#define _SAME1(f, p1T, p1N)							\
	STDMETHODIMP								\
	CeE3DUtil::f(p1T p1N) {							\
		::glu##f(p1N);							\
		return NOERROR;							\
	}

#define _SAME2(f, p1T, p1N, p2T, p2N)						\
	STDMETHODIMP								\
	CeE3DUtil::f(p1T p1N, p2T p2N) {					\
		::glu##f(p1N, p2N);						\
		return NOERROR;							\
	}

#define _SAME3(f, p1T, p1N, p2T, p2N, p3T, p3N)					\
	STDMETHODIMP								\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N) {				\
		::glu##f(p1N, p2N, p3N);					\
		return NOERROR;							\
	}

#define _SAME4(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N) 			\
	STDMETHODIMP								\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N) {			\
		::glu##f(p1N, p2N, p3N, p4N);					\
		return NOERROR;							\
	}

#define _SAME5(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N) 		\
	STDMETHODIMP								\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N) {		\
		::glu##f(p1N, p2N, p3N, p4N, p5N);				\
		return NOERROR;							\
	}

#define _SAME6(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N) 									\
	STDMETHODIMP																\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N) {									\
		::glu##f(p1N, p2N, p3N, p4N, p5N, p6N);												\
		return NOERROR;															\
	}

#define _SAME7(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N)								\
	STDMETHODIMP																\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N) {								\
		::glu##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N);											\
		return NOERROR;															\
	}

#define _SAME8(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N) 						\
	STDMETHODIMP																\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N) {							\
		::glu##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N);										\
		return NOERROR;															\
	}

#define _SAME9(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N, p9T, p9N) 					\
	STDMETHODIMP																\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N, p9T p9N) {						\
		::glu##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N, p9N);										\
		return NOERROR;															\
	}

#define _SAME10(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N, p9T, p9N, p10T, p10N) 			\
	STDMETHODIMP																\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N, p9T p9N, p10T p10N) {				\
		::glu##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N, p9N, p10N);									\
		return NOERROR;															\
	}

#define _SAME11(f, p1T, p1N, p2T, p2N, p3T, p3N, p4T, p4N, p5T, p5N, p6T, p6N, p7T, p7N, p8T, p8N, p9T, p9N, p10T, p10N, p11T, p11N) 		\
	STDMETHODIMP																\
	CeE3DUtil::f(p1T p1N, p2T p2N, p3T p3N, p4T p4N, p5T p5N, p6T p6N, p7T p7N, p8T p8N, p9T p9N, p10T p10N, p11T p11N) {			\
		::glu##f(p1N, p2N, p3N, p4N, p5N, p6N, p7N, p8N, p9N, p10N, p11N);								\
		return NOERROR;															\
	}
