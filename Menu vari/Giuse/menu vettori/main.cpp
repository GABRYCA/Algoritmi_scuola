#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
//variabili globali
int selezione;
int num1 ;
const int num2 = 1000;
char scelta = 's';
int Vettore[num2];
int frequenza[num2];

//prototipo funzioni
void genera_casuali(int tanti , int MAX);
int logaritmo(int numero ,int base);
void mostra_vettore(int mioVettore[] , int dimensione);
void raddoppio_vettore(int mioVettore[], int dimensione);
void dimezza_vettore(int mioVettore[], int dimensione);
void sposta_avanti(int mioVettore[],int dimensione,int inizio);
void sposta_indietro(int mioVettore[], int dimensione,int inizio);
int maggiore(int mioVettore[], int dimensione);
int minore(int mioVettore[], int dimensione);
int conta_uguali(int mioVettore[],int num_trovare,int dimensione);
float media_vettore(int mioVettore[],int dimensione);
int moda_vettore(int mioVettore[],int dimensione);
int somma_magg60perc(int mioVettore[],int dimensione,int max);
int somma_tutto(int mioVettore[], int dimensione);
void non_pronta() {
    cout<<"oops questa funzione non è ancora pronta,\nma verrà implementata in una future release\n";
}
//funzione che mostra una stringa di testo
int main() {
    int num ,max ;

    while( scelta != 'n' ){
        system("clear");
        cout <<"benvenuto nel programma: inserisci un numero per avviare un sottoprogramma\n inserisci:"<< endl;
        cout << "\t1 - genera N numeri casuali " << endl;
        cout << "\t2 - modifica il vettore" << endl;
        cout << "\t3 - visualizza il vettore"<< endl;
        cout << "\t4 - raddoppia il vettore"<< endl;
        cout << "\t5 - dimezza il vettore"<< endl;
        cout << "\t6 - risolutore di logaritmi interi" << endl;
        cout << "\t7 - Mostra il maggiore e il minore generati" << endl;
        cout << "\t8 - Sposta in avanti di 1 tutti i numeri" << endl;
        cout << "\t9 - Sposta indietro di 1 tutti i numeri" << endl;
        cout << "\t10 - Rimuovi valore " << endl;
        cout << "\t11 - Aggiungi un valore" << endl;
        cout << "\t12 - Frequenza" << endl;
        cout << "\t13 - Mostra tabelle" << endl;
        cout << "\t0 - chiudi"<< endl;
        //da un vettore caricato in modo casuale caricato in modo casuale tra 0 e 100, ottenere la memorizzazione di quanti valori sono uguali tra loro
        //visualizzare in modo grafico i valori tabelle (range, percentuali)

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
                break;
            }
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
                sposta_avanti(Vettore,num,0);
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
                cout << "rimuovo il valore: " <<  Vettore[num3] << endl;
                sposta_indietro(Vettore,num,num3);
                break;
            }
            case 11: {
                int num3;
                cout << "in quale posizione vuoi aggiungere il valore"<< endl;
                cin >> num3;
                cout << "qual'è il valore"<< endl;
                cin >> num1;
                cout << "il valore sarà compreso tra " << Vettore[num3-1] << "\t"<<Vettore[num3]<< endl;
                sposta_avanti(Vettore,num,num3-1);
                cout << Vettore[num3]<<"\t"<<Vettore[num3+1]<<"\t"<<Vettore[num3-1];
                Vettore[num3]=num1;
                num++;
                break;
        }
            case 12: {
                cout << "mostra quante volte si ripete un numero"<< endl;
                for (int conta=0; conta < max;conta++) {
                    //mostra il risultato solo se il conteggio tramite la funzione è superiore a zero
                    if (conta_uguali(Vettore, conta, num) != 0) {
                        cout << "il numero " << "\'"<< conta << "\'"<< " si ripete " << conta_uguali(Vettore, conta, num) << " volte"<< endl;
                    }
                }
                break;
            }
            case 13: {

                //range: l'intervallo ogni quanto calcolare i valori; start è il valore di inizio; contay è un contatore che fa eseguire il loop fin quando non è uguale alla dimensione del vettore moda è il valore più ripetuto nel range
                int range,start=0,contay=0,moda=0;
                char continuare;
                cout << "media\tmoda\tvalori maggiori del 60%\tpercentuale maggiore di 60%"<<endl;
                cout << setprecision(2)<< fixed << media_vettore(Vettore,num)<<"\t"<< moda_vettore(Vettore,num)<<"\t\t"<<somma_magg60perc(Vettore,num,max)<<"\t\t\t\t\t"<<float(somma_magg60perc(Vettore,num,max)*100)/float(num)<<"%"<< endl;
                cout << "visualizzare altro?"<< endl;
                cin >> continuare;
                if (continuare == 's'){
                    cout << "tabelle in un range :\ninserisci un range per generare le tabelle" << endl;
                    cin >> range;
                    cout << "range\tconteggio\t\tpercentuale\t\tmoda" << endl;

                    while (contay < num) {
                        //contatore è il contatore di quante volte si ripete un numero
                        int contatore = 0;
                        //conta è volta uguale a start e viene incrementata fin quando non è uguale al numero finale del range
                        for (int conta = start; conta < start + range; conta++) {
                            //verifico che il conteggio precedente sia minore del nuovo in caso affermativo la moda assume il valore di conta
                            if (contatore < (contatore + conta_uguali(Vettore, conta, num)))
                                moda = conta;
                            //contatore viene incremnetato
                            contatore = contatore + conta_uguali(Vettore, conta, num);

                        }
                        //è la precentuale rapportata al numero di valori
                        float percentuale = (float(contatore) / float(num)) * 100;
                        if (contatore > 0)
                            cout << setprecision(2) << fixed << start + 1 << "-" << start + range << "\t\t" << contatore
                                 << "\t\t\t" << percentuale << "%" << "\t\t\t" << moda << endl;
                        contay++;
                        //int boh=start+range;
                        //if(boh > num) { range = num - start; }
                        start = start + range;
                    }
                }


            }
    }
        if (selezione == 0){break;}
        cout << "\ninserisci una lettera per continuare" << endl;
        //scelta = getchar();
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

            cout << conta << " - " << mioVettore[conta] << "\t" << ++conta << " - " << mioVettore[conta] << "\t" << ++conta << " - " << mioVettore[conta] << "\t"<< ++conta << " - " << mioVettore[conta] << "\n";
    }
    cout << endl;
}

void sposta_indietro(int mioVettore[],int dimensione,int inizio){       //mio vettore è il vettore, dimensione sono tu
    int  conta, val0 ;
    val0 = mioVettore[1] ;
    for(conta = inizio; conta < dimensione;conta++){
        mioVettore[conta]=mioVettore[conta+1];
    }
    mioVettore[conta]=val0;
}

void sposta_avanti(int mioVettore[],int dimensione,int inizio){
    int  conta, val0 ;
    val0 = mioVettore[dimensione] ;
    for(conta = dimensione; conta != inizio ;conta--){
        mioVettore[conta]=mioVettore[conta-1];
    }
    //mioVettore[conta]=val0;


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
float media_vettore(int mioVettore[],int dimensione){
    float media=0;
    for (int i = 0 ; i< dimensione;i++) {
        media = float(mioVettore[i] )+ media;
    }
    media=media/float(dimensione);
    return media;
}
int moda_vettore(int mioVettore[],int dimensione){
    int contatore=0,moda;
    for (int conta=0 ; conta < dimensione; conta++) {
        //verifico che il conteggio precedente sia minore del nuovo in caso affermativo la moda assume il valore di conta

        if (contatore < (contatore + conta_uguali(Vettore, conta, dimensione)))
            moda = conta;
        contatore = contatore + conta_uguali(Vettore, conta, dimensione);
    }
    return moda;

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
int conta_uguali(int mioVettore[],int num_trovare,int dimensione){
    int conta;
    for(conta=0;dimensione != 0;dimensione--){
        if(mioVettore[dimensione] == num_trovare){
            conta++;
        }
    }
    return conta;
}
int somma_magg60perc(int mioVettore[], int dimensione,int max){
    int magg60=0;
    for(int i =0 ; i <= dimensione; i++){
        if (mioVettore[i]>=((60*max)/100))
            magg60++;
    }
    return magg60;
}
