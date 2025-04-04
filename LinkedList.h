#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode {
    double value;
    ListNode* next;
};

class LinkedList {
private:
    ListNode* head;
    void swapNodeData(ListNode* valueNodeA, ListNode* valueNodeB);
    //Exchanges the data held in two specified nodes.
    //Pointers to the next node are not touched


public:
    LinkedList();
    // List constructor
    ~LinkedList();
    // List Destructor

    bool isEmpty() const;
    void displayList() const;
    // prints the data in each node of the linked list to the screen
    int lengthList() const;
    // counts the nodes in the linked list
    double removeListNodeN(int N);
    // removes the nodes at location N from the list
    // the nodes are counted N = 1, 2, 3 ...
    // node N=1 is connectd to the head of the list
    // You can modify the C function removeListNode
    // to find the Nth node instead of the node
    // containing a particular value
    void appendListNode(double val);
    // adds a new node to the end of the list
    ListNode* getHead() const;
    void selectionSort();

};

#endif // LINKEDLIST_H