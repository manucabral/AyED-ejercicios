#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    
    int n = 0, numero = 0, mayor = 0, menor = 9999, pos_mayor = 0, pos_menor = 0;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> numero;

        if(numero > mayor){
            mayor = numero;
            pos_mayor = i;
        }

        if(numero < menor){
            menor = numero;
            pos_menor = i;
        }
    }

    cout << "El mayor es: " << mayor << " posicion " << pos_mayor;
    cout << "El menor es: " << menor << " posicion " << pos_menor;
    return 0;
}