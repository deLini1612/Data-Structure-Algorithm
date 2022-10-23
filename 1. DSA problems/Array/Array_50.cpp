//4-sum problem: Given an unsorted integer array, check if it contains 
//four elements tuple (quadruplets) having a given sum.
*********************************************************************
//Function to check if quadruplet exists in an array with the given sum
bool hasQuadruplet(int nums[], int n, int target)

  //create an empty map
  //key —> target of a pair in the array
  //value —> vector storing an index of every pair having that sum
  unordered_map<int, vector<Pair>> map;
 
  //consider each element except the last element
  for (int i = 0; i < n - 1; i++)

    //start from the i'th element until the last element
    for (int j = i + 1; j < n; j++)

      //calculate the remaining sum
      int val = target - (nums[i] + nums[j]);
 
      //if the remaining sum is found on the map,
      //we have found a quadruplet
      if (map.find(val) != map.end())

        //check every pair having a sum equal to the remaining sum
        for (auto pair: map.find(val)->second)

          int x = pair.first;
          int y = pair.second;
 
          //if quadruplet doesn't overlap, print it and return true
          if ((x != i && x != j) && (y != i && y != j))

            cout << "Quadruplet Found ("
                 << nums[i] << ", " << nums[j] << ", " << nums[x]
                 << ", " << nums[y] << ")";
            return true;

      //insert the current pair into the map
      map[nums[i] + nums[j]].push_back({i, j});

  //return false if quadruplet doesn't exist
  return false;

//Time complexity:O(n^2).

int main()
{
    int nums[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
    int target = 20;
 
    int n = sizeof(nums) / sizeof(nums[0]);
 
    if (!hasQuadruplet(nums, n, target)) {
        cout << "Quadruplet Doesn't Exist";
    }
 
    return 0;
}

