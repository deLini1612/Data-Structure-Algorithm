//Find the maximum absolute difference between the sum of two non-overlapping subarrays
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
 
// `diff` ——> counter for loop from `i` to `j` in `A[]` (`diff` can be `+1` or `-1`)
// If the `diff` is 1, fill `aux[k]` with the maximum sum of subarray `A[0, k]`
// If the `diff` is -1, fill `aux[k]` with the maximum sum of subarray `A[k, n-1]`
// using Kadane’s algorithm
 
void findMaxSumSubarray(int A[], int aux[], int i, int j, int diff)
{
    int max_so_far = A[i];
    int max_ending_here = A[i];
    aux[i] = A[i];
 
    for (int k = i + diff; k != j; k += diff)
    {
        // update the maximum sum of subarray "ending" or "starting" at index `k`
        max_ending_here = max(A[k], max_ending_here + A[k]);
 
        // update the result if the current subarray sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here);
        aux[k] = max_so_far;
    }
}
 
void fillArrays(int A[], int left_max[], int right_max[],
                int left_min[], int right_min[], int n)
{
    findMaxSumSubarray(A, left_max, 0, n - 1, 1);
    findMaxSumSubarray(A, right_max, n - 1, 0, -1);
 
    // negate `A[]` for finding the minimum sum of subarrays using
    // the same logic for finding the maximum sum of subarrays
    transform(A, A + n, A, negate<int>());
 
    // `transform()` is equivalent to
 
    /* for (int i = 0; i < n; i++) {
        A[i] = -A[i];
    } */
 
    findMaxSumSubarray(A, left_min, 0, n - 1, 1);
    findMaxSumSubarray(A, right_min, n - 1, 0, -1);
 
    // negate `left_min[]` and `right_min[]` to get the minimum sum of subarrays
    transform(left_min, left_min + n, left_min, negate<int>());
    transform(right_min, right_min + n, right_min, negate<int>());
 
    // restore the sign of `A[]`
    transform(A, A + n, A, negate<int>());
}
 
// Find the maximum absolute difference between the sum of elements of
// two non-overlapping subarrays in a given array
int findMaxAbsDiff(int A[], int n)
{
    // base case
    if (n == 0) {
        return 0;
    }
 
    // base case
    if (n == 1) {
        return A[0];
    }
 
    // `left_max[i]` stores maximum sum of subarray in `A(0, i)`
    // `right_max[i]` stores maximum sum of subarray in `A(i, n-1)`
    // `left_min[i]` stores minimum sum of subarray in `A(0, i)`
    // `right_min[i]` stores minimum sum of subarray in `A(i, n-1)`
 
    int left_max[n], right_max[n], left_min[n], right_min[n];
    fillArrays(A, left_max, right_max, left_min, right_min, n);
 
    // stores the maximum absolute difference
    int max_abs_diff = INT_MIN;
 
    // do for each index `i` in the array
    for (int i = 0; i < n - 1; i++)
    {
        max_abs_diff = max(max_abs_diff, max(abs(left_max[i] - right_min[i+1]),
                                    abs(left_min[i] - right_max[i+1])));
    }
 
    return max_abs_diff;
}
 
int main()
{
    int A[] = { -3, -2, 6, -3, 5, -9, 3, 4, -1, -8, 2 };
    int n = sizeof(A) / sizeof(A[0]);
 
    cout << "The maximum absolute difference is " << findMaxAbsDiff(A, n);
 
    return 0;
}