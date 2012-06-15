

# basic-style grammer

# keywords:
#
#
#

# x@a comments: here just use m* (macro x@a), it is for general
# purpose in text macro processing.
#
# x@a comments support parsing parellelly.
#

# x@a.m* #include "basic.g"
# x@a.m* tag MyBasic : [public] _base {

	[ignore_space, ignore_cr, ignore_lf] {

		[BNF, ascii, ignore_case] {
			FOR	::= T(, "for")
			TO	::= T(case|string, to)
			TO	::= T(case, "TO")
			STEP	::= T[string, step]

			FOR	::= dynamic_for()

		}

		[__e_GDL, unicode, case] {
			MAG_F1	::= T(long, 0x48695465)
		}

	}

# x@a.m* }

[auto, ascii] {

	s:
		T(,'a') j+ s1 do action_1

		# specific language is supported. compiler will isolate the embed source
		# to an outside file, depends on whether embed language is equal to
		# host generated language.
		T(char,x) j s2 embed c{ stmt; }

	s1:
		epsilon j- s_accept1

	s2:

	[accept]s_accept1:
		epsilon j s

}
