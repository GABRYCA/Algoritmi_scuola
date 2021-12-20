#include <iostream>

using namespace std;

int main() {
    int *pi1, **pi2;
    int num1 = 3, num2 = 6;

    *pi1 = num1 + 2;
    pi2 = &pi1;
    pi1 = &num1;
    num1 = **pi2 + 20;
    num2 = *pi1;

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "*pi1 = " << *pi1 << endl;
    cout << "**pi2 = " << **pi2 << endl;
    return 0;
}
