#include <iostream>

using namespace std;

int main(){
    int num = 0, i = 0, count = 0, acum = 0, sum = 0;
    float average = 0;

    while (++i < 50){

        cin >> num;

        if(num > 100){
            count++;
            acum += num;
        }

        if(num < -10) sum += num;
    }

    average = acum / count;
    
    cout << "Promedio de num mayores a 100: " << average << endl;
    cout << "Sumatoria de num menores que -10: " << sum << endl;
    
    return 0;
}