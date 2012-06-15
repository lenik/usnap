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


// #define MAX_ITEMS                       1024
#define SLOT_AVAILABLE                  -1
// #define SLOT_PLACEHOLDER                -2

typedef int index_type;
typedef std::vector<index_type> indexes;

// slotted-array operation test
class saot {
    // dria m_dria;
    indexes m_slot;

    int m_used;
    int m_next;                         // -1 if no more space available
public:
    saot();

    // slot-layer
    int slot_alloc();
    int slot_add();                     // returns -1 if no no more space available
    void slot_remove(int slot);
    void slot_clear();

    // index-layer
    int idx_insert(index_type index);   // before index
    int idx_remove(index_type index);   // WARNING: the returned slot# is a hint, which may be not usable.
    int idx_append(int count, int *slots); // returns number of indexes have been appended.

    // mapping
    int size();
    index_type find_slot(int slot);
    int find_index(index_type index);
    void idx_sort(int *slots);
};
