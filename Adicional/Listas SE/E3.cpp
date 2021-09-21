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

Node *last_node(Node *n)
{
    while (n && n->next)
        n = n->next;
    return n;
}

Node *next(Node *node)
{
    return node ? node->next : NULL;
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

Node *merge(Node *alpha, Node *beta)
{
    Node *merge_node = NULL;
    while (alpha)
    {
        push(merge_node, alpha->num);
        if (beta)
        {
            push(merge_node, beta->num);
            beta = beta->next;
        }
        alpha = alpha->next;
    }
    while (beta)
    {
        push(merge_node, beta->num);
        beta = beta->next;
    }
    return merge_node;
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
    Node *beta = NULL;
    Node *gamma = NULL;

    for (int i = 1; i < 4; i++)
        push(alpha, i);

    for (int i = 6; i < 12; i++)
        push(beta, i);

    display(alpha);
    display(beta);

    gamma = merge(alpha, beta);
    display(gamma);

    return 0;
}
