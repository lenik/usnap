
-------------------------------------------------

Ƕ��ģ�����Ƿ�֧�֣�
֧�֡��磺
	template<class T1_T>
	class T1 {
	public:
		template<class iT_T>
		class iT {
		public:
			iT_T	member;
		};
		T1_T		member;
		iT<T1_T>	member_object;
	};

	template<class T2_T>
	class T2 {
	public:
		template<class iT_T>
		class iT {
		public:
			iT_T	member;
		};
		T2_T		member;
		iT<T2_T>	member_object;
	};

	���� T1::iT �� T2::iT �ǲ�ͬ������ģ���ࡣ

	@ 2002-1-20
------------------------------------------------------------
