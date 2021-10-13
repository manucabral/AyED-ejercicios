/**
 * Realice un programa que lea de un archivo datos de alumnos de un curso. A medida
 * que el archivo se va leyendo va insertando los registros en una lista. Liste finalmente
 * todos los nodos para verificar que la operación fue exitosa
 */

#include <stdio.h>
#include <iostream>

#define NOMBRE_ARCHIVO "alumnos.utn"

using namespace std;

struct Alumno
{
    int legajo;
    int codigoCarrera;
    char nombre[50];
    char apellido[50];
    char dni[10];
};

struct Nodo
{
    Alumno alumno;
    Nodo *siguiente;
};

void InsertarAlumno(Nodo *&raiz, Alumno nuevoAlumno)
{
    Nodo *nuevo = new Nodo();
    nuevo->alumno = nuevoAlumno;
    if (raiz)
    {
        nuevo->siguiente = raiz->siguiente;
        raiz->siguiente = nuevo;
    }
    else
    {
        nuevo->siguiente = nullptr;
        raiz = nuevo;
    }
    return;
}

void Leer(const char *nombre_archivo, Nodo *&raiz)
{
    FILE *archivo = NULL;
    Alumno alumno;
    if (archivo = fopen(nombre_archivo, "rb"))
    {
        fread(&alumno, sizeof(Alumno), 1, archivo);
        while (!feof(archivo))
        {
            InsertarAlumno(raiz, alumno);
            fread(&alumno, sizeof(Alumno), 1, archivo);
        }
        fclose(archivo);
    }
}

void Mostrar(Nodo *lista)
{
    while (lista)
    {
        cout << lista->alumno.nombre << " " << lista->alumno.apellido << " " << lista->alumno.legajo << endl;
        lista = lista->siguiente;
    }
}

int main(int argc, char const *argv[])
{
    Nodo *listaAlumnos = nullptr;
    Leer(NOMBRE_ARCHIVO, listaAlumnos);
    Mostrar(listaAlumnos);
    return 0;
}
