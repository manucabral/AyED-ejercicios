#include <iostream>

/*
Escriba en C++ un programa que lea  juegos de números reales.
La lectura de valores de un juego finaliza al leer un valor-1, que no se toma como valor del juego. 
Al finalizar cada juego debe informar por pantalla el mínimo valor y el promedio de los valores entre 20 y 40 
(incluidos ambos límites) del juego.
La lectura de juegos finaliza al leer un juego que contenga el número 27, pero debe terminar de procesarse dicho juego 
(debe finalizarse el juego con -1).
Terminada la  lectura de todos los valores de todos los juegos se debe mostrar el mínimo de todos 
los valores de todos los juegos, en qué número de juego apareció y la posición dentro del juego. (6 ptos)
*/
using namespace std;

int main(){
    int game=0, value=0, min_value=0, sum_range=0, count_range=0, count=0, 
        min_pos_value=0, last_min_value=0, min_index=0, min_gameid=0, min_value_game=9999;
    bool first_entry=true;
    float range_average=0;

    cin >> game;
    while(game != 27){
        
        while(value != -1){
            cout << "Ingresa el valor: ";
            cin >> value;

            count++;

            if(first_entry){
                first_entry = false;
                min_value = value;
                min_pos_value = count;
            }else if(value < min_value && value != -1){
                min_pos_value = count;
                min_value = value;
            }

            if(value >= 20 && value <= 40){
                count_range++;
                sum_range += value;
            }
        };

        if(count_range > 0) cout << "Promedio entre 30 y 40: " << sum_range/count_range << endl;
        else cout << "No hubo valores entre 30 y 40" << endl;

        cout << "Valor minimo entre 30 y 40:" << min_value << endl;

        if(min_value < min_value_game){
            min_gameid = game;
            min_value_game = min_value;
            min_index = min_pos_value;
        }

        cout << "Ingresa el juego: ";
        cin >> game;

        first_entry = true;
        count_range = 0;
        sum_range = 0;
        count = 0;
        value = 0;
    };

    cout << "El valor minimo de todos los juegos fue " << min_value_game << " en posicion: " << min_index << "en el juego: "<< min_gameid << endl;
    return 0;
}