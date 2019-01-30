/*

GeeksForGeeks: Heap Sort

Link to Problem: https://practice.geeksforgeeks.org/problems/heap-sort/1

Difficulty: Easy

The task is to complete heapify() and buildHeap() functions which are used to implement Heap Sort. 

Input:
First line of the input denotes number of test cases 'T'. First line of the test case is the size of array and second line consists of array elements.


Output:
Sorted array in ascending order.


Constraints:
1 <=T<= 50
1 <=N<= 1000
1 <=arr[i]<= 1000


Example:

Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10


*/

// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);
void buildHeap(int arr[], int n);
// main function to do heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("
");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
void heapify(int arr[], int n, int i)  {
      // Your Code Here
    int max = i;
	int l = 2*i +1;
	int r = 2*i +2;

	if(l<n && arr[l]>arr[max]){
		max = l;
	}
	if(r<n && arr[r]>arr[max]){
		max = r;
	}
	if(max!=i){
		swap(arr[i],arr[max]);
		heapify(arr,n,max);
	}
      
}
// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    // Your Code Here
    for(int i= n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}

	for(int i=n-1;i>=0;i--){
		// swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
