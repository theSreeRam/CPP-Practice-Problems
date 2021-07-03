// Given an unsorted array of size N, use selection sort to sort arr[] in increasing order.


// Example 1:

// Input:
// N = 5
// arr[] = {4, 1, 3, 9, 7}
// Output:
// 1 3 4 7 9
// Explanation:
// Maintain sorted (in bold) and unsorted subarrays.
// Select 1. Array becomes 1 4 3 9 7.
// Select 3. Array becomes 1 3 4 9 7.
// Select 4. Array becomes 1 3 4 9 7.
// Select 7. Array becomes 1 3 4 7 9.
// Select 9. Array becomes 1 3 4 7 9.


#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
   //we'll select the smallest item and place it at first
   for(int i=0; i<n-1; i++){
       int min_index = i;
       for(int j=i; j<n; j++){
           if(arr[j]<arr[min_index]){
               min_index = j;
           }
       }
       swap(&arr[i], &arr[min_index]);
   }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends