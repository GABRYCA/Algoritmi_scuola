
; Modificare codice precedente (scritta Hello) e aggiungere il messaggio (it is a good day!) la riga dopo
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

MOV DL, 0DH ; Manda a capo, carica in DL l'ascii ritorno 
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 0AH ; Nuova linea, carica nuova linea
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'I' ; Inserire il carattere I in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h
  
MOV DL, 'T' ; Inserire il carattere T in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, ' ' ; Inserire il carattere Spazio in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'I' ; Inserire il carattere I in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'S' ; Inserire il carattere S in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, ' ' ; Inserire il carattere Spazi in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'A' ; Inserire il carattere A in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, ' ' ; Inserire il carattere Spazio in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'G' ; Inserire il carattere G in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'O' ; Inserire il carattere O in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'O' ; Inserire il carattere O in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'D' ; Inserire il carattere D in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, ' ' ; Inserire il carattere Spazio in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'D' ; Inserire il carattere D in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'A' ; Inserire il carattere A in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h

MOV DL, 'Y' ; Inserire il carattere Y in DL
INT 21H     ; Visualizza il valore su monitor utilizzando l'interrupt 21h


MOV AH, 4CH ; Funzione di ritorno al DOS
INT 21H

END