; Programma assembly                                                  
; Somma degli elementi di un vettore (versione III)

DIM EQU 5
.MODEL SMALL
.STACK
.DATA


VETT DW 2,5,16,12,34    
RESULT DW ?
.CODE
.STARTUP

MOV AX, 0      ; Azzeramento accumulatore
MOV CX, DIM    ; Assegnazione a CX del valore DIM (5), contatore
               ; ciclo servira' a LOOP per capire quante volte ripetere il
               ; il ciclo e il decremento di CX sara' fatto automaticamente all'interno
               ; del ciclo (SOMMA)

MOV DI, 0      ; Assegnazione a DI del valore 0


SOMMA:            ; Inizio ciclo SOMMA
ADD AX, VETT[DI]  ; Addiziona AX con il contenuto VETT[DI]
ADD DI, 2         ; Incrementa DI di 2
LOOP SOMMA        ; Chiudi il ciclo

MOV RESULT, AX    ; Assegna a RESULT il contenuto di AX
.EXIT
END