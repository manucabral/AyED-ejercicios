/**
    7) Declare los nodos necesarios para implementar una lista de caracteres que contenga una sublista de números enteros. (1 pto).
    8) Implemente un subprograma que reciba un nro. y busque si existe. En caso que exista debe devover el caracter de la lista a la que
    pertenece. Si no existe puede devolver el carácter ‘0’ (3 ptos).
    
    char buscarNro(NodoLetra *lista, int nro); 

 */

#include <iostream>

struct NodoNumero
{
    int numero;
    NodoNumero *siguiente;
};

struct NodoCaracter
{
    char caracter;
    NodoCaracter *siguiente;
    NodoNumero *listaNumeros;
};

NodoCaracter *agregarCaracter(NodoCaracter *&raiz, char caracter)
{
    NodoCaracter *nuevo = new NodoCaracter();
    nuevo->caracter = caracter;
    if (raiz)
    {
        nuevo->siguiente = raiz->siguiente;
        raiz->siguiente = nuevo;
    }
    else
    {
        nuevo->siguiente = raiz;
        raiz = nuevo;
    }
    return nuevo;
}

char buscarNumero(NodoCaracter *&raiz, int numero)
{
    NodoCaracter *aux = raiz;
    while (aux)
    {
        while (aux->listaNumeros)
        {
            if (aux->listaNumeros->numero == numero)
                return aux->caracter;
            aux->listaNumeros = aux->listaNumeros->siguiente;
        }
        aux = aux->siguiente;
    }
    return '0';
}

void agregarNumero(NodoNumero *&raiz, int numero)
{
    NodoNumero *nuevo = new NodoNumero();
    nuevo->numero = numero;
    if (raiz)
    {
        nuevo->siguiente = raiz->siguiente;
        raiz->siguiente = nuevo;
    }
    else
    {
        nuevo->siguiente = raiz;
        raiz = nuevo;
    }
}

int main(int argc, char const *argv[])
{
    NodoCaracter *listaCaracteres = NULL, *nuevo = NULL;

    nuevo = agregarCaracter(listaCaracteres, 'a');
    agregarNumero(nuevo->listaNumeros, 10);
    agregarNumero(nuevo->listaNumeros, 20);

    nuevo = agregarCaracter(listaCaracteres, 'b');
    agregarNumero(nuevo->listaNumeros, 50);
    agregarNumero(nuevo->listaNumeros, 30);

    std::cout << buscarNumero(listaCaracteres, 20);
    return 0;
}
