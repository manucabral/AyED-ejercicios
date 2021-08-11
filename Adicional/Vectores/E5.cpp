/*
    Hacer un programa que permita realizar la suma y el producto de dos
    vectores. El usuario deberá poder elegir el tamaño del vector (entre 2 y 10
    valores).
*/

#include <iostream>

using namespace std;

int scalar_arrays(int *arr1, int *arr2, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr1[i] * arr2[i];
    return sum;
}

void sum_arrays(int *arr1, int *arr2, int size, int *arr3)
{
    for (int i = 0; i < size; i++)
        arr3[i] = arr1[i] + arr2[i];
}

int main(int argc, char const *argv[])
{
    int first_arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1},
        second_arr[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2},
        output_arr[10], size = 0;

    while (size > 10 || size < 2)
    {
        cout << "Enter size: ";
        cin >> size;
    }

    sum_arrays(first_arr, second_arr, size, output_arr);

    for (int i = 0; i < size; i++)
        cout << output_arr[i] << " ";

    cout << endl << scalar_arrays(first_arr, second_arr, size);
    return 0;
}
