Attribute VB_Name = "modLMServer"
Option Explicit

Type Guid
    i1 As Long
    i2 As Long
    i3 As Long
    i4 As Long
End Type

Declare Function NetServerEnum Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, refbufptr As Long, ByVal prefmaxlen As Long, entriesread As Long, totalentries As Long, ByVal servertype As Long, ByVal domain As String, resume_handle As Long) As Long
Declare Function NetServerEnum2 Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, refbufptr As Long, ByVal prefmaxlen As Long, entriesread As Long, totalentries As Long, ByVal servertype As Long, ByVal domain As String, resume_handle As Long) As Long
Declare Function NetServerEnumA Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, refbufptr As Long, ByVal prefmaxlen As Long, entriesread As Long, totalentries As Long, ByVal servertype As Long, ByVal domain As String, resume_handle As Long) As Long
Declare Function NetServerEnumEx Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, refbufptr As Long, ByVal prefmaxlen As Long, entriesread As Long, totalentries As Long, ByVal servertype As Long, ByVal domain As String, ByVal FirstNameToReturn As String) As Long
Declare Function NetServerGetInfo Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, refbufptr As Long) As Long
Declare Function NetServerSetInfo Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, buf As Byte, ParmError As Long) As Long

'
' Temporary hack function.
'

Declare Function NetServerSetInfoCommandLine Lib "NetApi32.dll" (ByVal argc As Integer, ByVal ref_strArgv As Long) As Long
Declare Function NetServerDiskEnum Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, refbufptr As Long, ByVal prefmaxlen As Long, entriesread As Long, totalentries As Long, resume_handle As Long) As Long
Declare Function NetServerComputerNameAdd Lib "NetApi32.dll" (ByVal servername As String, ByVal EmulatedDomaName As String, ByVal EmulatedServerName As String) As Long
Declare Function NetServerComputerNameDel Lib "NetApi32.dll" (ByVal servername As String, ByVal EmulatedServerName As String) As Long
Declare Function NetServerTransportAdd Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, bufptr As Byte) As Long
Declare Function NetServerTransportAddEx Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, bufptr As Byte) As Long
Declare Function NetServerTransportDel Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, bufptr As Byte) As Long
Declare Function NetServerTransportEnum Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, refbufptr As Long, ByVal prefmaxlen As Long, entriesread As Long, totalentries As Long, resumehandle As Long) As Long

'
' The following function can be called by W NT services to register
' their service type.  This function is exported from advapi32.dll.
' Therefore, if this is the only function called by that service, then
' it is not necessary to lk to netapi32.lib.
'
Declare Function SetServiceBits Lib "NetApi32.dll" (ByVal hServiceStatus As Long, ByVal dwServiceBits As Long, ByVal bSetBitsOn As Boolean, ByVal bUpdateImmediately As Boolean) As Boolean

'
' Data Structures - SERVER
'

Type SERVER_INFO_100
    sv100_platform_id As Long
    sv100_name As String
End Type
Type PSERVER_INFO_100
    address As Long
End Type
Type LPSERVER_INFO_100
    address As Long
End Type

Type SERVER_INFO_101
    sv101_platform_id As Long
    sv101_name As String
    sv101_version_major As Long
    sv101_version_mor As Long
    sv101_type As Long
    sv101_comment As String
End Type
Type PSERVER_INFO_101
    address As Long
End Type
Type LPSERVER_INFO_101
    address As Long
End Type

Type SERVER_INFO_102
    sv102_platform_id As Long
    sv102_name As String
    sv102_version_major As Long
    sv102_version_mor As Long
    sv102_type As Long
    sv102_comment As String
    sv102_users As Long
    sv102_disc As Long
    sv102_hidden As Boolean
    sv102_announce As Long
    sv102_anndelta As Long
    sv102_licenses As Long
    sv102_userpath As String
End Type
Type PSERVER_INFO_102
    address As Long
End Type
Type LPSERVER_INFO_102
    address As Long
End Type

Type SERVER_INFO_402
      sv402_ulist_mtime As Long
      sv402_glist_mtime As Long
      sv402_alist_mtime As Long
      sv402_alerts As String
      sv402_security As Long
      sv402_numadm As Long
      sv402_lanmask As Long
      sv402_guestacct As String
      sv402_chdevs As Long
      sv402_chdevq As Long
      sv402_chdevjobs As Long
      sv402_connections As Long
      sv402_shares As Long
      sv402_openfiles As Long
      sv402_sessopens As Long
      sv402_sessvcs As Long
      sv402_sessreqs As Long
      sv402_opensearch As Long
      sv402_activelocks As Long
      sv402_numreqbuf As Long
      sv402_sizreqbuf As Long
      sv402_numbigbuf As Long
      sv402_numfiletasks As Long
      sv402_alertsched As Long
      sv402_erroralert As Long
      sv402_logonalert As Long
      sv402_accessalert As Long
      sv402_diskalert As Long
      sv402_netioalert As Long
      sv402_maxauditsz As Long
      sv402_srvheuristics As String
End Type
Type PSERVER_INFO_402
    address As Long
End Type
Type LPSERVER_INFO_402
    address As Long
End Type

Type SERVER_INFO_403
      sv403_ulist_mtime As Long
      sv403_glist_mtime As Long
      sv403_alist_mtime As Long
      sv403_alerts As String
      sv403_security As Long
      sv403_numadm As Long
      sv403_lanmask As Long
      sv403_guestacct As String
      sv403_chdevs As Long
      sv403_chdevq As Long
      sv403_chdevjobs As Long
      sv403_connections As Long
      sv403_shares As Long
      sv403_openfiles As Long
      sv403_sessopens As Long
      sv403_sessvcs As Long
      sv403_sessreqs As Long
      sv403_opensearch As Long
      sv403_activelocks As Long
      sv403_numreqbuf As Long
      sv403_sizreqbuf As Long
      sv403_numbigbuf As Long
      sv403_numfiletasks As Long
      sv403_alertsched As Long
      sv403_erroralert As Long
      sv403_logonalert As Long
      sv403_accessalert As Long
      sv403_diskalert As Long
      sv403_netioalert As Long
      sv403_maxauditsz As Long
      sv403_srvheuristics As String
      sv403_auditedevents As Long
      sv403_autoprofile As Long
      sv403_autopath As String
End Type
Type PSERVER_INFO_403
    address As Long
End Type
Type LPSERVER_INFO_403
    address As Long
End Type

Type SERVER_INFO_502
     sv502_sessopens As Long
     sv502_sessvcs As Long
     sv502_opensearch As Long
     sv502_sizreqbuf As Long
     sv502_itworkitems As Long
     sv502_maxworkitems As Long
     sv502_rawworkitems As Long
     sv502_irpstacksize As Long
     sv502_maxrawbuflen As Long
     sv502_sessusers As Long
     sv502_sessconns As Long
     sv502_maxpagedmemoryusage As Long
     sv502_maxnonpagedmemoryusage As Long
     sv502_enablesoftcompat As Boolean
     sv502_enableforcedlogoff As Boolean
     sv502_timesource As Boolean
     sv502_acceptdownlevelapis As Boolean
     sv502_lmannounce As Boolean
End Type
Type PSERVER_INFO_502
    address As Long
End Type
Type LPSERVER_INFO_502
    address As Long
End Type

Type SERVER_INFO_503
     sv503_sessopens As Long
     sv503_sessvcs As Long
     sv503_opensearch As Long
     sv503_sizreqbuf As Long
     sv503_itworkitems As Long
     sv503_maxworkitems As Long
     sv503_rawworkitems As Long
     sv503_irpstacksize As Long
     sv503_maxrawbuflen As Long
     sv503_sessusers As Long
     sv503_sessconns As Long
     sv503_maxpagedmemoryusage As Long
     sv503_maxnonpagedmemoryusage As Long
     sv503_enablesoftcompat As Boolean
     sv503_enableforcedlogoff As Boolean
     sv503_timesource As Boolean
     sv503_acceptdownlevelapis As Boolean
     sv503_lmannounce As Boolean
     sv503_domain As String
     sv503_maxcopyreadlen As Long
     sv503_maxcopywritelen As Long
     sv503_mkeepsearch As Long
     sv503_maxkeepsearch As Long
     sv503_mkeepcomplsearch As Long
     sv503_maxkeepcomplsearch As Long
     sv503_threadcountadd As Long
     sv503_numblockthreads As Long
     sv503_scavtimeout As Long
     sv503_mrcvqueue As Long
     sv503_mfreeworkitems As Long
     sv503_xactmemsize As Long
     sv503_threadpriority As Long
     sv503_maxmpxct As Long
     sv503_oplockbreakwait As Long
     sv503_oplockbreakresponsewait As Long
     sv503_enableoplocks As Boolean
     sv503_enableoplockforceclose As Boolean
     sv503_enablefcbopens As Boolean
     sv503_enableraw As Boolean
     sv503_enablesharednetdrives As Boolean
     sv503_mfreeconnections As Long
     sv503_maxfreeconnections As Long
End Type
Type PSERVER_INFO_503
    address As Long
End Type
Type LPSERVER_INFO_503
    address As Long
End Type

Type SERVER_INFO_599
     sv599_sessopens As Long
     sv599_sessvcs As Long
     sv599_opensearch As Long
     sv599_sizreqbuf As Long
     sv599_itworkitems As Long
     sv599_maxworkitems As Long
     sv599_rawworkitems As Long
     sv599_irpstacksize As Long
     sv599_maxrawbuflen As Long
     sv599_sessusers As Long
     sv599_sessconns As Long
     sv599_maxpagedmemoryusage As Long
     sv599_maxnonpagedmemoryusage As Long
     sv599_enablesoftcompat As Boolean
     sv599_enableforcedlogoff As Boolean
     sv599_timesource As Boolean
     sv599_acceptdownlevelapis As Boolean
     sv599_lmannounce As Boolean
     sv599_domain As String
     sv599_maxcopyreadlen As Long
     sv599_maxcopywritelen As Long
     sv599_mkeepsearch As Long
     sv599_maxkeepsearch As Long
     sv599_mkeepcomplsearch As Long
     sv599_maxkeepcomplsearch As Long
     sv599_threadcountadd As Long
     sv599_numblockthreads As Long
     sv599_scavtimeout As Long
     sv599_mrcvqueue As Long
     sv599_mfreeworkitems As Long
     sv599_xactmemsize As Long
     sv599_threadpriority As Long
     sv599_maxmpxct As Long
     sv599_oplockbreakwait As Long
     sv599_oplockbreakresponsewait As Long
     sv599_enableoplocks As Boolean
     sv599_enableoplockforceclose As Boolean
     sv599_enablefcbopens As Boolean
     sv599_enableraw As Boolean
     sv599_enablesharednetdrives As Boolean
     sv599_mfreeconnections As Long
     sv599_maxfreeconnections As Long
     sv599_itsesstable As Long
     sv599_itconntable As Long
     sv599_itfiletable As Long
     sv599_itsearchtable As Long
     sv599_alertschedule As Long
     sv599_errorthreshold As Long
     sv599_networkerrorthreshold As Long
     sv599_diskspacethreshold As Long
     sv599_reserved As Long
     sv599_maxlkdelay As Long
     sv599_mlkthroughput As Long
     sv599_lkfovalidtime As Long
     sv599_scavqosfoupdatetime As Long
     sv599_maxworkitemidletime As Long
End Type
Type PSERVER_INFO_599
    address As Long
End Type
Type LPSERVER_INFO_599
    address As Long
End Type

Type SERVER_INFO_598
     sv598_maxrawworkitems As Long
     sv598_maxthreadsperqueue As Long
     sv598_producttype As Long
     sv598_serversize As Long
     sv598_connectionlessautodisc As Long
     sv598_shargviolationretries As Long
     sv598_shargviolationdelay As Long
     sv598_maxglobalopensearch As Long
     sv598_removeduplicatesearches As Long
     sv598_lockviolationoffset As Long
     sv598_lockviolationdelay As Long
     sv598_mdlreadswitchover As Long
     sv598_cachedopenlimit As Long
     sv598_otherqueueaffity As Long
     sv598_restrictnullsessaccess As Boolean
     sv598_enablewfw311directipx As Boolean
     sv598_queuesamplesecs As Long
     sv598_balancecount As Long
     sv598_preferredaffity As Long
     sv598_maxfreerfcbs As Long
     sv598_maxfreemfcbs As Long
     sv598_maxfreelfcbs As Long
     sv598_maxfreepagedpoolchunks As Long
     sv598_mpagedpoolchunksize As Long
     sv598_maxpagedpoolchunksize As Long
     sv598_sendsfrompreferredprocessor As Boolean
     sv598_cacheddirectorylimit As Long
     sv598_maxcopylength As Long
     sv598_enablebulktransfer As Boolean
     sv598_enablecompression As Boolean
     sv598_autosharewks As Boolean
     sv598_autoshareserver As Boolean
     sv598_enablesecuritysignature As Boolean
     sv598_requiresecuritysignature As Boolean
     sv598_mclientbuffersize As Long
     sv598_serverguid As Guid
     sv598_ConnectionNoSessionsTimeout As Long
End Type
Type PSERVER_INFO_598
    address As Long
End Type
Type LPSERVER_INFO_598
    address As Long
End Type

Type SERVER_INFO_1005
    sv1005_comment As String
End Type
Type PSERVER_INFO_1005
    address As Long
End Type
Type LPSERVER_INFO_1005
    address As Long
End Type

Type SERVER_INFO_1107
    sv1107_users As Long
End Type
Type PSERVER_INFO_1107
    address As Long
End Type
Type LPSERVER_INFO_1107
    address As Long
End Type


Type SERVER_INFO_1010
    sv1010_disc As Long
End Type
Type PSERVER_INFO_1010
    address As Long
End Type
Type LPSERVER_INFO_1010
    address As Long
End Type


Type SERVER_INFO_1016
    sv1016_hidden As Boolean
End Type
Type PSERVER_INFO_1016
    address As Long
End Type
Type LPSERVER_INFO_1016
    address As Long
End Type

Type SERVER_INFO_1017
    sv1017_announce As Long
End Type
Type PSERVER_INFO_1017
    address As Long
End Type
Type LPSERVER_INFO_1017
    address As Long
End Type

Type SERVER_INFO_1018
    sv1018_anndelta As Long
End Type
Type PSERVER_INFO_1018
    address As Long
End Type
Type LPSERVER_INFO_1018
    address As Long
End Type

Type SERVER_INFO_1501
    sv1501_sessopens As Long
End Type
Type PSERVER_INFO_1501
    address As Long
End Type
Type LPSERVER_INFO_1501
    address As Long
End Type

Type SERVER_INFO_1502
    sv1502_sessvcs As Long
End Type
Type PSERVER_INFO_1502
    address As Long
End Type
Type LPSERVER_INFO_1502
    address As Long
End Type

Type SERVER_INFO_1503
    sv1503_opensearch As Long
End Type
Type PSERVER_INFO_1503
    address As Long
End Type
Type LPSERVER_INFO_1503
    address As Long
End Type

Type SERVER_INFO_1506
    sv1506_maxworkitems As Long
End Type
Type PSERVER_INFO_1506
    address As Long
End Type
Type LPSERVER_INFO_1506
    address As Long
End Type

Type SERVER_INFO_1509
    sv1509_maxrawbuflen As Long
End Type
Type PSERVER_INFO_1509
    address As Long
End Type
Type LPSERVER_INFO_1509
    address As Long
End Type

Type SERVER_INFO_1510
    sv1510_sessusers As Long
End Type
Type PSERVER_INFO_1510
    address As Long
End Type
Type LPSERVER_INFO_1510
    address As Long
End Type

Type SERVER_INFO_1511
    sv1511_sessconns As Long
End Type
Type PSERVER_INFO_1511
    address As Long
End Type
Type LPSERVER_INFO_1511
    address As Long
End Type

Type SERVER_INFO_1512
    sv1512_maxnonpagedmemoryusage As Long
End Type
Type PSERVER_INFO_1512
    address As Long
End Type
Type LPSERVER_INFO_1512
    address As Long
End Type

Type SERVER_INFO_1513
    sv1513_maxpagedmemoryusage As Long
End Type
Type PSERVER_INFO_1513
    address As Long
End Type
Type LPSERVER_INFO_1513
    address As Long
End Type

Type SERVER_INFO_1514
    sv1514_enablesoftcompat As Boolean
End Type
Type PSERVER_INFO_1514
    address As Long
End Type
Type LPSERVER_INFO_1514
    address As Long
End Type

Type SERVER_INFO_1515
    sv1515_enableforcedlogoff As Boolean
End Type
Type PSERVER_INFO_1515
    address As Long
End Type
Type LPSERVER_INFO_1515
    address As Long
End Type

Type SERVER_INFO_1516
    sv1516_timesource As Boolean
End Type
Type PSERVER_INFO_1516
    address As Long
End Type
Type LPSERVER_INFO_1516
    address As Long
End Type

Type SERVER_INFO_1518
    sv1518_lmannounce As Boolean
End Type
Type PSERVER_INFO_1518
    address As Long
End Type
Type LPSERVER_INFO_1518
    address As Long
End Type

Type SERVER_INFO_1520
    sv1520_maxcopyreadlen As Long
End Type
Type PSERVER_INFO_1520
    address As Long
End Type
Type LPSERVER_INFO_1520
    address As Long
End Type

Type SERVER_INFO_1521
    sv1521_maxcopywritelen As Long
End Type
Type PSERVER_INFO_1521
    address As Long
End Type
Type LPSERVER_INFO_1521
    address As Long
End Type

Type SERVER_INFO_1522
    sv1522_mkeepsearch As Long
End Type
Type PSERVER_INFO_1522
    address As Long
End Type
Type LPSERVER_INFO_1522
    address As Long
End Type

Type SERVER_INFO_1523
    sv1523_maxkeepsearch As Long
End Type
Type PSERVER_INFO_1523
    address As Long
End Type
Type LPSERVER_INFO_1523
    address As Long
End Type

Type SERVER_INFO_1524
    sv1524_mkeepcomplsearch As Long
End Type
Type PSERVER_INFO_1524
    address As Long
End Type
Type LPSERVER_INFO_1524
    address As Long
End Type

Type SERVER_INFO_1525
    sv1525_maxkeepcomplsearch As Long
End Type
Type PSERVER_INFO_1525
    address As Long
End Type
Type LPSERVER_INFO_1525
    address As Long
End Type

Type SERVER_INFO_1528
    sv1528_scavtimeout As Long
End Type
Type PSERVER_INFO_1528
    address As Long
End Type
Type LPSERVER_INFO_1528
    address As Long
End Type

Type SERVER_INFO_1529
    sv1529_mrcvqueue As Long
End Type
Type PSERVER_INFO_1529
    address As Long
End Type
Type LPSERVER_INFO_1529
    address As Long
End Type

Type SERVER_INFO_1530
    sv1530_mfreeworkitems As Long
End Type
Type PSERVER_INFO_1530
    address As Long
End Type
Type LPSERVER_INFO_1530
    address As Long
End Type

Type SERVER_INFO_1533
    sv1533_maxmpxct As Long
End Type
Type PSERVER_INFO_1533
    address As Long
End Type
Type LPSERVER_INFO_1533
    address As Long
End Type

Type SERVER_INFO_1534
    sv1534_oplockbreakwait As Long
End Type
Type PSERVER_INFO_1534
    address As Long
End Type
Type LPSERVER_INFO_1534
    address As Long
End Type

Type SERVER_INFO_1535
    sv1535_oplockbreakresponsewait As Long
End Type
Type PSERVER_INFO_1535
    address As Long
End Type
Type LPSERVER_INFO_1535
    address As Long
End Type

Type SERVER_INFO_1536
    sv1536_enableoplocks As Boolean
End Type
Type PSERVER_INFO_1536
    address As Long
End Type
Type LPSERVER_INFO_1536
    address As Long
End Type

Type SERVER_INFO_1537
    sv1537_enableoplockforceclose As Boolean
End Type
Type PSERVER_INFO_1537
    address As Long
End Type
Type LPSERVER_INFO_1537
    address As Long
End Type

Type SERVER_INFO_1538
    sv1538_enablefcbopens As Boolean
End Type
Type PSERVER_INFO_1538
    address As Long
End Type
Type LPSERVER_INFO_1538
    address As Long
End Type

Type SERVER_INFO_1539
    sv1539_enableraw As Boolean
End Type
Type PSERVER_INFO_1539
    address As Long
End Type
Type LPSERVER_INFO_1539
    address As Long
End Type

Type SERVER_INFO_1540
    sv1540_enablesharednetdrives As Boolean
End Type
Type PSERVER_INFO_1540
    address As Long
End Type
Type LPSERVER_INFO_1540
    address As Long
End Type

Type SERVER_INFO_1541
    sv1541_mfreeconnections As Boolean
End Type
Type PSERVER_INFO_1541
    address As Long
End Type
Type LPSERVER_INFO_1541
    address As Long
End Type

Type SERVER_INFO_1542
    sv1542_maxfreeconnections As Boolean
End Type
Type PSERVER_INFO_1542
    address As Long
End Type
Type LPSERVER_INFO_1542
    address As Long
End Type

Type SERVER_INFO_1543
    sv1543_itsesstable As Long
End Type
Type PSERVER_INFO_1543
    address As Long
End Type
Type LPSERVER_INFO_1543
    address As Long
End Type

Type SERVER_INFO_1544
    sv1544_itconntable As Long
End Type
Type PSERVER_INFO_1544
    address As Long
End Type
Type LPSERVER_INFO_1544
    address As Long
End Type

Type SERVER_INFO_1545
    sv1545_itfiletable As Long
End Type
Type PSERVER_INFO_1545
    address As Long
End Type
Type LPSERVER_INFO_1545
    address As Long
End Type

Type SERVER_INFO_1546
    sv1546_itsearchtable As Long
End Type
Type PSERVER_INFO_1546
    address As Long
End Type
Type LPSERVER_INFO_1546
    address As Long
End Type

Type SERVER_INFO_1547
    sv1547_alertschedule As Long
End Type
Type PSERVER_INFO_1547
    address As Long
End Type
Type LPSERVER_INFO_1547
    address As Long
End Type

Type SERVER_INFO_1548
    sv1548_errorthreshold As Long
End Type
Type PSERVER_INFO_1548
    address As Long
End Type
Type LPSERVER_INFO_1548
    address As Long
End Type

Type SERVER_INFO_1549
    sv1549_networkerrorthreshold As Long
End Type
Type PSERVER_INFO_1549
    address As Long
End Type
Type LPSERVER_INFO_1549
    address As Long
End Type

Type SERVER_INFO_1550
    sv1550_diskspacethreshold As Long
End Type
Type PSERVER_INFO_1550
    address As Long
End Type
Type LPSERVER_INFO_1550
    address As Long
End Type

Type SERVER_INFO_1552
    sv1552_maxlkdelay As Long
End Type
Type PSERVER_INFO_1552
    address As Long
End Type
Type LPSERVER_INFO_1552
    address As Long
End Type

Type SERVER_INFO_1553
    sv1553_mlkthroughput As Long
End Type
Type PSERVER_INFO_1553
    address As Long
End Type
Type LPSERVER_INFO_1553
    address As Long
End Type

Type SERVER_INFO_1554
    sv1554_lkfovalidtime As Long
End Type
Type PSERVER_INFO_1554
    address As Long
End Type
Type LPSERVER_INFO_1554
    address As Long
End Type

Type SERVER_INFO_1555
    sv1555_scavqosfoupdatetime As Long
End Type
Type PSERVER_INFO_1555
    address As Long
End Type
Type LPSERVER_INFO_1555
    address As Long
End Type

Type SERVER_INFO_1556
    sv1556_maxworkitemidletime As Long
End Type
Type PSERVER_INFO_1556
    address As Long
End Type
Type LPSERVER_INFO_1556
    address As Long
End Type

Type SERVER_INFO_1557
    sv1557_maxrawworkitems As Long
End Type
Type PSERVER_INFO_1557
    address As Long
End Type
Type LPSERVER_INFO_1557
    address As Long
End Type

Type SERVER_INFO_1560
    sv1560_producttype As Long
End Type
Type PSERVER_INFO_1560
    address As Long
End Type
Type LPSERVER_INFO_1560
    address As Long
End Type

Type SERVER_INFO_1561
    sv1561_serversize As Long
End Type
Type PSERVER_INFO_1561
    address As Long
End Type
Type LPSERVER_INFO_1561
    address As Long
End Type

Type SERVER_INFO_1562
    sv1562_connectionlessautodisc As Long
End Type
Type PSERVER_INFO_1562
    address As Long
End Type
Type LPSERVER_INFO_1562
    address As Long
End Type

Type SERVER_INFO_1563
    sv1563_shargviolationretries As Long
End Type
Type PSERVER_INFO_1563
    address As Long
End Type
Type LPSERVER_INFO_1563
    address As Long
End Type

Type SERVER_INFO_1564
    sv1564_shargviolationdelay As Long
End Type
Type PSERVER_INFO_1564
    address As Long
End Type
Type LPSERVER_INFO_1564
    address As Long
End Type

Type SERVER_INFO_1565
    sv1565_maxglobalopensearch As Long
End Type
Type PSERVER_INFO_1565
    address As Long
End Type
Type LPSERVER_INFO_1565
    address As Long
End Type

Type SERVER_INFO_1566
    sv1566_removeduplicatesearches As Boolean
End Type
Type PSERVER_INFO_1566
    address As Long
End Type
Type LPSERVER_INFO_1566
    address As Long
End Type

Type SERVER_INFO_1567
    sv1567_lockviolationretries As Long
End Type
Type PSERVER_INFO_1567
    address As Long
End Type
Type LPSERVER_INFO_1567
    address As Long
End Type

Type SERVER_INFO_1568
    sv1568_lockviolationoffset As Long
End Type
Type PSERVER_INFO_1568
    address As Long
End Type
Type LPSERVER_INFO_1568
    address As Long
End Type

Type SERVER_INFO_1569
    sv1569_lockviolationdelay As Long
End Type
Type PSERVER_INFO_1569
    address As Long
End Type
Type LPSERVER_INFO_1569
    address As Long
End Type

Type SERVER_INFO_1570
    sv1570_mdlreadswitchover As Long
End Type
Type PSERVER_INFO_1570
    address As Long
End Type
Type LPSERVER_INFO_1570
    address As Long
End Type

Type SERVER_INFO_1571
    sv1571_cachedopenlimit As Long
End Type
Type PSERVER_INFO_1571
    address As Long
End Type
Type LPSERVER_INFO_1571
    address As Long
End Type

Type SERVER_INFO_1572
    sv1572_criticalthreads As Long
End Type
Type PSERVER_INFO_1572
    address As Long
End Type
Type LPSERVER_INFO_1572
    address As Long
End Type

Type SERVER_INFO_1573
    sv1573_restrictnullsessaccess As Long
End Type
Type PSERVER_INFO_1573
    address As Long
End Type
Type LPSERVER_INFO_1573
    address As Long
End Type

Type SERVER_INFO_1574
    sv1574_enablewfw311directipx As Long
End Type
Type PSERVER_INFO_1574
    address As Long
End Type
Type LPSERVER_INFO_1574
    address As Long
End Type

Type SERVER_INFO_1575
    sv1575_otherqueueaffity As Long
End Type
Type PSERVER_INFO_1575
    address As Long
End Type
Type LPSERVER_INFO_1575
    address As Long
End Type

Type SERVER_INFO_1576
    sv1576_queuesamplesecs As Long
End Type
Type PSERVER_INFO_1576
    address As Long
End Type
Type LPSERVER_INFO_1576
    address As Long
End Type

Type SERVER_INFO_1577
    sv1577_balancecount As Long
End Type
Type PSERVER_INFO_1577
    address As Long
End Type
Type LPSERVER_INFO_1577
    address As Long
End Type

Type SERVER_INFO_1578
    sv1578_preferredaffity As Long
End Type
Type PSERVER_INFO_1578
    address As Long
End Type
Type LPSERVER_INFO_1578
    address As Long
End Type

Type SERVER_INFO_1579
    sv1579_maxfreerfcbs As Long
End Type
Type PSERVER_INFO_1579
    address As Long
End Type
Type LPSERVER_INFO_1579
    address As Long
End Type

Type SERVER_INFO_1580
    sv1580_maxfreemfcbs As Long
End Type
Type PSERVER_INFO_1580
    address As Long
End Type
Type LPSERVER_INFO_1580
    address As Long
End Type

Type SERVER_INFO_1581
    sv1581_maxfreemlcbs As Long
End Type
Type PSERVER_INFO_1581
    address As Long
End Type
Type LPSERVER_INFO_1581
    address As Long
End Type

Type SERVER_INFO_1582
    sv1582_maxfreepagedpoolchunks As Long
End Type
Type PSERVER_INFO_1582
    address As Long
End Type
Type LPSERVER_INFO_1582
    address As Long
End Type

Type SERVER_INFO_1583
    sv1583_mpagedpoolchunksize As Long
End Type
Type PSERVER_INFO_1583
    address As Long
End Type
Type LPSERVER_INFO_1583
    address As Long
End Type

Type SERVER_INFO_1584
    sv1584_maxpagedpoolchunksize As Long
End Type
Type PSERVER_INFO_1584
    address As Long
End Type
Type LPSERVER_INFO_1584
    address As Long
End Type

Type SERVER_INFO_1585
    sv1585_sendsfrompreferredprocessor As Boolean
End Type
Type PSERVER_INFO_1585
    address As Long
End Type
Type LPSERVER_INFO_1585
    address As Long
End Type

Type SERVER_INFO_1586
    sv1586_maxthreadsperqueue As Long
End Type
Type PSERVER_INFO_1586
    address As Long
End Type
Type LPSERVER_INFO_1586
    address As Long
End Type

Type SERVER_INFO_1587
    sv1587_cacheddirectorylimit As Long
End Type
Type PSERVER_INFO_1587
    address As Long
End Type
Type LPSERVER_INFO_1587
    address As Long
End Type

Type SERVER_INFO_1588
    sv1588_maxcopylength As Long
End Type
Type PSERVER_INFO_1588
    address As Long
End Type
Type LPSERVER_INFO_1588
    address As Long
End Type

Type SERVER_INFO_1589
    sv1589_enablebulktransfer As Long
End Type
Type PSERVER_INFO_1589
    address As Long
End Type
Type LPSERVER_INFO_1589
    address As Long
End Type

Type SERVER_INFO_1590
    sv1590_enablecompression As Long
End Type
Type PSERVER_INFO_1590
    address As Long
End Type
Type LPSERVER_INFO_1590
    address As Long
End Type

Type SERVER_INFO_1591
    sv1591_autosharewks As Long
End Type
Type PSERVER_INFO_1591
    address As Long
End Type
Type LPSERVER_INFO_1591
    address As Long
End Type

Type SERVER_INFO_1592
    sv1592_autosharewks As Long
End Type
Type PSERVER_INFO_1592
    address As Long
End Type
Type LPSERVER_INFO_1592
    address As Long
End Type

Type SERVER_INFO_1593
    sv1593_enablesecuritysignature As Long
End Type
Type PSERVER_INFO_1593
    address As Long
End Type
Type LPSERVER_INFO_1593
    address As Long
End Type

Type SERVER_INFO_1594
    sv1594_requiresecuritysignature As Long
End Type
Type PSERVER_INFO_1594
    address As Long
End Type
Type LPSERVER_INFO_1594
    address As Long
End Type

Type SERVER_INFO_1595
    sv1595_mclientbuffersize As Long
End Type
Type PSERVER_INFO_1595
    address As Long
End Type
Type LPSERVER_INFO_1595
    address As Long
End Type

Type SERVER_INFO_1596
    sv1596_ConnectionNoSessionsTimeout As Long
End Type
Type PSERVER_INFO_1596
    address As Long
End Type
Type LPSERVER_INFO_1596
    address As Long
End Type

'
' A special structure defition is required  order for this
' structure to work with RPC.  The problem is that havg addresslength
' dicate the number of bytes  address means that RPC must know the
' lk between the two.
'

Type SERVER_TRANSPORT_INFO_0
    svti0_numberofvcs As Long
    svti0_transportname As String
    lpbyte_svti0_transportaddress As Long
    svti0_transportaddresslength As Long
    svti0_networkaddress As String
End Type
Type PSERVER_TRANSPORT_INFO_0
    address As Long
End Type
Type LPSERVER_TRANSPORT_INFO_0
    address As Long
End Type

Type SERVER_TRANSPORT_INFO_1
    svti1_numberofvcs As Long
    svti1_transportname As String
    lpbyte_svti1_transportaddress As Long
    svti1_transportaddresslength As Long
    svti1_networkaddress As String
    svti1_domain As String
End Type
Type PSERVER_TRANSPORT_INFO_1
    address As Long
End Type
Type LPSERVER_TRANSPORT_INFO_1
    address As Long
End Type

Type SERVER_TRANSPORT_INFO_2
    svti2_numberofvcs As Long
    svti2_transportname As String
    lpbyte_svti2_transportaddress As Long
    svti2_transportaddresslength As Long
    svti2_networkaddress As String
    svti2_domain As String
    svti2_flags As Long     ' ULONG
End Type
Type PSERVER_TRANSPORT_INFO_2
    address As Long
End Type
Type LPSERVER_TRANSPORT_INFO_2
    address As Long
End Type

'
' Defes - SERVER
'

'
' The platform ID dicates the levels to use for platform-specific
' formation.
'

Public Const SV_PLATFORM_ID_OS2 As Integer = 400
Public Const SV_PLATFORM_ID_NT As Integer = 500

'
'      Mask to be applied to svX_version_major  order to obta
'      the major version number.
'

Public Const MAJOR_VERSION_MASK As Integer = &HF

'
'      Bit-mapped values for svX_type fields. X = 1, 2 or 3.
'

Public Const SV_TYPE_WORKSTATION As Long = &H1
Public Const SV_TYPE_SERVER As Long = &H2
Public Const SV_TYPE_SQLSERVER As Long = &H4
Public Const SV_TYPE_DOMAIN_CTRL As Long = &H8
Public Const SV_TYPE_DOMAIN_BAKCTRL As Long = &H10
Public Const SV_TYPE_TIME_SOURCE As Long = &H20
Public Const SV_TYPE_AFP As Long = &H40
Public Const SV_TYPE_NOVELL As Long = &H80
Public Const SV_TYPE_DOMAIN_MEMBER As Long = &H100
Public Const SV_TYPE_PRTQ_SERVER As Long = &H200
Public Const SV_TYPE_DIAL_SERVER As Long = &H400
Public Const SV_TYPE_XENIX_SERVER As Long = &H800
Public Const SV_TYPE_SERVER_UNIX As Long = SV_TYPE_XENIX_SERVER
Public Const SV_TYPE_NT As Long = &H1000
Public Const SV_TYPE_WFW As Long = &H2000
Public Const SV_TYPE_SERVER_MFPN As Long = &H4000
Public Const SV_TYPE_SERVER_NT As Long = &H8000
Public Const SV_TYPE_POTENTIAL_BROWSER As Long = &H10000
Public Const SV_TYPE_BACKUP_BROWSER As Long = &H20000
Public Const SV_TYPE_MASTER_BROWSER As Long = &H40000
Public Const SV_TYPE_DOMAIN_MASTER As Long = &H80000
Public Const SV_TYPE_SERVER_OSF As Long = &H100000
Public Const SV_TYPE_SERVER_VMS As Long = &H200000
Public Const SV_TYPE_WDOWS As Long = &H400000    ' /* Wdows95 and above */
Public Const SV_TYPE_DFS As Long = &H800000    ' /* Root of a DFS tree */
Public Const SV_TYPE_CLUSTER_NT As Long = &H1000000   ' /* NT Cluster */
Public Const SV_TYPE_DCE As Long = &H10000000  ' /* IBM DSS (Directory and Security Services) or equivalent */
Public Const SV_TYPE_ALTERNATE_XPORT As Long = &H20000000  ' /* return list for alternate transport */
Public Const SV_TYPE_LOCAL_LIST_ONLY As Long = &H40000000  ' /* Return local list only */
Public Const SV_TYPE_DOMAIN_ENUM As Long = &H80000000
Public Const SV_TYPE_ALL As Long = &HFFFFFFFF  ' /* handy for NetServerEnum2 */

'
'      Special value for sv102_disc that specifies fite disconnect
'      time.
'

Public Const SV_NODISC As Integer = -1  ' /* No autodisconnect time enforced */

'
'      Values of svX_security field. X = 2 or 3.
'

Public Const SV_USERSECURITY As Integer = 1
Public Const SV_SHARESECURITY As Integer = 0

'
'      Values of svX_hidden field. X = 2 or 3.
'

Public Const SV_HIDDEN As Integer = 1
Public Const SV_VISIBLE As Integer = 0

'
'      Values for ParmError parameter to NetServerSetInfo.
'

Public Const SV_PLATFORM_ID_PARMNUM As Integer = 101
Public Const SV_NAME_PARMNUM As Integer = 102
Public Const SV_VERSION_MAJOR_PARMNUM As Integer = 103
Public Const SV_VERSION_MOR_PARMNUM As Integer = 104
Public Const SV_TYPE_PARMNUM As Integer = 105
Public Const SV_COMMENT_PARMNUM As Integer = 5
Public Const SV_USERS_PARMNUM As Integer = 107
Public Const SV_DISC_PARMNUM As Integer = 10
Public Const SV_HIDDEN_PARMNUM As Integer = 16
Public Const SV_ANNOUNCE_PARMNUM As Integer = 17
Public Const SV_ANNDELTA_PARMNUM As Integer = 18
Public Const SV_USERPATH_PARMNUM As Integer = 112

Public Const SV_ULIST_MTIME_PARMNUM As Integer = 401
Public Const SV_GLIST_MTIME_PARMNUM As Integer = 402
Public Const SV_ALIST_MTIME_PARMNUM As Integer = 403
Public Const SV_ALERTS_PARMNUM As Integer = 11
Public Const SV_SECURITY_PARMNUM As Integer = 405
Public Const SV_NUMADM_PARMNUM As Integer = 406
Public Const SV_LANMASK_PARMNUM As Integer = 407
Public Const SV_GUESTACC_PARMNUM As Integer = 408
Public Const SV_CHDEVQ_PARMNUM As Integer = 410
Public Const SV_CHDEVJOBS_PARMNUM As Integer = 411
Public Const SV_CONNECTIONS_PARMNUM As Integer = 412
Public Const SV_SHARES_PARMNUM As Integer = 413
Public Const SV_OPENFILES_PARMNUM As Integer = 414
Public Const SV_SESSREQS_PARMNUM As Integer = 417
Public Const SV_ACTIVELOCKS_PARMNUM As Integer = 419
Public Const SV_NUMREQBUF_PARMNUM As Integer = 420
Public Const SV_NUMBIGBUF_PARMNUM As Integer = 422
Public Const SV_NUMFILETASKS_PARMNUM As Integer = 423
Public Const SV_ALERTSCHED_PARMNUM As Integer = 37
Public Const SV_ERRORALERT_PARMNUM As Integer = 38
Public Const SV_LOGONALERT_PARMNUM As Integer = 39
Public Const SV_ACCESSALERT_PARMNUM As Integer = 40
Public Const SV_DISKALERT_PARMNUM As Integer = 41
Public Const SV_NETIOALERT_PARMNUM As Integer = 42
Public Const SV_MAXAUDITSZ_PARMNUM As Integer = 43
Public Const SV_SRVHEURISTICS_PARMNUM As Integer = 431

Public Const SV_SESSOPENS_PARMNUM As Integer = 501
Public Const SV_SESSVCS_PARMNUM As Integer = 502
Public Const SV_OPENSEARCH_PARMNUM As Integer = 503
Public Const SV_SIZREQBUF_PARMNUM As Integer = 504
Public Const SV_ITWORKITEMS_PARMNUM As Integer = 505
Public Const SV_MAXWORKITEMS_PARMNUM As Integer = 506
Public Const SV_RAWWORKITEMS_PARMNUM As Integer = 507
Public Const SV_IRPSTACKSIZE_PARMNUM As Integer = 508
Public Const SV_MAXRAWBUFLEN_PARMNUM As Integer = 509
Public Const SV_SESSUSERS_PARMNUM As Integer = 510
Public Const SV_SESSCONNS_PARMNUM As Integer = 511
Public Const SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM As Integer = 512
Public Const SV_MAXPAGEDMEMORYUSAGE_PARMNUM As Integer = 513
Public Const SV_ENABLESOFTCOMPAT_PARMNUM As Integer = 514
Public Const SV_ENABLEFORCEDLOGOFF_PARMNUM As Integer = 515
Public Const SV_TIMESOURCE_PARMNUM As Integer = 516
Public Const SV_ACCEPTDOWNLEVELAPIS_PARMNUM As Integer = 517
Public Const SV_LMANNOUNCE_PARMNUM As Integer = 518
Public Const SV_DOMAIN_PARMNUM As Integer = 519
Public Const SV_MAXCOPYREADLEN_PARMNUM As Integer = 520
Public Const SV_MAXCOPYWRITELEN_PARMNUM As Integer = 521
Public Const SV_MKEEPSEARCH_PARMNUM As Integer = 522
Public Const SV_MAXKEEPSEARCH_PARMNUM As Integer = 523
Public Const SV_MKEEPCOMPLSEARCH_PARMNUM As Integer = 524
Public Const SV_MAXKEEPCOMPLSEARCH_PARMNUM As Integer = 525
Public Const SV_THREADCOUNTADD_PARMNUM As Integer = 526
Public Const SV_NUMBLOCKTHREADS_PARMNUM As Integer = 527
Public Const SV_SCAVTIME_PARMNUM As Integer = 528
Public Const SV_MRCVQUEUE_PARMNUM As Integer = 529
Public Const SV_MFREEWORKITEMS_PARMNUM As Integer = 530
Public Const SV_XACTMEMSIZE_PARMNUM As Integer = 531
Public Const SV_THREADPRIORITY_PARMNUM As Integer = 532
Public Const SV_MAXMPXCT_PARMNUM As Integer = 533
Public Const SV_OPLOCKBREAKWAIT_PARMNUM As Integer = 534
Public Const SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM As Integer = 535
Public Const SV_ENABLEOPLOCKS_PARMNUM As Integer = 536
Public Const SV_ENABLEOPLOCKFORCECLOSE_PARMNUM As Integer = 537
Public Const SV_ENABLEFCBOPENS_PARMNUM As Integer = 538
Public Const SV_ENABLERAW_PARMNUM As Integer = 539
Public Const SV_ENABLESHAREDNETDRIVES_PARMNUM As Integer = 540
Public Const SV_MFREECONNECTIONS_PARMNUM As Integer = 541
Public Const SV_MAXFREECONNECTIONS_PARMNUM As Integer = 542
Public Const SV_ITSESSTABLE_PARMNUM As Integer = 543
Public Const SV_ITCONNTABLE_PARMNUM As Integer = 544
Public Const SV_ITFILETABLE_PARMNUM As Integer = 545
Public Const SV_ITSEARCHTABLE_PARMNUM As Integer = 546
Public Const SV_ALERTSCHEDULE_PARMNUM As Integer = 547
Public Const SV_ERRORTHRESHOLD_PARMNUM As Integer = 548
Public Const SV_NETWORKERRORTHRESHOLD_PARMNUM As Integer = 549
Public Const SV_DISKSPACETHRESHOLD_PARMNUM As Integer = 550
Public Const SV_MAXLKDELAY_PARMNUM As Integer = 552
Public Const SV_MLKTHROUGHPUT_PARMNUM As Integer = 553
Public Const SV_LKFOVALIDTIME_PARMNUM As Integer = 554
Public Const SV_SCAVQOSFOUPDATETIME_PARMNUM As Integer = 555
Public Const SV_MAXWORKITEMIDLETIME_PARMNUM As Integer = 556
Public Const SV_MAXRAWWORKITEMS_PARMNUM As Integer = 557
Public Const SV_PRODUCTTYPE_PARMNUM As Integer = 560
Public Const SV_SERVERSIZE_PARMNUM As Integer = 561
Public Const SV_CONNECTIONLESSAUTODISC_PARMNUM As Integer = 562
Public Const SV_SHARGVIOLATIONRETRIES_PARMNUM As Integer = 563
Public Const SV_SHARGVIOLATIONDELAY_PARMNUM As Integer = 564
Public Const SV_MAXGLOBALOPENSEARCH_PARMNUM As Integer = 565
Public Const SV_REMOVEDUPLICATESEARCHES_PARMNUM As Integer = 566
Public Const SV_LOCKVIOLATIONRETRIES_PARMNUM As Integer = 567
Public Const SV_LOCKVIOLATIONOFFSET_PARMNUM As Integer = 568
Public Const SV_LOCKVIOLATIONDELAY_PARMNUM As Integer = 569
Public Const SV_MDLREADSWITCHOVER_PARMNUM As Integer = 570
Public Const SV_CACHEDOPENLIMIT_PARMNUM As Integer = 571
Public Const SV_CRITICALTHREADS_PARMNUM As Integer = 572
Public Const SV_RESTRICTNULLSESSACCESS_PARMNUM As Integer = 573
Public Const SV_ENABLEWFW311DIRECTIPX_PARMNUM As Integer = 574
Public Const SV_OTHERQUEUEAFFITY_PARMNUM As Integer = 575
Public Const SV_QUEUESAMPLESECS_PARMNUM As Integer = 576
Public Const SV_BALANCECOUNT_PARMNUM As Integer = 577
Public Const SV_PREFERREDAFFITY_PARMNUM As Integer = 578
Public Const SV_MAXFREERFCBS_PARMNUM As Integer = 579
Public Const SV_MAXFREEMFCBS_PARMNUM As Integer = 580
Public Const SV_MAXFREELFCBS_PARMNUM As Integer = 581
Public Const SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM As Integer = 582
Public Const SV_MPAGEDPOOLCHUNKSIZE_PARMNUM As Integer = 583
Public Const SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM As Integer = 584
Public Const SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM As Integer = 585
Public Const SV_MAXTHREADSPERQUEUE_PARMNUM As Integer = 586
Public Const SV_CACHEDDIRECTORYLIMIT_PARMNUM As Integer = 587
Public Const SV_MAXCOPYLENGTH_PARMNUM As Integer = 588
Public Const SV_ENABLEBULKTRANSFER_PARMNUM As Integer = 589
Public Const SV_ENABLECOMPRESSION_PARMNUM As Integer = 590
Public Const SV_AUTOSHAREWKS_PARMNUM As Integer = 591
Public Const SV_AUTOSHARESERVER_PARMNUM As Integer = 592
Public Const SV_ENABLESECURITYSIGNATURE_PARMNUM As Integer = 593
Public Const SV_REQUIRESECURITYSIGNATURE_PARMNUM As Integer = 594
Public Const SV_MCLIENTBUFFERSIZE_PARMNUM As Integer = 595
Public Const SV_CONNECTIONNOSESSIONSTIME_PARMNUM As Integer = 596

'
' Sgle-field INFOLEVELs for NetServerSetInfo.
'

Public Const SV_COMMENT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_COMMENT_PARMNUM)
Public Const SV_USERS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_USERS_PARMNUM)
Public Const SV_DISC_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_DISC_PARMNUM)
Public Const SV_HIDDEN_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_HIDDEN_PARMNUM)
Public Const SV_ANNOUNCE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ANNOUNCE_PARMNUM)
Public Const SV_ANNDELTA_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ANNDELTA_PARMNUM)
Public Const SV_SESSOPENS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SESSOPENS_PARMNUM)
Public Const SV_SESSVCS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SESSVCS_PARMNUM)
Public Const SV_OPENSEARCH_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_OPENSEARCH_PARMNUM)
Public Const SV_MAXWORKITEMS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXWORKITEMS_PARMNUM)
Public Const SV_MAXRAWBUFLEN_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXRAWBUFLEN_PARMNUM)
Public Const SV_SESSUSERS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SESSUSERS_PARMNUM)
Public Const SV_SESSCONNS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SESSCONNS_PARMNUM)
Public Const SV_MAXNONPAGEDMEMORYUSAGE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM)
Public Const SV_MAXPAGEDMEMORYUSAGE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXPAGEDMEMORYUSAGE_PARMNUM)
Public Const SV_ENABLESOFTCOMPAT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLESOFTCOMPAT_PARMNUM)
Public Const SV_ENABLEFORCEDLOGOFF_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEFORCEDLOGOFF_PARMNUM)
Public Const SV_TIMESOURCE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_TIMESOURCE_PARMNUM)
Public Const SV_LMANNOUNCE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_LMANNOUNCE_PARMNUM)
Public Const SV_MAXCOPYREADLEN_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYREADLEN_PARMNUM)
Public Const SV_MAXCOPYWRITELEN_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYWRITELEN_PARMNUM)
Public Const SV_MKEEPSEARCH_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MKEEPSEARCH_PARMNUM)
Public Const SV_MAXKEEPSEARCH_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXKEEPSEARCH_PARMNUM)
Public Const SV_MKEEPCOMPLSEARCH_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MKEEPCOMPLSEARCH_PARMNUM)
Public Const SV_MAXKEEPCOMPLSEARCH_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXKEEPCOMPLSEARCH_PARMNUM)
Public Const SV_SCAVTIME_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SCAVTIME_PARMNUM)
Public Const SV_MRCVQUEUE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MRCVQUEUE_PARMNUM)
Public Const SV_MFREEWORKITEMS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MFREEWORKITEMS_PARMNUM)
Public Const SV_MAXMPXCT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXMPXCT_PARMNUM)
Public Const SV_OPLOCKBREAKWAIT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_OPLOCKBREAKWAIT_PARMNUM)
Public Const SV_OPLOCKBREAKRESPONSEWAIT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM)
Public Const SV_ENABLEOPLOCKS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEOPLOCKS_PARMNUM)
Public Const SV_ENABLEOPLOCKFORCECLOSE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEOPLOCKFORCECLOSE_PARMNUM)
Public Const SV_ENABLEFCBOPENS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEFCBOPENS_PARMNUM)
Public Const SV_ENABLERAW_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLERAW_PARMNUM)
Public Const SV_ENABLESHAREDNETDRIVES_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLESHAREDNETDRIVES_PARMNUM)
Public Const SV_MFREECONNECTIONS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MFREECONNECTIONS_PARMNUM)
Public Const SV_MAXFREECONNECTIONS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREECONNECTIONS_PARMNUM)
Public Const SV_ITSESSTABLE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ITSESSTABLE_PARMNUM)
Public Const SV_ITCONNTABLE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ITCONNTABLE_PARMNUM)
Public Const SV_ITFILETABLE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ITFILETABLE_PARMNUM)
Public Const SV_ITSEARCHTABLE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ITSEARCHTABLE_PARMNUM)
Public Const SV_ALERTSCHEDULE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ALERTSCHEDULE_PARMNUM)
Public Const SV_ERRORTHRESHOLD_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ERRORTHRESHOLD_PARMNUM)
Public Const SV_NETWORKERRORTHRESHOLD_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_NETWORKERRORTHRESHOLD_PARMNUM)
Public Const SV_DISKSPACETHRESHOLD_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_DISKSPACETHRESHOLD_PARMNUM)
Public Const SV_MAXLKDELAY_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXLKDELAY_PARMNUM)
Public Const SV_MLKTHROUGHPUT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MLKTHROUGHPUT_PARMNUM)
Public Const SV_LKFOVALIDTIME_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_LKFOVALIDTIME_PARMNUM)
Public Const SV_SCAVQOSFOUPDATETIME_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SCAVQOSFOUPDATETIME_PARMNUM)
Public Const SV_MAXWORKITEMIDLETIME_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXWORKITEMIDLETIME_PARMNUM)
Public Const SV_MAXRAWWORKITEMS_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXRAWWORKITEMS_PARMNUM)
Public Const SV_PRODUCTTYPE_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_PRODUCTTYPE_PARMNUM)
Public Const SV_SERVERSIZE_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SERVERSIZE_PARMNUM)
Public Const SV_CONNECTIONLESSAUTODISC_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_CONNECTIONLESSAUTODISC_PARMNUM)
Public Const SV_SHARGVIOLATIONRETRIES_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SHARGVIOLATIONRETRIES_PARMNUM)
Public Const SV_SHARGVIOLATIONDELAY_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SHARGVIOLATIONDELAY_PARMNUM)
Public Const SV_MAXGLOBALOPENSEARCH_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXGLOBALOPENSEARCH_PARMNUM)
Public Const SV_REMOVEDUPLICATESEARCHES_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_REMOVEDUPLICATESEARCHES_PARMNUM)
Public Const SV_LOCKVIOLATIONRETRIES_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONRETRIES_PARMNUM)
Public Const SV_LOCKVIOLATIONOFFSET_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONOFFSET_PARMNUM)
Public Const SV_LOCKVIOLATIONDELAY_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONDELAY_PARMNUM)
Public Const SV_MDLREADSWITCHOVER_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MDLREADSWITCHOVER_PARMNUM)
Public Const SV_CACHEDOPENLIMIT_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_CACHEDOPENLIMIT_PARMNUM)
Public Const SV_CRITICALTHREADS_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_CRITICALTHREADS_PARMNUM)
Public Const SV_RESTRICTNULLSESSACCESS_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_RESTRICTNULLSESSACCESS_PARMNUM)
Public Const SV_ENABLEWFW311DIRECTIPX_FOLOEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEWFW311DIRECTIPX_PARMNUM)
Public Const SV_OTHERQUEUEAFFITY_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_OTHERQUEUEAFFITY_PARMNUM)
Public Const SV_QUEUESAMPLESECS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_QUEUESAMPLESECS_PARMNUM)
Public Const SV_BALANCECOUNT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_BALANCECOUNT_PARMNUM)
Public Const SV_PREFERREDAFFITY_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_PREFERREDAFFITY_PARMNUM)
Public Const SV_MAXFREERFCBS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREERFCBS_PARMNUM)
Public Const SV_MAXFREEMFCBS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREEMFCBS_PARMNUM)
Public Const SV_MAXFREELFCBS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREELFCBS_PARMNUM)
Public Const SV_MAXFREEPAGEDPOOLCHUNKS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM)
Public Const SV_MPAGEDPOOLCHUNKSIZE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MPAGEDPOOLCHUNKSIZE_PARMNUM)
Public Const SV_MAXPAGEDPOOLCHUNKSIZE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM)
Public Const SV_SENDSFROMPREFERREDPROCESSOR_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM)
Public Const SV_MAXTHREADSPERQUEUE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXTHREADSPERQUEUE_PARMNUM)
Public Const SV_CACHEDDIRECTORYLIMIT_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_CACHEDDIRECTORYLIMIT_PARMNUM)
Public Const SV_MAXCOPYLENGTH_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYLENGTH_PARMNUM)
Public Const SV_ENABLEBULKTRANSFER_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEBULKTRANSFER_PARMNUM)
Public Const SV_ENABLECOMPRESSION_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLECOMPRESSION_PARMNUM)
Public Const SV_AUTOSHAREWKS_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_AUTOSHAREWKS_PARMNUM)
Public Const SV_AUTOSHARESERVER_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_AUTOSHARESERVER_PARMNUM)
Public Const SV_ENABLESECURITYSIGNATURE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLESECURITYSIGNATURE_PARMNUM)
Public Const SV_REQUIRESECURITYSIGNATURE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_REQUIRESECURITYSIGNATURE_PARMNUM)
Public Const SV_MCLIENTBUFFERSIZE_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_MCLIENTBUFFERSIZE_PARMNUM)
Public Const SV_CONNECTIONNOSESSIONSTIME_INFOLEVEL As Integer = _
            (PARMNUM_BASE_INFOLEVEL + SV_CONNECTIONNOSESSIONSTIME_PARMNUM)

Public Const SVI1_NUM_ELEMENTS As Integer = 5
Public Const SVI2_NUM_ELEMENTS As Integer = 40
Public Const SVI3_NUM_ELEMENTS As Integer = 44

'
'      Maxmimum length for command strg to NetServerAdmCommand.
'

Public Const SV_MAX_CMD_LEN As Integer = PATHLEN

'
'      Masks describg AUTOPROFILE parameters
'

Public Const SW_AUTOPROF_LOAD_MASK As Integer = &H1
Public Const SW_AUTOPROF_SAVE_MASK As Integer = &H2

'
'      Max size of svX_srvheuristics.
'

Public Const SV_MAX_SRV_HEUR_LEN As Integer = 32      ' Max heuristics fo strg length.

'
'      Equate for use with sv102_licenses.
'

Public Const SV_USERS_PER_LICENSE As Integer = 5

'
' Equate for use with svti2_flags  NetServerTransportAddEx.
'

Public Const SVTI2_REMAP_PIPE_NAMES As Integer = &H2
