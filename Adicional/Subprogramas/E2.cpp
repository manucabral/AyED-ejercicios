#include <iostream>

using namespace std;

void abss(int &n);

int main(){

    int a = -3;
    abss(a);
    cout << a << endl;

    return 0;
}

void abss(int &n){
    n = n > 0? n : -1*n;
}