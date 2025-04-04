#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

class Stack {
private:
    LinkedList list;

public:
    Stack();
    ~Stack();
    int height() const;
    void push(double val);
    double pop();
    bool isEmpty() const;
    void displayStack() const;
    void sortStack();
};

#endif // STACK_H
