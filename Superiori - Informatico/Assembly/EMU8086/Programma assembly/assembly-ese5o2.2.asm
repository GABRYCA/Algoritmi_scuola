
; Programma che scrive un semplice saluto su video
; (Utilizza un servizio DOS che permette di scrivere stringhe)

TITLE Saluto

.MODEL SMALL

.DATA

Saluto DB "Ciao mondo!$"
Saluto2 DB 13, 10, "Ciao mondo2 !$s" ; 13 e 10 permettono 
;di visualizzare la stringa a capo. 

.CODE
.STARTUP

MOV DX, OFFSET Saluto ; MOV con indirizzo immediato
MOV AH, 9             ; Out stringa su video
INT 21h

MOV DX, OFFSET Saluto2 ; MOV Con indirizzo immediato
MOV AH, 9              ; Out stringa su video
INT 21h

MOV AH, 4Ch ;Ritorno del controllo da DOS
INT 21h
END



