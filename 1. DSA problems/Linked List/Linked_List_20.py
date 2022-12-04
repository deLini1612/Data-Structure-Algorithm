"""Reverse singly linked List using recursion"""

class Node:
    """A linked list node"""
    def __init__(self, data, next=None):
        self.data = data
        self.next = next
 
def printList(head):
    """Function to print a linked list"""
    p = head
    while p:
        print(p.data, end=' —> ')
        p = p.next
    print('None')

def reverseList(head):
    """Fuction to reverse a linked list"""

    # Base case
    if head is None:
        return head
    
    first = head
    rest = head.next

    if rest is None:
        return head
    
    rest = reverseList(rest)
    
    first.next.next = first
    first.next = None
    head = rest

    return head

def main():
    A = [1,3,6,8,10]
    head = None
    for i in reversed(range(len(A))):
        head = Node(A[i], head)
    print("Before:", end = " ")
    printList(head)
    print("After:", end = " ")
    printList(reverseList(head))

if __name__ == "__main__":
    main()