#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

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

    printf("Valore inserito: ");

    int nAlgoritmoScelto;

    scanf("%d", &nAlgoritmoScelto);

    // Switch degli algoritmi in base a quello scelto
    switch (nAlgoritmoScelto) {

        // Algoritmo Moltiplicazione
        case 1: {

            printf("\nHai scelto: Moltiplicazione...\n");

            printf("Inserire il primo numero: ");

            int x, y;

            scanf("%d", &x);

            printf("Inserire il secondo numero: ");

            scanf("%d", &y);

            int ris = moltiplicazione(x,y);

            printf("\nRisultato: %d", ris);

            break;

        }

            // Algoritmo Divisione
        case 2: {

            printf("\nHai scelto: Divisione...\n");

            printf("Inserire il primo valore -da dividere-: ");

            int x, y, ris, resto;

            scanf("%d", &x);

            printf("Inserire il numero -che divide-: ");

            scanf("%d", &y);

            ris = divisione(x,y);
            resto = divisioneResto(x,y);

            printf("\nRisultato: %d", ris);
            printf("\nResto: %d", resto);

            break;
        }

            // Algoritmo Pari o dispari
        case 3: {

            printf("\nHai scelto: Pari o dispari...\n");

            printf("Inserire il valore: ");

            int x;

            scanf("%d", &x);

            x = pariDispari(x);

            // Se x == 0 allora �
            if (x == 0){

                printf("\nIl numero � pari.");

            } else if (x == 1){

                printf("\nIl numero � dispari.");

            }

            break;
        }

            // Algoritmo Verifica Numero intero
        case 4: {

            printf("\nHai scelto: Numero intero...\n");

            printf("Inserire il valore: ");

            double x;

            scanf("%lf", &x);

            x = numeroIntero(x);

            // Verifico le condizioni, se � uguale a 0 allora non contiene decimali, in caso contrario contiene
            if (x == 0){

                printf("\nIl valore è intero.");

            } else {

                printf("\nIl valore è decimale.");

            }
            break;
        }

            // Algoritmo Tabellina di numeri compresi in un intervallo
        case 5: {

            printf("\nHai scelto: Tabellina dei numeri compresi in un intervallo...\n");

            printf("Inserire il primo valore da cui iniziare (minore): ");

            int x, y;

            scanf("%d", &x);

            printf("Inserire il numero in cui finire (maggiore): ");

            scanf("%d", &y);

            tabellinaIntervallo(x,y);

            break;
        }

            // Algoritmo M.C.D.
        case 6: {

            printf("\nHai scelto: M.C.D...\n");

            int x,y;

            printf("Inserire il primo valore: ");

            scanf("%d", &x);

            printf("Inserire il secondo valore: ");

            scanf("%d", &y);

            printf("L'M.C.D. �: %d", mcd(x,y));

            break;
        }

            // Algoritmo Numeri Perfetti
        case 7: {

            printf("\nHai scelto: Primi N numeri perfetti...");
            int n;

            printf("\nInserire quanti numeri perfetti trovare: ");

            scanf("%d", &n);

            numeriPerfetti(n);

            break;
        }

            // Algoritmo Media di numeri
        case 8: {

            printf("\nHai scelto: Media di numeri...\n");

            printf("Inserire un numero, inserire 0 per ottenere la media: \n");

            double n, tot = 0, contatore = 0, mediaRis;

            // Ripeto il loop fino a quando n non diventa uguale a 0
            while (n != 0){

                scanf("%lf", &n);

                if (n != 0) {
                    tot += n;

                    contatore++;
                }

            }

            mediaRis = media(tot,contatore);

            printf("La media �: %4.2f", mediaRis);

            break;
        }

            // Algoritmo Cifre singole di un numero
        case 9: {

            printf("\nHai scelto: Cifre singole di un numero...\n");

            printf("Inserire un numero, verranno mostrate singolarmente le sue cifre: \n");

            int num;

            scanf("%d", &num);

            cifreNumero(num);

            break;
        }

            // Algoritmo Numero Risultante
        case 10: {

            printf("\nHai scelto: Ricostruire numero risultante dall'ultima cifra...\n");

            printf("Numero %d" ,numeroRisultante());

            break;
        }

        case 11:{

            printf("\nHai scelto: Massimo e minimo di numeri...\n");

            printf("Inserire i numeri e 0 per uscire...\n");

            numeroMaxMin();

            break;
        }

        case 12:{

            printf("\nHai scelto: Conta quanti numeri decimali...\n");

            double x;

            printf("Inserire il numero di cui contarne i decimali: ");

            scanf("%lf", &x);

            int ris = numeriDecimali(x);

            printf("Numeri decimali: %d", ris);

            break;
        }

        case 13: {

            printf("\nHai scelto: Elevamento a potenza...\n");

            int x, y;

            printf("Inserire il primo numero da elevare: ");

            scanf("%d", &x);

            printf("\nInserire quanto elevare il numero: ");

            scanf("%d", &y);

            int ris = elevamentoPotenza(x,y);

            printf("\nRisultato: %d", ris);

            break;
        }

        case 14:{

            printf("\nHai scelto: Trova Radici Quadrate senza decimali comprese in un intervallo...\n");

            int x, y;

            printf("Scrivere numero minore: ");

            scanf("%d", &x);

            printf("\nScrivere numero maggiore: ");

            scanf("%d", &y);

            trovaRadici(x,y);

            break;
        }

        case 15:{

            printf("\nHai scelto: Conta del numero inserito fino a zero...");

            printf("\nDigitare il numero di cui fare la conta fino a 0: ");

            int n;

            scanf("%d", &n);

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
    int numeriGenerati[nNum];

    numeriGenerati[contatore1] = rand() % (max - (min) + 1) + (min);

    maxTrovato = numeriGenerati[contatore1];
    minTrovato = numeriGenerati[contatore1];

    while (contatore1 < nNum){

        contatore1++;

        numeriGenerati[contatore1] = rand() % (max - (min) + 1) + (min);

        if (numeriGenerati[contatore1] > maxTrovato){
            maxTrovato = numeriGenerati[contatore1];
        } else if (numeriGenerati[contatore1] < minTrovato){
            minTrovato = numeriGenerati[contatore1];
        }
    }

    printf("Il numero maggiore trovato è %d e il minore %d", maxTrovato, minTrovato);
}

int contaDimezza(int num) {
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