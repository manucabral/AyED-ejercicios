/*
    Diseñar un algoritmo para ordenar una agenda que contiene
    apellido y nombre, dirección, teléfono, código postal por la columna
    de código postal creciente.
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>

#define f(i, max) for (int i = 0; i < max; i++)

#define ROWS 2
#define COLUMNS 4
#define STR_LENGHT 24

void sort_asc(char arr[][COLUMNS][STR_LENGHT])
{
    char aux[STR_LENGHT];
    f(m, ROWS)
        f(n, COLUMNS) if (atoi(arr[n + 1][3]) < atoi(arr[n][3]))
            f(c, COLUMNS)
    {
        strcpy(aux, arr[n][c]);
        strcpy(arr[n][c], arr[n + 1][c]);
        strcpy(arr[n + 1][c], aux);
    }
}

void read(char arr[][4][STR_LENGHT], int m)
{
    std::cout << "Apellido y nombre: ";
    fflush(stdin);
    std::cin.getline(arr[m][0], STR_LENGHT);

    std::cout << "Dirección: ";
    fflush(stdin);
    std::cin.getline(arr[m][1], STR_LENGHT);

    std::cout << "Telefono: ";
    std::cin >> arr[m][2];

    std::cout << "Codigo postal: ";
    std::cin >> arr[m][3];
}

int main()
{
    char diary[ROWS][COLUMNS][STR_LENGHT];

    f(i, ROWS)
        read(diary, i);

    sort_asc(diary);

    f(m, ROWS)
        f(n, COLUMNS)
            std::cout << diary[m][n] << " ";

    return 0;
}
