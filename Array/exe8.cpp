//Find the largest subarray having an equal number of 0's and 1's
// given a binary array containing 0's and 1's, find the langest subarray with equal numbers of 0's and 1's
//Input:  { 0, 0, 1, 0, 1, 0, 0 }
//Output: { 0, 1, 0, 1 } or { 1, 0, 1, 0 }
// idea : replace 0 with -1 and find out the lafgest subarray with sum of 0.
//        create an empty map that stores the first subarray's ending index having a given sum.
//        traverse the given array and maintain the sum of elements seen so far
//              If the sum is seen for the first time, insert the sum with its index into the map.
//              If the sum is seen before, there exists a subarray with a sum of 0, which ends at the current index, and update the largest subarray if the current subarray has more length.
#include <iostream>
#include <unordered_map>
using namespace std;
 
// Function to find the largest subarray having an equal number
// of 0's and 1's
void findlargestsubarray(int nums[], int n)
{
    // create an empty map to store the ending index of the first subarray
    unordered_map<int, int> map;
 
    // insert (0, -1) pair into the set to handle the case when a
    // subarray with zero-sum starts from index 0
    map[0] = -1;
 
    // `leng` stores the maximum length of subarray with zero-sum
    int leng = 0;
 
    // stores ending index of the largest subarray having zero-sum
    int ending_index = -1;
 
    int sum = 0;
 
    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far (replace 0 with -1)
        sum += (nums[i] == 0)? -1 : 1;
 
        // if the sum is seen before
        if (map.find(sum) != map.end())
        {
            // update length and ending index of largest subarray having zero-sum
            if (leng < i - map[sum])
            {
                leng = i - map[sum];
                ending_index = i;
            }
        }
        // if the sum is seen for the first time, insert the sum with its
        // index into the map
        else {
            map[sum] = i;
        }
    }
 
    // print the subarray if present
    if (ending_index != -1) {
        cout << "[" << ending_index - leng + 1 << ", " << ending_index << "]"<< "\n " ;
        for (int i= ending_index -leng +1; i <= ending_index; i++)
        {
            cout << nums[i] << ",";
        }
    }
    else {
        cout << "No subarray exists";
    }
}
int main()
{
    int nums[] = { 0, 0, 1, 0, 1, 0, 0 };
	int n = sizeof(nums) / sizeof(nums[0]);

	findlargestsubarray(nums, n);

	return 0;
    
}
4
