#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    int actual_date = 0, date_of_birth = 0, years_difference = 0, max_date = 0, minor_date = 99999999;
    char name[24], ma_name[24], mi_name[24];

    cin >> actual_date;

    while(strcmp(name, "FIN") != 0){
        cout << "Nombre: "; cin >> name;
        
        cout << "Fecha de nacimiento: "; cin >> date_of_birth;

        years_difference = abs(actual_date - date_of_birth);

        if(years_difference > max_date){
            max_date = years_difference;
            strcpy(ma_name, name);
        }
        
        if(years_difference < minor_date){
            minor_date = years_difference;
            strcpy(mi_name, name);
        }
    }

    cout << "Persona mas vieja " << ma_name << endl; 
    cout << "Persona mas joven " << mi_name;

    return 0;
}
