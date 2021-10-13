#include <stdio.h>
#include <iostream>
#include <cstring>

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
        cout << lista->alumno.nombre << " " << lista->alumno.apellido << endl;
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
