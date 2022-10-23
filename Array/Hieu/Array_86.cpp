//Given a binary array, find the index of 0 to be replaced with 1 to get a maximum length sequence of continuous ones.
//The idea is simple – update each non-zero array element with a count of their adjacent consecutive 1’s. For example, 
//the array [0, 0, 1, 0, 1, 1, 1, 0, 1, 1] is converted into [0, 0, 1, 0, 3, 3, 3, 0, 2, 2]. Now, the problem reduces to finding the index of 0 whose sum of the left and the right element is maximum.
#include <stdio.h>
 
// Utility function to find the maximum of two numbers
int max(int x, int y) {
    return (x > y) ? x : y;
}
 
// Find the index of 0 to replace with 1 to get the maximum sequence of
// continuous 1's
int findIndexofZero(int arr[], int n)
{
    // base case
    if (n == 1) {
        return (arr[0] == 0 ? 0 : -1);
    }
 
    // `arr[i]` now stores the length of consecutive 1's ending at `arr[i]`
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 1) {
            arr[i] += arr[i - 1];
        }
    }
 
    int count = 0;
 
    // traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // update the count to the number of adjacent 1's, which includes the
        // current element
        count = max(arr[i], count);
 
        // update the array with the count of adjacent 1's for each non-zero element
        if (arr[i]) {
            arr[i] = count;
        }
        else {
            // reset the count if the current element is 0
            count = 0;
        }
    }
 
    int max_count = 0;      // stores the maximum number of 1's (including zero)
    int max_index = -1;     // stores the index of 0 to be replaced
 
    // consider each index `i` in the array
    for (int i = 0; i < n; i++)
    {
        // if the current element is 0
        if (arr[i] == 0)
        {
            // update maximum count and index of 0 to be replaced if
            // required by taking a left and right element count
 
            if (i == 0)
            {
                if (max_count < arr[i + 1] + 1)
                {
                    max_count = arr[i + 1] + 1;
                    max_index = i;
                }
            }
            else if (i == n - 1)
            {
                if (max_count < arr[i - 1] + 1)
                {
                    max_count = arr[i - 1] + 1;
                    max_index = i;
                }
            }
            else if (max_count < arr[i - 1] + arr[i + 1] + 1)
            {
                max_count = arr[i - 1] + arr[i + 1] + 1,
                max_index = i;
            }
        }
    }
 
    // restore the original array
    for (int i = 1; i < n; i++)
    {
        if (arr[i]) {
            arr[i] = 1;
        }
    }
 
    // return the index of 0 to be replaced, or -1 if the array contains all 1's
    return max_index;
}
 
 
int main(void)
{
    int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int index = findIndexofZero(arr, n);
 
    if (index != -1) {
        printf("Index to be replaced is %d", index);
    }
    else {
        printf("Invalid input");
    }
 
    return 0;
}