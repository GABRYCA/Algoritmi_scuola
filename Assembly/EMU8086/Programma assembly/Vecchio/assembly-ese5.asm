org 100h

; funzione dell'istruzione ROR (Rotate right).
; sposta verso destra tutti i valori e sposta il meno significativo 
; a destra dove (se presente) c'era quello + significativo.
; Quindi sarebbe una sorta di divisione qual'ora non sia presente
; resto, nel caso sia presente invece ne modifica il valore
; che sara' incrementato o decrementato in base ai valori
; presenti nel registro, con questa istruzione e' possibile 
; spostare di + di una sola volta tutti i valori (essenzialmente
; funziona simile alla ROL solamente che al posto di L c'e' R che
; sta per right e va verso destra invece di sinistra) specificandolo
; in modo simile alla ROL.
; Recap di quello detto, e' l'opposto del ROL.


.MODEL SMALL
.STACK
.DATA

A1 DW 008h ; Variabile X (a 16 bit).
RIS DW ?

.CODE
.STARTUP       


MOV AX, A1 ; Assegno il valore di X al registro AX

ROR AX, 1 ; Eseguo uno shift di una posizione, in questo caso
          ; avra' una funzione simile alla divisione.


ROR AX, 2 ; Divido di 2 volte (ritorna 1h).

MOV RIS,AX ; Copio il valore in RIS

MOV AH, 4CH ; Ritorno al DOS

int 21h


.EXIT
END         
          


ret