
<%
dim conn
set conn=server.createobject("adodb.connection")
'conn.open "DBQ="&server.mappath("index.htm")&";Driver={Microsoft Access Driver (*.mdb)}"
conn.open "DSN=P"
%>
