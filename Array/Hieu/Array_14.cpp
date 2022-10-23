//Fisher_Yates shuffle
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap function
void swap (int A[], int i, int j){
    int k;
    k = A[i];
    A[i] = A[j];
    A[j] = k;
}
//suffle function
void shuffle(int A[], int leng_array){
    for (int i = leng_array-1; i>=0 ; i--)
    {
        int j = rand() % (i+1);
        swap(A,i,j);
    }
}
int main(){
    int A[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(A) / sizeof(A[1]);
 
    // seed for random input
    srand(time(NULL));
 
    shuffle(A, n);
 
    // print the shuffled array
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
 
    return 0;
}