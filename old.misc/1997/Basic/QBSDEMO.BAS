DEFINT A-Z
'
DIM song1(28000)
'
CALL initsound
'
CALL readsong("Music.", song1())
CALL playsong(-1, song1())
'
PRINT "Playing ... , press any key to stop."
Ik$ = INPUT$(1)
'
CALL stopsong
CALL quitsound
END
