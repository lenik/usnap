call_scripttext_keypress=true
call_scriptform_keydown=true
call_scriptform_keyup=true
sub scripttext_keypress(asc)
	if chr(asc) = "~" then scriptform.execscriptfile "V:\vbp\waveForm.vbs"
	scriptform.caption = scriptform.caption & "*"
	if len(scriptform.caption)>20 then scriptform.caption=""
end sub
sub scriptform_keydown(code, shift)
	scriptform.caption = scriptform.caption & "+"
	if len(scriptform.caption)>20 then scriptform.caption=""
end sub
sub scriptform_keyup(code,shift)
	scriptform.caption = scriptform.caption & "-"
	if len(scriptform.caption)>20 then scriptform.caption=""
end sub
