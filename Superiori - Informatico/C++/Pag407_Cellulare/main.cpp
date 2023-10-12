#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Cellulari.h"
using namespace std;

void pausa();

int main() {

    printf("/////////////////////////////////////////"
            "\n   Gerarchia Cellulare di G.C. 4BITI"
            "\n/////////////////////////////////////////");

    int nCellulari = 3;
    Cellulari **cellulari = new Cellulari*[10];
    cellulari[0] = new Cellulari;
    cellulari[0]->setTipo("TELEFONO");
    cellulari[0]->setNome("Mi 9T Pro");
    cellulari[0]->setMarca("Xiaomi");
    cellulari[0]->setPrezzo(399);
    cellulari[0]->setProcessore("SNAPDRAGON 855");
    cellulari[0]->setNumero_core(8);
    cellulari[0]->setSistema_operativo("Android");
    cellulari[0]->setRAM_GB(8.00);
    cellulari[0]->setMemoria_interna_GB(128.00);

    int scelta;
    do {

        printf("\nOpzioni:"
               "\n0 -> Esci."
               "\n1 -> Vedi tutti i telefoni."
               "\n2 -> Aggiungi telefono."
               "\n3 -> Rimuovi telefono."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta){

            case 0:{

                printf("\nHai scelto: Esci..."
                        "\n\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Informazioni cellulari...");

                int conta = 0;
                while (cellulari[conta] != nullptr && !cellulari[conta]->getNome().empty()){
                    printf("\nCellulare %d:", conta + 1);
                    cellulari[conta]->stampa();
                    printf("\n-------------");
                    conta++;
                }

                if (conta == 1){
                    printf("\nNessun cellulare disponibile!");
                }

                pausa();
                break;
            }

            case 2:{

                printf("\nHai scelto: Aggiungi telefono...");

                int conta = 0;
                int spazioVuoto = -1;
                for (int i = 0; i < nCellulari; i++){
                    if (!cellulari[i]->getNome().empty()){
                        conta++;
                    } else {
                        spazioVuoto = i;
                    }
                }

                if (conta == nCellulari || spazioVuoto == -1){
                    printf("\nNon è possibile aggiungere cellulari, il limite interno massimo supportato è %d."
                            "\nPuoi aumentare il valore da codice, il nome della variabile è 'int nCellulari'.", nCellulari);
                    break;
                }

                string nome, marca, processore, sistema_operativo;
                double prezzo;
                int numero_core;
                float memoria_int_GB, RAM_GB;

                printf("\nInserire il nome del cellulare: ");
                cin.ignore();
                getline(cin, nome);

                printf("\nInserire la marca del cellulare: ");
                getline(cin, marca);

                printf("\nInserire il prezzo del cellulare: ");
                scanf("%d", &prezzo);

                printf("\nInserire il nome del processore del cellulare: ");
                getline(cin, processore);

                printf("\nInserire il nome del sistema operativo del cellulare: ");
                getline(cin, sistema_operativo);

                printf("\nInserire il numero di core del cellulare: ");
                scanf("%d", &numero_core);

                printf("\nInserire numero GB interni del cellulare: ");
                scanf("%d", &memoria_int_GB);

                printf("\nInserire il numero di GB di RAM del cellulare: ");
                scanf("%d", RAM_GB);

                cellulari[spazioVuoto]->setTipo("TELEFONO");
                cellulari[spazioVuoto]->setNome(nome);
                cellulari[spazioVuoto]->setMarca(marca);
                cellulari[spazioVuoto]->setPrezzo(prezzo);
                cellulari[spazioVuoto]->setProcessore(processore);
                cellulari[spazioVuoto]->setNumero_core(numero_core);
                cellulari[spazioVuoto]->setSistema_operativo(sistema_operativo);
                cellulari[spazioVuoto]->setRAM_GB(RAM_GB);
                cellulari[spazioVuoto]->setMemoria_interna_GB(memoria_int_GB);

                printf("\nAggiunto con successo cellulare, informazioni: ");
                cellulari[spazioVuoto]->stampa();

                pausa();
                break;
            }

            case 3:{

                printf("\nHai scelto: Rimuovi cellulare...");

                int conta = 0;
                for (int i = 0; i < nCellulari; i++){
                    if (!cellulari[i]->getNome().empty()){
                        conta++;
                    }
                }

                if (conta == nCellulari){
                    printf("\nNon è possibile rimuovere cellulari, non ne sono disponibili!");
                    break;
                }

                conta = 0;
                for (int i = 0; i < nCellulari; i++){
                    if (!cellulari[i]->getNome().empty()){
                        printf("\nCellulare %d:"
                                "\nNome: %s", conta, cellulari[i]->getNome().c_str());
                    }
                }

                printf("\nInserire il nome del cellulare da rimuovere: ");
                cin.ignore();
                string nome;
                getline(cin, nome);

                for (int i = 0; i < nCellulari; i++){
                    if (!cellulari[i]->getNome().empty()){
                        if (cellulari[i]->getNome() == nome){
                            cellulari[i] = new Cellulari();
                            break;
                        }
                    }
                }

                printf("\nCellulare '%s' rimosso con successo!", nome.c_str());
                pausa();
                break;
            }

            default:{

                printf("\nOpzione non valida, per favore riprovare!");

                break;
            }

        }

    } while (scelta != 0);

    printf("\n\nUscito con successo!");

    return 0;
}

void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    scanf("%d");
}
