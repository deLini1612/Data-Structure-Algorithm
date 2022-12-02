"""Declare a polynomial and print using a linked list"""

class Node:
    """A node of linked list"""
    def __init__(self, coef = None, exp = None, next = None):
        self.coef = float(coef)
        self.exp = int(exp)
        self.next = next

def appendPoly(head, coef, exp):
    """Function to append elements of polynomial (by append a node to the tail of linked list)"""
    current = head
    element = Node(coef, exp)
    if current is None:
        head = element
    else:
        while current.next:
            current = current.next
        current.next = element
    return head

def creatPoly():
    """Function to creat a polynomial with input from terminal"""
    n = int(input("Number of elements:"))
    head = None
    for i in range(n):
        coef, exp = input("Enter coef and exp of the element (split by ,): ").split(",")
        head = appendPoly(head, coef, exp)
    return head

def printPoly(head: Node):
    """Function to print a polynomial (given in a linked list with the first element is head)"""
    p = head
    print("{}*x^{}".format(p.coef, p.exp), end = " ")
    p = p.next
    while p:
        if p.coef == 0:
            continue
        elif p.coef > 0:
            print("+ {}*x^{}".format(p.coef, p.exp), end = " ")
        else:
            print("{}*x^{}".format(p.coef, p.exp), end = " ")
        p = p.next

def main():    
    headPoly = None
    headPoly = creatPoly()
    printPoly(headPoly)

if __name__ == "__main__":
    main()