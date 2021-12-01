#include <ctime>
#include <iostream>
#include <stdlib.h>
#define TESTA 0
#define CROCE 1
using namespace std;
class Moneta{
    private:
        int faccia;
    public:
        Moneta(){
            srand(time(NULL));
            lancia();
        };
        void lancia(){
            faccia = rand() % 2;
        };
        bool isTesta(){
            return (faccia = TESTA);
        };
        string toString(){
            string nomeFaccia;
            if (faccia == TESTA){
                nomeFaccia = "Testa";
            } else {
                nomeFaccia = "Croce";
            }
            return nomeFaccia;
        }
};


