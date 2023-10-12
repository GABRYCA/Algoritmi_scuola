#include <iostream>
#include <string>

using namespace std;

class Insetto{
public:
    string nome;
    string getNome(){
        return nome;
    }
    void setNome(string nome){
        this->nome = nome;
    }
};

class Ape:public Insetto{
public:
    string ruolo;
    string getRuolo(){
        return ruolo;
    }
    void setRuolo(string ruolo){
        this->ruolo = ruolo;
    }
};

class ApeLigustica:public Ape{
public:
    string nomeTipo;
    int tempoDiVita;
    string getNomeTipo(){
        return nomeTipo;
    }
    int getTempoDiVita(){
        return tempoDiVita;
    }
    void setNomeTipo(string nomeTipo){
        this->nomeTipo = nomeTipo;
    }
    void setTempoDiVita(int tempoDiVita){
        this->tempoDiVita = tempoDiVita;
    }
    ApeLigustica(string nome, string ruolo, string nomeTipo, int tempoDiVita){
        this->nome = nome;
        this->ruolo = ruolo;
        this->nomeTipo = nomeTipo;
        this->tempoDiVita = tempoDiVita;
    }
};

class MezziDiTrasporto{
public:
    string nome;
    string alimentazione;
    string getNome(){
        return nome;
    }
    string getAlimentazione(){
        return alimentazione;
    }
    void setNome(string nome){
        this->nome = nome;
    }
    void setAlimentazione(string alimentazione){
        this->alimentazione = alimentazione;
    }
};

class Bicicletta:public MezziDiTrasporto{
public:
    string materiale;
    int peso;
    string getMateriale(){
        return materiale;
    }
    int getPeso(){
        return peso;
    }
    void setMateriale(string materiale){
        this->materiale = materiale;
    }
    void setPeso(int peso){
        this->peso = peso;
    }
    Bicicletta(string nome, string alimentazione, string materiale, int peso){
        this->nome = nome;
        this->alimentazione = alimentazione;
        this->materiale = materiale;
        this->peso = peso;
    }
};

int main() {

    printf("//////////////////"
           "\nLavoro di G.C. 4BITI"
           "\n//////////////////");

    int scelta;

    do {

        printf("\n\nOpzioni:"
               "\n0 -> Esci."
               "\n1 -> Api."
               "\n2 -> Biciclette."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Api...");

                ApeLigustica apeLigustica("Ape", "Regina", "Ape Ligustica", 1460);

                printf("\nInformazioni nel dettaglio con eredita': ");
                printf("\nNome: %s.", apeLigustica.getNome().c_str());
                printf("\nRuolo: %s.", apeLigustica.getRuolo().c_str());
                printf("\nNome tipo: %s.", apeLigustica.getNomeTipo().c_str());
                printf("\nTempo di vita: %d Giorni.", apeLigustica.getTempoDiVita());

                break;
            }

            case 2:{

                printf("\nHai scelto: Biciclette...");

                Bicicletta bicicletta("Traverse", "Elettrica", "Metallo e Plastica", 20);


                printf("\nInformazioni nel dettaglio con eredita': ");
                printf("\nNome: %s.", bicicletta.nome.c_str());
                printf("\nAlimentazione: %s.", bicicletta.alimentazione.c_str());
                printf("\nMateriale: %s.", bicicletta.materiale.c_str());
                printf("\nPeso: %dKG", bicicletta.peso);

                break;
            }

            default:{

                printf("\nScelta non valida! Per favore riprovare!");

                break;
            }

        }

    } while (scelta != 0);

    return 0;
}
