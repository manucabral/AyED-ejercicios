/*

Desarrollar una función que calcule el máximo común divisor de dos números
enteros A, B con el siguiente algoritmo:
1) Dividir A por B, y calcular el resto (0 < R < B)
2) Si R = 0, el MCD es B, si no seguir en 3)
3) Reemplazar A por B, B por R, y volver al paso 1)

*/

#include <iostream>

using namespace std;

int mcd(int, int);

int main(){
    int a=0, b=0;
    cin >> a >> b;
    cout << "Maximo comun divisor: " << mcd(a, b) << endl;
    return 0;
};

int mcd(int a, int b){
    return a%b == 0 ? b : mcd(b, a%b);
}