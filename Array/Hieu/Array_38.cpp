#include <stdio.h>

// target: gain the biggest product of subarray.
//Algorithm:
//  For every index i in the array, update the maxium product at
//  the current index
//  In case of negative number, we also need to compute the minium
//  product at current index    
 
// Utility function to find a minimum of two numbers
int min(int x, int y) {
    return (x < y) ? x : y;
}
 
// Utility function to find a maximum of two numbers
int max(int x, int y) {
    return (x > y) ? x : y;
}
 
// Function to return the maximum product of a subarray of a given array
int findMaxProduct(int arr[], int n)
{
    // base case
    if (n == 0) {
        return 0;
    }
 
    // maintain two variables to store the maximum and minimum product
    // ending at the current index
    int max_ending = arr[0], min_ending = arr[0];
 
    // to store the maximum product subarray found so far
    int max_so_far = arr[0];
 
    // traverse the given array
    for (int i = 1; i < n; i++)
    {
        int temp = max_ending;
 
        // update the maximum product ending at the current index
        max_ending = max(arr[i], max(arr[i] * max_ending, arr[i] * min_ending));
 
        // update the minimum product ending at the current index
        min_ending = min(arr[i], min(arr[i] * temp, arr[i] * min_ending));
 
        max_so_far = max(max_so_far, max_ending);
    }
 
    // return maximum product
    return max_so_far;
}
 
int main(void)
{
    int arr[] = { -6, 4, -5, 8, -10, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("The maximum product of a subarray is %d",
            findMaxProduct(arr, n));
 
    return 0;
}

