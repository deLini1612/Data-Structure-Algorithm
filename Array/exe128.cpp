//Find the peak element in an array
//Given an integer array, find the peak element in it. A peak element is an element that is greater than its neighbors. There might be multiple peak elements in an array, and the solution should report any peak element
//Input : [8, 9, 10, 2, 5, 6]
//Output: The peak element is 10
#include <stdio.h>
#include <stdlib.h>
 
// Recursive function to find the peak element in an array
int findPeakElement(int nums[], int left, int right, int n)
{
    int mid = (left + right) / 2;
 
    // check if the middle element is greater than its neighbors
    if ((mid == 0 || nums[mid - 1] <= nums[mid]) &&
            (mid == n - 1 || nums[mid + 1] <= nums[mid])) {
        return mid;
    }
 
    // If the left neighbor of `mid` is greater than the middle element,
    // find the peak recursively in the left subarray
    if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
        return findPeakElement(nums, left, mid - 1, n);
    }
 
    // If the right neighbor of `mid` is greater than the middle element,
    // find the peak recursively in the right subarray
    return findPeakElement(nums, mid + 1, right, n);
}
 
int findPeak(int nums[], int n)
{
    // base case
    if (n == 0) {
        exit(-1);
    }
 
    int index = findPeakElement(nums, 0, n - 1, n);
    return nums[index];
}
 
int main(void)
{
    int nums[] = { 8, 9, 10, 2, 5, 6 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    printf("The peak element is %d", findPeak(nums, n));
 if (nums[n-1] > nums[n-2]) printf("and %d", nums[n-1] );
    return 0;
}
