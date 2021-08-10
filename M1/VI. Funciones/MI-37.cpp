/*
    Desarrolle la función
    float CalcularPorcentajeDiferencia(int A ,int B)
    que recibe dos valores y retorne el siguiente cálculo: (B-A) *100 / (A+B) 
*/

#include <iostream>

using namespace std;

float CalcularPorcentajeDiferencia(int, int);

int main(){
    int a=0, b=0;
    cin >> a >> b;
    cout << "R: " << CalcularPorcentajeDiferencia(a, b);
    return 0;
};

float CalcularPorcentajeDiferencia(int a, int b){
    return ((b-a) * 100) / (a+b);
}