SCREEN 9: CLS
PRINT "******************************"
PRINT "------------KS V1-------------"
PRINT "     1    Start Game"
PRINT "     2    Option"
PRINT "     0    End"
PRINT "**** Made:XieJilei 1995 ******"
PRINT "****** (C)Copyright **********"
PRINT "****** Tell 7444659 **********"
PRINT "****** Po.  317605  **********"
INPUT "Number:", n$
IF n$ = "1" THEN
   SHELL "ren s.dat s.exe"
   RUN "s"
END IF
IF n$ = "2" THEN
      CLS
      PRINT "******************************"
      PRINT "------------------------------"
      PRINT "       1  Edit LIFE"
      PRINT "       2  Edit Map"
      PRINT "       3  Quit"
      PRINT "------------------------------"
      INPUT "Number:", n2$
      IF n2$ = "1" THEN
             INPUT "Life="; l
             OPEN "L" FOR OUTPUT AS #1
             PRINT #1, l
             CLOSE #1
      END IF
      IF n2$ = "2" THEN RUN "EM"
      IF n2$ = "3" THEN RUN
   END IF
IF n$ = "3" THEN END
