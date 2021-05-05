#include <iostream>

using namespace std;

int main(){
    int a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    // desigualdad triangular
    if(a + b > c && b + c > a && c + a > b) cout << "es triangulo";
    else cout << "no es triangulo";
    
    return 0;
};