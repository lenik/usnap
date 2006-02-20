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
    void clear();
    int size() const;
    int ceil(int v) const;
    int floor(int v) const;
    bool add(const int_range& range);
    bool remove(const int_range& range);

    inline bool add(int i) { return add(int_range(i, i)); }
    inline bool remove(int i) { return remove(int_range(i, i)); }

    int_range& operator[](int seg_index);

    // int[] = { from[0] to[0] from[1] to[1] ... 0 -1 };
    int* ranges();

    bool operator<(const int_range& rhs) const;
};


#define MAX_SLOTS                       1024

// slotted-array operation test
class saot {
    // dria m_dria;
    int m_slot[MAX_SLOTS];
    int m_alloc;
    int m_nextfree;                     // -1 if slots full
public:
    saot();

    int alloc_size();

    // return: slot-index
    int add(int ar_index);

    // return: slot-index
    int remove(int ar_index);

    // return: ar-index
    int remove_slot(int slot);

    int index_at_slot(int slot);
    int slot_of_index(int ar_index);
};
