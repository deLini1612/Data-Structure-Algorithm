//Problem: Find all distinct combinations of a given length with repetition allowed
//Given an integer array, find all distinct combinations of a given length k, 
//where the repetition of elements is allowed.
*****************************************************************************
//Take the number of elements and the elements as input.
//function Combi(char a[], int reqLen, int s, int currLen, bool check[], int l) :
//If currLen>reqLen then
//Return
//Else if currLen=reqLen then
//   Then print the new generated sequence.
//If s=l then
//   Then return no further element is left.
//For every index there are two option:
//either proceed with a start as ‘true’ and recursively call Combi() with 
//incremented value of ‘currLen’ and ‘s’.Or proceed with a start as
//‘false’ and recursively call Combi() with only incremented value of ‘s’.
******************************************************************************
//Function to print the contents of the vector
void printVector(vector<int> const &out)
  for (auto it = out.begin(); it != out.end(); it++)

//Function to print all distinct combinations of length `k`, where the
//repetition of elements is allowed
void findCombinations(int arr[], vector<int> &out, int k, int i, int n)

  //base case: if the combination size is `k`, print it
  if (out.size() == k) 
     printVector(out);
     return;

  //start from the previous element in the current combination
  //till the last element
  for (int j = i; j < n; j++)
    
    //add current element `arr[j]` to the solution and recur with the
    //same index `j` (as repeated elements are allowed in combinations)
    out.push_back(arr[j]);
    findCombinations(arr, out, k, j, n);
 
    //backtrack: remove the current element from the solution
    out.pop_back();
 
    //code to handle duplicates – skip adjacent duplicates
    while (j < n - 1 && arr[j] == arr[j + 1])
      j++;

//Time complexity: T(n)=0(n!)

int main()
{
    int arr[] = { 1, 2, 1 };
    int k = 2;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    //if the array contains repeated elements, sort the array to
    //handle duplicates combinations
    sort (arr, arr + n);
 
    vector<int> out;
    findCombinations(arr, out, k, 0, n);
 
    return 0;
}
