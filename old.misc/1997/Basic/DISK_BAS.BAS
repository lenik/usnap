' $INCLUDE: 'BBX_INC.BAS'

' This Disk-Based BlackBox performs an ARCTANGENT operation.
'
' It requests a variable to get the arctangent value of,
' and a variable to put that result into.
'

DIM LanguageType as INTEGER
DIM ArcTangentArgument as DOUBLE
DIM ArcTangentResult as DOUBLE

CALLS Get.BlackBox.Parameters (3, LayoutInteger+InputOnly, LanguageType, _
				  LayoutDouble, ArcTangentResult, _
				  LayoutDouble, ArcTangentArgument)

ArcTangentResult = ATN (ArcTangentArgument)

CALLS Set.BlackBox.Parameters (3, LayoutInteger+InputOnly, LanguageType, _
				  LayoutDouble, ArcTangentResult, _
				  LayoutDouble, ArcTangentArgument)

END
