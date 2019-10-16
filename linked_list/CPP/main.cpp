
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;     // 建立LinkedList的object
    list.printList();    // 目前list是空的
    list.delet(4);      // list是空的, 沒有4
    list.pushEnd(5);   // list: 5
    list.pushEnd(3);   // list: 5 3
    list.pushFront(9);  // list: 9 5 3
    list.printList();    // 印出:  9 5 3
    list.pushEnd(4);   // list: 9 5 3 4
    list.delet(9);      // list: 5 3 4
    list.printList();    // 印出:  5 3 4
    list.pushFront(8);  // list: 8 5 3 4
    list.printList();    // 印出:  8 5 3 4
    list.reverse();      // list: 4 3 5 8
    list.printList();    // 印出:  4 3 5 8
    list.clear();        // 清空list
    list.printList();    // 印出: List is empty.
    return 0;
}
