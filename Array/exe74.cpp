//Problem: Check if an array is formed by consecutive integers
//Given an integer array, check if only consecutive integers form the array.
**************************************************************

//Function to check if consecutive integers form an array
bool isConsecutive(int arr[], int n)

    //1. Check if all elements in the array are distinct.
    //create an empty tree-based set
    set<int> set;
 
    //traverse the array and checks if each element appears only once
    for (int i = 0; i < n; i++)
    
        // if an element is seen before, return false
        if (set.find(arr[i]) != set.end()) 
            return false;
        
        // mark element as seen
        set.insert(arr[i]);
    
 
    //2. Check if all elements present in the set are consecutive
    int prev;
    
    //iterate through the set and check if the difference between
    //consecutive elements is 1
    //(Note that `std::set` stores the elements in sorted order)
    for (int curr: set)
   
        if (curr != *set.begin() && (curr != prev + 1)) 
            return false;
 
        prev = curr;
 
    return true;

//Time complexity: O(n)
 
int main()
{
    int arr[] = { -1, 5, 4, 2, 0, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    isConsecutive(arr, n) ? cout << "The array contains consecutive integers":
                        cout << "The array does not contain consecutive integers";
 
    return 0;
}
