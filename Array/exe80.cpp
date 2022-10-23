//Count distinct absolute values in a sorted array
//Given an array of sorted integers that may contain several duplicate elements, count the total number of distinct absolute values in it.
//Input:  { -1, -1, 0, 1, 1, 1 }
//Output: The total number of distinct absolute values is 2 (0 and 1)
#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>
using namespace std;
 
// Returns the total number of distinct absolute values in a given input
int findDistinctCount(vector<int> &input)
{
    unordered_set<int> set;
    for (int const &i: input) {
         set.insert(abs(i));
         cout << abs(i);
    }
 
    return set.size();

}
 
int main()
{
    vector<int> input = { -1, -1, 0, 1, 1, 1 };
 
    cout << "The total number of distinct absolute values is "
         << findDistinctCount(input);
 
    return 0;
}
