
class a {
public:
	int i1;
	class b {
		int i2;
		void f2();
	} m_b;
	friend class b;
};

void a::b::f2() {
	a::i1 = 0;
}

void main() {
}
