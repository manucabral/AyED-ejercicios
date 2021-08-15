/*
    Dada una matriz de MxN con datos de clientes (apellido y
    nombre, dirección, edad y saldos) se pide ordenarla por saldos.
    Considere que cada dato es una columna de la tabla y cada cliente es
    una fila.
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>

#define f(i, max) for (int i = 0; i < max; i++)

#define ROWS 3
#define COLUMNS 4
#define STR_LENGHT 24

void sort(char arr[ROWS][COLUMNS][STR_LENGHT])
{
    char aux[STR_LENGHT];
    f(m, ROWS)
        f(n, COLUMNS - m)
            if (atoi(arr[n][3]) < atoi(arr[n + 1][3]))
                f(c, COLUMNS)
                {
                    strcpy(aux, arr[n][c]);
                    strcpy(arr[n][c], arr[n + 1][c]);
                    strcpy(arr[n + 1][c], aux);
                }
}

void read(char arr[ROWS][COLUMNS][STR_LENGHT])
{
    f(person, ROWS)
    {
        std::cout << "Apellido y nombre: ";
        fflush(stdin);
        std::cin.getline(arr[person][0], STR_LENGHT);

        std::cout << "Dirección ";
        fflush(stdin);
        std::cin.getline(arr[person][1], STR_LENGHT);

        std::cout << "Edad: ";
        std::cin >> arr[person][2];

        std::cout << "Saldo: ";
        std::cin >> arr[person][3];
    }
}

int main(int argc, char const *argv[])
{
    char data[ROWS][COLUMNS][STR_LENGHT];
    
    memset(data, 0, sizeof data);
    read(data);
    sort(data);

    f(m, ROWS)
    {
        std::cout << std::endl;
        f(n, COLUMNS)
            std::cout << data[m][n] << " ";
    }

    return 0;
}
