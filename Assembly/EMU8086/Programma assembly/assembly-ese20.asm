; Programma assembly                                                  
; Somma degli elementi di un vettore (versione VI)

DIM EQU 5
.MODEL SMALL
.STACK
.DATA


VETT DW 8,7,6,9,10   
RESULT DW ?
.CODE
.STARTUP

MOV AX, 0      ; Azzeramento accumulatore
MOV CX, DIM    ; Assegnazione a CX del valore DIM (5), contatore
               ; ciclo servira' a LOOP per capire quante volte ripetere il
               ; il ciclo e il decremento di CX sara' fatto automaticamente all'interno
               ; del ciclo (SOMMA)

MOV DI, 0      ; Assegnazione a DI del valore 0


SOMMA:            ; Punto arrivo Jump

ADD AX, VETT[DI]  ; Addiziona ad AX il contenuto di VETT[DI]
ADD DI,2          ; Addizione a DI (registro indice di destinazione) il valore 2
DEC CX            ; Decremento di 1 CX
CMP CX, 0         ; Confronto CX con 0
JNZ SOMMA         ; Se il risultato del confronto è diverso da 0 salto a SOMMA

MOV RESULT, AX    ; Assegna a RESULT il contenuto di AX
.EXIT
END