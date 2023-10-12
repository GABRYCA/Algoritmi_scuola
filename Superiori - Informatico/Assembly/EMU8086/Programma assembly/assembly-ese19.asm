
;Programma assembly
;Somma degli elemnti di un vettore (versione V)

.MODEL SMALL
.STACK
.DATA
VETT DW 1,3,8,5,11,12,9 ; Creazione vettore con assegnazione interna dei valori
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
ADD AX, VETT+10   ; Addiziona ad AX il contenuto sesta locazione di VETT
ADD AX, VETT+12   ; Addiziona ad AX il contenuto settima locazione di VETT

MOV RESULT, AX
.EXIT
END


