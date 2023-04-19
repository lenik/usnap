

tree:
	leaves stick root
	s.t layout_tree($1, $2, $3)

	do c{
		$$ = construct_tree($1, $2, $3);
	}

stick:
	segment
	| stick segment s.t {
		// segment生长在stick的确切位置
		r = grow_at_regular_position($1, $2);

		/*
			grow_at_regular_position(parent, child) {
				child.root is on parent
				cross_angle (sgp::line(child), sgp::line(parent)) < 45 degree
			}
		*/
		return r;
		}

	do c{
		link_segment($1, $2);
		$$ = $1;
	}

root:
	root_group
	| root root_group s.t {
		// 须根和根的关系需要服从统计
		return sparse_than($2, $1);
		}
	do c{
		sparse_join_group($1, $2);
		$$ = $1;
	}
