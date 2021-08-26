#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int actual_date = 0, first_date = 0, second_date = 0, first_date_difference = 0, second_date_difference = 0, result = 0;

    cin >> actual_date >> first_date >> second_date;

    first_date_difference = abs(actual_date - first_date);
    second_date_difference = abs(actual_date - second_date);

    if(first_date_difference == second_date_difference)
        cout << "Son guales" << endl;
    else{
        result = first_date_difference < second_date_difference ? first_date : second_date;
        cout << "Fecha mas reciente: " << result;
    }

    return 0;
}
