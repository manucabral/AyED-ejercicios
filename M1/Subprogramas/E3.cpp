#include <iostream>

using namespace std;

int fact(int n);

int main(){
    cout << fact(3) << endl;
    return 0;
}

int fact(int n){
    return n == 0 ? 1 : n * fact(n - 1);
}