org 100h

; funzione dell'istruzione ROR (Rotate right).
; sposta verso destra tutti i valori e sposta il meno significo 
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

X DW 00A0h ; Variabile X (a 16 bit).

.CODE
.STARTUP

MOV AX, X ; Assegno il valore di X al registro AX

ROR AX, 1 ; Eseguo uno shift di una posizione, in questo caso
          ; avra' una funzione simile alla divisione.

.EXIT
END         
          


ret