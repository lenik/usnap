
#include "ra_basic.h"


// basic algorithm of human3d:
//
//	x=1:src_width {
//		y=1:src_height {
//			src[x,y] --> dest[x .. x + src_depth[x,y], y]
//		}
//	}
//
// and then make a mirror of " x .. x - src_depth[x,y], y "

// ( depth[i] --> -Inf (far, deeply)
//	offset = middepth - src_depth[x,y]
//		right : ( src + offset ) --> dest, offset --> +Inf (far, deeply)
//		left :  ( src - offset ) --> dest, offset --> +Inf (fra, deeply)

void	rglEffect::human3d(pressLinear src_bitmap,
			   pressLinear src_depthmap,
			   pressLinear dest_bitmap,
			   pressEnum   offsetDirection,	// left or right, up or down
			   pressData   offsetPatch
			   ) {
	//
	//	LONG    src_width, src_height;
	//	INT	src_bitmap_depth, src_depthmap_depth;
