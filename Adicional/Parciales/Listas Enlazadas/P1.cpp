/**
 * Dado un codigo UNQUEUE de una cola de enteros.
 * a) Realice una declaración para el tipo de Nodo de forma que funcione el código presentado.
 * b) Codifique un subprograma que implemente QUEUE.
 */
#include <iostream>

// a) declaración del nodo.
struct Nodo{
    int info;
    Nodo *sgte;
};

// Codigo dado  por el enunciado.
bool unqueue(Nodo *&cola, int &e)
{
    Nodo *aux;
    if(cola)
    {
        aux = cola;
        cola = cola -> sgte;
        e = aux->info;
        delete aux;
        return true;
    }else
        return false;
}

// b) QUEUE.
void agregar(Nodo *&raiz, int numero)
{
    Nodo *aux = raiz;
    if(raiz)
    {
        while(aux->sgte)
            aux = aux->sgte;
        aux->sgte = new Nodo();
        aux->sgte->info = numero;
        aux->sgte->sgte = NULL;
    }else{
        raiz = new Nodo();
        raiz->info = numero;
        raiz->sgte = NULL;
    }
}
