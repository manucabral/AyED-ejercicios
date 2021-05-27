#include <iostream>

using namespace std;

int abs(int n);

int main(){

    cout << abs(-3) << endl;

    return 0;
}

int abs(int n){
    return n > 0? n : -1*n;
}