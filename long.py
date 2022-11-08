def maxSum(A):
    max_so_far = 0
    max_here = 0
    for i in A:
        max_here = max_here + i
        max_here = max(max_here, 0)
        max_so_far = max(max_here, max_so_far)
    return max_so_far

A = [1,-3,9,7,-8,6,10,101,-200,-21,67,58,31,-50,-1000,10,3,1,9,-9]
print(maxSum(A))