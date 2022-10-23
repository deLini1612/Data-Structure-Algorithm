"""Binary Search Algorithm
Problem: Given sorted array A[] and a target value
    - Determine if target value is in A[] or not
    - If yes, print its index
Input: Sorted Array A[Int], Int target
Output: int index or -1 (if target doesn't on A) 
"""

# Idea:
#     - Normal idea - Linear search:
#         + Using for loop to check every element in A[]  for the target value until a match
#     ---> Time: O(n) and not take advantage of the fact that the input is sorted

#     - Binary search (Divide and Conquer algorithm):
#         + Divides A[] into two smaller subarrays at search key = mid element of A[] -> got A1[] and A2[]
#             a. If search key = target -> return index
#             b. If search key < target -> Discards A1[] (including the middle element)
#             c. If search key > target -> Discards A2[] (including the middle element)
#         + Repeatedly do the first step until return the index or the interval is empty
#     ---> In conclusion, we repeatedly dividing the search interval in half at each step -> take advantage of the fact that the input is sorted
#     ---> Time: O(logn) - Space: O(1)

#     - Binary Search Algorithm can be implemented in two ways: Iterative Method and Recursive Method


# Iterative Implementation

def binarySearchIter(A: list[int], target: int) -> int:
    """ Function to use Binary Search in iterative method to find the index of target in array A[]"""

    # Search interval is A[left: right]
    (left, right) = (0, len(A) - 1) # Set left, right
 
    # Loop till the search space is empty
    while left <= right:
        mid = left + (right - left) // 2

        if target == A[mid]:
            return mid
        elif target < A[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return -1 # Return -1 if target isn't exist
 
def binarySearchRecur(A: list[int], left: int, right: int, target: int) -> int:
    """ Function to use Binary Search in recursive method to find the index of target in array A[left: right]"""

    if left > right:
        return -1

    mid = left + (right - left) // 2

    if target == A[mid]:
        return mid
    elif target < A[mid]:
        return binarySearchRecur(A, left, mid - 1, target)
    else:
        return binarySearchRecur(A, mid + 1, right, target)

def main():
    A = [2, 3, 5, 7, 9]
    target = 7
    (left, right) = (0, len(A) - 1)
    print(binarySearchIter(A, target))
    print(binarySearchRecur(A, left, right, target))

if __name__ == '__main__':
    main()