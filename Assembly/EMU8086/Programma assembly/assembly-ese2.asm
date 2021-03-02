org 100h  

;Programma assembly che calcoli
;l'espressione W=2X+3Y-2Z. W, X e Y siano numeri su 16 bit
;X=10 (Ah), Y=5 (5h) e Z=4 (4h) 
;W = 27 (1Bh)

.MODEL SMALL
.STACK
.DATA

X DW 9h ; Assegno il valore 9 e lo incremento
Y DW 5h
Z DW 4h
W DW ?

.CODE    
.STARTUP

inc X
mov AX, X ; si assegna a AX il valore di X
add AX, X ; si aggiunge a AX il valore di X
add AX, Y ; si aggiunge a AX il valore di Y
add AX, Y ; si aggiunge a AX il valore di Y    
add AX, Y ; si aggiunge a AX il valore di Y
sub AX, Z ; si sottrae a AX il valore di Z
sub AX, Z ; si sottrae a AX il valore di Z
    
mov W, AX ; copio il valore di AX in W (5 ossia 37h)   

.EXIT
END

ret