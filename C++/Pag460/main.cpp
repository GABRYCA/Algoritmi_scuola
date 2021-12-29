#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void cercaCar(string s);

struct Persona{
    string nome;
    string cognome;
};

int main() {

    int scelta;
    do {

        printf("\nOpzioni: "
               "\n0 -> Esci."
               "\n1 -> Esercizio."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Esercizio...");

                int a;
                float b;
                char *c = new char[2];

                int *pa = &a;
                float *pb = &b;
                char *pc = reinterpret_cast<char *>(&c);

                *pa = 10;
                *pb = 77.3;
                *pc = *(char*) "@";

                int vet[10] = {1,2,3,4,5,6,7,8,9,10};

                int *pt4 = &vet[3];

                *pt4 = 12;

                for (int i = 0; i < 10; i++) {
                    printf("\n%d:%d", i + 1, vet[i]);
                }

                int *pt0 = &vet[0];
                int posDaPuntare = 5;

                printf("\n\nPuntatore elemento %d, val ptr %p.", posDaPuntare, &vet[posDaPuntare]);

                string stringa = "Buonasera!";

                printf("\n\nPuntatore prima vocale stringa: %p", &stringa[0]);

                printf("\n\nPuntatori:");
                for (int i = 0; i < stringa.length(); i++) {
                    printf("\n%c:%p", stringa[i], &stringa[i]);
                }

                string st = "Nel mezzo del cammin di nostra vita";
                string spazio = " ";

                printf("\n\nPrimo carattere puntato di ogni parola:");
                for (int i = 0; i < st.length(); i++) {
                    if (i == 0){
                        printf("\n\n%c:%p", st[i], &st[i]);
                    }
                    if (st[i] == spazio[0]) {
                        printf("\n\n%c:%p", st[i + 1], &st[i + 1]);
                    }
                }

                string s = "Carattere";
                cercaCar(s);

                srand(time(0));
                int *vet2 = new int[10];
                int pMIN = 102, pMED = 0, pMAX = -1;

                for (int i = 0; i < 10; i++) {
                    int valRand = rand() % 100;
                    if (valRand > pMAX) pMAX = valRand;
                    if (valRand < pMIN) pMIN = valRand;
                    pMED += valRand;
                    vet2[i] = valRand;
                }
                pMED = pMED / 10;

                printf("\n\nRisultati: "
                       "\npMIN: %d, ptr: %p."
                       "\npMED: %d, ptr: %p."
                       "\npMAX: %d, ptr: %p.", pMIN, &pMIN, pMED, &pMED, pMAX, &pMAX);

                int dimensioneVetFloat;
                printf("\n\nInserire di che dimensione vuoi il vettore float: ");
                scanf("%d", &dimensioneVetFloat);

                float *vetFloat = new float[dimensioneVetFloat];

                double valInsDaUtente = 1, totale = 0;
                int contatore = 0;
                double *vet3 = new double[10000];
                while (valInsDaUtente != 0.00) {
                    printf("\nScrivi 0.00 per vedere la media oppure inserisci un double: ");
                    scanf("%lf", &valInsDaUtente);
                    if (valInsDaUtente != 0.00){
                        vet3[contatore] = valInsDaUtente;
                        contatore++;
                    }
                }
                for (int i = 0; i < contatore; i++) {
                    totale += vet3[i];
                }
                printf("\n\nMedia: %2.f", totale / contatore);

                int *vetC1 = new int[10];
                int *vetC2 = new int[10];

                for (int i = 0; i < 10; i++) {
                    if (&vetC1[i] + sizeof(int) == &vetC2[i]){
                        printf("\n%d - %d", vetC1[i], vetC2[i]);
                    }
                }
                if (&vetC1 < &vetC2){
                    printf("\n\nMinore ind. mem. vetC1");
                } else {
                    printf("\n\nMinore ind. mem. vetC2");
                }


                int *vet4 = new int(10);
                printf("\n");
                for (int i = 0; i < 10; i++) {
                    vet4[i] = rand() % 100;
                    printf("\n%d - %d:%p", i + 1,vet4[i], &vet4[i]);
                }
                printf("\n");
                for (int i = 0; i < 10; ++i) {
                    printf("\n%d - %d:%p", i + 1,vet4[i], &vet4[i]);
                }

                Persona *persona = new Persona;

                printf("\nInserire il nome: ");
                cin >> persona->nome;

                printf("\nInserire il cognome: ");
                cin >> persona->cognome;

                Persona personaStatic;
                personaStatic.nome = persona->nome;
                personaStatic.cognome = persona->cognome;
                free(persona);
                printf("\nDati persona: "
                       "\nNome: %s"
                       "\nCognome: %s", personaStatic.nome.c_str(), personaStatic.cognome.c_str());

                string colori = "gwr";
                while (colori != "gwr"){
                    if (colori[0] != 'g'){
                        swap(colori[0], colori[colori.find('g')]);
                    }
                    if (colori[1] != 'w'){
                        swap(colori[1], colori[colori.find('w')]);
                    }
                    if (colori[2] != 'r'){
                        swap(colori[2], colori[colori.find('r')]);
                    }
                }

                printf("\n\nColori: %s", colori.c_str());

                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }
        }

    } while (scelta != 0);

    printf("\nUscito con successo!");

    return 0;
}

void cercaCar(string s){
    size_t trovato = s.find("Car");
    if (trovato != string::npos){
        printf("\n\nPrima corrispondenza in %p.", &trovato);
    } else {
        printf("\n\nNon trovato %p", nullptr);
    }
}