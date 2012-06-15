cls
PRINT "Password:"
PRINT "Made:XieJilei"
PW$="2244"
30 input p$
if p$<>pw$ then cs=cs+1:goto 30
if cs>3 then end
run "ooo.bas"
end
