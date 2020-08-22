/*

GeeksForGeeks: Maximum of all subarrays of size k

Link to Problem: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

Difficulty:Easy

Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer 'N' denoting the size of array and the size of subarray 'k'.
The second line contains 'N' space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 100
1 ≤ k ≤ N
0 ≤A[i]<1000

Example:

Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

*/


#include<iostream>
#include<vector>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int i,n,k,a[100],b[100],max=0;
 		//Stores the current subarray
 		vector<int> v;
 		cin>>n>>k;
 		for (i=0;i<n;i++){
 			cin>>a[i];
 			// Stores the first subarray of size k
 			if(i<k){
 				v.push_back(a[i]);
 				if(a[i]>max){
 					max=a[i];
 				}
 			}
 			// b array stores max values for the subarrays
 			b[0]=max;
 		}
 		for(int i=1;i<n-k+1;i++){
 			
 			// Element to be removed is the max value. Find new max value
 			if(v.front()==max){
 				max=0;
 				for(int j=1;j<k;j++){
 					if(v.at(j)>max){
 						max=v.at(j);
 					}
 				}
 			}
 			// Remove first element
 			v.erase(v.begin());
 			// Add new element
 			int l = a[i+k-1];
 			v.push_back(l);
 			if(l>max){
 				max=l;
 			}
 			b[i]=max;
 		}
 		for(i=0;i<n-k+1;i++){
 			cout<<b[i]<<" ";
 		}
 		cout<<endl;
 	}
	return 0;
}

// Deque solution copied from gfg editorial

public class SlidingWindow { 
  
    // A Dequeue (Double ended queue) based method for printing maximum element of 
    // all subarrays of size k 
    static void printMax(int arr[], int n, int k) 
    { 
        // Create a Double Ended Queue, Qi that will store indexes of array elements 
        // The queue will store indexes of useful elements in every window and it will 
        // maintain decreasing order of values from front to rear in Qi, i.e., 
        // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order 
        Deque<Integer> Qi = new LinkedList<Integer>(); 
  
        /* Process first k (or first window) elements of array */
        int i; 
        for (i = 0; i < k; ++i) { 
            // For every element, the previous smaller elements are useless so 
            // remove them from Qi 
            while (!Qi.isEmpty() && arr[i] >= arr[Qi.peekLast()]) 
                Qi.removeLast(); // Remove from rear 
  
            // Add new element at rear of queue 
            Qi.addLast(i); 
        } 
  
        // Process rest of the elements, i.e., from arr[k] to arr[n-1] 
        for (; i < n; ++i) { 
            // The element at the front of the queue is the largest element of 
            // previous window, so print it 
            System.out.print(arr[Qi.peek()] + " "); 
  
            // Remove the elements which are out of this window 
            while ((!Qi.isEmpty()) && Qi.peek() <= i - k) 
                Qi.removeFirst(); 
  
            // Remove all elements smaller than the currently 
            // being added element (remove useless elements) 
            while ((!Qi.isEmpty()) && arr[i] >= arr[Qi.peekLast()]) 
                Qi.removeLast(); 
  
            // Add current element at the rear of Qi 
            Qi.addLast(i); 
        } 
  
        // Print the maximum element of last window 
        System.out.print(arr[Qi.peek()]); 
    } 
  
    // Driver program to test above functions 
    public static void main(String[] args) 
    { 
        int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
        int k = 3; 
        printMax(arr, arr.length, k); 
    } 
} 