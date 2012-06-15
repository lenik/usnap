a=inputbox("Rows")
redim data(a)
data(1) = 1
for i = 2 to a
	ss = ""
	for j = 1 to i
	if j<>1 then
		ai = 0
		if j < i then ai = data(j)
		data(j) = data(j - 1) + ai
	end if
	ss = ss & data(j)
	msgbox ss
	next
next
