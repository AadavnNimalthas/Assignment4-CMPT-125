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
    ListNode* currentp = head;
    while (currentp != nullptr) {
        ListNode* temp = currentp;
        currentp = currentp->next;
        delete temp;
    }
    head = nullptr;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::appendListNode(double val) {
    ListNode* newNodep = new ListNode{val, nullptr};
    if (!head) {
        head = newNodep;
    } else {
        ListNode* currentp = head;
        while (currentp->next) {
            currentp = currentp->next;
        }
        currentp->next = newNodep;
    }
}

void LinkedList::displayList() const {
    ListNode* currentp = head;
    while (currentp) {
        cout << fixed << setprecision(1) << currentp->value << " ";
        currentp = currentp->next;
    }
    cout << endl;
}

int LinkedList::lengthList() const {
    int count = 0;
    ListNode* currentp = head;
    while (currentp) {
        ++count;
        currentp = currentp->next;
    }
    return count;
}

double LinkedList::removeListNodeN(int index) {
    if (index <= 0 || index > lengthList()) {
        cerr << "ERROR: There is no element with index " << index << endl;
        return 0.0;
    }

    ListNode* currentp = head;
    ListNode* prevp = nullptr;
    double val = 0.0;
    int count = 1;

    if (index == 1) {
        head = currentp->next;
        val = currentp->value;
        delete currentp;
        return val;
    }

    while (count < index) {
        prevp = currentp;
        currentp = currentp->next;
        ++count;
    }

    if (currentp) {
        prevp->next = currentp->next;
        val = currentp->value;
        delete currentp;
    }
    return val;
}

void LinkedList::swapNodeData(ListNode* node1, ListNode* node2) {
    double temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

void LinkedList::selectionSort() {
    for (ListNode* ip = head; ip && ip->next; ip = ip->next) {
        ListNode* maxNodep = i;
        for (ListNode* jp = ip->next; jp; jp = jp->next) {
            if (jp->value > maxNodep->value) {
                maxNodep = jp;
            }
        }
        swapNodeData(ip, maxNodep);
    }
}
