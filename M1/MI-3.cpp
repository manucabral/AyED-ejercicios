#include <iostream>

using namespace std;

int main(){
    int day = 0, month = 0, year = 0, date = 0;
    cin >> date;

    year = date / 10000;
    month = (date % 10000) / 100;
    day = (date % 10000) % 100;

    cout << year << month << day;
    
    return 0;
};