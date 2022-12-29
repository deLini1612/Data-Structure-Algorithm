class Node:
	def __init__(self, data, next=None, left = None, right = None):
		self.data = data
		self.next = next

class Stack:
    """A stack"""
    def __init__(self):
        self.top = None
        self.nodesCount = 0
        
    def push(self, x):
        """Push x to stack"""
        node = Node(x)
        node.next = self.top
        self.top = node
        self.nodesCount += 1
    
    def isEmpty(self):
        """Check if stack is empty"""
        return self.top is None

    def pop(self):
        """Pop first element"""
        if self.isEmpty():
            print('Stack is empty')
            exit(-1)
        		# take note of the top node's data

        topd = self.top.data
        self.top = self.top.next
        self.nodesCount -= 1
        return topd
    
    def print(self):
        """Print the stack"""
        p = self.top
        while p:
            print(p.data, end='->')
            p = p.next
        print('None')

class Queue:
    """Queue"""
    def __init__(self):
        self.rear = None
        self.front = None
        self.count = 0
  
    def dequeue(self):
        """Delete the begining element"""
        if self.front is None:
            print('Queue is empty')
            exit(-1)
        
        rm = self.front
        self.front = self.front.next
        if self.front is None:
            self.rear = None
            
        self.count -= 1
        return rm.data

    def enqueue(self, item):
        """Add item element at the end"""
        node = Node(item)

        if self.front is None:
            self.front = node
            self.rear = node
        else:
            self.rear.next = node
            self.rear = node
        self.count += 1
    
    def print(self):
        """Print the queue"""
        p = self.front
        while p:
            print(p.data, end='->')
            p = p.next
        print('None')

if __name__ == '__main__':
    # Creat linked list
    A = [1,2,3,4,5,6]
    head = None
    for i in reversed(range(len(A))):
        head = Node(A[i], head)
    
    s = Stack()
    q = Queue()
    
    p = head
    noe_list = 0
    while (p):
        noe_list += 1
        p = p.next
    
    p = head
    
    for i in range(int(noe_list/2)):
        q.enqueue(p.data)
        p = p.next
    
    while(p):
        s.push(p.data)
        p = p.next
        
    s.print()
    q.print()
