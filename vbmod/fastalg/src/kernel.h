#pragma once

#include <vector>

struct int_range {
    int from;
    int to;
    int_range() {}
    int_range(int a, int b) : from(a), to(b) {}
    bool operator<(const int_range& rhs) const;
};

/*
#include <functional>
#include <xtree>

typedef std::less<int_range> int_range_less;

struct int_range_hash : public std::unary_function<int_range, int> {
    const int& operator()(const int_range &x) const {
        return x.from;
    }
};

typedef std::_Tree<int, int_range, int_range_hash, int_range_less, std::allocator<int_range> > int_range_tree;

class irt : public int_range_tree {
public:
    bool existed(int_range& ir);
    iterator left(int_range& ir);
    iterator right(int_range& ir);
};

bool irt::existed(int_range& ir) {
    iterator it = lower_bound(ir.from);
    while (it != end()) {
        it++;
    }
    return true;
}
*/

typedef std::vector<int_range> int_ranges;

// discover ranges in array
class dria {
    //int_range_tree tree;
    int_ranges vec;
public:
    dria();
    ~dria();

    void clear();
    int ceil(int v) const;
    int floor(int v) const;
    bool add(const int_range& range);
    bool remove(const int_range& range);

    // int[] = { from[0] to[0] from[1] to[1] ... 0 -1 };
    int* ranges();

    bool operator<(const int_range& rhs) const;
};

// slotted-array operation test
class saot {
};
