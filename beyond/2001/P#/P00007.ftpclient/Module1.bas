Attribute VB_Name = "Module1"
Option Explicit

Public Const ע���_���� = "FTP������"

Public Const ��ɫ_�Ͽ� = &HFFFFFF
Public Const ��ɫ_���� = &HFF00&
Public Const ��ɫ_æµ = &HFFFF&
Public Const ��ɫ_���� = &HFF&

Public Type ����Ŀ¼
        ��������Ŀ¼��λ�� As String
        ���� As String
        ӳ��Ŀ¼ As String
End Type

Public Type �û�
        �û��� As String
        ���� As String
        ����Email���� As Boolean
        ��Ȩ�� As Boolean
        дȨ�� As Boolean
        Ŀ¼����Ȩ�� As Boolean
End Type

Public ���ڽ������� As Boolean
Public ������� As Boolean
Public ���ݷ������ As Boolean

Public Զ�̵�ַ, Զ�̶˿�

Public ��ǰ�û� As �û�
Public ��ǰĿ¼ As String
Public ��ǰĿ¼���� As scripting.Folder
Public �ļ�ϵͳ As New scripting.FileSystemObject
Public �û��ѵ�½ As Boolean
Public �ȴ��������� As String
Public �������� As String


Public Function ��������Ŀ¼(d As ����Ŀ¼) As String
        ��������Ŀ¼ = d.���� & "|" & "                                        " & _
                                        d.��������Ŀ¼��λ�� & "|" & _
                                        d.ӳ��Ŀ¼
End Function

Public Function ��������Ŀ¼(s As String) As ����Ŀ¼
'        On Error Resume Next
        ��������Ŀ¼.���� = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(��������Ŀ¼.����) + 22)
        ��������Ŀ¼.��������Ŀ¼��λ�� = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(��������Ŀ¼.��������Ŀ¼��λ��) + 2)
        ��������Ŀ¼.ӳ��Ŀ¼ = s
End Function

Public Function �����û�(u As �û�) As String
        �����û� = u.�û��� & "|" & "                                        " & _
                                u.���� & "|" & _
                                u.����Email���� & "|" & _
                                u.��Ȩ�� & "|" & _
                                u.дȨ�� & "|" & _
                                u.Ŀ¼����Ȩ��
End Function

Public Function �����û�(s As String) As �û�
        �����û�.�û��� = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(�����û�.�û���) + 22)
        �����û�.���� = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(�����û�.����) + 2)
        �����û�.����Email���� = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(CStr(�����û�.����Email����)) + 2)
        �����û�.��Ȩ�� = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(CStr(�����û�.��Ȩ��)) + 2)
        �����û�.дȨ�� = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(CStr(�����û�.дȨ��)) + 2)
        �����û�.Ŀ¼����Ȩ�� = s 'Left(s, InStr(s, "|") - 1)
End Function

Public Function ��ȡ�û�����(�û���) As �û�
        Dim i
        For i = 0 To �û�����.�û��б�.ListCount - 1
                ��ȡ�û����� = �����û�(�û�����.�û��б�.List(i))
                If ��ȡ�û�����.�û��� = �û��� Then Exit Function
        Next
        ��ȡ�û�����.�û��� = ""  '!!�����ڸ��û�
End Function

'���ʱ��t���ַ������ʽ
Public Function ʱ��(t As Date) As String
        ʱ�� = Trim(Month(t)) & "-" & Trim(Day(t)) & "-" & Right(Trim(Year(t)), 2) & " " & _
                Trim(Hour(t)) & ":" & Trim(Minute(t)) & ":" & Trim(Second(t))
End Function

Public Function ��ȡ��ǰĿ¼����() As String
        Dim d As scripting.Folder

        Dim r
        Dim sf As scripting.File, sd As scripting.Folder

        r = ""

        For Each sf In ��ǰĿ¼����.Files
                r = r & ʱ��(sf.DateLastModified) & " " & sf.Size & " " & sf.Name & vbNewLine
        Next

        For Each sd In ��ǰĿ¼����.SubFolders
                r = r & ʱ��(sd.DateLastModified) & " " & "<DIR>" & " " & sd.Name & vbNewLine
        Next

        ��ȡ��ǰĿ¼���� = r
End Function

Public Function Ŀ¼����(a, b) As String
        If Right(a, 1) = "\" Then
                If Left(b, 1) = "\" Then
                        Ŀ¼���� = a & Mid(b, 2)
                Else
                        Ŀ¼���� = a & b
                End If
        Else
                Ŀ¼���� = a & "\" & b
        End If
End Function
