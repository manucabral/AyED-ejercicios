#include <iostream>

using namespace std;

int factorial(int);
int esMultiplo(int, int);

int main(){
    int n = -1, m3 = 0, m5 = 0, m3_5 = 0;

    while(n != 0){
        cin >> n;
        cout << "Factorial: " << factorial(n) << endl;
        m3 += esMultiplo(n, 3);
        m5 += esMultiplo(n, 5);
        m3_5 += esMultiplo(n, 3) && esMultiplo(n, 5);
    }

    cout << "Multiplos de 3: " << m3 << endl;
    cout << "Multiplos de 5: " << m5 << endl;
    cout << "Multiplos de 3 y 5: " << m3_5 << endl;

    return 0;
}

int factorial(int n){
    return n == 0 ? 1 : n * factorial(n - 1);
}

int esMultiplo(int numero, int multiplo){
    return numero != 0 && (numero % multiplo) == 0;
}
