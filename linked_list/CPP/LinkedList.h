
#ifndef SINGLELINKLIST_LINKEDLIST_H
#define SINGLELINKLIST_LINKEDLIST_H

#include <iostream>
class LinkedList;
class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode() : data(0), next(nullptr) {};

    explicit ListNode(int a) : data(a), next(nullptr) {};
    friend class LinkedList;
};
class LinkedList{
private:

    ListNode *first;
public:
    LinkedList() : first(nullptr) {};

    void printList();

    void pushFront(int x);

    void pushEnd(int x);

    void delet(int x);

    void clear();

    void reverse();



};
#endif //SINGLELINKLIST_LINKEDLIST_H
