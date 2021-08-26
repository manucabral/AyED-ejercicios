/*
Desarrollar una función tal que dado un número entero positivo calcule y retorne
su factorial.
*/

#include <iostream>

using namespace std;

int factorial(int);

int main(){
    int n = 0;
    cin >> n;
    cout << "Factorial: " << factorial(n) << endl;
    return 0;
}

int factorial(int n){
    return n == 0 ? 1 : n * factorial(n - 1);
}