SCREEN 12: CLS
CONST pi = 3.14159
  DIM x1 AS INTEGER, y1  AS INTEGER, x2  AS INTEGER, y2 AS INTEGER, xx AS INTEGER, yy AS INTEGER, gm AS INTEGER, gd AS INTEGER
  DIM k AS STRING * 1
  x1 = INT(getmaxx / 2): y1 = INT(getmaxy / 2)
  k = INKEY$
  WHILE k <> CHR$(27)
    k = INKEY$
    SELECT CASE LEFT$(k, 1)
    CASE "7": x1 = x1 - 1: y1 = y1 - 1
    CASE "8": y1 = y1 - 1
    CASE "9": x1 = x1 + 1: y1 = y1 - 1
    CASE "4": x1 = x1 - 1
    CASE "6": x1 = x1 + 1
    CASE "1": x1 = x1 - 1: y1 = y1 + 1
    CASE "2": y1 = y1 + 1
    CASE "3": x1 = x1 + 1: y1 = y1 + 1
    CASE CHR$(0): SELECT CASE RIGHT$(k, 1)
                    CASE CHR$(71): x1 = x1 - 1: y1 = y1 - 1
                    CASE CHR$(72): y1 = y1 - 1
                    CASE CHR$(73): x1 = x1 + 1: y1 = y1 - 1
                    CASE CHR$(75): x1 = x1 - 1
                    CASE CHR$(77): x1 = x1 + 1
                    CASE CHR$(79): x1 = x1 - 1: y1 = y1 + 1
                    CASE CHR$(80): y1 = y1 + 1
                    CASE CHR$(81): x1 = x1 + 1: y1 = y1 + 1
                  END SELECT
    END SELECT
    PSET (x1, y1), 15
  WEND
SCREEN 0
