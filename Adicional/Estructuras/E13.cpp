/*
    Se desea obtener cierta información correspondiente a los empleados de
    una empresa. La misma tiene 25 empleados y los datos que tiene son: DNI,
    nombre, estado civil, dirección, teléfono, sexo y edad. Se pide:
    − Listado de los empleados que estén próximos a jubilarse ordenados
    alfabéticamente.
    − Edad promedio de los empleados.
    - Todos los datos de un empleado. (Al seleccionar esta opción, el
    sistema debe solicitar el DNI)
    − El usuario deberá poder elegir la operación a realizar.
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define f(i, max) for (int i = 0; i < max; i++)

typedef struct
{
    int dni, edad, telefono;
    char nombre[24], estado_civil[24], direccion[24], sexo[24];
} Empleado;

void mostrarMenu()
{
    std::cout << std::endl
              << "a. Ingresar empleado." << std::endl;
    std::cout << "b. Listado de empleados a jubilarse." << std::endl;
    std::cout << "c. Edad promedio de los empleados." << std::endl;
    std::cout << "d. Datos de un empleado." << std::endl;
    std::cout << "esc. Cerrar programa." << std::endl;
}

void inicializarDatos(Empleado *arr, int size)
{
    f(i, size) arr[i].dni = -1;
}

void ingresarEmpleado(Empleado &empleado)
{
    std::cout << "Nombre:";
    fflush(stdin);
    std::cin >> empleado.nombre;

    std::cout << "Direccion:";
    fflush(stdin);
    std::cin >> empleado.direccion;

    std::cout << "Estado civil:";
    fflush(stdin);
    std::cin >> empleado.estado_civil;

    std::cout << "Sexo:";
    fflush(stdin);
    std::cin >> empleado.sexo;

    std::cout << "DNI:";
    std::cin >> empleado.dni;

    std::cout << "Edad:";
    std::cin >> empleado.edad;

    std::cout << "Telefono:";
    std::cin >> empleado.telefono;
}

int sumarEdades(Empleado *arr, int size)
{
    int sumatoria = 0;
    f(i, size) sumatoria += arr[i].edad;
    return sumatoria;
}

void mostrarEmpleado(Empleado &empleado)
{
    std::cout << "Nombre: " << empleado.nombre << std::endl;
    std::cout << "Estado civil: " << empleado.estado_civil << std::endl;
    std::cout << "Direccion: " << empleado.direccion << std::endl;
    std::cout << "Sexo: " << empleado.sexo << std::endl;
    std::cout << "DNI: " << empleado.dni << std::endl;
    std::cout << "Edad: " << empleado.edad << std::endl;
    std::cout << "Telefono: " << empleado.telefono << std::endl
              << std::endl;
}

int ultimoElemento(Empleado *arr, int size)
{
    f(i, size) if (arr[i].dni == -1) return i;
    return 0;
}

int procesarIngreso(Empleado *arr, int size)
{
    if (ultimoElemento(arr, size) == -1)
    {
        std::cout << "Error: la lista esta llena.";
        return 0;
    }

    std::cout << std::endl
              << "INGRESO DE EMPLEADO" << std::endl;
    ingresarEmpleado(arr[ultimoElemento(arr, size)]);
    return 1;
}

void swap(Empleado *p1, Empleado *p2)
{
    Empleado temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int procesoMostrarEmpleadosJubilados(Empleado *arr, int size)
{
    if (ultimoElemento(arr, size) == 0)
    {
        std::cout << "Error: no hay empleados en la lista";
        return 0;
    }

    Empleado ordenados[size];

    f(i, ultimoElemento(arr, size))
        ordenados[i] = arr[i];

    f(i, ultimoElemento(arr, size))
        f(j, ultimoElemento(arr, size) - 1) if (strcmp(ordenados[j].nombre, ordenados[j + 1].nombre) > 0)
            swap(&ordenados[j], &ordenados[j + 1]);

    std::cout << std::endl
              << "LISTA DE EMPLEADOS:" << std::endl;
    f(i, ultimoElemento(arr, size)) if (ordenados[i].edad > 60)
        mostrarEmpleado(ordenados[i]);

    return 1;
}

int procesoEdadPromedio(Empleado *arr, int size)
{
    if (ultimoElemento(arr, size) == 0)
    {
        std::cout << "Error: no hay empleados en la lista";
        return 0;
    }

    std::cout << "Promedio: " << sumarEdades(arr, ultimoElemento(arr, size)) / ultimoElemento(arr, size) << std::endl;

    return 1;
}

int procesoObtenerEmpleado(Empleado *arr, int size)
{
    int dni = 0, encontrado = -1;
    std::cout << "Ingresa DNI del empleado: ";
    std::cin >> dni;

    f(i, size) if (arr[i].dni == dni)
        encontrado = i;

    if (encontrado == -1)
    {
        std::cout << "Error: no se encontro al empleado con dni: " << dni << std::endl;
        return 0;
    }

    mostrarEmpleado(arr[encontrado]);
    return 1;
}

int main(int argc, char const *argv[])
{
    Empleado arr[3];
    int length = sizeof arr / sizeof arr[0], opcion = 0;

    inicializarDatos(arr, length);

    do
    {
        mostrarMenu();
        opcion = (int)getch();

        if (opcion == 97 || opcion == 65)
            procesarIngreso(arr, length);

        if (opcion == 98 || opcion == 66)
            procesoMostrarEmpleadosJubilados(arr, length);

        if (opcion == 99 || opcion == 67)
            procesoEdadPromedio(arr, length);

        if (opcion == 100 || opcion == 68)
            procesoObtenerEmpleado(arr, length);

    } while (opcion != 27);
    return 0;
}
