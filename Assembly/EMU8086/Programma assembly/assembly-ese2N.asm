;Programma per la scrittura di un testo

.MODEL SMALL ; Definizione di un segmento di memoria di tipo small
.STACK 100h  ; Definisce la memoria di stack (100h = 256 locazioni)
.CODE        ; Inizio codice

MOV AH, 2   ;Inserisci valore 02 in AH che stabilisce la modalita'
            ; 02 di INT 21H (ossia standard di output il video)

MOV DL, 'H' ; Inserire il carattere H in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'E' ; Inserire il carattere E in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'L' ; Inserire il carattere L in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'L' ; Inserire il carattere L in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'O' ; Inserire il carattere O in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'W' ; Inserire il carattere W in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'O' ; Inserire il carattere O in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'R' ; Inserire il carattere R in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'L' ; Inserire il carattere L in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'D' ; Inserire il carattere D in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h


MOV AH, 4CH ; Funzione di ritorno al DOS
INT 21H

END