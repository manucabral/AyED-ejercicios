/*
    Realice un subprograma que muestre el contenido de un vector en forma 
    ordenada descendentemente. El tamaño del array es informado por 
    parámetro
*/

#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort_desc(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);

    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

int main(int argc, char const *argv[])
{
    int arr[6] = {10, 300, 85, 32, 12};
    bubble_sort_desc(arr, 5);   
    return 0;
}
