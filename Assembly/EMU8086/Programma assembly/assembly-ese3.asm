org 100h

;Programma che esegue la moltiplicazione per 2 tramite shift

.MODEL SMALL
.STACK
.DATA

A1 DW 002h ; variabile A1 (a 16 bit) assume il valore 2 in esadecimale
RIS DW ?   ; il valore della variabile RIS dovrà essere calcolato (?)

.CODE
.STARTUP

MOV AX, A1 ; primo operando in AX

ROL AX, 1  ; Eseguo shift di una posizione a sinistra che equivale a
           ; una moltiplicazione per 2

MOV RIS, AX ; copio il valore di AX in RIS (5Fh)

MOV AH, 4CH ; funzione di ritorno al DOS (attenzione leggete il contenuto di AX
            ; prima di questa istruzione)

INT 21H

.EXIT
END

ret