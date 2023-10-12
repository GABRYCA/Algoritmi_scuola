
; Programma che scrive una intestazione su video
; (Utilizza un servizio DOS che permette di scrivere stringhe)

TITLE Saluto

.MODEL SMALL

.DATA

Saluto DB "Questo programma serve per calcolare il valore!$"
Saluto2 DB 13, 10, "che assume l'espressione che viene $s" ; 13 e 10 permettono 
;di visualizzare la stringa a capo. 
Saluto3 DB 13, 10, "riportata di seguito... $s"     
     
.CODE
.STARTUP

MOV DX, OFFSET Saluto ; MOV con indirizzo immediato
MOV AH, 9             ; Out stringa su video
INT 21h

MOV DX, OFFSET Saluto2 ; MOV Con indirizzo immediato
MOV AH, 9              ; Out stringa su video
INT 21h

MOV DX, OFFSET Saluto3 ; MOV Con indirizzo immediato
MOV AH, 9              ; Out stringa su video
INT 21h


MOV AH, 4Ch ;Ritorno del controllo da DOS
INT 21h
END
