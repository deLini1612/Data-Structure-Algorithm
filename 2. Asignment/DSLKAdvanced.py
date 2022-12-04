"""Josephus problem: 
- There are N people sitting in a circle table
- The 1st person will pass a ball for 2nd person and so on
- Continue till the ball pass M times -> person who is keeping the ball is eliminated
- Repeat till there is only 1 person left -> It's the winner"""

# Idea:
# Using Circular Linked List

class Node:
    """Initial a linked list node"""
    def __init__(self, data):
        self.data = data
        self.next = None
 
 
class CircularLinkedList:
    """Circular Linked List"""
    def __init__(self):
        self.head = None
    
    def getPrevNode(self, refNode):
        """Get the previous node of refNode"""
        if self.head is None:
            return None
        current = self.head
        while current.next != refNode:
            current = current.next
        return current

    def getMNode(self, m: int, start: Node):
        """Get the next m-th node from start node"""
        if self.head is None:
            return None
        current = start
        for i in range(m):
            current = current.next
        return current
    
    def addAtEnd(self, data):
        """Add a node with specific data at the end of linked list"""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            newNode.next = newNode
        else:
            prevNode = self.getPrevNode(self.head)
            newNode.next = prevNode.next
            prevNode.next = newNode

    def delNode(self, node):
        """Delete a node from linked list"""
        if self.head.next == self.head:
            self.head = None
        else:
            prevNode = self.getPrevNode(node)
            prevNode.next = node.next
            if self.head == node:
                self.head = node.next
 
def oneNode(cllist):
    """Check if cllist has 1 node or not"""
    if cllist.head.next == cllist.head:
        return True
    else:
        return False
 
def josephusAns(n, m):
    """Get Josephus problem answer with N = n and M = m"""
    cllist = CircularLinkedList()
    for i in range(1, n+1):
        cllist.addAtEnd(i)
    
    if cllist.head is None:
        return None
    start = cllist.head
    while not oneNode(cllist):
        eliminated = cllist.getMNode(m, start)
        start = eliminated.next
        cllist.delNode(eliminated)
    print("The winner is player {}".format(cllist.head.data))

def main():
    n = int(input("Enter n: "))
    m = int(input("Enter m: "))
    josephusAns(n, m)

if __name__ == "__main__":
    main()

# Time: O(M*N)