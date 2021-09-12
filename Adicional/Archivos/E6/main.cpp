/**
 * Escriba un programa que guarde en un archivo tres alumnos y luego los liste. 
 * El alumno es una estructura que contiene:
 * Nombre
 * Apellido
 * Legajo
 * DNI
 * Fecha de nacimiento
 */

#include <iostream>
#include <stdlib.h>
#include <conio.h>

#define SIZE 3

using namespace std;

typedef struct
{
    int dni, legajo;
    char nombre[24], apellido[24], fecha_nacimiento[24];
} Alumno;

void ingresarAlumno(Alumno &alumno)
{
    std::cout << "Nombre:";
    fflush(stdin);
    std::cin >> alumno.nombre;

    std::cout << "Apellido:";
    fflush(stdin);
    std::cin >> alumno.apellido;

    std::cout << "Fecha de nacimiento:";
    fflush(stdin);
    std::cin >> alumno.fecha_nacimiento;

    std::cout << "DNI: ";
    std::cin >> alumno.dni;

    std::cout << "Legajo:";
    std::cin >> alumno.legajo;
}

void guardarAlumno(char *filename, Alumno &alumno)
{
    FILE *file;
    if (file = fopen(filename, "ab"))
    {
        fwrite(&alumno, sizeof(Alumno), 1, file);
        std::cout << "Alumno guardado" << std::endl;
        fclose(file);
    }
}

void procesoIngresar(char *filename, Alumno *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        ingresarAlumno(arr[i]);
        guardarAlumno(filename, arr[i]);
    }
}

void mostrarAlumno(Alumno &alumno)
{
    std::cout << std::endl;
    std::cout << alumno.nombre << " ";
    std::cout << alumno.apellido << " ";
    std::cout << alumno.fecha_nacimiento << " ";
    std::cout << alumno.dni << " ";
    std::cout << alumno.legajo << " ";
}

void procesoListar(char *filename)
{
    FILE *file;
    Alumno alumno;
    if (file = fopen(filename, "rb"))
    {
        fread(&alumno, sizeof(Alumno), 1, file);
        while (!feof(file))
        {
            mostrarAlumno(alumno);
            fread(&alumno, sizeof(alumno), 1, file);
        }
        fclose(file);
    }
}

int main(int argc, char const *argv[])
{
    Alumno arr[SIZE];
    procesoIngresar("alumnos", arr, SIZE);
    procesoListar("alumnos");
    return 0;
}
