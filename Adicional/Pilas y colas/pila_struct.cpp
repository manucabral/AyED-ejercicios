#include <iostream>

#define STACK_SIZE 5

typedef struct
{
    int index, arr[STACK_SIZE];
} Stack;

void init(Stack *s)
{
    s->index = -1;
}

int isEmpty(Stack *s)
{
    return s->index == -1;
}

int isFull(Stack *s)
{
    return s->index == STACK_SIZE - 1;
}

void push(Stack *s, int num)
{
    if (isFull(s))
        return;
    s->index++;
    s->arr[s->index] = num;
}

void display(Stack *s)
{
    if (isEmpty(s))
        return;
    for (int i = 0; i < s->index; i++)
        std::cout << s->arr[i] << " ";
}

void get(Stack *s, int position)
{
    if (isEmpty(s))
        return;
    if (position > s->index)
        return;
    std::cout << s->arr[position] << std::endl;
}

void pop(Stack *s)
{
    if (isEmpty(s))
        return;
}

int main(int argc, char const *argv[])
{
    Stack pila;
    init(&pila);
    push(&pila, 1);
    push(&pila, 2);
    display(&pila);
    pop(&pila);
    return 0;
}
