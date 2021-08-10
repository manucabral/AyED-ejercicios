#include <iostream>

using namespace std;

int main(){

    int id = 0, seaport = 0, total_weight = 0, id_heavier_container = 0;
    int f_port = 0, s_port = 0, t_port = 0;
    float weight = 0, max_weight = 0;

    for (int i = 0; i < 100; i++)
    {
        cout << "Identificacion: "; cin >> id;
        cout << "Peso: "; cin >> weight;
        
        while(seaport != 1 && seaport != 2 && seaport != 3){
            cout << "Puerto: "; 
            cin >> seaport;
        }

        total_weight += weight;

        if(weight > max_weight){
            max_weight = weight;
            id_heavier_container = id;
        }

        switch(seaport){
            case 1: f_port++; break;
            case 2: s_port++; break;
            case 3: t_port++; break;
        }
    }

    cout << "Total weight: " << total_weight << endl;
    cout << "Heavier container: " << id_heavier_container << endl;

    cout << "1 seaport containers: " << f_port << endl;
    cout << "2 seaport containers: " << s_port << endl;
    cout << "3 seaport containers: " << t_port << endl;

    return 0;
}