/*
    Dada una serie de caracteres que conforman una oración, donde cada palabra está
    separada de la siguiente por un carácter blanco y la oración finaliza con un punto. Se pide
    informar:
    a) cantidad de veces que apareció cada vocal
    b) cantidad de palabras que contiene la oración
    c) cantidad de letras que posee la palabra más larga.
*/

#include <iostream>

using namespace std;

int main(){

    char oracion[32];
    int i = 0, vocal[5] = {0}, max_palabra = 0, cant_palabras = 0, letras = 0;
    cin.getline(oracion, sizeof(oracion), 46);

    while(oracion[i] != '\0'){

        if( (int) oracion[i] != 32)
            letras++;
        
        if( (int) oracion[i] == 32 || (int) oracion[i + 1] == 0 || (int) oracion[i] == 10){
            max_palabra = letras > max_palabra ? letras : max_palabra;
            letras = 0;
            cant_palabras++;
        }

        switch((int)oracion[i]){
            case 97: case 65: vocal[0]++; break;
            case 101: case 69: vocal[1]++; break;
            case 105: case 73: vocal[2]++; break;
            case 111: case 79: vocal[3]++; break;
            case 117: case 85: vocal[4]++; break;
        };

        i++;
    };

    cout << "a:" << vocal[0] << " e:" << vocal[1] << " i:" << vocal[2] << " o:" << vocal[3] << " u:" << vocal[4] << endl;  
    cout << "Cantidad de palabras: " << cant_palabras << endl;
    cout << "La palabra mas larga tiene " << max_palabra << " letras" << endl;
    return 0;
}