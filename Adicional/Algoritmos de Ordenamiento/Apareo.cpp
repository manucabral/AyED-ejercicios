#include <iostream>

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
    int arr[] = {23, 46}, n = sizeof(arr) / sizeof(arr[0]),
        arr2[] = {12, 56, 57, 58}, m = sizeof(arr2) / sizeof(arr2[0]),
        res[20] = {0};

    sort(arr, arr2, res, n, m);

    return 0;
}
