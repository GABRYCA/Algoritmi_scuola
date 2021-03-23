; Programma che scrive un semplice saluto sul video
; (Utilizza un servizio DOS che permette di scrivere stringhe)
                                                             
TITLE Saluto

.MODEL SMALL

.DATA

Saluto DB "Ciao mondo!$" ;Definisce saluto come stringa e $ come ultimo carattere

.CODE
.STARTUP

MOV DX, OFFSET Saluto ;MOV con indirizzo immediato
MOV AH, 9             ;out stringa su video
INT 21h

MOV AH, 4Ch           ; Ritorno del controllo dal DOS
INT 21h

END





