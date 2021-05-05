#include <iostream>

using namespace std;

int main(){
    int num = 0, resto = 0;
    float quinta = 0, septima = 0;

    cin >> num;
    
    quinta = float(num) / 5;
    resto = num % 5;
    septima = quinta / 5;

    cout << quinta << endl;
    cout << resto << endl;
    cout << septima << endl;

    return 0;
};