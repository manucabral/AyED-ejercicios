#include <iostream>
#include <conio.h>

using namespace std;

#define ESC 27

void mostrarOpciones();
float sumar(float a, float b);
float restar(float a, float b);
float multiplicar(float a, float b);
float dividir(float dividendo, float divisor);

int main(){

    char tecla;
    float a = 0, b = 0;


    do{
        cout << "Ingrese el numero a: "; cin >> a;
        cout << "Ingrese el numero b: "; cin >> b;
        mostrarOpciones();
        cin >> tecla;
        cout << tecla << endl;

        
    }while(tecla != ESC);


    return 0;
}

void mostrarOpciones(){
    cout << "a - sumar \n" << "b - restar\n" << "c - multiplicar" << "d - dividir\n" << "esc - salir\n" << endl;
}