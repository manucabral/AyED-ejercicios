#include <iostream>

using namespace std;

int main(){
    int edad = 0;

    cin >> edad;

    if(edad <= 12) cout << "menor" << endl;

    else if(edad > 13 && edad < 18) cout << "cadete" << endl;

    else if(edad > 18 && edad < 26) cout << "juvenil" << endl;
    
    else cout << "mayor" << endl;

    return 0;
}