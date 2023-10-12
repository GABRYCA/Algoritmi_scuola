.model small

.stack 100h  ; Opzionale e alloca 100 blocchetti di memoria esadecimali
             ; Perchè l'h che segue il numero indica il decimale.
.code

start:       ; Etichetta start...

mov AH, 1h ; 1h e' la funzione dell'interrupt 21h che permette l'input di un carattere con eco.
int 21h    ; Funzione interrupt che richiama servizi generali del dos. (21h)

mov DL, AL ; Copia AL in DL perche' l'interrupt 21h salva il caratter ricevuto in AL
; in AH e si tengono le funzioni (i parametri per gli interrupt), in AL i dati.

mov AH, 2h ; Mettiamo in AH un altro comando, ovvero 2g che fa l'output a video di un carattere
int 21h    ; Richiamo dunque ancora l'interrupt 21h che segue il comando in AH.

mov AX, 4c00h ;Comando per stoppare l'interrupt
int 21h ; Eseguiamo

end start

ret




