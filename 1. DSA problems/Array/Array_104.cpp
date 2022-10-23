//Bubble Sort Algorithm – Iterative & Recursive 
//Given an integer array, sort it using the bubble sort algorithm.
//input:3, 5, 8, 4, 1, 9, -2
//output:-2 1 3 4 5 8 9 
#include <stdio.h>

 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
 
void bubbleSort(int arr[], int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
 
    }
}
 
int main(void)
{
    int arr[] = { 3, 5, 8, 4, 1, 9, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    bubbleSort(arr, n);
    printArray(arr, n);
 
    return 0;
}