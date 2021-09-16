/**
 * Utilizando las funciones de ListasSE provistas en clase 
 * un programa que permita realizar usuario:
 * - Insertar un elemento ordenadamente en la lista
 * - Buscar el mayor elemento
 * - Calcular el promedio de la lista
 */

#include <iostream>

using namespace std;

struct Node{
    int num;
    Node *next;
};

/**
 * @brief Get the last node
 * 
 * @param n Value to push
 * @return Node* Last node pointer
 */
Node *last_node(Node *n){
    while(n && n -> next) n = n -> next;
    return n;
}

/**
 * @brief Get the max node
 * 
 * @param root Root node
 * @return Node* Node pointer with max number
 */
Node *get_max_node(Node *&root){
    Node *aux = root;
    Node *target = root;
    while(aux){
        target = target -> num < aux -> num? aux : target;
        aux = aux -> next;
    }
    return target;
}

/**
 * @brief Get average
 * 
 * @param root Root node
 * @return float Average
 */
float get_average(Node *&root){
    Node *aux = root;
    float sum = 0;
    int counter = 0;
    while(aux){
        sum += aux -> num;
        aux = aux -> next;
        counter++;
    }
    return counter > 0 ? sum / counter : 0;
}

/**
 * @brief Creates a new node and push it a number
 * 
 * @param root Root node, if not exists is created
 * @param num Number to push
 */
void push(Node *&root, int num){
    Node *aux;
    if(root){
        aux = last_node(root);
        aux -> next = new Node();
        aux = aux -> next;
        aux -> num = num;
        aux -> next = NULL;
    }else{
        root = new Node();
        root -> num = num;
        root -> next = NULL;
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    Node *max = NULL;
    float average = 0;

    push(root, 50);
    push(root, 50);
    push(root, 70);

    max = get_max_node(root);
    cout << "Max element: " << max -> num << " Node: " << max << endl;

    average = get_average(root);
    cout << "Average: " << average;

    return 0;
}
