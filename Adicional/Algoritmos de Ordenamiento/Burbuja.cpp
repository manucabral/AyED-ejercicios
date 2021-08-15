#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 300, 85, 32, 12}, n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    return 0;
}