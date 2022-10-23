//Problem: Find the first or last occurrence of a given number in a sorted array
//Given a sorted integer array, find the index of a given number’s first or last occurrence.
//If the element is not present in the array, report that as well.
*******************************************************************
//Function to find the first occurrence of a given number in a sorted integer array
int findFirstOccurrence(int nums[], int n, int target)

    //search space is nums[low…high]
    int low = 0, high = n - 1;
 
    //initialize the result by -1
    int result = -1;
 
    //loop till the search space is exhausted
    while (low <= high)
    
        //find the mid-value in the search space and compares it with the target
        int mid = (low + high)/2;
 
        //if the target is located, update the result and
        //search towards the left (lower indices)
        if (target == nums[mid])
        
            result = mid;
            high = mid - 1;       
 
        // if the target is less than the middle element, discard the right half
        else if (target < nums[mid]) 
            high = mid - 1;
         
        //if the target is more than the middle element, discard the left half
        else 
            low = mid + 1;       
     
    //return the leftmost index, or -1 if the element is not found
    return result;

//Time complexity:0(logn)

int main(void)
{
    int nums[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int n = sizeof(nums)/sizeof(nums[0]);
 
    int target = 5;
 
    int index = findFirstOccurrence(nums, n, target);
 
    if (index != -1)
    {
        printf("The first occurrence of element %d is located at index %d",
                target, index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}
