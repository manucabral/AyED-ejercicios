#include <iostream>

using namespace std;

void numeroMayor(int n1, int n2, int &mayor);

int main(){
    int a = 5, b = 10, mayor = 0;
    numeroMayor(a, b, mayor);
    cout << mayor << endl;
    return 0;
}

void numeroMayor(int n1, int n2, int &mayor){
    mayor = n1 > n2 ? n1 : n2;
}