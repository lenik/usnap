
'call_scriptform_gotfocus = true

	scrW = scriptscreen.width
	scrH = scriptscreen.height
	ox = scrW / 2
	oy = scrH / 2
	waveSpeed = 100
	waveH = scriptform.height / 10
	t = 0
	direction = 1.0
	scripttimer.interval = 10

	waveSpeed = 100
	waveH = scriptform.height / 10
	call_scripttimer_timer = true

sub scripttimer_timer
	toX = ox + t * waveSpeed - scriptform.width / 2
	toY = oy + sin(abs(t)) * waveH - scriptform.height / 2
	scriptform.left = toX
	scriptform.top = toY
	if toX > scrW - scriptform.width then
		direction = -direction
	elseif toX <= 0 then
		direction = -direction
	end if
	t = t + 0.01 * direction
end sub
