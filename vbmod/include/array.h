#ifndef __ARRAY_H
#define __ARRAY_H

template<class _ET>
class Array {
protected:
    _ET *data;
    int allocated;
    int used;
    int growth;

public:
    Array() {
        data = 0;
        allocated = 0;
        used = 0;
        growth = 4;
    }

    Array(_ET *init, int allocated, int used = -1) {
        this->allocated = allocated;
        if (used == -1)
            used = allocated;
        this->used = used;
    }

    ~Array() {
        if (data)
            free(data);
    }

    inline operator const _ET *() const {
        return data;
    }

    inline operator _ET *() const {
        return data;
    }

    inline _ET& operator[](int index) {
        return data[index];
    }

    inline int getSize() const {
        return used;
    }

    inline int getAllocated() const {
        return allocated;
    }

    inline bool _write(const void *pv, size_t cb) {
        _assert_(pv);
        _assert_(cb % sizeof(_ET) == 0);
        int n = (int)(cb / sizeof(_ET));
        return write((const _ET *)pv, n);
    }

    inline bool write(const _ET *p, int n) {
        _assert_(p);
        if (n == 0)
            return true;
        if (! allocateMore(n))
            return false;

        memcpy(data + used, p, n2size(n));
        used += n;

        return true;
    }

    template<class _VT>
    inline bool write(const _VT value) {
        _assert_(sizeof(_VT) % sizeof(_ET) == 0);

		int n = sizeof(_VT) / sizeof(_ET);
		const _ET *p = (_ET *)&value;

        return write(p, n);
    }

	inline _ET *detach() {
		_ET *detached = data;
		data = 0;
		allocated = 0;
		used = 0;
		return detached;
	}

protected:
    inline size_t n2size(int n) const {
        return (size_t)(n * sizeof(_ET));
    }

    inline bool allocate(int n) {
        _assert_(n > 0);
        _ET *newp;
        if (data)
            newp = (_ET *)realloc(data, n2size(n));
        else
            newp = (_ET *)malloc(n2size(n));

        if (newp) {
            data = newp;
            allocated = n;
            return true;
        }

        return false;
    }

    inline bool extendTo(int n) {
        if (n <= allocated)
            return true;
        return allocate(n);
    }

    inline bool allocateMore(int more) {
        return allocate(used + more);
    }

    inline bool truncate() {
        if (used == allocated)
            return true;
        return allocate(used);
    }
};


template<class _ET>
class ArrayInput : public Array<_ET> {
protected:
    int readPos;

public:

    ArrayInput() : Array<_ET>() {
        readPos = 0;
    }

    ArrayInput(_ET *init, int allocated, int used = -1)
            : Array<_ET>(init, allocated, used) {
        readPos = 0;
    }

    inline operator const _ET *() const {
        return data + readPos;
    }

    inline operator _ET *() const {
        return data + readPos;
    }

    inline int getUnread() {
        return used - readPos;
    }

    inline bool _read(void *pv, size_t cb) {
        _assert_(pv);
        _assert_(cb % sizeof(_ET) == 0);
        int n = (int)(cb / sizeof(_ET));
        return read((_ET *)pv, n);
    }

    inline bool read(_ET *p, int n) {
        _assert_(p);
        if (! checkRead(n))
            return false;

        if (n == 0)
            return true;

        memcpy(p, data + readPos, n2size(n));
        readPos += n;
        return true;
    }

    template<class _VT>
    inline bool read(const _VT& value) {
        _assert_(sizeof(_VT) % sizeof(_ET) == 0);

		int n = sizeof(_VT) / sizeof(_ET);
		const _ET *p = (_ET *)&value;

        return read(p, n);
    }

    inline bool skip(int n) {
        if (! checkRead(n))
            return false;
        readPos += n;
        return true;
    }

protected:
    inline bool checkRead(int n) {
        return readPos + n <= used;
    }

};


class Releasable {
public:
    virtual ~Releasable() = 0;
};

class AutoRelease {
    Releasable *m_Releasable;

public:
    AutoRelease(Releasable *p) : m_Releasable(p) {
	}

    ~AutoRelease() {
        if (m_Releasable)
            delete m_Releasable;
    }
};

typedef Array<char> CharArray;
typedef Array<short> ShortArray;
typedef Array<int> IntArray;
typedef Array<long> LongArray;
typedef Array<float> FloatArray;
typedef Array<double> DOubleArray;

typedef Array<unsigned char> ByteArray;
typedef Array<unsigned short> WordArray;
typedef Array<unsigned long> DWordArray;

typedef Array<void *> PtrArray;
typedef Array<const void *> CPtrArray;

/*
typedef Array<AutoRelease> RObjectArray;
*/

typedef ArrayInput<char> CharArrayInput;
typedef ArrayInput<short> ShortArrayInput;
typedef ArrayInput<int> IntArrayInput;
typedef ArrayInput<long> LongArrayInput;
typedef ArrayInput<float> FloatArrayInput;
typedef ArrayInput<double> DOubleArrayInput;

typedef ArrayInput<unsigned char> ByteArrayInput;
typedef ArrayInput<unsigned short> WordArrayInput;
typedef ArrayInput<unsigned long> DWordArrayInput;

typedef ArrayInput<void *> PtrArrayInput;
typedef ArrayInput<const void *> CPtrArrayInput;

#endif
