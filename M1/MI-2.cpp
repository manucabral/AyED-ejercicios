#include <iostream>

using namespace std;

int main(){
    int day = 0, month = 0, year = 0, date = 0;
    cin >> day >> month >> year;

    date += (year * 10000) + (month * 100) + day;

    cout << date;
    
    return 1;
}