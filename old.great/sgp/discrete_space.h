
/*
 * Discrete space 通用离散空间
 *
 * 桃壳高科技 2001
 */

#pragma once

#include <sgp/sgpdef.h>
#include <list>
#include <vector>
#include <utility>
#include <his/pointer.h>
#include <stdarg.h>

SGP_BEGIN



///////////////////////////////////////////////////////////////////////////////
//
// infinite-D
//
template<class _Ty>
class linear_space {
public:
	typedef _Ty *pointer;
	typedef _Ty& reference;
	typedef std::allocator<_Ty> _A;
	typedef _A::size_type size_type;
	typedef std::vector<size_type> vector;
	typedef std::pair<vector, vector> box_range;

private:
	his::smart_pointer<int> _dimcache;		// 各维的下标缓存
	his::smart_pointer<size_type> _dimpitchcache;	// 各维的跨距缓存
public:
	int dimensions;
	typedef std::list<int> dimension_list_type;
	dimension_list_type dimension_list;
	pointer base;
public:
	reference element(vector v) {
		if (base == NULL || dimensions <= 0) {
			throw std::logic_error(string("class invalid"));
		}
		size_type offset = 0;
		for (int i = 0; i < dimensions; i++) {
			if (v[i] < 0 || v[i] >= _dimcache[i]) {
				throw std::out_of_range(string("out of index"));
			}
			offset += v[i] * _dimpitchcache[i];
		}
		return base[offset];
	}

	reference element(size_type index1, ...) {
		vector correspond_vector = new size_type[dimensions];
		va_list args;
		va_start(args, index1);
		size_type thearg;
		for (int i = 0; i < dimensions; i++) {
			thearg = va_arg(args, size_type);
			correspond_vector[i] = thearg;
		}
		va_end(args);
		reference retval = element(correspond_vector);
		delete[] correspond_vector;
		return retval;
	}
	int getdimension(size_type dimindex) {
		if (dimindex >= 0 && dimindex < dimensions) {
			return _dimcache[dimindex];
		} else {
			return 0;
		}
	}

protected:
	void _initspace(pointer _base, int dims, va_list vargs) {
		dimensions = dims;
		base = _base;
		int thedim;
		dimension_list.clear();
		for (int i = 0; i < dims; i++) {
			thedim = va_arg(vargs, int);
			dimension_list.push_back(thedim);
		}
		// set dimension cache
		_dimcache = NULL;
		_dimpitchcache = NULL;
		if (dims > 0) {
			_dimcache.allocate(dims);
			_dimpitchcache.allocate(dims);
			dimension_list_type::iterator li = dimension_list.begin();
			for (i = 0; li != dimension_list.end(); ++li) {
				_dimcache[i++] = *li;
			}
			_dimpitchcache[dims - 1] = 1;	// 最右维(底维)具有存储连续性, 跨距为1.
			for (i = dims - 2; i >= 0; i--) {
				_dimpitchcache[i] = _dimcache[i + 1] * _dimpitchcache[i + 1];
			}
		}
	}
public:
	void initspace(pointer _base, int dims, ...) {
		va_list eachdim;
		va_start(eachdim, dims);
		va_arg(eachdim, int);	// skip the 'int dims'
		_initspace(_base, dims, eachdim);
		va_end(eachdim);
	}

	linear_space(pointer _base, int dims, ...) {
		va_list eachdim;
		va_start(eachdim, dims);
		va_arg(eachdim, int);	// skip the 'int dims'
		_initspace(_base, dims, eachdim);
		va_end(eachdim);
	}
	linear_space() {
		initspace(NULL, 0) ;
	}
	~linear_space() {}
};

SGP_END
