.MODEL SMALL
.STACK 100H
.CODE

MAIN PROC ;

MOV AH, 2 ; Inserire il valore 02 in AH che stabilisce la modalità
          ; 02 di INT 21H (Ossia standard di output il video)

          ; Ciclo ripetuto per 44 volte


MOV CL, 28h ;inizializzazione del contatore CL

ciclo: MOV DL, CL; Istruzione da ripetere
INT 21H          ; Visualizza il valore su monitor utilizzando l'interrupt 21H

LOOP ciclo ;salta se CX <>0

MAIN ENDP
END MAIN