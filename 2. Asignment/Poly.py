"""Declare a polynomial and print it in sorted order using a linked list"""

class Node:
    """A node of linked list"""
    def __init__(self, coef, exp, next = None):
        self.coef = float(coef)
        self.exp = int(exp)
        self.next = next

def addDec(head, coef, exp):
    """Add a element to a sorted (in decreasing order) polynomial so that it is still sorted"""
    temp = Node(16,-1)
    current = temp
    element = Node(coef, exp)

    if head is None:
        head = element
        return head
    else:
        temp.next = head
        while current.next and current.next.exp >= element.exp:
            current = current.next

        if current.exp == element.exp:
            current.coef = current.coef + element.coef
        else:
            element.next = current.next
            current.next = element
    return temp.next

def createPoly():
    """Create a polynomial with input from terminal"""
    n = int(input("Number of elements:"))
    head = None
    for i in range(n):
        coef, exp = input("Enter coef and exp of the element (split by ,): ").split(",")
        head = addDec(head, coef, exp)
    return head

def printPoly(head: Node):
    """Print a polynomial (given in a linked list with the first element is head)"""
    p = head
    print("{}*x^{}".format(p.coef, p.exp), end = " ")
    p = p.next
    while p:
        if p.coef == 0:
            pass
        elif p.coef > 0:
            if p.exp ==0:
                print("+ {}".format(p.coef), end = " ")
            else:
                print("+ {}*x^{}".format(p.coef, p.exp), end = " ")
        else:
            if p.exp ==0:
                print("- {}".format(-p.coef), end = " ")
            else:
                print("- {}*x^{}".format(-p.coef, p.exp), end = " ")
        p = p.next
    print("")

def main():    
    P1 = createPoly()
    printPoly(P1)

if __name__ == "__main__":
    main()