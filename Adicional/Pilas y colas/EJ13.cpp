/*
    Dado un vector de 20 posiciones (números enteros), genere un
    programa que permita realizar las siguientes operaciones.
        − Ingresar un elemento al final de la cola (primera posición libre
        del vector), comprobando antes del ingreso que existe una 
        posición libre, sino colocar un mensaje de aviso.
        − Sacar el elemento que se encuentre en la primera posición (si
        no lo hubiera colocar un mensaje de aviso), corriendo luego los
        demás en la cola una posición hacia delante.
        − Listar en cualquier momento el contenido de la cola del primero
        al último.
*/

#include <iostream>
#define SIZE 20

/**
 * @brief Sets the value of all elements from a array to -1
 * 
 * @param arr Target array.
 * @param size Size of array.
 */
void init(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = -1;
}

/**
 * @brief Remove an element from an simple array.
 * 
 * @param arr Target array.
 * @param size Size of array.
 * @param index Target index.
 */
void pop(int *arr, int size, int index)
{
    if (arr[index] == -1)
    {
        std::cout << "No hay un elemento en esa posicion" << std::endl;
        return;
    }

    arr[index] = -1;
    for (int i = index; i < size; i++)
        if (i + 1 < SIZE){
            arr[i] = arr[i + 1];
            arr[i + 1] = -1;
        }

}

/**
 * @brief Get the Last Index of an array.
 * 
 * @param arr Target array.
 * @param size Size of the array.
 * @return int last element index.
 */
int getLastIndex(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == -1)
            return i;
    return -1;
}

/**
 * @brief Display a simple array.
 * 
 * @param arr Target array.
 * @param size Size of array.
 */
void display(int *arr, int size){
    for(int i=0; i<size;i++)
        std::cout << arr[i] << " ";
}

/**
 * @brief Add an element to the array.
 * 
 * @param arr Target array.
 * @param size Size of array.
 * @param num Value to add.
 */
void push(int *arr, int size, int num)
{
    int index = getLastIndex(arr, size);
    if (index != -1)
        arr[index] = num;
    else
        std::cout << "Estamos llenos!" << std::endl;
}

int main(int argc, char const *argv[])
{
    int arr[SIZE], num = -1;

    init(arr, SIZE);

    // agregando elementos..
    for(int i=0; i<SIZE; i++)
        push(arr, SIZE, i);
    display(arr, SIZE);

    // eliminando elemento posicion 0
    pop(arr, SIZE, 0);
    std::cout << std::endl;
    display(arr, SIZE);

    return 0;
}
