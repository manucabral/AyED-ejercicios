#include <iostream>

using namespace std;

int main(){

    int identificacion = 0, puerto = 0, identificacionContenedorPesado = 0;
    int totalPrimerPuerto = 0, totalSegundoPuerto = 0, totalTercerPuerto = 0;
    float peso = 0, pesoTotalATrasladar = 0, contenedorMasPesado = 0;

    for(int i = 0; i < 100; i++){
        cin >> identificacion;
        cin >> peso;
        cin >> puerto;

        if(peso > contenedorMasPesado){
            contenedorMasPesado = peso;
            identificacionContenedorPesado = identificacion;
        }
        switch(puerto){
            case 1: totalPrimerPuerto++; break;
            case 2: totalSegundoPuerto++; break;
            case 3: totalTercerPuerto++; break;
        }

        pesoTotalATrasladar += peso;
    }

    // couts..

    return 0;
}