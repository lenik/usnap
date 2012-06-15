
-------------------------------------------------

嵌套模版类是否被支持？
支持。如：
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

	其中 T1::iT 与 T2::iT 是不同的两个模版类。

	@ 2002-1-20
------------------------------------------------------------
