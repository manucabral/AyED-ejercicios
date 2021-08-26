#include <iostream>

using namespace std;

/*
    En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de
    todos contra todos. Por cada partido disputado por un equipo se dispone de la siguiente
    información:
    a) Nro. de equipo,
    b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado).

    Se arma un lote de datos con todos los resultados del torneo, agrupados por Nro. de equipo.
    Desarrollar el programa que imprima:
    Por cada equipo, su número y el puntaje total que obtuvo (suma 3 si gana, y 1 si
    empata).
*/

int main(){
    int max_teams = 0;
    int id_team = 0, total_score = 0;
    char result;

    cout << "Ingrese cantidad de equipos: "; cin >> max_teams;

    for(int i = 0; i < max_teams; i++){
        cout << "> Ingrese numero de equipo: "; cin >> id_team;
        while(result != 'G' && result != 'E' && result != 'P'){
            cout << id_team << "> Ingrese resultado: "; cin >> result;
            cin.clear();
        }

        switch(result){
            case 'G': total_score += 3; break;
            case 'E': total_score += 1; break;
            case 'P': continue;
        }

        cout << "Equipo: " << id_team << " puntaje total: " << total_score << endl;
    }

    return 0;
}