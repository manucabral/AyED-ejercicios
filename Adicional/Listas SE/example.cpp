#include <iostream>

struct Node{
    int num;
    Node *next;
};

Node *last_node(Node *n){
    while(n && n -> next) n = n -> next;
    return n;
}

// *& is a reference to a pointer
// ** is a pointer to a pointer
void push(Node *&root, int num){
    Node *aux;
    if(root){
        std::cout << "Inserting new node.." << std::endl;
        aux = last_node(root);
        aux -> next = new Node();
        aux = aux -> next;
        aux -> num = num;
        aux -> next = NULL;
    }else{
        std::cout << "Creating root node.." << std::endl;
        root = new Node();
        root -> num = num;
        root -> next = NULL;
    }
}

void display(Node *&root){
    Node *aux = root;
    while(aux){
        std::cout << "Num: " << aux -> num << " Next: " << aux -> next << std::endl;
        aux = aux -> next;
    }
}

void clear(Node *&root){
    Node *aux;
    Node *previous;

    while(root){
        previous = NULL;
        aux = root;
        while(aux && aux -> next){
            previous = aux;
            aux = aux -> next;
        }
        if(aux){
            delete aux;
            if(previous)
                previous -> next = NULL;
            else
                root = NULL;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    push(root, 1);
    push(root, 2);
    push(root, 225);
    display(root);
    clear(root);
    return 0;
}
