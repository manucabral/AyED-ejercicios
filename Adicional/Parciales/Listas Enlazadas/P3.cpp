/**
 * Intercambie los nodos que tienen los numeros 42 y 54 de modo que la lista quede ordenada.
 * Puede utilizar un unico puntero auxiliar: Nodo *aux
 */

struct Nodo
{
    int info;
    Nodo *sgte;
};

// Prueba
int main(int argc, char const *argv[])
{
    Nodo *Lista = new Nodo();
    Lista->info = 37;
    Lista->sgte = new Nodo();
    Lista->sgte->info = 54;
    Lista->sgte->sgte = new Nodo();
    Lista->sgte->sgte->info = 43;
    Lista->sgte->sgte->sgte = new Nodo();
    Lista->sgte->sgte->sgte->info = 61;

    Nodo *aux = Lista->sgte->sgte;
    Lista->sgte->sgte = aux->sgte;
    aux->sgte = Lista->sgte;
    Lista->sgte = aux;

    return 0;
}
