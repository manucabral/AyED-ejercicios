#include <iostream>

using namespace std;

int main(){
    int a = 0, b = 0;

    cin >> a >> b;

    a > b ? cout << a << " es mayor a " << b : cout << b << " es mayor a " << a;

    return 0;
}