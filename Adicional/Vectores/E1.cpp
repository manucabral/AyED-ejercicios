/*
    Leer una lista de 10 valores enteros listarlos por pantalla en sentido inverso
    al que ingresaron.
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    short arr[10] = {0};

    for (size_t i = 0; i < 10; i++)
        std::cin >> arr[i];

    for (int i = 10 - 1; i >= 0; i--)
        std::cout << arr[i] << " ";

    return 0;
}
