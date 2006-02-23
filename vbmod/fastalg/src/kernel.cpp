
#include "stdafx.h"
#include "kernel.h"

bool int_range::operator<(const int_range& rhs) const {
    _assert_(rhs.from > to || rhs.to < from);
    if (rhs.from > to) {                // this | rhs
        _assert_(rhs.to > to);
        return true;
    }
    else if (rhs.to < from) {           // rhs | this
        _assert_(rhs.from < from);
        return false;
    }
    _assert_(rhs.from == from && rhs.to == to);
    return false;
}

int dria::ceil(int v) const {
    if (vec.size() == 0) return -1;
    int l = 0;
    int r = vec.size() - 1;
    int i = (r - l) / 2;
    while (l < r) {
        const int_range& x = vec[i];
        if (x.to < v)                   // x < v
            l = i + 1;                  // ? x [L ... R]    apply "greaer"
        else if (v < x.from)            // v < x
            r = i;                      // [L ... x] ?      apply "min"
        else
            return i;                   // range x covered v
        // Don't use:
        //  l + (r - l + 1) / 2  ==> Error: cause infinite loop.
        i = l + (r - l) / 2;
    }
    // expected: v < x
    if (vec[i].to < v)                  // ... < v
        return vec.size();
    return i;
}

int dria::floor(int v) const {
    if (vec.size() == 0) return -1;
    int l = 0;
    int r = vec.size() - 1;
    int i = (r - 1) / 2;
    while (l < r) {
        const int_range& x = vec[i];
        if (x.to < v)                   // x < v            apply "max"
            l = i;                      // ? [x ... R]
        else if (v < x.from)            // v < x            apply "less"
            r = i - 1;                  // [L ... R] x ?
        else
            return i;                   // range x covered v
        i = l + (r - l + 1) / 2;
    }
    // expected: x < v
    if (v < vec[i].from)                // v < ...
        return -1;
    return i;
}

void dria::clear() {
    vec.clear();
}

int dria::size() const {
    return vec.size();
}

bool dria::add(const int_range& range) {
    if (vec.size() == 0) {
        vec.push_back(range);
        return true;
    }
    int_range L;
    int_range R;
    int l = floor(range.from);          // -1 if range.from < ALL
    int r = ceil(range.to);             // size() if range.to > ALL
    _assert_(l <= r);
    _assert_(r >= 0);
    if (l < 0) {
        vec[0].from = range.from;
        l = 0;
        if (vec[0].to >= range.to)
            return true;
    }
    if (l == r)                         // full covered.
        return false;

    // _assert_(0 <= l < r <= size());
    if (vec[l].to < range.from) {
        l++;
        if (l < vec.size()) {
            vec[l].from = range.from;
        } else {
            vec.push_back(range);
            return true;
        }
    }

    if (vec[r].from > range.to) {
        // because, if r == 0, then l <= 0:
        //      l < 0       , see if (l < 0)
        //      l == 0      , see if (l == r)
        _assert_(r > 0);
        r--;
        vec[r].to = range.to;
    }

    vec.erase(&vec[l + 1], &vec[r]);
    vec[l].to = range.to;
    return true;
}

bool dria::remove(const int_range& range) {
    // NOT IMPL.
    return false;
}

int_range& dria::operator[](int seg_index) {
    return vec[seg_index];
}

int* dria::ranges() {
    int size = vec.size();
    int *ret = new int[size * 2 + 2];
    int j = 0;
    for (int i = 0; i < size; i++) {
        ret[j++] = vec[i].from;
        ret[j++] = vec[i].to;
    }
    ret[j++] = 0;
    ret[j++] = -1;
    return ret;
}


saot::saot() {
    m_used = 0;
    m_next = 0;
}


int saot::slot_alloc() {
    return m_slot.size();
}

int saot::size() {
    return m_used;
}

int saot::slot_add() {
    index_type newindex = size();

    int alloc = m_slot.size();
    if (m_next == alloc) {
        m_slot.push_back(newindex);
        m_used++;
        return m_next++;
    }

    int slot = m_next;
    m_slot[m_next++] = newindex;
    m_used++;
    // update m_next
    while (m_next < alloc) {
        if (m_slot[m_next] == SLOT_AVAILABLE)
            return slot;
        m_next++;
    }
    // loop back
    m_next = 0;
    while (m_next < slot) {
        if (m_slot[m_next] == SLOT_AVAILABLE)
            return slot;
        m_next++;
    }
    // slots full..
    m_next = alloc;                     // ask for more alloc space.
    return slot;
}

void saot::slot_remove(int slot) {
    int alloc = m_slot.size();
    _assert_(slot >= 0 && slot < alloc);
    if (m_slot[slot] != SLOT_AVAILABLE) {
        m_slot[slot] = SLOT_AVAILABLE;
        m_used--;
        if (slot == alloc - 1) {
            if (m_next != alloc)
                m_slot.pop_back();
        } else if (slot < m_next) {     // optimize
            m_next = slot;
        }
    }
}

void saot::slot_clear() {
    m_slot.clear();
    m_used = 0;
    m_next = 0;
}

int saot::idx_insert(index_type before) {
    if (before > m_used)
        return -1;
    int slot = slot_add();
    int alloc = m_slot.size();
    for (int i = 0; i < alloc; i++) {
        if (m_slot[i] >= before)
            m_slot[i]++;
    }
    m_slot[slot] = before;
    return slot;
}

int saot::idx_remove(index_type index) {
    int slot = find_index(index);
    if (slot == -1)
        return -1;
    int alloc = m_slot.size();
    for (int i = 0; i < alloc; i++) {
        if (m_slot[i] > index)
            m_slot[i]--;
    }
    slot_remove(slot);
    return slot;
}

int saot::idx_append(int count, int *slots) {
    int start = 0;
    int made = 0;
    for (int i = 0; i < m_used; i++) {
        if (m_slot[i] >= start)
            start = m_slot[i] + 1;
    }
    while (count--) {
        int slot = slot_add();
        m_slot[slot] = start++;
        if (slots) *slots++ = slot;
        made++;
    }
    return made;
}

index_type saot::find_slot(int slot) {
    _assert_(slot >= 0 && slot < m_slot.size());
    return m_slot[slot];
}

int saot::find_index(index_type index) {
    if (index < 0 || index >= m_used)
        return -1;
    int alloc = m_slot.size();
    for (int i = 0; i < alloc; i++)
        if (m_slot[i] == index)
            return i;
    return -1;
}

struct index_slot {
    index_type index;
    int slot;
};

int _cdecl index_slot_cmp(const void *a, const void *b) {
    const index_slot *p = (const index_slot *)a;
    const index_slot *q = (const index_slot *)b;
    return p->index - q->index;
}

void saot::idx_sort(int *slots) {
    index_slot *map = new index_slot[m_used];
    int i, mapi = 0;
    int alloc = m_slot.size();
    for (i = 0; i < alloc; i++) {
        if (m_slot[i] >= 0) {
            _assert_(mapi < m_used);
            map[mapi].slot = i;
            map[mapi].index = m_slot[i];
            mapi++;
        }
    }
    qsort(map, m_used, sizeof(index_slot), index_slot_cmp);
    for (i = 0; i < m_used; i++) {
        slots[i] = map[i].slot;
    }
    delete[] map;
}
