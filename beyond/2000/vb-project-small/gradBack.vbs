scripttimer.interval=100
call_scripttimer_timer = true
scripttext.backcolor = rgb(200,200,100)
redim oldcolor(3)
sub scripttimer_timer
	'on error resume next
	oldcolor(0)=int(scripttext.backcolor / 65536)
	oldcolor(1)=int((scripttext.backcolor mod 65536) / 256)
	oldcolor(2)=scripttext.backcolor mod 256
	for i = 0 to 2
		adjcolor = int(rnd*5) - 2
		oldcolor(i) = oldcolor(i) + adjcolor
		if oldcolor(i) < 0 then oldcolor(i)=0
		if oldcolor(i) > 255 then oldcolor(i) = 255
	next
	scripttext.backcolor = rgb(oldcolor(2), oldcolor(1), oldcolor(0))
	scripttext.forecolor = rgb(255 - oldcolor(2), 255 - oldcolor(1), 255 - oldcolor(0))
end sub
