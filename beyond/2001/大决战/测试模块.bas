Attribute VB_Name = "测试模块"
Option Explicit

' 66 * 16
Private Const 主地图宽度 = 66
Private Const 主地图高度 = 16
Private Const 主地图 As String = _
        "  ..........      ...  vvv     ..    ........................     " & _
        "    ..........    ..  v   vv    ..             ......    .....    " & _
        "   ..........      ..   v   v    .      ooooo       ...........   " & _
        "     ..........        v   vvv   .     o     oo   .....           " & _
        "   ....    .....         vv  vv   .    o       o     ......       " & _
        "    ...   v  ...          v  v     .    ooo   o   ......  ....    " & _
        "  ...    v  .....     .  v    v   ..       ooo  ....        ....  " & _
        "   ...    vv   ...    ..  vv v     ...        ...    v   ....     " & _
        " ...     v   ....    ....   v               ....      v   ....    " & _
        "  ....  v v   ............               ....        vv     ....  " & _
        "   .....   v  .....................       .......   v  v   ....   " & _
        " .....    v  ....               .......  ....          v     ...  " & _
        "  .......    ..    oooooooo       .........          vv  .....    " & _
        "     .......     oo        o        .......       vvv  v    ..    " & _
        "       ......      oooooooo           .........  v      v    ...  " & _
        "         ..                     .............     vvvvvv   ...    "

Public Function 创建主地图() As 地图
        Dim r As New 地图
        Dim 当前地图行 As String
        Dim i As Integer, j As Integer
        r.宽度 = 主地图宽度
        r.高度 = 主地图高度
        For j = 0 To r.高度 - 1
                当前地图行 = Mid(主地图, j * r.宽度 + 1, r.宽度)
                For i = 0 To r.宽度 - 1
                        Dim 格子类型 As 格子类型

                        Select Case Mid(当前地图行, i + 1, 1)
                        Case " ": 格子类型 = 草地
                        Case ".": 格子类型 = 平地
                        Case "v": 格子类型 = 山丘
                        Case "o": 格子类型 = 湖泊
                        End Select

                        r.格子(i, j) = 格子类型
                Next
        Next
        Set 创建主地图 = r
End Function
