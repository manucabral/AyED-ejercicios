/*
    Convertir una tabla de 6 x 5 en un vector ordenado de mayor a menor
*/

#include <iostream>

#define M 6
#define N 5

void sort(int arr[M][N], int *res)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            res[i * N + j] = arr[i][j];
}

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
}

int main(int argc, char const *argv[])
{
    int arr[M][N] = {
        1, 2, 3, 4, 5,
        1, 2, 3, 4, 5,
        1, 2, 3, 4, 5,
        1, 2, 3, 4, 5,
        1, 2, 3, 4, 5,
        1, 2, 3, 4, 5},

        res[M * N] = {0};

    sort(arr, res);

    bubble_sort_desc(res, M * N);

    for (int i = 0; i < M * N; i++)
        std::cout << res[i] << " ";

    return 0;
}
