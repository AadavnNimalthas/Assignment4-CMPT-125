/*
    Aadavn Nimalthas
    April 5th, 2025
    
    LinkedList.cpp - A C++ class that implements a linked list

*/


#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::appendListNode(double val) {
    ListNode* newNode = new ListNode{val, nullptr};
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::displayList() const {
    ListNode* current = head;
    while (current) {
        cout << fixed << setprecision(1) << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int LinkedList::lengthList() const {
    int count = 0;
    ListNode* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

double LinkedList::removeListNodeN(int index) {
    if (index <= 0 || index > lengthList()) {
        cerr << "ERROR: There is no element with index " << index << endl;
        return 0.0;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;
    double val = 0.0;
    int count = 1;

    if (index == 1) {
        head = current->next;
        val = current->value;
        delete current;
        return val;
    }

    while (count < index) {
        prev = current;
        current = current->next;
        ++count;
    }

    if (current) {
        prev->next = current->next;
        val = current->value;
        delete current;
    }
    return val;
}

void LinkedList::swapNodeData(ListNode* node1, ListNode* node2) {
    double temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

void LinkedList::selectionSort() {
    for (ListNode* i = head; i && i->next; i = i->next) {
        ListNode* maxNode = i;
        for (ListNode* j = i->next; j; j = j->next) {
            if (j->value > maxNode->value) {
                maxNode = j;
            }
        }
        swapNodeData(i, maxNode);
    }
}
