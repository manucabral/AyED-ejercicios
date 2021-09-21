/**
 * Haga un procedimiento que reciba los mismos parámetros del punto 1 pero devuelva
 * una tercer lista con el contenido de ambas intercalado (es decir un nodo de la lista 1
 * seguido por un nodo de la lista 2, si una lista se finaliza primero quedan todos los
 * demás nodos de la otra lista consecutivos).
 */

#include <iostream>

using namespace std;

struct Node
{
    int num;
    Node *next;
};

Node *last_node(Node *node)
{
    while (node && node->next)
        node = node->next;
    return node;
}

Node *next(Node *node)
{
    return node ? node->next : NULL;
}

int length(Node *node)
{
    int c = 0;
    while (node)
    {
        c++;
        node = next(node);
    }
    return c;
}

void push(Node *&root, int value)
{
    Node *new_node = new Node();
    Node *last = NULL;

    new_node->num = value;
    new_node->next = NULL;

    if (root)
    {
        last = last_node(root);
        last->next = new_node;
    }
    else
        root = new_node;
}

Node *swap(Node *a, Node *b)
{
    Node *tmp = b->next;
    b->next = a;
    a->next = tmp;
    return b;
}

void sort(Node *&node)
{
    for (Node *i = node; i->next; i = i->next)
        for (Node *j = i->next; j; j = j->next)
            if (i->num > j->num)
                swap(i->num, j->num);
}

void display(Node *node)
{
    cout << "[";
    while (node)
    {
        cout << node->num;
        node = next(node);
        node ? cout << ", " : cout << "]";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Node *alpha = NULL;

    push(alpha, 5);
    push(alpha, 4);
    push(alpha, 104);
    push(alpha, 8);

    sort(alpha);
    display(alpha);
    return 0;
}
