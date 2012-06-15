// stl1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

//#define _make__accumulate_copy_
//#define _make__adjacent_difference_
//#define _make__non_predicate_adjacent_find_
//#define _make__basic_math_
//#define _make__basic_string_
#define _make__count_
#define _make__count_if_

#ifdef _make__accumulate_copy_
#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <iterator>
#include <string>

// 1
typedef vector<float>		FloatArray;
typedef vector<string>		StringArray;
typedef ostream_iterator<
			float,
			char,
			char_traits<char>
			> FloatOstreamIt;

int main(int argc, char* argv[])
{
	FloatArray	rgFA;
	FloatOstreamIt	OstreamIt(cout, " ");

	for (int i = 0; i < 10; i++) {
		rgFA.push_back(1.0f/(i + 1));
	}

	copy(rgFA.begin(), rgFA.end(), OstreamIt);
	cout << endl;

	cout	<< "The sum of 1 + 1/2 + 1/3 + .. + 1/10 is "
		<< accumulate(rgFA.begin(), rgFA.end(), 0.0f)
		<< endl;
	cout	<< "The product of 1 * 1/2 * 1/3 * .. * 1/10 is "
		<< accumulate(rgFA.begin(), rgFA.end(), 0.0f, multiplies<float>())
		<< endl;

	StringArray	rgs;
	rgs.push_back("This ");
	rgs.push_back("is ");
	rgs.push_back("one ");
	rgs.push_back("sentences. ");

	cout	<< "The concatenated vector of strings: "
		<< accumulate(rgs.begin(), rgs.end(), string(""))
		<< endl;

	return 0;
}
#endif

#ifdef _make__adjacent_difference_
#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <iterator>

typedef vector<int>	IntegerArray;
typedef ostream_iterator< int, char, char_traits<char> >	IntOstreamIt;

void main() {
	IntOstreamIt	itOstream(cout, " ");
	IntegerArray	rgIA;
	rgIA.push_back(5661);
	rgIA.push_back(43728);
	rgIA.push_back(34898);
	rgIA.push_back(7566);
	rgIA.push_back(323);
	rgIA.push_back(5673);
	rgIA.push_back(23428);

	copy(rgIA.begin(), rgIA.end(), itOstream);
	cout	<< endl;

	IntegerArray	rgDifferences(7);
	IntegerArray::iterator itDiff = rgDifferences.begin();
	adjacent_difference(rgIA.begin(), rgIA.end(), itDiff);

	cout	<< "The adjacent diff are: ";
	copy(rgDifferences.begin(), rgDifferences.end(), itOstream);
	cout	<< endl;

	IntegerArray	rgGT(6);
	IntegerArray::iterator	itGT	= rgGT.begin();
	adjacent_difference(rgGT.begin() + 1, rgGT.end(), itGT, less<int>());

	cout	<< "Which adjacent distances are greater: "
		<< endl
		<< "(If you have [a,b,c], then you have [1,0] if a>b and b<=c)"
		<< endl;
	copy(rgGT.begin(), rgGT.end(), itOstream);
	cout	<< endl;
}
#endif

#ifdef _make__non_predicate_adjacent_find_
#include <algorithm>
#include <iostream>

void main() {
	const int	ARRAY_SIZE		= 8;
	int		IntArray[ARRAY_SIZE]	= { 1, 2, 3, 4, 4, 5, 6, 7 };

	int *		location;
	int		i;

	cout	<< "IntArray { ";
	for (i = 0; i < ARRAY_SIZE; i++) cout << IntArray[i] << ", ";
	cout	<< " }" << endl;

	location	= adjacent_find(IntArray, IntArray + ARRAY_SIZE);
	if (location != IntArray + ARRAY_SIZE) {
		cout	<< "Found adjacent pair of matching elements: ("
			<< *location << ", " << *(location + 1) << "), "
			<< "at location: " << location - IntArray << endl;
	} else {
		cout	<< "no adjacent pair of matching elements werefound. "
			<< endl;
	}
}

#endif

#ifdef _make__basic_math_
#include <functional>
#include <iostream>

class MathOps :	public plus<int>,
		public minus<int>,
		public multiplies<int>,
		public divides<int>,
		public modulus<int>
{
public:
	int	value;
	MathOps()	{ value	= 0; }
	MathOps(int x)	{ value	= x; }

	result_type	operator+(second_argument_type add2) { return value + add2; }
	result_type	operator-(second_argument_type sub2) { return value - sub2; }
	result_type	operator*(second_argument_type mul2) { return value * mul2; }
	result_type	operator/(second_argument_type div2) { return value / div2; }
	result_type	operator%(second_argument_type mod2) { return value % mod2; }

	//friend ostream&	operator<<(ostream &os, const MathOps& obj);
};

ostream& operator<<(ostream& os, const MathOps& obj) {
	os	<< obj.value;
	return os;
}

void main() {
	MathOps		one, two, three, four, five, six;
	cout	<< "using mathops class... " << endl;

	one	= 18;
	two	= one + 1;
	three	= two - 2;
	four	= three * 3;
	five	= four / 4;
	six	= five % 5;

	cout	<< "one		" << one << endl
		<< "two		" << two << endl
		<< "three	" << three << endl
		<< "four	" << four << endl
		<< "five	" << five << endl
		<< "six		" << six << endl;

}

#endif

#ifdef _make__basic_string_
#include <string>
#include <iostream>

void main() {
	string	str1("012");
	string	str2("345");

	cout	<< "str1 = " << str1.c_str() << endl;

	str1.append(str2);
	cout	<< "str1 = " << str1.c_str() << endl;

	str2	= "567";
	str1.append(str2, 1, 2);
	cout	<< "str1 = " << str1.c_str() << endl;

	char	achTest[]	= { '8', '9', 'A' };
	str1.append(achTest, 2);
	cout	<< "str1 = " << str1.c_str() << endl;

	str1.append(1, 'D');
	cout	<< "str1 = " << str1.c_str() << endl;

	str2	= "EF";
	str1.append(str2.begin(), str2.end());
	cout	<< "str1 = " << str1.c_str() << endl;

}
#endif

#ifdef _make__count_
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

void main() {
	const int VECTOR_SIZE	= 8;

	typedef vector<string>	StringVector;
	typedef StringVector::iterator	StringVectorIt;

	StringVector	NamesVect(VECTOR_SIZE);
	int result = 0;

	NamesVect[0]	= "She";
	NamesVect[1]	= "know";
	NamesVect[2]	= "Sea";
	NamesVect[3]	= "Hill";
	NamesVect[4]	= "Sea";
	NamesVect[5]	= "High";
	NamesVect[6]	= "What";
	NamesVect[7]	= "Sea";

	string	value("Sea");

	StringVectorIt	begin, end, it;
	begin	= NamesVect.begin();
	end	= NamesVect.end();

	cout	<< "NamesVect { ";
	for (it = begin; it != end; it++)
		cout	<< *it << " ";
	cout	<< " }" << endl;

	result	= count(begin, end, value);
	cout	<< "Number of elements that match \"Sea\" = "
		<< result << endl;

}
#endif
