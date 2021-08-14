/*
    Confeccionar un subprograma que, dados dos vectores de números 
    enteros liste el contenido de ambos pero en forma ordenada. Utilice el 
    algoritmo de apareo
*/

#include <iostream>

#define LEN 2

void sort(int *arr, int *arr2, int *res, int len_arr, int len_arr2)
{
    int i = 0, j = 0, k = 0;

    while (i < len_arr && j < len_arr2)
        res[k++] = arr[i] < arr2[j] ? arr[i++] : arr2[j++];

    while (i < len_arr)
        res[k++] = arr[i++];

    while (j < len_arr2)
        res[k++] = arr2[j++];
}

int main(int argc, char const *argv[])
{
    int arr[LEN] = {23, 46},
        arr2[LEN*2] = {12, 56, 57, 58},
        res[LEN+LEN*2] = {0};

    sort(arr, arr2, res, LEN, LEN*2);

    for (int i = 0; i < LEN+LEN*2; i++)
        std::cout << res[i] << " ";

    return 0;
}
