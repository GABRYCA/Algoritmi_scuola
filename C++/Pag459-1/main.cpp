#include <iostream>

using namespace std;

// Errore
int main() {
    int *pi1, *pi2;
    int n1, n2;
    n1 = 10;
    pi1 = &n1;
    *pi2 = 20;
    n2 = *pi1;
    *pi1 = *pi1 + 30;
    *pi2 = *pi1 - n1;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "*pi1 = " << *pi1 << endl;
    cout << "*pi2 = " << *pi2 << endl;
    return 0;
}
