/**
 * Escriba un programa que, utilizando aritmética de punteros, tome 5 elementos enteros en 
 * un array y luego los muestre en pantalla
 */

#include <iostream>

int main(int argc, char const *argv[])
{
    int nums[5];
    int *p = nums;

    for (int i = 0; i < 5; i++)
        std::cin >> *(p+i);

    for (int i = 0; i < 5; i++)
        std::cout << *p++ << " ";
    
    return 0;
}
