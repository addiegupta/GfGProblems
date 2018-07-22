/*

GeeksForGeeks: Maximum sum increasing subsequence

Link to Problem: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0

Difficulty:Easy

Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[].

Output:

Print the sum of maximum sum sequence of the given array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ A[] ≤ 1000

Example:

Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
For input:
7
1 101 2 3 100 4 5
All the increasing subsequences : (1,101); (1,2,3,100); (1,2,3,4,5), out of this (1,2,3,100) has maximum sum,i.e., 106. Hence the output is stated as 106.

References: https://www.youtube.com/watch?v=99ssGWhLPUE
*/


#include<iostream>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,a[100],b[100],max=0,i;
 		cin>>n;
 		for (i=0;i<n;i++){
 			cin>>a[i];
 			// Create a array to store the max subsequence sum till the particular index
 			b[i]=a[i];
 		}
 		for(i=1;i<n;i++){
 			for(int j=0;j<i;j++){
 				// Follows increasing subsequence pattern
 				if(a[j]<a[i]){
 					// Current sum is greater than existing sum
 					if(a[i]+b[j]>b[i]){
 						// Replace the sum with new value
 						b[i]=a[i]+b[j];
 					}
 				}
 			}
 		}
 		// Find max value of sum
 		for(i=0;i<n;i++){
 			if(b[i]>max){
 				max = b[i];
 			}
 		}
 		cout<<max<<endl;
 	}
	return 0;
}