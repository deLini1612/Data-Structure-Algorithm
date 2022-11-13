"""Print continuous subarray with maximum sum
Problem: Find maximum sum of a contiguous subarray of given array A[]
Input: A[]
Output: Maximum sum
"""

# Idea: Maintaining a maximum (positive) sum ending at each index
#     -> The sum 0 (when the subarray is empty) or consists of 1 more element than the maximum subarray ending at the previous index
#     -> compare with the max so far

def maxSum(A: list) -> int:
    """Function to find the max sum of subarray of A[]"""

    max_so_far = 0
    max_here = 0
    for i in A:
        max_here = max_here + i
        max_here = max(max_here, 0)
        max_so_far = max(max_here, max_so_far)
    return max_so_far

def main():
    A = [1,-3,9,7,-8,6,10,101,-200,-21,67,58,31,-50,-1000,10,3,1,9,-9]
    print("The maximum sum of subarray is {}".format(maxSum(A)))

if __name__=='__main__':
    main()