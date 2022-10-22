''' Find Longest Bitonic Subarray (LBS) in an array
Problem: find subarray X of a given sequence so that: 
    - X's elements are first sorted in increasing order, then in decreasing order (Strictly ascending or descending is okay)
    - X as long as possible
Input: Array A[]
Output: Array B[]
'''

'''
Idea:
    - Check for the LBS starting at A[i]
        -> If the LBS starting at A[i] ends at A[j] -> skip all elements between i and j
    - Next, check for the LBS starting at A[j] -> We continue this process until the end of A
'''
def findLBS(A: list[int]) -> (list[int], int):
    """ Function to find the LBS and its length """
    
    if len(A) ==0: # Check if A[] is empty
        return ([],0)

    i = 0
    end_point = 0
    LBS_length = -1

    while i + 1 < len(A):
        # Check for the LBS starting at A[i]
        length = 1 # Restart the temp length to 1

        while i + 1 < len(A) and A[i] < A[i+1]: # Shift i till sequence is increasing-> length increases
            length += 1
            i += 1
        
        while i + 1 < len(A) and A[i] > A[i+1]: # Shift i till sequence is decreasing -> length increases
            length += 1
            i += 1

        while i + 1 < len(A) and A[i] == A[i+1]: # Shift i till decreasing sequence is equal -> length stays unchange
            i += 1

        if length > LBS_length: # Update length and end point
            LBS_length = length
            end_point = i
    
    return (A[end_point - LBS_length + 1: end_point + 1], LBS_length)

# Time: O(n) - Space 0

def main():
    A = [3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4]
    print("The longest bitonic subarray is {} - its length is {}".format(*findLBS(A)))

if __name__ == "__main__":
    main()