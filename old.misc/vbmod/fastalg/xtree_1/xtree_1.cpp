// xtree_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <xtree>
#include <set>

struct int_hash : public std::unary_function<int, int> {
    const int& operator()(const int& x) const {
        return x;
    }
};

typedef std::less<int> int_less;
typedef std::_Tree<int, int, int_hash, int_less, std::allocator<int> > int_tree;

class int_searcher : public int_tree {
public:
    int_searcher() : int_tree(int_less(), false /* not multi */) {}

    int valuebefore(int v) {
        iterator it = lower_bound(v);
        return *it;
    }
};

int main(int argc, char* argv[])
{
    bool multi = false;
    int_searcher t;
    //int_tree t(int_less(), false);
    int x;
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);
    x = t.valuebefore(50);

	printf("%d\n", x);
	return 0;
}
