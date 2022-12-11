//Chèn một nút vào đúng vị trí đã sắp xếp của nó trong danh sách liên kết đã sắp xếp
//ĐỀ BÀI:Cho một danh sách được sắp xếp theo thứ tự tăng dần và một nút duy nhất, hãy chèn nút đó vào vị trí được sắp xếp chính xác của danh sách. 
//Hàm sẽ lấy một nút hiện có và sắp xếp lại các con trỏ để chèn nó vào danh sách.
//Giair pháp:lặp lại danh sách để tìm vị trí chèn nút mới. Đó có thể là điểm cuối của danh sách hoặc một điểm ngay trước nút lớn hơn nút mới. 
//           Ba giải pháp được trình bày xử lý trường hợp “đầu cuối” theo những cách khác nhau.
//input: 2,4,6,8
//       5,9,1
//output:1 —> 2 —> 4 —> 5 —> 6 —> 8 —> 9 —> NULL

#include <stdio.h>
#include <stdlib.h>
 

struct Node
{
    int data;
    struct Node* next;
};


void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
 

void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
//  return a new node of the linked list
struct Node* newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// insert a given node at its correct sorted position into
// a given list sorted in increasing order
void sortedInsert(struct Node** head, struct Node* newNode)
{
    
    if (*head == NULL || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
 
    
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
}
 
int main(void)
{
    
    int keys[] = {2, 4, 6, 8};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    
    struct Node* head = NULL;
 
    // construct a linked list
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    sortedInsert(&head, newNode(5));
    sortedInsert(&head, newNode(9));
    sortedInsert(&head, newNode(1));
 
    // print linked list
    printList(head);
 
    return 0;
}