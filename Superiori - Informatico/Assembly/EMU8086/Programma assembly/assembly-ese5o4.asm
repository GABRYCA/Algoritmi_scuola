
;Programma assembly
;Somma degli elemnti di un vettore (versione I)

.MODEL SMALL
.STACK
.DATA
VETT DW 5,7,3,4,3 ; Creazione vettore con assegnazione interna dei valori
RESULT DW ?       ; Definizione di RESULT come variabile tipologia word
.CODE
.STARTUP

MOV AX, 0         ; Azzeramento AX
ADD AX, VETT      ; Addiziona ad AX il contenuto prima locazione di VETT
ADD AX, VETT+2    ; Addiziona ad AX il contenuto seconda locazione di VETT
                  ; si somma +2 perche' VETT e' definito come Word
ADD AX, VETT+4    ; Addiziona ad AX il contenuto terza locazione di VETT
ADD AX, VETT+6    ; Addizione ad AX il contenuto quarta locazione di VETT
ADD AX, VETT+8    ; Addiziona ad AX il contenuto quinta locazione di VETT

MOV RESULT, AX
.EXIT
END