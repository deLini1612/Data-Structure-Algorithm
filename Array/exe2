Check if a subarray with 0 sum exists or not
Given an integer array, check if it contains a subarray having zero-sum.

//Function to check if subarray with zero-sum is present in a given array or not
bool hasZeroSumSubarray(int nums[], int n)

  //create a new set
  unordered_set<int> set;

  //insert 0 into handle the case when first  element in array is 0
  set.insert(0);

  //To calculate the sum
  int sum = 0;

  //traverse the given array
  for (int i = 0; i < n; i++) 
   
    //calculate the sum of the subarrays
    sum += nums[i];
   
    //if sum is already there, then subarray with 0-sum is found
    if (set.find(sum) != set.end())
      return true;

    else 
      // insert sum into the set
      set.insert(sum);
  
  //Return false by default
  return false;

//Time complexity: O(n^2)

int main()
{
    int nums[] = { 4, 2, -3, -1, 0, 4 };
    int n = sizeof(nums)/sizeof(nums[0]);
 
    hasZeroSumSubarray(nums, n) ?
            cout << "Subarray exists":
            cout << "Subarray does not exist";
 
    return 0;
}
