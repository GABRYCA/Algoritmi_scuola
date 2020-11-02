#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


// Dichiaro i prototipi
int moltiplicazione(int x, int y);

int divisione(int x, int y);

int divisioneResto(int x, int y);

int pariDispari(int x);

double numeroIntero(double x);

void tabellinaIntervallo(int x, int y);

int mcd(int x, int y);

void numeriPerfetti(int n);

double media(int tot, int contatore);

void cifreNumero(int num);

int numeroRisultante();

void numeroMaxMin();

int numeriDecimali(double x);

int elevamentoPotenza(int x, int y);

void trovaRadici(int x,int y);

void conta(int x);

void numeriCasuali(int TANTI, int MAX);

void indovinaNumero();

int contaDimezza(int num);

void numeriGenMaxMin(int max, int min, int nNum, int contatore1, int maxTrovato, int minTrovato);

int main() {

    printf("Di Gabriele Caretti, iniziato il 09/10/2020.");
    printf("Scegli un numero per avviare un programma o algoritmo, ti baster� digitarlo e premere invio, eccone la lista: \n");

    printf("1 -> Moltiplicazione\n");
    printf("2 -> Divisione\n");
    printf("3 -> Pari o dispari\n");
    printf("4 -> Verifica SE numero intero\n");
    printf("5 -> Tabellina dei numeri compresi tra un intervallo\n");
    printf("6 -> M.C.D.\n");
    printf("7 -> Visualizzare primi N numeri perfetti\n");
    printf("8 -> Calcolare media di una serie di numeri\n");
    printf("9 -> Visualizzare cifre di un numero inserito dall'ultima\n");
    printf("10 -> Data una serie di numeri, ricostruire il numero risultante dall'ultima cifra inserita\n");
    printf("11 -> Data una serie di numeri, trovare il maggiore e minore.\n");
    printf("12 -> Conta quanti numeri decimali ha un numero.\n");
    printf("13 -> Elevamento a potenza.\n");
    printf("14 -> Trova N radici quadrate senza decimali.\n");
    printf("15 -> Conta del numero inserito fino a 0.\n");
    printf("16 -> Trova N numeri casuali con un numero massimo a scelta.\n");
    printf("17 -> Gioco indovina il numero.\n");
    printf("18 -> Conta dimezza numero.\n");
    printf("19 -> Generatore X numeri compresi tra un intervallo e trova maggiore e minore.\n");

    printf("Valore inserito: ");

    // Dichiaro parametri
    int nAlgoritmoScelto;

    // Ottengo dall'utente l'input
    scanf("%d", &nAlgoritmoScelto);

    // Switch degli algoritmi in base a quello scelto
    switch (nAlgoritmoScelto) {

        // Algoritmo Moltiplicazione
        case 1: {

            // Messaggi iniziali
            printf("\nHai scelto: Moltiplicazione...\n");
            printf("Inserire il primo numero: ");

            // Dichiarazione parametri
            int x, y;

            // Ottengo x dall'input dell'utente
            scanf("%d", &x);

            // Chiedo all'utente il secondo numero
            printf("Inserire il secondo numero: ");

            // Ottengo y dall'input dell'utente
            scanf("%d", &y);

            // Ottengo il risultato usando la funzione della moltiplicazione
            int ris = moltiplicazione(x,y);

            // Comunico il risultato all'utente
            printf("\nRisultato: %d", ris);

            break;

        }

            // Algoritmo Divisione
        case 2: {

            // Messaggi d'inizio
            printf("\nHai scelto: Divisione...\n");
            printf("Inserire il primo valore -da dividere-: ");

            // Dichiarazione variabili
            int x, y, ris, resto;

            // Ottengo il valore di x dall'input dell'utente
            scanf("%d", &x);

            // Chiedo all'uente di dare in input y
            printf("Inserire il numero -che divide-: ");

            // Ottengo il valore di y dall'input dell'utente
            scanf("%d", &y);

            // Eseguo i calcoli usando le funzioni della divisione e del resto
            ris = divisione(x,y);
            resto = divisioneResto(x,y);

            // Comunico il risultato e il resto all'utente
            printf("\nRisultato: %d", ris);
            printf("\nResto: %d", resto);

            break;
        }

            // Algoritmo Pari o dispari
        case 3: {

            // Messaggi d'inizio
            printf("\nHai scelto: Pari o dispari...\n");
            printf("Inserire il valore: ");

            // Dichiarazione variabili
            int x;

            // Ottengo il valore di x dall'input dell'utente
            scanf("%d", &x);

            // Richiamo la funzione per ridurre x ad un numero minore di 2
            x = pariDispari(x);

            // Se x == 0 allora è pari, altrimenti dispari
            if (x == 0){

                printf("\nIl numero è pari.");

            } else if (x == 1){

                printf("\nIl numero è dispari.");

            }

            break;
        }

            // Algoritmo Verifica Numero intero
        case 4: {

            // Messaggi d'inizio
            printf("\nHai scelto: Numero intero...\n");
            printf("Inserire il valore: ");

            // Dichiarazioni variabili
            double x;

            // Ottengo il valore di x dall'input dell'utente
            scanf("%lf", &x);

            // Richiamo la funzione del numero Intero per ottenere il valore di x su cui eseguire la condizione
            x = numeroIntero(x);

            // Verifico le condizioni, se � uguale a 0 allora non contiene decimali, in caso contrario contiene
            if (x == 0){

                printf("\nIl valore NON contiene decimali");

            } else {

                printf("\nIl valore CONTIENE decimali");

            }
            break;
        }

            // Algoritmo Tabellina di numeri compresi in un intervallo
        case 5: {

            // Messaggi d'inizio
            printf("\nHai scelto: Tabellina dei numeri compresi in un intervallo...\n");
            printf("Inserire il primo valore da cui iniziare (minore): ");

            // Dichiarazione variabili
            int x, y;

            // Ottengo il valore di x dall'input dell'utente
            scanf("%d", &x);

            // Comunico all'utente di dare in input il secondo valore
            printf("Inserire il numero in cui finire (maggiore): ");

            // Ottengo il valore di y dall'input dell'utente
            scanf("%d", &y);

            // Richiamo la funzione
            tabellinaIntervallo(x,y);

            break;
        }

            // Algoritmo M.C.D.
        case 6: {

            // Messaggi d'inizio
            printf("\nHai scelto: M.C.D...\n");

            // Dichiarazioni variabili
            int x,y;

            // Chiedo all'utente di inserire x
            printf("Inserire il primo valore: ");

            // Ottengo x dall'input dell'utente
            scanf("%d", &x);

            // Chiedo all'utente di inserire y
            printf("Inserire il secondo valore: ");

            // Ottengo y dall'input dell'utente
            scanf("%d", &y);

            // Dichiaro mcd e ne richiamo la funzione per ottenere il risultato
            int ris = mcd(x,y);

            // Comunico il risultato all'utente
            printf("L'M.C.D. �: %d", ris);

            break;
        }

            // Algoritmo Numeri Perfetti
        case 7: {

            // Messaggi d'inizio
            printf("\nHai scelto: Primi N numeri perfetti...");

            // Dichiarazione variabili
            int n;

            // Chiedo all'utente n come input
            printf("\nInserire quanti numeri perfetti trovare: ");

            // Ottengo n dall'input dell'utente
            scanf("%d", &n);

            // Richiamo la funzione
            numeriPerfetti(n);

            break;
        }

            // Algoritmo Media di numeri
        case 8: {

            // Messaggi d'inizio
            printf("\nHai scelto: Media di numeri...\n");
            printf("Inserire un numero, inserire 0 per ottenere la media: \n");

            // Dichiaro le variabili
            double n, tot = 0, contatore = 0, mediaRis;

            // Ripeto il loop fino a quando n non diventa uguale a 0
            while (n != 0){

                // Ottengo l'input dall'utente
                scanf("%lf", &n);

                if (n != 0) {

                    tot += n;

                    contatore++;
                }

            }

            // Ottengo il risultato richiamando la funzione
            mediaRis = media(tot,contatore);

            // Comunico il risultato all'utente
            printf("La media �: %4.2f", mediaRis);

            break;
        }

            // Algoritmo Cifre singole di un numero
        case 9: {

            // Messaggi d'inizio
            printf("\nHai scelto: Cifre singole di un numero...\n");
            printf("Inserire un numero, verranno mostrate singolarmente le sue cifre: \n");

            // Dichiaro le variabili
            int num;

            // Ottengo l'input dall'utente e num
            scanf("%d", &num);

            // Richiamo la funzione
            cifreNumero(num);

            break;
        }

            // Algoritmo Numero Risultante
        case 10: {

            // Messaggi d'inizio e richiamo la funzione
            printf("\nHai scelto: Ricostruire numero risultante dall'ultima cifra...\n");

            // Richiamo la funzione
            int risultante = numeroRisultante();

            // Comunico il risultato all'utente
            printf("Numero %d" , risultante);

            break;
        }

        case 11:{

            // Messaggi d'inizio
            printf("\nHai scelto: Massimo e minimo di numeri...\n");
            printf("Inserire i numeri e 0 per uscire...\n");

            // Richiamo la funzione
            numeroMaxMin();

            break;
        }

        case 12:{

            // Messaggi d'inizio
            printf("\nHai scelto: Conta quanti numeri decimali...\n");

            // Dichiarazione variabili
            double x;

            // Chiedo all'utente di dare x in input
            printf("Inserire il numero di cui contarne i decimali: ");

            // Ottengo l'input dell'utente e quindi x
            scanf("%lf", &x);

            // Richiamo la funzione
            int ris = numeriDecimali(x);

            // Comunico il risultato all'utente
            printf("Numeri decimali: %d", ris);

            break;
        }

        case 13: {

            // Messaggi d'inizio
            printf("\nHai scelto: Elevamento a potenza...\n");

            // Dichiarazione variabili
            int x, y;

            // Chiedo all'utente di inserire come input il valore di x
            printf("Inserire il primo numero da elevare: ");

            // Ottengo x dall'input dell'utente
            scanf("%d", &x);

            // Chiedo all'utente un altro input
            printf("\nInserire quanto elevare il numero: ");

            // Ottengo il valore di y dall'input dell'utente
            scanf("%d", &y);

            // Ottengo ris richiamando la funzione
            int ris = elevamentoPotenza(x,y);

            // Comunico il risultato all'utente
            printf("\nRisultato: %d", ris);

            break;
        }

        case 14:{

            // Messaggi d'inizio
            printf("\nHai scelto: Trova Radici Quadrate senza decimali comprese in un intervallo...\n");

            // Dichiarazione variabili
            int x, y;

            // Chiedo all'utente di scrivere un input ossia x
            printf("Scrivere numero minore: ");

            // Ottengo x dall'input dell'utente
            scanf("%d", &x);

            // Chiedo all'utente di inserire in input y
            printf("\nScrivere numero maggiore: ");

            // Ottengo y dall'input dell'utente
            scanf("%d", &y);

            // Richiamo la funzione
            trovaRadici(x,y);

            break;
        }

        case 15:{

            // Messaggi d'inizio
            printf("\nHai scelto: Conta del numero inserito fino a zero...");
            printf("\nDigitare il numero di cui fare la conta fino a 0: ");

            // Dichiarazione variabili
            int n;

            // Ottengo n dall'input dell'utente
            scanf("%d", &n);

            // Chiamo la funzione per dare un input
            conta(n);

            break;
        }

        case 16:{

            printf("Hai scelto: Algoritmo dei numeri casuali...\n");

            // Ottengo TANTI dall'utente
            int TANTI;
            printf("\nInserire quanti numeri CASUALI vuoi trovare: ");
            scanf("%d", &TANTI);

            // Ottengo MAX dall'utente
            int MAX;
            printf("Inserire il valore massimo che vuoi possano assumere: ");
            scanf("%d", &MAX);

            numeriCasuali(TANTI, MAX);

            break;
        }

        case 17:{

            // Messaggi d'inizio
            printf("Hai scelto: Indovina numero casuale...\n");
            printf("\nIl numero casuale da indovinare è compreso tra -10 e 20, hai 10 solo tentativi!");

            indovinaNumero();

            break;
        }

        case 18: {

            // Messaggio d'inizio
            printf("\nHai scelto: Quante volte Dimezzare un numero fino ad arrivare all'unità...");
            printf("\nInserire il numero da dimezzare: ");

            int num, nVolte;

            scanf("%d", &num);

            nVolte = contaDimezza(num);

            printf("Il numero è stato dimezzato -%d- volte. Significa che per trovare un numero compreso servirebbero circa %d tentativi.", nVolte, nVolte * 2);

            break;
        }

        case 19: {

            printf("\nHai scelto: Generea x numeri casuali compresi in un intervallo e mostra il MAGGIORE e MINORE.");

            int max, min, nNum, contatore1 = 0, maxTrovato, minTrovato;

            printf("\nInserire numero massimo: ");
            scanf("%d", &max);
            printf("\nInserire numero minimo: ");
            scanf("%d", &min);
            printf("\nInserire QUANTI NUMERI generare: ");
            scanf("%d", &nNum);

            numeriGenMaxMin(max, min, nNum, contatore1, maxTrovato, minTrovato);

            break;
        }

        default: {

            printf("\n[ERRORE] -> Il valore inserito non � valido!");

            break;
        }

    }

    return 0;
}

void numeriGenMaxMin(int max, int min, int nNum, int contatore1, int maxTrovato, int minTrovato) {

    // Dichiaro il vettore
    int numeriGenerati[nNum];

    // Assegno un valore al vettore
    numeriGenerati[contatore1] = rand() % (max - (min) + 1) + (min);

    // Dichiaro le variabili con il loro valore iniziale
    maxTrovato = numeriGenerati[contatore1];
    minTrovato = numeriGenerati[contatore1];

    // Ripeto il loop finchè il contatore non diventa maggiore di nNum
    while (contatore1 < nNum){

        // Incremento il contatore
        contatore1++;

        // Assegno un nuovo valore al vettore
        numeriGenerati[contatore1] = rand() % (max - (min) + 1) + (min);

        // Controllo se è maggiore o minore e nel caso di una condizione soddisfatta, assegno un nuovo valore
        if (numeriGenerati[contatore1] > maxTrovato){
            maxTrovato = numeriGenerati[contatore1];
        } else if (numeriGenerati[contatore1] < minTrovato){
            minTrovato = numeriGenerati[contatore1];
        }
    }

    // Comunico il numero maggiore e minore casuale generato
    printf("Il numero maggiore trovato è %d e il minore %d", maxTrovato, minTrovato);
}

int contaDimezza(int num) {

    // Dichiaro parametri e variabili
    int nVolte = 0, dimezzatore = 2;

    while (num >= 2){

        num = divisione(num, dimezzatore);

        nVolte++;

    }
    return nVolte;
}


int moltiplicazione(int x, int y){

    int ris = 0;

    // Ripeti il loop fino a quando la condizione diventa falsa

        while (y > 0) {

            ris += x;

            y--;

        }

    return ris;

}

int divisione(int x, int y){

    int ris = 0;

    // Loop fino a quando x non diventa minore a y
    while (x >= y){

        x -= y;

        ris++;

    }

    return ris;
}

int divisioneResto(int x, int y){

    int ris = 0;

    // Loop fino a quando x non diventa minore a y
    while (x >= y){

        x -= y;

        ris++;

    }

    return x;

}

int pariDispari(int x){

    // Ripeto il loop fino a quando x diventa minore a 2
    while (x >= 2){

        x -= 2;

    }

    return x;
}

double numeroIntero(double x){

    // Ripeto il loop fino a quando x non diventa minore a 1
    while (x >= 1){

        x--;

    }

    return x;
}

void tabellinaIntervallo(int x, int y){

    int ris = 0;

    // Ripeto il loop finch� x non diventa maggiore di x
    while (x <= y){

        printf("\n\nTabellina del: %d", x);

        for (int i = 1; i <= 10 ; i++) {

            ris = x * i;

            printf("\nTabellina %d Ris:  %d", x, ris);

        }

        x++;
    }

}

int mcd(int x, int y){

    int resto;

    if (x > y){

        // Ripeti il loop finch� y non diventa uguale a 0
        while (y != 0){

            resto = x % y;

            x = y;

            y = resto;

            if (resto == 0){

                return x;

            }

        }

        return x;

        // Bastava -else- ma ho deciso di mettere la condizione comunque
    } else if (x < y){

        while (x != 0){

            resto = y % x;

            y = x;

            x = resto;

            if (resto == 0){

                return y;

            }

        }

        return y;

    }
}

void numeriPerfetti(int n){

    int ris = 0,x = 0;

    // n � il contatore dei numeri primi da trovare, x di quelli trovati
    while (x < n){

            ris++;

            int i, somma=0;

            for (i=1; i<ris; i++) {

                if ((ris % i)==0) {
                    somma = somma + i;
                }

            }

            if (somma == ris) {

                // Ris � il numero per cui � stata fatta la verifica del numero perfetto ed � risultato vero
                printf("\nNumero: %d", ris);

                x++;
            }
    }
}

double media(int tot, int contatore){

    return divisione(tot,contatore);

}

void cifreNumero(int num){

    int x = 0;

    // Ripeto il loop fino a quando num non � minore a 1
    while (num > 1){

        x = divisioneResto(num, 10);

        printf("%d\n",x);

        num = (num - x) / 10;

    }

    if (num != 0){

        printf("%d\n" ,num);

    }

}

int numeroRisultante(){

    printf("Inserire un numero, inserire 0 per ottenere il numero risultante: \n");

    int x, ris = 0, n = 0;

    while (x > 0){

        scanf("%d", &x);

        if (x == 0){
            return ris;
        }

        ris += (int) (x * pow(10,n));

        n++;

    }

    return ris;
}

void numeroMaxMin(){

    int a;

    scanf("%d", &a);

    int max = a, min = a;

    while (a != 0){

        scanf("%d", &a);

        if (max < a){
            max = a;
        } else if (min > a){
            min = a;
        }

    }

    printf("Numero maggiore: %d\n", max);

    printf("Numero minore: %d\n", min);

}

int numeriDecimali(double x){

    int ris = 0;

    while (x != 0){

        while (x >= 1){
            printf("\ndebug x %f", x);
            x = x - 1;
        }

        if (x < 1 && x != 0){
            x = x * 10;
        }

        ris++;
    }

    return ris;
}

int elevamentoPotenza(int x, int y){

    int contatore = 1, ris = x;

    while (contatore < y){

        ris = ris * x;

        contatore++;
    }

    return ris;

}

void trovaRadici(int x, int y){

    int radice = 0;

    while(moltiplicazione(radice,radice) <= y){

        if(moltiplicazione(radice,radice) >= x){
            printf("%d Radice è la base del quadrato di valore %d\n", radice, moltiplicazione(radice,radice));
        }

        radice++;
    }

}

void conta(int x){

    for ( x; x >= 0; x--) {
        printf("Numero: %d \n", x);
    }

}

void numeriCasuali(int TANTI, int MAX) {

    int mioVettore[TANTI];
    srand(time(0));

    // Generatore numeri casuali
    for (int conta = 0; conta < TANTI; conta++) {
        // Ottengo un valore casuale compreso tra 0 e MAX
        mioVettore[conta] = (rand() % MAX);
    }

    // Visualizzatore risultati
    printf("\nI numeri generati sono: \n");
    for (int conta = 0; conta < TANTI; conta++) {

        // Scrivo il risultato
        printf("%d \t", mioVettore[conta]);

    }
}

void indovinaNumero() {
    int tentativi = 10, conta = 1, x;
    int numeriInseriti[tentativi];

    // Ottengo x dall'utente
    printf("\nInserisci il numero con cui provare: ");
    scanf("%d", &x);

    // Genero un numero casuale compreso tra 20 e -10
    srand(time(0));
    int numeroCasuale = rand()%(20-(-10) + 1) + (-10);

    // Controllo se l'utente ha trovato il numero al primo tentativo
    if (x == numeroCasuale){

        printf("\nComplimenti, hai indovinato il numero al primo tentativo! Era %d", numeroCasuale);

        // Vado avanti se non l'ha indovinato subito
    } else {

        // Decremento il numero di tentativi rimasti
        tentativi--;

        // Comunico all'utente che il numero che aveva inserito era errato
        printf("\nHai inserito un numero errato, hai ancora %d tentativi!\n", tentativi);
        if (x > numeroCasuale){

            // Consiglio per trovare il numero
            printf("\nConsiglio: il numero inserito è -MAGGIORE- di quello da indovinare!");

        } else if (x < numeroCasuale){

            // Consiglio per trovare il numero
            printf("\nConsiglio: Il numero inserito è -MINORE- di quello da indovinare!");

        }

        // While che va avanti finchè i tentativi non sono uguali a 0
        while (tentativi >= 0){

            // Assegna il valore al vettore e lo incrementa
            numeriInseriti[conta++] = x;

            // L'utente ha finito i tentativi e ha quindi perso
            if (tentativi <= 0){

                // Messaggio della sconfitta
                printf("\nHai finito i tentativi! Hai inserito i seguenti numeri:");

                // Visualizzatore numeri inseriti
                printf("\nI numeri che hai provato sono: \n");
                for (int i = 1; i < conta; i++) {

                    // Scrivo i numeri
                    printf("%d \t", numeriInseriti[i]);

                }
            }

            // Messaggio che invita l'utente a riprovare e quindi inserire un nuovo x
            printf("\nInserisci il nuovo numero con cui provare: ");
            scanf("%d", &x);

            // Se l'utente ha indovinato il numero, finisce
            if (x == numeroCasuale){

                // Messaggio della vittoria e quanti tentativi sono stati usati
                printf("\nHai indovinato il numero al %d° tentativo", conta);

                // Visualizzatore numeri inseriti
                printf("\nI numeri che hai provato sono: \n");
                for (int i = 1; i < conta; i++) {

                    // Scrivo i numeri
                    printf("%d \t", numeriInseriti[i]);

                }

                // Ferma il programma
                break;
            } else {

                // Decrementa il numero di tentativi rimasti
                tentativi--;

                // Comunica all'utente che ha un numero errato
                printf("\nHai inserito un numero errato, hai ancora %d tentativi!\n", tentativi);
                if (x > numeroCasuale){

                    // Consiglio
                    printf("\nConsiglio: il numero inserito è -MAGGIORE- di quello da indovinare!");

                } else if (x < numeroCasuale){

                    // Consiglio
                    printf("\nConsiglio: Il numero inserito è -MINORE- di quello da indovinare!");

                }
            }
        }
    }
}