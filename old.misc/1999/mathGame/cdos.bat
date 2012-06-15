
tcc -Ip:\include -c incalc.c calcdecl.c
tcc -Ip:\include -Lp:\lib mathgame.c incalc.obj calcdecl.obj

del *.lib
P:\bin\tlib incalc +incalc.obj +calcdecl.obj
