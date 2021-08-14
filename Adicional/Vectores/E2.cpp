/*
    Dado un vector 15 valores, hacer un programa que pueda obtener, y sacar
    por pantalla:
    − el mayor de los valores
    − el menor de los valores
    − el más próximo al promedio
*/

#include <iostream>
#include <math.h>

int main(int argc, char const *argv[])
{
    int arr[15] = {0}, num = 0, max = 0, min = 0, sum = 0,
        closest = 9999, tempd = 0, tempc = 0;
    float average = 0;

    // read values
    for (size_t i = 0; i < 5; i++)
    {
        std::cin >> arr[i];
        sum += arr[i];
    }

    min = arr[0];
    max = arr[0];
    average = sum == 0 ? 0 : sum / 5;

    // search min, max and closest value
    for (size_t i = 0; i < 5; i++)
    {

        // difference beetwen number and average
        tempd = abs(arr[i] - average);

        // difference beetwen closest number and average
        tempc = abs(closest - average);

        if (tempd < tempc)
            closest = arr[i];
        else if (tempd == tempc && arr[i] < closest)
            closest = arr[i];

        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    std::cout << "min: " << min << "max: " << max << "promedio: " << average << "cercano: " << closest;

    return 0;
}
