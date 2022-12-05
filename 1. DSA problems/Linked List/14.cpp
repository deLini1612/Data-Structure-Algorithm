#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Function takes the node from the front of the source and moves it
// to the front of the destination
void moveNode(struct Node** destRef, struct Node** sourceRef)
{
    // if the source list empty, do nothing
    if (*sourceRef == NULL) {
        return;
    }
 
    struct Node* newNode = *sourceRef;  // the front source node
    *sourceRef = (*sourceRef)->next;    // advance the source pointer
    newNode->next = *destRef;           // link the old dest off the new node
    *destRef = newNode;                 // move dest to point to the new node
}
 
/*
    Given the source list, split its nodes into two shorter lists.
    If we number the elements 0, 1, 2, then all the even elements
    should go in the first list and all the odd elements in the second.
    The elements in the new lists may be in any order.
*/
void alternatingSplit(struct Node* source, struct Node** aRef, struct Node** bRef)
{
    // Split the nodes into `a` and `b` lists
    struct Node* a = NULL;
    struct Node* b = NULL;
 
    struct Node* current = source;
 
    while (current != NULL)
    {
        moveNode(&a, &current);         // Move a node to `a`
 
        if (current != NULL) {
            moveNode(&b, &current);     // Move a node to `b`
        }
    }
 
    *aRef = a;
    *bRef = b;
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    // construct the first linked list
    struct Node* head = NULL;
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    struct Node *a = NULL, *b = NULL;
    alternatingSplit(head, &a, &b);
 
    // print both lists
    printf("First List: ");
    printList(a);
 
    printf("Second List: ");
    printList(b);
 
    return 0;
}