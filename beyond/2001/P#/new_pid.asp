
<!-- #include file="conn.inc.asp" -->

<%
dim sql,sqlv,comma
sql="insert into r("
if request("pid")<>"" then sql=sql&"PID,"
if request("d1")<>"" then sql=sql&"D1,"
if request("d2")<>"" then sql=sql&"D2,"
if request("d3")<>"" then sql=sql&"D3,"
if right(sql,1)="," then sql=left(sql,len(sql)-1)
sql=sql&") values("
if request("pid")<>"" then sql=sql&"'"&request("pid")&"',"
if request("d1")<>"" then sql=sql&"'"&request("d1")&"',"
if request("d2")<>"" then sql=sql&"'"&request("d2")&"',"
if request("d3")<>"" then sql=sql&"'"&request("d3")&"',"
if right(sql,1)="," then sql=left(sql,len(sql)-1)
sql=sql&")"

conn.execute sql
conn.close
response.redirect "new_pid_passed.htm"


%>
