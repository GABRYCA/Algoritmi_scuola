; Programma Assembly
; Somma delgi elementi di un vettore (Versione II)

DIM EQU 5 ;Dichiarazione di DIm come costante di valore 5
.MODEL SMALL
.STACK
.DATA
VETT DW 2,6,16,12,36 ;Creazione VETT di 5 numeri
RESULT DW ?          ; Definizione di RESULT come variabile tipologia word
.CODE
.STARTUP

MOV AX, 0            ; Azzeramento AX
MOV CX, DIM          ; Assegnazione a XC del valore DIM (5), contatore
                     ; che verra' decrementato
MOV DI, 0            ; Assegnazione a DI del valore 0
SOMMA:               ; Etichetta di ritorno per il salto 
ADD AX, VETT[DI]      ; Addizione di AX del contenuto di VETT[0]
                     ; la prima volta sarà 0 quindi VETT[0]
ADD DI, 2            ; Addizione a DI (registro indice di destinazione il valore)
DEC CX               ; Decremento di 1 CX
CMP CX, 0            ; Confronto CX con 0
JNZ SOMMA            ; Se il risultato del confronto e' diverso da zero salto a somma
MOV RESULT, AX       ; Assegno a RESULT il valore di AX

.EXIT
END

