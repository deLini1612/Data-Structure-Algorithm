#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
#define N 15
 
// Partition using Hoare's Partitioning scheme
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do {
            i++;
        } while (a[i] < pivot);
 
        do {
            j--;
        } while (a[j] > pivot);
 
        if (i >= j) {
            return j;
        }
 
        swap(a[i], a[j]);
    }
}
 
// Quicksort routine
void quicksort(int a[], int low, int high)
{
    // base condition
    if (low >= high) {
        return;
    }
 
    // rearrange elements across pivot
    int pivot = partition(a, low, high);
 
    // recur on subarray containing elements that are less than the pivot
    quicksort(a, low, pivot);
 
    // recur on subarray containing elements that are more than the pivot
    quicksort(a, pivot + 1, high);
}
 
int main()
{
    int arr[N];
    srand(time(NULL));
 
    // generate random input of integers
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 100) - 50;
    }
 
    quicksort(arr, 0, N - 1);
 
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}