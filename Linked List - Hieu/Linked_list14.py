"""Creating a linked list"""
class Node:
    def __init__(self, data=None, link=None):
        self.data = data
        self.link = link

"""Construct linked list"""
def Construct(linked_list,n):
    for i in reversed(range(n)):
        linked_list = Node(i+1,linked_list)
    return linked_list

"""Print linked list"""
def PrintList(linked_list):
    pointer = linked_list
    while (pointer):
        print(pointer.data, end = "->")
        pointer = pointer.link
    print("None")

"""Split linked list into 2 lists"""
def Split_list(source):
    odd, even = None, None
    current = source
    while current:
        new_node = current
        current = current.link
        new_node.link = odd
        odd = new_node
        if (current):
            new_node = current
            current = current.link
            new_node.link = even
            even = new_node
    return odd, even


if __name__ == "__main__":
    linked_list = None
    linked_list = Construct(linked_list,8)
    OddNumber , EvenNumber = Split_list(linked_list)
    PrintList(OddNumber)
    PrintList(EvenNumber)