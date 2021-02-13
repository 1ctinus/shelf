       IDENTIFICATION DIVISION.
       PROGRAM-ID. LINUX.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 INP PIC 9(1).

       PROCEDURE DIVISION.
           DISPLAY "LINUX DISTRO? ".
           DISPLAY "1: UBUNTU".
           DISPLAY "2: LINUX MINT ".
           DISPLAY "3. VANILLA DEBIAN".
           DISPLAY "4. UBUNTU FLAVORS".
           DISPLAY "5. POP!_OS".
           DISPLAY "5. MANJARO".
           DISPLAY "6. ARCH LINUX".
           DISPLAY "7. GENTOO LINUX".
           ACCEPT INP.
       EVALUATE TRUE
           WHEN INP = 1
                DISPLAY "YOU ARE TOO SCARED TO USE LINUX."
           WHEN INP = 2
                DISPLAY "YOU SUCK AT LINUX, BUT WANT TO BE SPECIAL"
                DISPLAY "BECAUSE YOU DON'T USE UBUNTU"
           WHEN INP = 3
                DISPLAY "YOU WANT TO USE ARCH BUT YOU LIKE APT."
           WHEN INP = 4
                DISPLAY "WHY BOTHER? JUST USE DEBIAN/ARCH."
           WHEN INP = 5
                DISPLAY "YOU WANT TO BE COOL BC YOU HATE UBUNTU"
                DISPLAY "POP HOLESOME HIDDEN GEM THO"
           WHEN INP = 6
                DISPLAY "PLEASE TAKE A SHOWER"
           WHEN INP = 7
                DISPLAY "WHY BOTHER? JUST USE ARCH/DEBIAN. RIP CPU"
           WHEN OTHER
                DISPLAY "NOT AN ACCEPTABLE VALUE"
        END-EVALUATE.
        STOP RUN.

               
