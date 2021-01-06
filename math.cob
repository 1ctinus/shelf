MATH
       IDENTIFICATION DIVISION.
       PROGRAM-ID. MATH.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 INP PIC A(14).
       01 NUM1 PIC 9(7).
       01 NUM2 PIC A(2).
           88 PLU VALUE "+".
           88 AIDS VALUE "-".
           88 MULT VALUE "*".
       01 NUM3 PIC 9(15).
       01 ANS PIC 9(8).
       PROCEDURE DIVISION.
           DISPLAY "MATHS AND THINGS: $"
           ACCEPT INP.
           UNSTRING INP DELIMITED BY SPACE
               INTO NUM1, NUM2, NUM3
           END-UNSTRING.
           IF NUM2 = "+" THEN
               ADD NUM1 NUM3 GIVING ANS
           ELSE 
               IF NUM2 = "-" THEN
                   SUBTRACT NUM1 FROM NUM3 GIVING ANS
               ELSE 
                   IF NUM2 = "*" THEN
                       MULTIPLY NUM1 BY NUM3 GIVING ANS
           END-IF.
           DISPLAY ANS.
           STOP RUN.
