/*
    Aadavn Nimalthas
    April 5th, 2025

    Stack.cpp - A C++ class that implements a stack
*/

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {}

Stack::~Stack() {}

int Stack::height() const {
    return list.lengthList();
}

void Stack::push(double val) {
    list.appendListNode(val);
}

double Stack::pop() {
    if (list.isEmpty()) {
        return 0.0;
    }
    return list.removeListNodeN(list.lengthList());
}

bool Stack::isEmpty() const {
    return list.isEmpty();
}

void Stack::displayStack() const {
    list.displayList();
}

void Stack::sortStack() {
    list.selectionSort();
}
