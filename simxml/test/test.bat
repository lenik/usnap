@echo off

dbls test-dbls.txt >test-dbls.out
words words.c >words.out

echo dbls
diff test-dbls.ok test-dbls.out

echo words
diff words.ok words.out
