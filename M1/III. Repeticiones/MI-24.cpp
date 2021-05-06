#include <iostream>

using namespace std;

// program without arrays

int main(){
    int max = 0, min = 9999, number = 0, position = 0;
    int sublot = 0, sublot_acum = 0, sublot_with_max_value = 0, sublot_max_value_position = 0;
    float sublot_average = 0;

    while(number >= 0){
        sublot++;
        sublot_acum = 0;
        position = 0;

        while(true){
            cout << "A number for sublot " << sublot << " :"; cin >> number;

            if(number <= 0) break;  

            position++;
            sublot_acum += number;

            if(number < min) min = number;

            if(number > max){
                max = number;
                sublot_with_max_value = sublot;
                sublot_max_value_position = position; 
            }
        }

        if(sublot_acum > 0){
            cout << "Sublot min value: " << min << endl;
            sublot_average = sublot_acum / position;
            cout << "Sublot average: " << sublot_average << endl;
        }
    }
    if(sublot > 0){
        cout << "Total: " << sublot << endl;
        cout << "Max in sublot: " << sublot_with_max_value << " position: " << sublot_max_value_position << " value: " << max; 
    }
    return 0;
}