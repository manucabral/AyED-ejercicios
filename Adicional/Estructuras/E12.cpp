/*
    Se leen datos de notas obtenidas por los alumnos de una cátedra y se
    desea informar
    − el promedio de las notas obtenidas por los alumnos
    − el nombre, tipo y número de documento y número de legajo
    (padrón) de los alumnos que hayan aprobado con nota igual o mayor
    que siete.
    La secuencia finaliza con el alumno Wolf Roberto que debe ser
    procesado
*/

#include <iostream>

#define f(i, max) for (int i = 0; i < max; i++)

typedef struct
{
    int num_documento, legajo, nota;
    char nombre[24], tipo_documento[24];
} Alumno;

void ingresarAlumno(Alumno &a)
{
    std::cin >> a.num_documento;
    std::cin >> a.legajo;
    std::cin >> a.nota;
    std::cin >> a.nombre;
    std::cin >> a.tipo_documento;
}

void mostrarAlumno(Alumno &a)
{
    std::cout << "Nombre: " << a.nombre << std::endl;
    std::cout << "Tipo documento" << a.tipo_documento << std::endl;
    std::cout << "Numero documento: " << a.num_documento << std::endl;
    std::cout << "Legajo: " << a.legajo << std::endl;
    std::cout << "Nota: " << a.nota << std::endl;
}

int obtenerPromedio(Alumno *arr, int size)
{
    int sum = 0;
    f(i, size) sum += arr[i].nota;
    return sum / size;
}

void mostrarAlumnosAprobados(Alumno *arr, int size)
{
    std::cout << "ALUMNOS APROBADOS" << std::endl;
    f(i, size) if (arr[i].nota >= 7)
        mostrarAlumno(arr[i]);
}

void inicializar(Alumno *arr, int size)
{
    f(i, size)
    {
        std::cout << "Alumno " << i << std::endl;
        ingresarAlumno(arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    Alumno arr[3];
    int length = sizeof arr / sizeof arr[0];

    inicializar(arr, length);
    std::cout << "Promedio de notas: " << obtenerPromedio(arr, length) << std::endl;
    mostrarAlumnosAprobados(arr, length);

    return 0;
}
