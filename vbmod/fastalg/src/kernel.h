#pragma once

#include <functional>
#include <xtree>

struct int_range {
    int from;
    int to;

    bool operator<(const int_range& rhs) const;
};

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

// discover ranges in array
class dria {
    int_range_tree tree;
public:
    dria();
    ~dria();

    void clear();
    void add(int_range *range);
    void remove(int_range *range);

    // int[] = { from[0] to[0] from[1] to[1] ... 0 -1 };
    int* ranges();

    bool operator<(const int_range& rhs) const;
};
