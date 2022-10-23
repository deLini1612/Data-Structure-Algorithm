"""Find a Triplet having Maximum Product in an Array
Problem: Given integer array A[]
    - find a triplet having the maximum product
Input: Array A[]
Output: Triplet (x, y, z)
"""

# Idea:
# The triplet having the maximum product only can be one of the two:
#   - The largest, the 2nd largest and the 3 largest
#   - The largest, the smallest and 2nd smallest
# P/s: We can sort A[] to deal with this problem but its disadvantage is A[] is modified
#   -> No need to sort A[], just find top 3 largest and the top 2 smallest element in A[] by using for loop

def maxProductTriplet(A: list[int]) -> list[int]:
    """Function to find the triplet whose product is maximum"""

    if len(A)<3: # Check if array length is less than 3 -> can't have triplet
        print("Less than 3 elements in array")
        return
    
    max1_index = 0
    max2_index = -1
    max3_index = -1
    min1_index = 0
    min2_index = -1

    for i in range(len(A)):
        if A[i] > A[max1_index]:
            max3_index = max2_index
            max2_index = max1_index
            max1_index = i
        elif A[i] > A[max2_index] or max2_index == -1:
            max3_index = max2_index
            max2_index = i
        elif A[i] > A[max3_index] or max3_index == -1:
            max3_index = i
        
        if A[i] < A[min1_index]:
            min2_index = min1_index
            min1_index = i
        elif A[i] < A[min2_index] or min2_index == -1:
            min2_index = i

    if (A[max1_index]*A[max2_index]*A[max3_index])>(A[max1_index]*A[min1_index]*A[min2_index]):
        triplet = [A[max1_index], A[max2_index], A[max3_index]]
    else:
        triplet = [A[max1_index], A[min1_index], A[min2_index]]
    return triplet

# Time: O(n.logn)

def main():
    A = [-4, 1, -8, 9, 6]
    print("The triplet is ({}, {}, {})".format(*maxProductTriplet(A)))

if __name__ == "__main__":
    main()