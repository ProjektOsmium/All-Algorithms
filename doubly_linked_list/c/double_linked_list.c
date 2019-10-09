/*
Program to implement a Doubly Linked List and perform the following operations
1. Insert at the front of the list
2. Delete at a specied position
3. Search for an element
4. Display the list
*/

#include <stdio.h>
#include <stdlib.h>

// Node of the linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
    Node *head;
    int number_of_nodes;
} List;

// initializes a linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at the beginning of the List
void insert_front(List* dll, int data);

// Deletes the node at position pos. No operation if pos is out of range.
void position_delete(List* dll, int pos);

// Return index of key in the list(0-based). Return -1 if not found
int search_list(List* dll, int key);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* dll);

// Deallocates resources held by the list
void destroy_list(List* dll);

int main() {
    List* dll = initialize_list();
    int ele, choice, pos;
    
    do {
        scanf("%d", &choice);

        switch(choice) {
            // Insert at beginning
            case 1:
                scanf("%d", &ele);
                insert_front(dll, ele);
                break;

            // Delete at position
            case 2:
                scanf("%d", &pos);
                position_delete(dll, pos);
                break;

            // Search for element
            case 3:
                scanf("%d", &ele);
                pos = search_list(dll, ele);
                printf("%d\n", pos);
                break;

            // Print entire list
            case 4:
                display(dll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(dll);
    return 0;
}

List* initialize_list() {
    List *temp = (List*)malloc(sizeof(List));
    temp->head = NULL;
    temp->number_of_nodes = 0;
    return temp;
}

Node* create_node(int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev  = temp->next = NULL;
    return temp;
}

void insert_front(List* dll, int data) {
    Node *temp = create_node(data);
    if(dll->head != NULL)
    {
        dll->head->prev = temp;
        temp->next = dll->head;
        dll->head = temp;
        return;
    }
    dll->head = temp;
}

void position_delete(List* dll, int pos) {
    int count=0;
    Node *temp = dll->head;
    if(pos < 0 || dll->head == NULL || (pos>0 && dll->head == NULL))
    {
        return;
    }
    else if(pos == 0)
    {
        if(temp->next == NULL)
        {
            dll->head = NULL ;
            free(temp);
        }
        else
        {
            dll->head = temp->next;
            temp->next->prev = NULL;
            temp->prev = NULL;
            free(temp);
        }
    }
    else if(pos > 0)
    {
        while(temp->next != NULL && pos!=count)
        {
            temp = temp->next;
            count++;
        }
        if(pos == count && temp->next == NULL)
        {
            temp->prev->next = NULL;
            free(temp);
        }
        else if(pos == count && temp->next != NULL)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        else
        {
            return;
        }
    }

}

int search_list(List* dll, int key) {
    Node *temp = dll->head;
    int offset = 0;
    while(temp != NULL)
    {
        if(temp->data == key) return offset;
        temp = temp->next;
        offset++;
    }
    if(temp == NULL) return -1;

}

void display(List* dll) {
    Node *temp = dll->head;
    if(temp == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    while(temp->next != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return;
}

void destroy_list(List* dll) {
    Node *temp;
    while(dll->head != NULL)
    {
        temp = dll->head;
        dll->head = dll->head->next;
        temp->next = NULL;
        free(temp);
    }
    dll->head = NULL;
    free(dll);
}


/*
Sample Input        Sample Output
1 1                 3 2 1
1 2                 1
1 3                 -1
4                   2 1
3 2                 EMPTY
3 5
2 0
2 2
4
2 0
2 0
4
0
*/