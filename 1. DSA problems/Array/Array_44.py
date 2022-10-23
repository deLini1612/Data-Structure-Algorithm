''' Length of longest continuous sequence with same sum in given binary arrays
Problem: Given 2 binary arrays X[] and Y[]. Find (i, j) that:
    - sum of subarray X[i: j] = sum of subarray Y[i: j]
    - j-i+1 is max
Input: Array X[], Array Y[]
Output: Int Ans
'''

# Idea: 
#   - Go over the array -> maintain the sum of X[] and Y[] till the current index & calculate the difference between the two sums
#   - If the difference is seen for the first time, store the difference and current index. (using dict or map)
#   - If the difference is seen before 
#       -> subarray satisfies the problem is X[i+1: j] and Y[i+1: j] with i = index of first occurrence 
#       -> length of this subarray is j-i -> update result

def maxLengthSubArray(X: list[int], Y: list[int]) -> int:
    """Fuction to find length of longest subarray with same sum in given binary arrays"""

    if len(X)>len(Y):
        lenA = len(Y)
    else:
        lenA = len(X)

    dict = {}
    dict[0] = -1 # The diff = 0 before start (in case the result subarray start from index 0)
    sumX = sumY = 0
    maxLen = 0

    for i in range(lenA):
        sumX += X[i]
        sumY += Y[i]
        diff = sumX - sumY

        if diff not in dict:
            dict[diff] = i
        else:
            maxLen = max(i - dict[diff], maxLen)

    return maxLen

# Time: O(n) - Space O(n)

def main():
    X = [0, 0, 1, 1, 1, 1]
    Y = [0, 1, 1, 0, 1, 0]
    print("The length of the longest subarray is {}".format(maxLengthSubArray(X, Y)))

if __name__ == "__main__":
    main()