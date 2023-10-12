#include <cstring>
#include <iostream>

using namespace std;

class Persona {
protected:
    char cognome[30];
    char nome[30];
public:
    Persona(){};
    Persona(char* no, char* co) {
        strcpy_s(nome, no);
        strcpy_s(cognome, co);
    };
    ~Persona(){};
    void setNome(char* no){
        strcpy_s(nome, no);
    }
    void setCognome(char* co){
        strcpy_s(cognome, co);
    }
    char* getCognome(){
        return cognome;
    }
    char* getNome(){
        return nome;
    }
    void stampa(){
        cout << "Nome   :" << nome;
        cout << "Cognome: " << cognome;
    }
};
