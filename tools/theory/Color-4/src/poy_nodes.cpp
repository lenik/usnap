

// poy: POI, implementation __take_by for POS

#include <pos/graph.h>

#include "poy_nodes.h"

namespace pos {
namespace graph {

	namespace iolinks {
		using iolinks_node_t::list_t;

		bool node_link_d(iolinks_node_t *_1, iolinks_node_t *_2) {
			_pos_assert(_1 && _2);
			if (!_1 || !_2) return false;

			bool b1, b2;
			b1 = nodes_add(_1->s, _2);
			b2 = nodes_add(_2->_s, _1);
			return b1 || b2;
		}

		bool node_link(iolinks_node_t *_1, iolinks_node_t *_2) {
			bool b1, b2;
			b1 = node_link_d(_1, _2);
			b2 = node_link_d(_2, _1);
			return b1 || b2;
		}

		bool node_link_d(iolinks_node_t *_1, list_t *_2s) {
			_pos_assert(_1 && _2s);
			bool b = false;
			while (_2s) {
				b = node_link_d(_1, _2s->data) || b;
				_2s = _2s->l;
			}
			return b;
		}

		bool node_link(iolinks_node_t *_1, list_t *_2s) {
			_pos_assert(_1 && _2s);
			bool b = false;
			while (_2s) {
				b = node_link(_1, _2s->data) || b;
				_2s = _2s->l;
			}
			return b;
		}

		bool nodes_add(list_t *&_1r, iolinks_node_t *_2) {
			list_t::value_type v;

			bool fCreate = true;
			list_t *_1 = _1r;
			while (_1) {
				if (_2 == _1->data) {
					fCreate = false;
					break;
				}
				if (!_1->l) break;
				_1 = _1->l;
			}
			if (fCreate) {
				list_t *_new = new list_t;
				_new->data = _2;
				if (!_1) {
					_1r = _1 = _new;
					_1->_l = _1->l = NULL;
				} else {
					_1->l = _new;
					_new->_l = _1;
					_new->l = NULL;
				}
			}
			return fCreate;
		}

		bool nodes_union(list_t *&_1r, list_t *&_2r, bool fCreate) {
			list_t::value_type v1, v2;

			bool fChanged = false;
			list_t *_2 = _2r;
			while (_2) {
				v2 = _2->data;

				list_t *_1 = _1r;
				bool _1exist = false;
				while (_1) {
					v1 = _1->data;
					if (v1 == v2) {
						_1exist = true;
						break;
					}

					// make _1copy points at the just before NULL.
					if (!_1->l) break;

					_1 = _1->l;
				}
				if (!_1exist) {
					// add
					list_t *_2next = _2->l;
					if (fCreate) {
						list_t *_new = new list_t;
						_new->data = _2->data;
						if (!_1) {
							_1r = _1 = _new;
							_1->_l = _1->l = NULL;
						} else {
							_1->l = _new;
							_new->_l = _1;
							_new->l = NULL;
						}
					} else {
						// delete from _2
						if (_2->_l) {
							_2->_l->l = _2->l;
						} else {
							// move the head ptr
							_2r = _2->l;
						}
						if (_2->l)  _2->l->_l = _2->_l;

						// so _1r is empty
						if (!_1) {
							_1r = _1 = _2;
							// set as the initial node.
							_1->_l = _1->l = NULL;
						} else {
							// insert into _1
							_1->l = _2;
							_2->l = NULL;
							_2->_l = _1;
						}
					}
					fChanged = true;
					_2 = _2next;
				} else {
					_2 = _2->l;
				}
			}
			return fChanged;
		}

		bool nodes_destroy_list(list_t *l) {
			if (l) {
				while (l->_l) l = l->_l;
				while (l) {
					list_t *x = l;
					l = l->l;
					delete x;
				}
			}
			return true;
		}

		// enumeration
		bool nodes_enum_t::prepare(iolinks_node_t *_entry) {
			scan_cmp = ~scan_cmp;
			enum_proc_t proc1 = proc;
			proc = &nodes_enum_t::_enum_proc_dummy;
			enumerate(_entry);
			proc = proc1;
			scan_cmp = ~scan_cmp;
			return true;
		}
		bool nodes_enum_t::enumerate(iolinks_node_t *_entry) {
			bool bCanceled = false;

			scan_mark(_entry);
			if (!proc(_entry, this)) return false;

			iolinks_node_t::list_t *adj;

			adj = _entry->s;
			while (adj) {
				iolinks_node_t *_node = adj->data;
				if (!is_scaned(_node)) {
					if (!enumerate(_node)) {
						bCanceled = true;
						break;
					}
				}
				adj = adj->l;
			}
			if (bCanceled) return false;

			// iolinks is always directional.
			// if (_graph->bDirectional) {
			adj = _entry->_s;
			while (adj) {
				iolinks_node_t *_node = adj->data;
				if (!is_scaned(_node)) {
					if (!enumerate(_node)) {
						bCanceled = true;
						break;
					}
				}
				adj = adj->l;
			}
			if (bCanceled) return false;
			return true;
		}
	}

}} // ns pos.graph