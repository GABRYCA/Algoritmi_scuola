org 100h  

;Programma assembly che calcoli
;l'espressione W=X-2Y+3Z. W, X e Y siano numeri su 16 bit
;X=100 (64h), y=54 (2Dh) e xZ=15 (Fh) 
;W = 55 (37h)

.MODEL SMALL
.STACK
.DATA

X DW 64h
Y DW 2Dh
Z DW 0Fh
W DW ?

.CODE    
.STARTUP

mov AX, X ; si assegna a AX il valore di X (64h)
sub AX, Y ; si sottrae a AX il valore di Y (2Dh)
sub AX, Y ; si sottrai ad AX il valore di Y (2Dh)
add AX, Z ; si somma a AX il valore di Z (0Fh)
add AX, Z ; si somma a AX il valore di Z (0Fh)
add AX, Z ; si somma a AX il valore di Z (0Fh)

mov W, AX ; copio il valore di AX in W (5 ossia 37h)   

.EXIT
END

ret




