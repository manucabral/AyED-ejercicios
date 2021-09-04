/**
 * Modifique la solución anterior para mostrar los números en orden inverso
 */

#include <iostream>

int main(int argc, char const *argv[])
{
    int nums[5];
    int *p = nums;

    for (int i = 0; i < 5; i++)
        std::cin >> *(p+i);

    for (int i = 4; i >= 0; i--)
        std::cout << *(p+i) << " ";
    
    return 0;
}
