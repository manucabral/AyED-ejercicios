#include <iostream>

using namespace std;

int main(){
    int a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    // desigualdad triangular
    if(a + b > c && b + c > a && c + a > b){
        if(a == b && b == c) cout << "Triangulo equilatero";

        else if(a != b && b != c) cout << "Triangulo escaleno";
        
        else cout << "Es isosceles";
    }
    
    return 0;
};