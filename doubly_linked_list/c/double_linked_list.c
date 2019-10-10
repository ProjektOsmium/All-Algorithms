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
            printf("%d is deleted from the list\n",temp->data);
            dll->head = NULL ;
            free(temp);
        }
        else
        {
            printf("%d is deleted from the list\n",temp->data);
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
            printf("%d is deleted from the list\n",temp->data);
            temp->prev->next = NULL;
            free(temp);
        }
        else if(pos == count && temp->next != NULL)
        {
            printf("%d is deleted from the list\n",temp->data);
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
        printf("List is EMPTY\n");
        return;
    }
    printf("Elements in list = ");
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

int main() {
    List* dll = initialize_list();
    int pos;

    insert_front(dll, 1);
    insert_front(dll, 2);
    insert_front(dll, 3);

    display(dll);

    pos = search_list(dll, 2);
    printf("Position of %d in list = %d\n",2, pos);

    pos = search_list(dll, 5);
    printf("Position of %d in list = %d\n",5, pos);

    position_delete(dll, 0);
    position_delete(dll, 2);
    
    display(dll);

    position_delete(dll, 0);
    position_delete(dll, 0);

    display(dll);

    destroy_list(dll);
    return 0;
}
