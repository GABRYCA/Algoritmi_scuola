#include <iostream>
#include <time.h>
using namespace std;
//variabili globali
int selezione;
int num1 ;
const int num2 = 1000;
char scelta = 's';
int Vettore[num2];

//prototipo funzioni
void genera_casuali(int tanti , int MAX);
int logaritmo(int numero ,int base);
void mostra_vettore(int mioVettore[] , int dimensione);
void raddoppio_vettore(int mioVettore[], int dimensione);
void dimezza_vettore(int mioVettore[], int dimensione);
void sposta_avanti(int mioVettore[],int dimensione);
void sposta_indietro(int mioVettore[], int dimensione,int inizio);
int maggiore(int mioVettore[], int dimensione);
int minore(int mioVettore[], int dimensione);
void non_pronta() {
    cout<<"oops questa funzione non è ancora pronta,\nma verrà implementata in una future release\n";
}
//funzione che mostra una stringa di testo
int main() {
    int num ,max ;

    while( scelta != 'n' || scelta != 'N' ){
        system("clear");
        cout <<"benvenuto nel programma: inserisci un numero per avviare un sottoprogramma\n inserisci:"<< endl;
        cout << "\t1 - genera N numeri casuali il cui valore massimo è 999" << endl;
        cout << "\t2 - modifica il vettore" << endl;
        cout << "\t3 - visualizza il vettore"<< endl;
        cout << "\t4 - raddoppia il vettore"<< endl;
        cout << "\t5 - dimezza il vettore"<< endl;
        cout << "\t6 - risolutore di logaritmi interi" << endl;
        cout << "\t7 - Mostra il maggiore e il minore generati" << endl;
        cout << "\t8 - Sposta in avanti di 1 tutti i numeri" << endl;
        cout << "\t9 - Sposta indietro di 1 tutti i numeri" << endl;
        cout << "\t10 - Rimuovi valore " << endl;
        cout << "\t11 - chiudi"<< endl;

        cin >> selezione;
        switch (selezione) {
            case 1: {
                cout << "quanti numeri vuoi generare ?";
                cin >> num;
                cout << "qual'è il massimo numero che vuoi generare?";
                cin >> max;
                genera_casuali(num,max);
                break;
            }
            case 2:{
                int num3;
                cout << "quale valore del vettore vuoi modificare"<< endl;
                cin >> num3;
                cout << "modificherai il valore " <<  Vettore[num3] << "\ninserisci il nuovo valore:";
                cin >> Vettore[num3];
            }
            break;
            case 3: {
                mostra_vettore(Vettore, num);
                break;
            }
            case 4: {
                raddoppio_vettore( Vettore,num);
                break;
            }
            case 5: {
                dimezza_vettore( Vettore,num);
                break;
            }

            case 6: {
                num = 2;   //la base del logaritmo è due ma volendo può essere definita dall'utente
                cout << "inserisci il numero di cui vuoi eseguire il logaritmo in base 2 ";
                cin >> num1;
                int ris;
                ris = logaritmo(num1, num);
                cout << "il risulato del logaritmo in base 2 è: " << ris  << endl ;
                break;
            }
            case 7: {
                cout << "il numero maggiore è: " << maggiore(Vettore,num) << "il numero minore è: "<<minore(Vettore,num) << endl;
                break;
            }
            case 8: {
                sposta_avanti(Vettore,num);
                break;
            }
            case 9: {
                sposta_indietro(Vettore,num,0);
                break;
            }
            case 10: {
                int num3;
                cout << "quale valore del vettore vuoi rimuovere"<< endl;
                cin >> num3;
                cout << "rimuovo il valore" <<  Vettore[num3] << endl;
                sposta_indietro(Vettore,num,--num3);
                break;
            }
        }
        if (selezione == 11){break;}
        cout << "\ninserisci 'N' per uscire\npremi un taso per continuare ";
        cin >> scelta;
    }

    return 0;

}

void genera_casuali(int tanti , int MAX){
    srand(time(0));
    for (int conta = 0; conta < tanti;conta++){
        Vettore[conta] = (rand() % MAX);
    }
}

int logaritmo(int numero, int base){
    int esponente=0;
    while(numero >= base ){
        numero = numero / base;
        esponente++;
    }
    return esponente;
}

void dimezza_vettore(int mioVettore[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        mioVettore[i] = mioVettore[i] / 2;
    }
}

void raddoppio_vettore(int mioVettore[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        mioVettore[i] = mioVettore[i] * 2;
    }
}

void mostra_vettore(int mioVettore[] , int dimensione){
    cout << "\n i numeri sono: \n";
    for (int conta = 1; conta < dimensione; conta++) {
        cout << conta << "-" << mioVettore[conta] << "\t" << ++conta << "-" << mioVettore[conta] << "\t"<< ++conta << "-" << mioVettore[conta] << "\t"<< ++conta << "-" << mioVettore[conta] << "\n";
    }
    cout << endl;
}


void sposta_indietro(int mioVettore[],int dimensione,int inizio){
    int  conta, val0 ;
    val0 = mioVettore[0] ;
    for(conta = inizio; conta < dimensione;conta++){
        //debug
        int debug=conta;
        cout << "debug\t"<< mioVettore[debug] <<"\t"<<mioVettore[++debug]<<"\t"<<debug<<endl;
        //fine debug
        mioVettore[conta]=mioVettore[conta+1];
    }
    mioVettore[conta]=val0;
}
void sposta_avanti(int mioVettore[],int dimensione){
    int appoggio;
    appoggio = mioVettore[dimensione];
    for(;dimensione>0;dimensione--){
        mioVettore[dimensione]=mioVettore[dimensione-1];
    }
    mioVettore[0]=appoggio;
}
int maggiore(int mioVettore[], int dimensione){
    int max = mioVettore[0];
    for(int conta = 0 ; conta < dimensione ; conta++){
        //verifico ogni volta che il maggiore sia maggiore del numero del vettore alla posizione conta
        if(mioVettore[conta] > max){
            max = mioVettore[conta];
        }
    }
    return max;
}
int minore(int mioVettore[], int dimensione){
    int min = mioVettore[0];
    for(int conta = 0 ; conta < dimensione ; conta++){
        //verifico ogni volta che il minore sia minore del numero del vettore alla posizione conta
        if(mioVettore[conta] < min){
            min = mioVettore[conta];
        }
    }
    return min;
}
