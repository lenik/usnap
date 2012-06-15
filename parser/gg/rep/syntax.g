
#
# standard syntax definition
# -------------------------------------------------
#
#	-- zauj.g.d., dec 2002.
#

# x@a.m* #include "xaa.g"
#
#	-- X@A comments support grammer definition.
#

# x@a.m* tag Syntax {

[header] {


# meta definition
# using built-in [G] grammer notation.
# G grammer notation is very like Yacc.

[meta, G] {

	property: BNF
		do script.exec("_sys.interrepter = "bnf.dll")
	property: Y
		do script.exec("_sys.interrupter = "buf.dll")

	property: MyBNF
		do script.exec("_body.type = MyBNF_Body")

	BODY<BNF>:
	BODY<Y>:
	BODY<MyBNF>:

}

[meta, G] {

# body doen't include '{' and '}'.

	MyBNF_Body:

}

# x@a.m* tag }
