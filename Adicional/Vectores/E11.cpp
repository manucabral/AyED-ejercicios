/*
    Dada un matriz tridimensional de N x M x P se pide ordenarla de
    menor a mayor
*/

#include <iostream>

#define f(i, max) for (int i = 0; i < max; i++)

#define N 2
#define M 3
#define P 2

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int size)
{
    f(i, size)
        f(j, size-1)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main(int argc, char const *argv[])
{
    int matrix[N][M][P] = {
        {{2, 1},
         {6, 4},
         {9, 6}},
        {{10, 15},
         {18, 8},
         {81, 12}}},
        aux = 0, arr[N * M * P];

    // 3d to simple simple array
    f(i, N)
        f(j, M)
            f(k, P)
                arr[(i * M + j) * P + k] = matrix[i][j][k];
    // sort asc
    bubble_sort(arr, N*M*P);
    
    f(i, N * M * P)
        std::cout << arr[i] << " ";
    
    return 0;
}
