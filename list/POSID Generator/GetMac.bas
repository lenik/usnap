Attribute VB_Name = "modGetMac"
Option Explicit
Option Base 0


Private Const NCBASTAT = &H33
Private Const NCBNAMSZ = 16
Private Const HEAP_ZERO_MEMORY = &H8
Private Const HEAP_GENERATE_EXCEPTIONS = &H4
Private Const NCBRESET = &H32

Private Type NCB
    ncb_command As Byte 'Integer
    ncb_retcode As Byte 'Integer
    ncb_lsn As Byte 'Integer
    ncb_num As Byte ' Integer
    ncb_buffer As Long 'String
    ncb_length As Integer
    ncb_callname As String * NCBNAMSZ
    ncb_name As String * NCBNAMSZ
    ncb_rto As Byte 'Integer
    ncb_sto As Byte ' Integer
    ncb_post As Long
    ncb_lana_num As Byte 'Integer
    ncb_cmd_cplt As Byte 'Integer
    ncb_reserve(0 To 9) As Byte  ' Reserved, must be 0
    ncb_event As Long
End Type

Private Type ADAPTER_STATUS
    adapter_address(0 To 5) As Byte 'As String * 6
    rev_major As Byte 'Integer
    reserved0 As Byte 'Integer
    adapter_type As Byte 'Integer
    rev_minor As Byte 'Integer
    duration As Integer
    frmr_recv As Integer
    frmr_xmit As Integer
    iframe_recv_err As Integer
    xmit_aborts As Integer
    xmit_success As Long
    recv_success As Long
    iframe_xmit_err As Integer
    recv_buff_unavail As Integer
    t1_timeouts As Integer
    ti_timeouts As Integer
    Reserved1 As Long
    free_ncbs As Integer
    max_cfg_ncbs As Integer
    max_ncbs As Integer
    xmit_buf_unavail As Integer
    max_dgram_size As Integer
    pending_sess As Integer
    max_cfg_sess As Integer
    max_sess As Integer
    max_sess_pkt_size As Integer
    name_count As Integer
End Type

Private Type NAME_BUFFER
    name As String * NCBNAMSZ
    name_num As Integer
    name_flags As Integer
End Type

Private Type ASTAT
    adapt As ADAPTER_STATUS
    NameBuff(0 To 30) As NAME_BUFFER
End Type


Private Declare Function Netbios Lib "netapi32.dll" (pncb As NCB) As Byte
Private Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" _
    (hpvDest As Any, ByVal hpvSource As Long, ByVal cbCopy As Long)
Private Declare Function GetProcessHeap Lib "kernel32" () As Long
Private Declare Function HeapAlloc Lib "kernel32" _
    (ByVal hHeap As Long, ByVal dwFlags As Long, _
    ByVal dwBytes As Long) As Long
Private Declare Function HeapFree Lib "kernel32" (ByVal hHeap As Long, _
    ByVal dwFlags As Long, lpMem As Any) As Long



Public Function GetMac(ByVal index As Integer) As Byte()
    Dim myNcb As NCB
    Dim bRet As Byte
    myNcb.ncb_command = NCBRESET
    bRet = Netbios(myNcb)
    myNcb.ncb_command = NCBASTAT
    myNcb.ncb_lana_num = index
    myNcb.ncb_callname = "*　　　　　　 "
    Dim myASTAT As ASTAT, tempASTAT As ASTAT
    Dim pASTAT As Long
    myNcb.ncb_length = Len(myASTAT)
    pASTAT = HeapAlloc(GetProcessHeap(), HEAP_GENERATE_EXCEPTIONS _
        Or HEAP_ZERO_MEMORY, myNcb.ncb_length)
    If pASTAT = 0 Then Err.Raise -1, "HeapAlloc", "Memory out"
    myNcb.ncb_buffer = pASTAT
    bRet = Netbios(myNcb)
    CopyMemory myASTAT, myNcb.ncb_buffer, Len(myASTAT)
    GetMac = myASTAT.adapt.adapter_address
    HeapFree GetProcessHeap(), 0, pASTAT
End Function


Public Function GetPosidTimestamp() As String
    Dim hmins As Long, hmins_bit_29 As Long
    Dim pad

    hmins = Int((DateDiff("D", "2005-5-8", Date) + CDbl(Time)) * 1440 * 2)

    ' hmins << 2, so forms value in high-30-bits
    hmins_bit_29 = hmins And &H20000000
    hmins = (hmins And &H1FFFFFFF) * &H4
    If hmins_bit_29 <> 0 Then hmins = hmins Or &H80000000

    pad = CCS6Random(3)

    ' ReverseBytes for this LE-machine
    GetPosidTimestamp = BytesToCCS6(ReverseBytes(LongToBytes(hmins)), 30) & "-" & pad
End Function
