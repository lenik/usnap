

#pragma once

#include <pos/config.h>
#include <pos/variant.h>
#include <pos/pointer.h>
#include <list>


namespace pos {

#if __POS__DEBUG > 0
	namespace debug {
		struct auto_var_usage {
			asz_ct m_name;
			long m_read_count;
			long m_write_count;
		};

		typedef std::list<auto_var_usage *> auto_var_usage_list;
		extern auto_var_usage_list g_auto_vars;
	}
#endif

	namespace util {
		// buffer pointer, auto delete.
		struct auto_release_ptr {
			void *m_pv;
			auto_release_ptr(void *pv) { m_pv = pv; }
			~auto_release_ptr() {
				if (m_pv) delete m_pv;
			}
			// don't use.
			auto_release_ptr(size_t size) { m_pv = new u8_t[size]; }
		};

		// fix-size buffer, (scope-auto), just a memory block.
		template<size_t size>
		struct auto_buf_fix {
			typedef u8_t auto_buf_fix_type[size];
			auto_buf_fix_type _by;
#if __POS__DEBUG > 0
			debug::auto_var_usage m_usage;
			static long g_def_count;
			auto_buf_fix(asz_ct name) {
				m_usage.m_name = name;
				debug::g_auto_vars.push_back(&m_usage);
				g_def_count++;
			}
			auto_buf_fix() {
				auto_buf_fix("##unnamed");
			}
#else
			auto_buf_fix(asz_t name) {}
			auto_buf_fix() {}
#endif
		};

#if __POS__DEBUG > 0
		template <size_t size>
		long auto_buf_fix<size>::g_def_count = 0;
#endif


		// auto-type, such as auto_type<PVT, 1024(bytes)>
		template<typename _ty, size_t size = sizeof(_ty), bool _initialize = true>
		struct auto_type {
			typedef auto_buf_fix<size>::auto_buf_fix_type auto_buf_fix_type;
			auto_buf_fix_type _buf;
			inline operator _ty() { return *(_ty *)_buf; }
			auto_type() {
				if (_initialize) {
					new(_buf) u8_t[size];
				}
			}
			~auto_type() {
				if (_initialize) {
					delete[] _buf;
				}
			}
		};


		// --------------------------------------------------------------------------------
		// utilities for declaring POS.Variant
		// --------------------------------------------------------------------------------
		inline void *_new_pvt(const long size, const int ty = pvt_void) {
			void *pv = new u8_t[4 + size];
			if (!pv) return NULL;
			*(u32_t *)pv = ty;	// | PVTF_BIND
			return pv;
		}
		// allocate new PVT which is't on the stack.
#		define new_pvt(ty) (pos::PVT *)pos::util::_new_pvt(sizeof(pos::ty##_t), pos::pvt_##ty)

		// declare PVT: extend mode
#		define auto_pvtx(ty, name) \
			pos::PVT& name = *(pos::PVT *)_new_pvt(sizeof(pos::ty##_t), pos::pvt_##ty); \
			__pvt_auto_object __ao_##name(&name);

		// declare PVT: stack mode
#		define auto_pvt(ty, name) \
			pos::u32_t __auto_buf_##name[1 + ((sizeof(pos::ty##_t) + 3) >> 2)] = { pos::pvt_##ty, }; \
			pos::PVT& name = *(pos::PVT *)__auto_buf_##name;

		// declare PVT: specified size mode
#		define auto_pvt_size(size, name) \
			pos::u32_t __auto_buf_##name[1 + ((size + 3) >> 2)]; \
			pos::PVT& name = *(pos::PVT *)__auto_buf_##name;


		// --------------------------------------------------------------------------------
		// utilities for declaring POS.Pointer
		// --------------------------------------------------------------------------------

		inline pointer_t *new_pointer(const u32_t hdr, const size_t bufsize = 0) {
			int cb = 8;
			if (hdr & POINTERF_COMPLEX) {
				cb = 16;
			}
			pointer_t *pNew = (pointer_t *)(new u8_t[cb]);
			pNew->hdr = hdr;
			pNew->_init_complex();
			if (bufsize > 0) {
				pNew->_pv = new u8_t[bufsize];
			}
			return pNew;
		}


		// declare Pointer: extend mode
#		define auto_pointerx(hdr, name) \
			pointer_t& name = *new_pointer(hdr); \
			__pvt_auto_object __ao_##name(&name);

		// declare Pointer: stack mode, hdr must be numeric constant
#		define auto_pointer(hdr, name) \
			u32_t __auto_buf_##name[(hdr) & POINTERF_COMPLEXMASK ? 4 : 2] = { hdr, }; \
			pointer_t& name = *(pointer_t *)__auto_buf_##name;

	} // namespace util
} // namespace pos
