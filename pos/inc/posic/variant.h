//
// POS in C/C++
//	variant template
//

//
// 2003.5.
// 2003.5.28	start

// todo:
//	variant::
#pragma once


// forward declaration
namespace pos {
namespace posic {


	template<>
		struct hfvc {
	};

	template<typename raw_type>
	struct body {
		BOOST_STATIC_CONSTANT(int, type_id = type_traits<raw_type>::type_id);
	};

	template<bool bComplex = false, bool bHfvc,
		bool bRefCount, bool b_BodyCache,
		bool bBindFriend,
		pv_t procRead, pv_t procWrite,
		bool b_r, bool b_a,
		domain_t *pDomain, unit_t *pUnit,
		void *pCards, void *pLeb, void *pMeta,
		bool bNoRWCache
		>
	struct complex_variant {
		//
	};

	template<bool bComplex, bool bHfvc,
		bool bRefCount, bool b_BodyCache,
		bool bBindFriend,
		pv_t procRead, pv_t procWrite,
		bool b_r, bool b_a,
		domain_t *pDomain, unit_t *pUnit,
		void *pCards, void *pLeb, void *pMeta,
		bool bNoRWCache
		>
	struct complex_variant<false, false,
		true, b_BodyCache, bBindFriend, procRead, procWrite, b_r, b_a, pDomain, pUnit,
		pCards, pLeb, pMeta, bNoRWCache>
	{
		void *
	};

	// subtype: void for non-extype.
	template<typename Tsubtype, typename Tcomplex, typename Tbody>
	struct variant {

		type_traits<Tsubtype>::storage id_subtype;

		//
		Tcomplex *_complex;

		Tbody _body;
	};

	template<class var_imp_t, typename pvt_type, bool ex_type>
	struct pvt_type_hdr {
		pvt_type_hdr() {
			var_imp_t::type = pvt_type::type_id_primary;
		}
	};
	template<class var_imp_t, typename pvt_type, bool ex_type>
	struct pvt_type_hdr<var_imp_t, pvt_type, true> {
		pvt_type_hdr() {
			var_imp_t::type = pvt_type::type_id_primary;
			//
		}
	};

	template<void *_read, void *_write, pos::var_t *_leb, void *_card>
	struct complex_t {
		//
	};
	template<typename complex_detail>
	struct var_t : public pos::var_t {

	};
	// ...
}} namespace pos.posic

#include <pos/config.h>
// #include ...

namespace pos {
namespace posic {

#	pragma pack(push, 4)

	// struct ...

#	pragma pack(pop)

	// additional implementation...

}} // namespace pos.posic