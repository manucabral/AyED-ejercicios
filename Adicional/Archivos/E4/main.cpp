/**
 * Dados dos archivos de enteros, previamente ordenados ascendentemente, 
 * confeccione un programa que guarde en un tercer archivo el 
 * contenido de ambos ordenado ascendentemente
 */

#include <iostream>

#define FILENAME_SIZE 24
#define ARRAY_SIZE 5

void read_archive(char *filename, int *arr){
    FILE *file;
    int filesize;
    if(file = fopen(filename, "rb")){
        fseek(file, 0, SEEK_END);
        filesize = ftell(file) / sizeof(int);
        fseek(file, 0, SEEK_SET);
        fread(arr, sizeof(int), filesize, file);
        fclose(file);
    }
}

int write_archive(char *filename, int *arr, int arr_size){

    FILE *file;
    int filesize = 0;
    if (file = fopen(filename, "wb"))
    {
        fseek(file, 0, SEEK_END);
        filesize = ftell(file) / sizeof(int);
        fseek(file, 0, SEEK_SET);
        fwrite(arr, sizeof(int), arr_size, file);
        fclose(file);
        return 0;
    }
    else
        return 1;
}

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

void sort(int *arr, int *arr2, int *output, int len_arr, int len_arr2)
{
    int i = 0, j = 0, k = 0;

    while (i < len_arr && j < len_arr2)
        output[k++] = arr[i] < arr2[j] ? arr[i++] : arr2[j++];

    while (i < len_arr)
        output[k++] = arr[i++];

    while (j < len_arr2)
        output[k++] = arr2[j++];
}

int main(int argc, char const *argv[])
{
    char first_filename[FILENAME_SIZE], second_filename[FILENAME_SIZE], output_filename[FILENAME_SIZE];
    int first_array[ARRAY_SIZE], second_array[ARRAY_SIZE], output_array[ARRAY_SIZE*2];

    std::cin >> first_filename;
    std::cin >> second_filename;
    std::cin >> output_filename;

    read_archive(first_filename, first_array);
    read_archive(second_filename, second_array);
    sort(first_array, second_array, output_array, ARRAY_SIZE, ARRAY_SIZE);
    bubbleSort(output_array, ARRAY_SIZE*2);
    write_archive(output_filename, output_array, ARRAY_SIZE*2);

    return 0;
}
