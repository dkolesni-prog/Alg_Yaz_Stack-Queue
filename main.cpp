#include <iostream>

#include <assert.h>

struct Node{
    Node* next;
    int data;
};

struct Stack{
    Node* head;
};

void constructor (Stack* stack){
    stack->head = NULL;
}

void push (Stack* stack, int data) {
    Node *element = new Node;
    element->data = data;
    if (stack->head == nullptr) {
        stack->head = element;
        element->next = nullptr;
    } else {
        element->next = stack->head;
        stack->head = element;
    }
}

int pop (Stack* stack){
    assert( stack->head != NULL);
    Node* to_delete = stack->head;
    int result = stack->head->data;
    stack->head = stack->head->next;
    delete to_delete;
    return result;
}

void destructor (Stack* stack){
    while (!(stack->head == NULL)){
        Node* tmp = stack->head;
        stack->head = stack->head->next;
        delete tmp;
    }
}

void print (Stack* stack){
    Node* end = stack->head;
    while (!(stack->head == NULL)){
        std::cout << stack->head->data << std::endl;
        stack->head = stack->head->next;
    }
    stack->head = end;
}

int counter (const Stack* stack){
    Node* tmp = stack->head;
    int counter = 0;
    while ( !(tmp == NULL)){
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

//-------------------------------------------------------

 struct Queue{
    Node* first;
    Node* last;
};
void constructor (Queue* queue ){
    queue->first = NULL;
    queue->last = NULL;
}

void destructor (Queue* queue){
    while ( queue->last != NULL){
        if (queue->last->next == NULL){
            delete queue->first;
            queue->first = NULL;
            queue->last = NULL;
        }
        else {
            Node* tmp = queue->first;
            queue->first = queue->first->next;
            delete tmp;
        }
    }
}

void push (Queue* queue, int value){
    Node* node  = new Node;
    node->data = value;
    if (queue->first == NULL){
        queue->first = node;
        queue->last = node;
        node->next = NULL;
    }
    else {
        queue->last->next = node;
        queue->last = node;
    }
}

int pop (Queue* queue){
    assert( queue->last != NULL);
    int result = queue->first->data;
    Node* tmp = queue->first;
    queue->first = queue->first->next;
    delete tmp;
    if (queue->first == NULL){
        queue->last = NULL;
    }
    return result;
}

void print (Queue* queue){
    Node* tmp = queue->first;
    while ( tmp != NULL){
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

int counter (Queue* queue){
    Node* tmp = queue->first;
    int counter = 0;
    while ( tmp != NULL){
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

int main() {
    Stack test;
    constructor (&test);
    push(&test, 7);
    push(&test, 8);
    push(&test, 9);
    push(&test, 10);
    push(&test, 11);
    int result = pop (&test);
    print (&test);
    std::cout <<  counter (&test) << std::endl;
    destructor (&test);
    return 0;
}
