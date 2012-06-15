
<!-- #include file=conn.inc.asp -->

<%
dim rs
set rs=conn.execute("select * from r")

%>
<TABLE>
<TR>
<%
for i=0 to rs.fields.count-1
%>
<TD><%= rs.fields(i).name%></TD>
<%
next
%>
</TR>

<%
while not rs.eof
%>
	<TR>
	<% for i=0 to rs.fields.count-1 %>
	<TD><%= rs.fields(i).value%></TD>
	<%next%>
	</TR>
	<% rs.movenext %>
<%
wend
%>

</TABLE>
