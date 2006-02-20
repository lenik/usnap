
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
