"""Longest Alternating Subsequence Problem
Problem: Find the length of longest subsequence of a given sequence A[] that:
    - Its elements are in alternating order (> < > < ...)
    - Note: subsequences are not required to occupy consecutive positions within the original array
Input: A[]
Output: Int n
"""

# Introduction to Dynamic Programming - 'remembering stuff to save time later'
# To solve a complex problem:
#     - Breaking it down into simpler subproblems
#     - Solving each subproblems just once
#         + Store their solutions using a memory-based data structure (array, map, ...)
#         + Each subproblem solution is indexed (based on its input) -> easier to lookup
#         -> If the same subproblem occurs -> looks up the previously computed solution (no need to recomputing) -> save time
# Condition for Dynamic Programming to be applicable:
#     - Optimal substructure
#         + Solution to a given optimization problem can be obtained by the combination of optimal solutions to its subproblems
#     - Overlapping subproblems
#         + The problem can be broken down into subproblems and each subproblem is repeated several times (i.e Fibonacci problem)
# 2 ways to apply Dynamic Programming
#     - Top-down approach
#     - Bottom-up approach

# Idea: Dynamic Programming
#     - Define a 2D array las[n][2] (lookuptable):
#         + las[i][0]: longest alternating subsequence (LAS) ending at index i and last element > previous element
#         + las[i][1]: LAS ending at index i and last element < previous element  
#     - Recursive Formulation:
#         + las[i][0] = max (las[i][0], las[j][1] + 1); for all j < i and A[j] < A[i] 
#             Because: If we can find an element A[j]<A[i] (with j< i) such that las[j][1] + 1 > las[i][0]
#             -> last[i][0] is not the length of LAS
#             -> update las[i][0]
#         + las[i][1] = max (las[i][1], las[j][0] + 1); for all j < i and A[j] > A[i]

def LAS1(A: list[int]) -> int:
    """Function to find the length of the longest subsequence with alternate low and high elements"""

    las = [[0] * 2 for r in range(len(A))]
    '''
    Lookup table las[n][2]:
        + las[i][0]: longest alternating subsequence (LAS) ending at index i and last element > previous element
        + las[i][1]: LAS ending at index i and last element < previous element  
    '''

    result = 1
    las[0][0] = las[0][1] = 1

    # Fill the lookup table in bottom up manner
    for i in range(1, len(A)):
        for j in range(i):
            if (A[j] < A[i] and las[i][0] < las[j][1] + 1):
                las[i][0] = las[j][1] + 1
            if (A[j] > A[i] and las[i][1] < las[j][0] + 1):
                las[i][1] = las[j][0] + 1

        # Update result
        if result < max(las[i][0], las[i][1]):
            result = max(las[i][0], las[i][1])
    return result

# Time: O(n^2) - Space: O(n)

# A more effective method:
# Instead of store a 2D lookup table -> just store 2 variable for any element at any index i
#     - inc: Length of LAS so far with current value > than previous value
#     - dec: Length of LAS so far with current value < than previous value
# -> Shift the current position and update 2 variable:
#     - “inc” should be increased <-> the last element in the alternative sequence < previous element
#     - “dec” should be increased <-> the last element in the alternative sequence > previous element

def LAS2(A):
    inc = 1
    dec = 1
    # Iterate from second element
    for i in range(1,len(A)):
        if (A[i] > A[i-1]):
            inc = dec + 1
        elif (A[i] < A[i-1]):
            dec = inc + 1
    return max(inc, dec)

# Time: O(n) - Space: O(1)

def main():
    A = [8, 9, 6, 4, 5, 7, 3, 2, 4]
    print('The length of the longest alternating subsequence is', LAS1(A))
    print('The length of the longest alternating subsequence is', LAS2(A))
 
if __name__ == '__main__':
    main()