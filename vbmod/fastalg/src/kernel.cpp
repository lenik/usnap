
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
