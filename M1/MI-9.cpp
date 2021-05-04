#include <iostream>

using namespace std;

/*
    30 días -> abril, junio, septiembre y noviembre
    31 días -> enero, marzo, mayo, julio, agosto, octubre y diciembre
    20 o 28 días -> febrero
*/

int main(){
    int year = 0, month = 0, days = 0;

    cin >> year >> month;
    
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            days = 30;
            break;

        case 4: case 6: case 9: case 11: 
            days = 31;
            break;
        
        case 2: 
            days = year % 4 == 0 ? 29 : 28; 
            break;
    }

    cout << "El mes " << month << " tiene" << days << " dias";
    return 0;
};