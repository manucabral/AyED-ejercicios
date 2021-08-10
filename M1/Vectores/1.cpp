/*
    Leer una lista de 10 valores enteros listarlos por pantalla en sentido inverso
    al que ingresaron.
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    short arr[10] = {0};

    for (size_t i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    for (int i = 10 - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
