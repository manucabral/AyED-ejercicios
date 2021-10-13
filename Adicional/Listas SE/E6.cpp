/**
 * Modifique el programa anterior para que cada estructura alumno contenga una lista
 * de materias aprobadas
 */

#include <stdio.h>
#include <iostream>

#define ARCHIVO_ALUMNOS "alumnos.utn"
#define ARCHIVO_MATERIAS "materias.utn"

using namespace std;

struct Materia
{
    char nombre[50], fechaAprobado[11];
    int nota, libro, folio, legajo;
};

struct Alumno
{
    int legajo, codigoCarrera;
    char nombre[50], apellido[50], dni[10];
};

struct NodoMaterias
{
    Materia info;
    NodoMaterias *siguiente;
};

struct Nodo
{
    Alumno alumno;
    NodoMaterias *materia;
    Nodo *siguiente;
};

/*
void cargar(const char *nombre_archivo)
{
    FILE *archivo;
    Materia ma;
    if (archivo = fopen(nombre_archivo, "wb"))
    {
        strcpy(ma.nombre, "Matematica");
        strcpy(ma.fechaAprobado, "20211013");
        ma.folio = 1;
        ma.libro = 1;
        ma.nota = 6;
        ma.legajo = 34;
        fwrite(&ma, sizeof(Materia), 1, archivo);
        strcpy(ma.nombre, "Quimica");
        strcpy(ma.fechaAprobado, "20211013");
        ma.folio = 2;
        ma.libro = 2;
        ma.nota = 7;
        ma.legajo = 65;
        fwrite(&ma, sizeof(Materia), 1, archivo);
        fclose(archivo);
    }
}
*/

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

Nodo *ObtenerAlumnoPorLegajo(Nodo *raiz, int legajo)
{
    Nodo *aux = raiz;
    while (aux && aux->alumno.legajo != legajo)
        aux = raiz->siguiente;
    return aux;
}

void InsertarMateria(NodoMaterias *&raiz, Materia nuevaMateria)
{
    NodoMaterias *nuevo = new NodoMaterias();
    nuevo->info = nuevaMateria;
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
}

void LeerMaterias(const char *nombre_archivo, Nodo *&raiz)
{
    FILE *archivo = nullptr;
    Nodo *alumno = nullptr;
    Materia materia;
    if (archivo = fopen(nombre_archivo, "rb"))
    {
        while (fread(&materia, sizeof(materia), 1, archivo))
        {
            alumno = ObtenerAlumnoPorLegajo(raiz, materia.legajo);
            if (alumno)
                InsertarMateria(alumno->materia, materia);
        }
    }
}

void LeerAlumnos(const char *nombre_archivo, Nodo *&raiz)
{
    FILE *archivo = nullptr;
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
        cout << lista->alumno.nombre << " " << lista->alumno.apellido << " " << lista->alumno.legajo;
        while (lista->materia)
        {
            cout << "materia: " << lista->materia->info.nombre << endl;
            lista->materia = lista->materia->siguiente;
        }
        lista = lista->siguiente;
    }
}

int main(int argc, char const *argv[])
{
    Nodo *listaAlumnos = nullptr;
    LeerAlumnos(ARCHIVO_ALUMNOS, listaAlumnos);
    LeerMaterias(ARCHIVO_MATERIAS, listaAlumnos);
    Mostrar(listaAlumnos);
    return 0;
}
