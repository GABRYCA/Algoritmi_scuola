#include<iostream>
#include<string.h>

using namespace std;

class O {

protected:
    int num;
    char s[32];

public:
    void somma(int h) { num += h; }
    void somma(char *h) { strcat(s, h); }
};

class N : public O {

public:
    void setnum(int x) { num = x; }
    int getnum() { return num; }
};

class S : public O {

public:
    void sets(char *st) {
        strcpy(s, st);
    }
    char *gets() { return s; }
};

int main() {
    int numero;
    char *str;

    N n1, n2;
    cout << "inserisci n1:";
    cin >> numero;
    n1.setnum(numero);
    cout << "inserisci n2:";
    cin >> numero;
    n2.setnum(numero);
    n1.somma(n2.getnum());
    cout << n1.getnum() << endl;

    S s1, s2;
    cout << "inserisci s1:";
    cin >> str;
    s1.sets(str);
    cout << "inserisci s2:";
    cin >> str;
    s2.sets(str);
    s1.somma(s2.gets());
    cout << s1.gets() << endl;
}
