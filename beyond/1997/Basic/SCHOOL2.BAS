10 GOSUB 2100: GOSUB 2900: GOSUB 3000: GOSUB 3100
20 GOSUB 3200: GOSUB 3600: GOSUB 3800
30 DATA 8
40 DATA -50,-70,0,"p",1980,-70,0,"*",1980,1150,0,"*",-50,1150,0,"*",-50,-70,0,"*",-50,-70,800,"*",-50,1150,800,"*",-50,1150,0,"*"
50 'ERASE x, y, z, dl$
60 '
70 GOSUB 2900
80 xm = 0: ym = 0: zm = 0
90 FOR ym = 0 TO 1000 STEP 200
100 FOR xm = 0 TO 1750 STEP 250
110 RESTORE 160: RESTORE 160: GOSUB 3000: GOSUB 3100: GOSUB 5400
120 GOSUB 3200: GOSUB 3600: GOSUB 3800
130 NEXT xm
140 NEXT ym
150 DATA 38
160 DATA 0,0,0,"p"
165 DATA 0,0,0,"p",180,0,0,"*",180,100,0,"*",0,100,0,"*",0,0,0,"*",60,100,0,"p",60,0,0,"*",120,100,0,"p",120,0,0,"*"
170 DATA 0,0,0,"p",0,0,-30,"*",180,0,-30,"*",180,0,0,"*",0,40,0,"p",0,40,-30,"*",180,40,-30,"*",180,40,0,"*"
180 DATA 0,40,-30,"p",0,0,-30,"*",20,40,-30,"p",20,0,-30,"*",40,40,-30,"p",40,0,-30,"*",60,40,-30,"p",60,0,-30,"*",80,40,-30,"p",80,0,-30,"*"
190 DATA 100,40,-30,"p",100,0,-30,"*",120,40,-30,"p",120,0,-30,"*",140,40,-30,"p",140,0,-30,"*",160,40,-30,"p",160,0,-30,"*",180,40,-30,"p",180,0,-30,"*"
950 END
2000 '
2010 '
2100 SCREEN 9: WIDTH 80: CLS
2110 pox = 640: poy = 340: pai = 3.14159
2120 dpx = 2.678: dpy = 2.721
2150 PRINT : PRINT "(ABCD)"
2160 PRINT
2200 a$ = "b"
2220 CLS
2230 PRINT
2240 x0 = -20: y0 = -30
2320 x0 = x0 * dpx: y0 = y0 * dpy
2330 WINDOW (-pox / 2 - x0, -poy / 2 + y0)-(pox / 2 - x0, poy / 2 + y0)
2640 PRINT : PRINT
2650 rt = .08
2660 xm = -400: xxm = xm
2670 ym = -180: yym = ym
2680 zm = 0: zzm = zm
2690 IF a$ = "d" GOTO 2760
2700 sp = 2500
2710 IF a$ = "a" THEN 2770
2720 IF a$ = "b" GOTO 2740
2730 IF a$ = "c" GOTO 2750
2740 yr = 30: GOTO 2770
2750 INPUT "yr=,xr="; yr, xr: GOTO 2770
2760 INPUT "yr=,xr=,zr="; yr, xr, zr
2770 CLS
2780 p = pai / 180: yr = p * yr: xr = xr * p: zr = zr * p
2790 RETURN
2800 '
2900 '
2910 READ nn
2920 DIM x(40), y(40), z(40), dl$(40)
2930 RETURN
2940 '
3000 '
3010 FOR i = 1 TO nn
3020 READ x(i), y(i), z(i), dl$(i)
3030 NEXT i
3040 RETURN
3050 '
3100 '
3110 FOR i = 1 TO nn
3120 GOSUB 3160
3130 NEXT i
3140 RETURN
3150 '
3160 x(i) = x(i) + xm: y(i) = y(i) + ym: z(i) = z(i) + zm
3170 RETURN
3180 '
3200 '
3210 FOR i = 1 TO nn
3220 GOSUB 3250
3230 NEXT i
3240 RETURN
3250 IF a$ = "a" THEN 3450
3260 '
3270 '
3280 x1 = x(i): z1 = z(i)
3290 x(i) = x1 * COS(yr) - z1 * SIN(yr)
3300 z(i) = x1 * SIN(yr) + z1 * COS(yr)
3310 IF a$ = "b" THEN 3450
3320 '
3330 '
3340 z2 = z(i): y2 = y(i)
3350 y(i) = z2 * SIN(xr) + y2 * COS(xr)
3360 z(i) = z2 * COS(xr) - y2 * SIN(xr)
3370 IF a$ = "c" THEN 3450
3380 '
3390 '
3400 y3 = y(i): x3 = x(i)
3410 x(i) = y3 * SIN(zr) + x3 * COS(zr)
3420 y(i) = y3 * COS(zr) - x3 * SIN(zr)
3430 IF a$ = "d" THEN RETURN
3440 '
3450 '
3460 x(i) = sp * x(i) / (sp + z(i))
3470 y(i) = sp * y(i) / (sp + z(i))
3480 RETURN
3490 '
3600 '
3610 FOR i = 1 TO nn
3620 GOSUB 3650
3630 NEXT i
3640 RETURN
3650 '
3670 '
3680 x(i) = x(i) * dpx: y(i) = y(i) * dpy
3690 '
3700 x(i) = x(i) * rt: y(i) = y(i) * rt
3730 RETURN
3800 '
3810 FOR i = 1 TO nn
3850 IF dl$(i) = "p" THEN GOSUB 3900: GOTO 3870
3860 GOSUB 3940
3870 NEXT i
     ERASE x, y, z, dl$
3880 RETURN
3890 '
3900 '
3920 PSET (x(i), -y(i)): RETURN
3930 '
3940 '
3960 LINE -(x(i), -y(i)): RETURN
3980 '
5400 '
5410 FOR i = 11 TO nn
5420 x(i) = x(i) + xxm: y(i) = y(i) + yym: z(i) = z(i) + zzm
5430 NEXT i
5440 RETURN
