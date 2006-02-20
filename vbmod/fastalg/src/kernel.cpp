
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
    m_alloc = 0;
    m_nextfree = -1;
}

int saot::alloc_size() {
    return m_alloc;
}

int saot::add(int ar_index) {
    _assert_(ar_index >= 0);
    int slot = slot_of_index(ar_index);
    if (slot >= 0)  // existed
        return slot;
    if (m_nextfree == m_alloc) {
        _assert_(m_alloc < MAX_SLOTS);
        m_slot[m_alloc] = -1;
        m_alloc++;
    }
    m_slot[slot = m_nextfree++] = ar_index;
    while (m_nextfree < m_alloc) {
        if (m_slot[m_nextfree] == -1)
            break;
        m_nextfree++;
    }
    if (m_nextfree == m_alloc) {
        // loop back, try once
        m_nextfree = 0;
        while (m_nextfree < slot) {
            if (m_slot[m_nextfree] == -1)
                break;
            m_nextfree++;
        }
        if (m_nextfree == slot) {
            // Really full..
            m_nextfree = m_alloc;       // ask for more alloc space.
        }
    }
    return slot;
}

int saot::remove(int ar_index) {
    _assert_(ar_index >= 0);
    int slot = slot_of_index(ar_index);
    if (slot >= 0)
        m_slot[slot] = -1;

    // adjust array indexes.
    for (int i = 0; i < m_alloc; i++)
        if (m_slot[i] > ar_index)
            m_slot[i]--;

    return slot;
}

int saot::remove_slot(int slot) {
    _assert_(slot >= 0 && slot < m_size);
    int i = m_slot[slot];
    m_slot[slot] = -1;
    return i;
}

int saot::index_at_slot(int slot) {
    _assert_(slot >= 0 && slot < m_size);
    return m_slot[slot];
}

int saot::slot_of_index(int ar_index) {
    _assert_(ar_index >= 0);
    for (int s = 0; s < m_alloc; s++)
        if (m_slot[s] == ar_index)
            return s;
    return -1;
}
