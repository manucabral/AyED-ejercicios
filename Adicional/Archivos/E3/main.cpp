/**
 * Dados dos archivos de enteros confeccione un programa que guarde en un tercer archivo el contenido de ambos intercalado de a un número
 */

#include <iostream>

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

int read_archive(char *filename, int *arr, int arr_size)
{
    FILE *file;
    int filesize;
    if (file = fopen(filename, "rb"))
    {
        fseek(file, 0, SEEK_END);
        filesize = ftell(file) / sizeof(int);
        fseek(file, 0, SEEK_SET);
        fread(arr, sizeof(int), filesize, file);
        fclose(file);
        return 0;
    }
    else
    {
        std::cout << "El archivo esta vacio" << std::endl;
        return 1;
    }
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
    char first_filename[24], second_filename[24], output_filename[24];
    int first_array[5], second_array[5], output_array[10]; 

    std::cin >> first_filename;
    std::cin >> second_filename;
    std::cin >> output_filename;

    read_archive(first_filename, first_array, 5);
    read_archive(second_filename, second_array, 5);
    sort(first_array, second_array, output_array, 5, 5);
    write_archive(output_filename, output_array, 10);

    return 0;
}