"""Find two duplicate elements in a limited range array
Problem: Given A[] of size n+2, 1 < A[i] < n for all i. A[] has two element repeating
    - Find both duplicate elements 
    - Without using any extra memory
    - Time complexity: O(n)
Input: A[] and n
Output: Two duplicate elements x and y
"""

# Idea:
#     - Nomarl idea: Using an Array f[n] to store frequency of n in A[] -> return n if f[n] == 2
#         -> Need to store f[n] -> Space: O(n)
#         -> Need to go over A[] and f[] -> Time: O(n)

#     - Using XOR operator: Note that x^x=0 and x^0=x
#         + Find x^y by calculate A[0]^A[1]^...^A[n+1]^1^2^...^n
#             Because: each number 1,...,n will apear once in A[] except for x and y appear 2 times 
#             -> in A[] and [1:n], each number 1,...,n apear 2 times; except x and y will appear 3 times
#             -> all number apear 2 times will cancel each other (cause a^a=0) -> result is x^y
#         + Find x and y from x^y: Notice that k-th bit (from right to left) of result is 1 <-> k-th bit of x and k-th bit of y is different
#             1. Find k so that k-th bit of result is 1
#             2. Split range [1:n] into 2 subrange:   (r1): numbers have k-th bit is 1
#                                                     (r2): numbers have k-th bit is 0
#             3. Split A[] into 2 subarray:   (A1): elements have k-th bit is 1
#                                             (A2): elements have k-th bit is 0
#                 -> x and y is in different subarray and subrange
#             4. XOR all elements of A1[] and r1[] -> the result is x (Because each number appear 2 times except for x)
#                XOR all elements of A2[] and r2[] -> the result is y

from math import log            
def findDuplicates(A: list[int], n: int) -> [int, int]:
    """Function to find duplicates element in list of size n+2 and its elements is in range(1,n)"""

    # Find x^y
    result = A[0] ^ A[n+1]
    for i in range (1,n+1):
        result = result ^ A[i] ^ i
    
    k = int(log(result)//log(2)) # find most left bit = 1
    x = 0
    y = 0
   
    # split the A[]
    for i in range(n + 2):
        # elements that have k'th bit 1
        if A[i] & (1 << k):
            x = x ^ A[i]
        # list elements that have k'th bit 0
        else:
            y = y ^ A[i]
 
    # split range(1, n)
    for i in range(1, n + 1):
        # number `i` has k'th bit 1
        if i & (1 << k):
            x = x ^ i
        # number `i` has k'th bit 0
        else:
            y = y ^ i
    return [y,x]

def main():
    A = [4, 3, 6, 5, 2, 4, 1, 7, 8, 10, 9, 10]
    n = 10
    print("The duplicate elements are {} and {}".format(*findDuplicates(A, n)))

if __name__ == '__main__':
    main()