/*
    Diseñar un algoritmo recursivo, que permita invertir el contenido de un
    vector. Como indica el ejemplo:
        Vector original: 28 35 12 43 56 77
        Vector invertido: 77 56 43 12 35 28
    El algoritmo no podrá usar un vector auxiliar.
*/

#include <iostream>

using namespace std;

void reverse(int *arr, int end=0, int start=0){

    if(start >= end) return;

    // swap elements
    int tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;
    
    reverse(arr, end-1, start+1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {28, 35, 12, 43, 56, 77};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    reverse(arr, arr_size - 1, 0);

    for (size_t i = 0; i < arr_size - 1; i++) cout << arr[i] << " ";
    
    return 0;
}
