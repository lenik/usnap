
#
# X@A comments support
# ----------------------------------------------------
#
#	-- zauj.g.d. dec 2002.
#


# x@a.m* #once thisfile

#
# x@a.m* #include "xaa.g"
#



#
# parsing will special deal with comments, exclude '#'.
#


[meta, G] {
	comment: COMMENT_PREFIX comment_line
	COMMENT_PREFIX: T('#')
	comment_line:
		T("x@a.") xaa_namespace xaa_comment_body
			{
				# 1
				analyse(xaa, "%s %s %s", $1.match, $2.match, $3.match);

				# 2
				xaa($2, $3);
			}
		| .*$
			{ __ignore; }
	xaa_namespace:
		node
		| xaa_namespace '.' node
	node: STRING

	xaa_comment_body: .*$
}

[meta, G] xaa {
	node: T("m*")
		do script.eval("xaa_interrepter = "xaa_m.dll")
}
