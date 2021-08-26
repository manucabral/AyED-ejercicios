#include <iostream>

using namespace std;

/*
    Dado un número entero positivo entre 1 y 3999 informar su correspondiente
    número Romano

*/
int main(){
    unsigned int n = 0, unidad = 0, decena = 0, centena = 0, mil = 0, last_i = 0;
    char romano[20];
    cin >> n;

    mil = n / 1000;
    centena = (n / 100) % 10;
    decena = (n / 10) % 10;
    unidad = n % 10;

    if(mil > 0 && mil < 4) for(int i = 0; i < mil; i++) romano[i] = 'M';

    last_i = mil;

    if(centena > 0 && centena <= 3){
        for(int i = 0; i < centena; i++) romano[last_i + i] = 'C';
        last_i = centena + mil;
        
    }else if(centena == 4){
        romano[last_i] = 'C';
        romano[last_i + 1] = 'D';
        last_i += 2;

    }else if(centena >= 5 && centena < 9){
        romano[last_i] = 'D';
        last_i++;
        for(int i = 0; i < centena-5 ; i++) romano[last_i + i] = 'C';

    }else if(centena == 9){
        romano[last_i] = 'C';
        romano[last_i + 1] = 'M';
        last_i = centena + 2;
    }

    
    //cout << mil << endl << centena << endl << decena << endl << unidad << endl;

    cout << romano << endl;


    return 0;
}