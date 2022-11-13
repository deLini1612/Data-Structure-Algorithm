""" In-place merge two sorted arrays 
Problem: Given 2 sorted array X[] and Y[] of size m and n
    - Merge elements of X[] and Y[] maintaining the sorted order
    - Fill X[] with the first m smallest elements and Y[] with remaining elements
Input: Sorted arrays X[] and Y[]
Output: X[] and Y[] after merge
"""

# Idea:
#     - Go through X: At any point i in X, compare X[i] with Y[0] (smallest element in Y)
#     - If X[i]>Y[0]
#         + Swap X[i] and Y[0]
#         + Resorted Y[] after swap X[i] and Y[0]

def merge(X: list[int], Y: list[int]) -> [list, list]:
    """ Function to merge 2 sorted array"""
    
    m = len(X)
    n = len(Y)
    for i in range(m):
        if X[i] > Y[0]:
            temp = Y[0]
            Y[0] = X[i]
            X[i] = temp
        
        first = Y[0]
        j=1
        while j < n and first > Y[j]:
            Y[j-1] = Y[j]
            j = j + 1
        Y[j-1] = first
    return [X, Y]

def main():
    X = [ 1, 4, 8, 12, 19 ]
    Y = [ 3, 5, 9, 10, 21, 30 ]
    print("After merged: X = {} and Y = {}".format(*merge(X, Y)))

if __name__ == '__main__':
    main()