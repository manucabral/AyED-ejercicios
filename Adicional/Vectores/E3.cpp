/*
    Se leen las letras de una palabra carácter a carácter. El último carácter que
    ingresa es la barra de dividir(/), que indica que la palabra ha finalizado.
    Escribir un programa que imprima la palabra en el orden que se ingresó y
    en sentido inverso (por ejemplo: pera arep, la palabra podrá tener hasta 20
    caracteres).
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    char arr[20], ch;
    int cont = 0;
    std::cin >> ch;

    while (ch != '/' || cont == 19)
    {
        arr[cont] = ch;
        std::cin >> ch;
        cont++;
    };

    std::cout << "Normal: " << arr << std::endl;
    std::cout << "Inverted: ";
    for (int i = cont - 1; i >= 0; i--)
        std::cout << arr[i];

    return 0;
}
