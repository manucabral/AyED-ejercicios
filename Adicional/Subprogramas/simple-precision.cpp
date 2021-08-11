#include <iostream>

using namespace std;

void convertToBinary(unsigned int decimal, unsigned int binary[]);

int main(){
    unsigned int number = 0, binary[8] = {0};
    cin >> number;
    convertToBinary(number, binary);
    for(int i = 7; i >= 0; i--) cout << binary[i];
    return 0;
}

void convertToBinary(unsigned int decimal, unsigned int binary[]){
    for(int i = 0; decimal > 0 ; i++){
        binary[i] = decimal % 2;
        decimal = decimal / 2;
    }
}