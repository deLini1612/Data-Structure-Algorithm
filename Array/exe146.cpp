//Problem: Find floor and ceil of a number in a sorted array (Recursive solution)
//Given a sorted integer array, find the floor and ceiling of a given number in it. 
//The floor and ceiling map the given number to the largest previous or the smallest following integer in the array.
********************************************************************
// Function to find the ceiling of `x` in a sorted array nums[low…high].
int findCeiling(int nums[], int low, int high, int x)

    // search space is nums[low…high]
 
    // base case
    if (high < low) 
        return -1;
 
    // if `x` is less than equal to the lowest element in search
    // space, the lowest element is the ceiling
    if (x <= nums[low]) 
        return nums[low];    
 
    // if `x` is more than the highest element in the search space,
    // its ceiling doesn't exist
    if (x > nums[high]) 
        return -1;   
 
    // find the middle index
    int mid = (low + high) / 2;
 
    // if `x` is equal to the middle element, it is the ceiling
    if (nums[mid] == x) 
        return nums[mid];   
 
    // if `x` is more than the middle element, the ceiling exists in the right
    // subarray nums[mid+1…high]
    else if (nums[mid] < x) 
        return findCeiling(nums, mid + 1, high, x);    
 
    // if `x` is less than the middle element, the ceiling exists in the left
    // subarray nums[low…mid] (Note – middle element can also be ceiling)
    else 
        return findCeiling(nums, low, mid, x);    
 
// Function to find the floor of `x` in a sorted array nums[low…high].
int findFloor(int nums[], int low, int high, int x)

    // search space is nums[low…high]
 
    // base case
    if (high < low) 
        return -1;  
 
    // if `x` is less than the lowest element in search
    // space, its floor doesn't exist
    if (x < nums[low]) 
        return -1;    
 
    // if `x` is more than equal to the highest element in
    // the search space, it is the floor
    if (x >= nums[high]) 
        return nums[high];    
 
    // find the middle index
    int mid = (low + high) / 2;
 
    // this check is placed to handle infinite loop for
    // a call to `findFloor(nums, mid, right, x)`
    if (mid == low) 
        return nums[low];   
 
    // if `x` is equal to the middle element, it is the floor
    if (nums[mid] == x) 
        return nums[mid];  
 
    // if `x` is more than the middle element, the floor exists in the right
    // subarray nums[mid…high] (Note – middle element can also be the floor)
    else if (nums[mid] < x) 
        return findFloor(nums, mid, high, x);    
 
    // if `x` is less than the middle element, the floor exists in the left
    // subarray nums[low…mid-1]
    else 
        return findFloor(nums, low, mid - 1, x);   

//Time complexity:0(logn) 
 
int main(void)
{
    int nums[] = { 1, 4, 6, 8, 9 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    for (int i = 0; i <= 10; i++)
    {
        printf("Number %2d —> ceiling is %2d, floor is %2d\n", i,
                    findCeiling(nums, 0, n - 1, i),
                    findFloor(nums, 0, n - 1, i));
    }
 
    return 0;
}
