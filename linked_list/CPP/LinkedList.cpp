#include <iostream>
#include "LinkedList.h"

using namespace std;

// print all elements in list
void LinkedList::printList() {
    if (first == nullptr) {
        // point to null -> no data in list
        cout << "List is empty.\n";
        return;
    }
    ListNode *current = this->first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// add element at start
void LinkedList::pushFront(int x) {
    auto *newNode = new ListNode(x);
    newNode->next = this->first;
    this->first = newNode;
}

void LinkedList::pushEnd(int x) {
    auto *newNode = new ListNode(x);
    if (this->first == nullptr) {
        this->first = newNode;
        return;
    }
    ListNode *cur = this->first;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void LinkedList::delet(int x) {
    ListNode *cur = this->first, *pre = nullptr;
    while (cur != nullptr && cur->data != x) {
        pre = cur;
        cur = cur->next;
    }
    if (cur == nullptr) {
        cout << "There is no " << x << " in the list" << endl;
    } else if (cur == this->first) {
        this->first = cur->next;
        delete cur;
        // after del a pointer, avoiding a bug, let cur point to null.
    } else {
        pre->next = cur->next;
        delete cur;
        //cur = 0;
    }

}

void LinkedList::clear() {
    while (this->first != nullptr) {
        ListNode *cur = first;
        first = first->next;
        delete cur;
        //cur = 0;
    }

}

void LinkedList::reverse() {
    if (first == nullptr || first->next == nullptr) {
        return;
    }
    ListNode *previous = nullptr;
    ListNode *current = this->first;
    ListNode *preceding = this->first->next;
    while (preceding != nullptr) {
        current->next = previous;
        previous = current;
        current = preceding;
        preceding = preceding->next;
    }
    // last node
    current->next = previous;
    first = current;

}
