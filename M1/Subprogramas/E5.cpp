#include <iostream>
#include <math.h>

using namespace std;

void calcularRaices(float a, float b, float c, float &r1, float &r2);

int main(){

    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    cin >> a >> b >> c;
    calcularRaices(a, b, c, x1, x2);
    cout << x1 << " " << x2 << endl;
    return 0;
}

void calcularRaices(float a, float b, float c, float &r1, float &r2){
    float d = b * b - 4 * a * c;
    r1 = d > 0 ? ( -b + sqrt(d) ) / ( 2 * a) : -b / (2 * a);
    r2 = d > 0 ? ( -b - sqrt(d) ) / ( 2 * a) : 0;
    return;
}
