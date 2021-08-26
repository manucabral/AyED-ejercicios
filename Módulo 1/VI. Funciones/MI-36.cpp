/*
    Dada la fracción P/Q, para P y Q naturales informar la mayor cantidad de
    simplificaciones. Desarrolle y utilice una función que reciba dos números naturales y retorne el
    menor factor común. Ej: 360/60 = 180/30 = 90/15 = 30/5 = 6/1
*/
#include <iostream>

using namespace std;

int mcd(int, int);

int main(){
    int p=0, q=0, m=0;
    cin >> p >> q;
    m = mcd(p, q);
    cout << "Simplificado: " << p/m << "/" << q/m << endl;
    return 0;
}

int mcd(int a, int b){
    return a%b == 0 ? b : mcd(b, a%b);
}