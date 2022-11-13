"""Heap Sort Algorithm"""

# Idea:
#     - Build a heap from input data -> 2 ways:
#         + Naive solution: start with an empty heap -> repeatedly insert element into it 
#             -> Time complexity: O(n.log(n))
#         + Better solution:
#             1. Putting elements into a heap (abide by the index -> I.e: A[6] is put at node 011)
#             2. The last internal node of the heap (Internal node is a node not the root and not the leaf)
#                 -> present index (n-2)/2 in the array
#                 -> Heapify on each node from the last internal node (cause leaft is already heapify) to the root
#     - A sorted array is created:
#         + Removing the largest/smallest element from the root of the heap
#         + Update the heap to maintain the heap property
#         + Repeat it till the heap is emplty
# To built an in-placeHeap sort:
#     - Using a max-heap instead of min-heap (to sort in ascending order),
#     - Using an input array for constructing heap (instead of using heap own storage)
#     -> Split the array into two parts: the heap and the sorted array
#     -> 1st popped item (max element) go to the last position in A[] -> swap A[0] and A[n-1]; and so on ...
#     -> When all items are popped from the heap, we will get an array sorted in ascending order.

def swap(A: list, i: int, j: int):
    """Function to swap A[i] with A[j]"""
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

def heapify(A: list, i: int, n: int):
    """Function to heapify node i of list A in size n"""
    left = 2 * i + 1
    right = 2 * i + 2

    largest = i
    if left < n and A[left] > A[largest]:
        largest = left
    if right < n and A[right] > A[largest]:
        largest = right
    if largest != i:
        swap(A, largest, i)
        heapify(A, largest, n)

def pop(A: list, n: int) -> int:
    """Function to pop the root and update the heap"""
    if n <= 0:
        return -1
    root = A[0]
    A[0] = A[n-1]
    heapify(A, 0, n-1)
    return root

def heapSort(A: list) -> list:
    """Function to in-place heap sort"""
    n = len(A)
    
    # Build heap by calling heapify from the last internal node
    i = (n - 1) // 2
    while i >= 0:
        heapify(A, i, n)
        i = i - 1
    
    # Repeatedly pop the root (max element) from the heap till it is empty
    while n:
        swap(A, n - 1, 0)
        heapify(A, 0, n - 1)
        n = n - 1
    return A

def firstSort(A: list) -> list: # Bài toán cô đặt ra
    """Function to print A[] after the first sort"""
    n = len(A)

    i = (n-1)//2
    while i >= 0:
        heapify(A, i, n)
        i = i - 1
    swap(A, n - 1, 0)
    heapify(A, 0, n - 1)
    return A


def main():
    A = [ 1, -2, 9, 7, -8, 6, 10, 101, -200, -21, 67, 58, 31, -50, -1000, 10, 3, 1, 9, -9 ]
    print("A after sorted 1 element: ", firstSort(A))
    print("A after fully sorted: ", heapSort(A))
    

if __name__ == '__main__':
    main()