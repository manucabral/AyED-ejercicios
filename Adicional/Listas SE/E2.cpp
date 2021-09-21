/**
 * Realice un procedimiento o función que al recibir dos listas como parámetro, 
 * devuelva una tercer lista que concatene las mismas
 * 
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

Node *merge(Node *alpha, Node *beta){
    Node *auxiliary = alpha;
    Node *last = last_node(auxiliary);
    last -> next = beta;
    return auxiliary;
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

    for (int i = 6; i < 9; i++)
        push(beta, i);

    display(alpha);
    display(beta);

    gamma = merge(alpha, beta);
    display(gamma);
    
    return 0;
}
