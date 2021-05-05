#include <iostream>

using namespace std;
/*
Dado un conjunto de valores, que finaliza con un valor nulo, determinar e
imprimir (si hubo valores):
a) El valor máximo negativo
b) El valor mínimo positivo
c) El valor mínimo dentro del rango -17.3 y 26.9
d) El promedio de todos los valores
*/
int main(){
    float number = 0, max_number_negative = -999999, min_range = 99999, min_number_positive = 999999;
    float average = 0, acum = 0, count = 0;

    while(true){
        cin >> number;
        
        if(cin.fail())
            break;
        
        max_number_negative = number > max_number_negative && number < 0 ? number : max_number_negative;
        min_number_positive = number > 0 && number < min_number_positive ? number : min_number_positive;
        min_range = (number > -17.3 && number < 26.9) && number < min_range ? number : min_range;

        acum += number;
        count++;
    }

    average = acum / count;

    cout << "Maximo negativo: " << max_number_negative << endl;
    cout << "Minimo positivo: " << min_number_positive << endl;
    cout << "Valor minimo dentro del rango -17.3 y 26.9: " << min_range << endl;
    cout << "Promedio: " << average;

    return 0;
}
