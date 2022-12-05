//Rearrange linked list in a specific manner in linear time
//1. Split the list into 2 halves.
//2. Reverse the second half.
//3. Merge the second half into the first half at alternate positions.

#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Function to print a given linked list
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
 
// Function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *head;
 
    *head = node;
}
 
// Function to reverse nodes of a linked list
void reverse(struct Node** head)
{
    struct Node* result = NULL;
    struct Node* current = *head;
    while (current != NULL)
    {       
        struct Node* next = current->next;        
        current->next = result;
        result = current;
        current = next;
    }

    *head = result;
}
 
// Recursive function to construct a linked list by merging
// alternate nodes of two given linked lists
struct Node* shuffleMerge(struct Node* a, struct Node* b)
{
    if (a == NULL) {
        return b;
    }
 
    if (b == NULL) {
        return a;
    }
 
    struct Node* recur = shuffleMerge(a->next, b->next);
 
    struct Node* result = a;    
    a->next = b;                
    b->next = recur;            
 
    return result;
}
 
// Function to split the linked list into two equal parts and return the
// pointer to the second half
struct Node* findMiddle(struct Node* head)
{
    struct Node *prev = NULL;
    struct Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast && fast->next == NULL)
    {
        prev = slow;
        slow = slow->next;
    }

    prev->next = NULL;
    return slow;
}
 
// Function to rearrange given linked list in a specific way
void rearrange(struct Node* head)
{
   
    if (head == NULL) {
        return;
    }
 
    struct Node* mid = findMiddle(head);

    reverse(&mid);
    shuffleMerge(head, mid);

}
int main(void)
{
   
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    rearrange(head);
 
    printList(head);
 
    return 0;
}
