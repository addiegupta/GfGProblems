/*

GeeksForGeeks:Sum of Middle Elements of two sorted arrays

Link to Problem: https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0

Given 2 sorted arrays A and B of size N each. Print sum of middle elements of the array obtained after merging the given arrays.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array. The second line contains the N space separated positive integers denoting the elements of array A. The third line contains N space separated positive integers denoting the elements of array B.

Output:
For each testcase, print the sum of middle elements of two sorted arrays. The number of the elements in the merged array are even so there will be 2 numbers in the center n/2 and n/2 +1. You have to print their sum.

Constraints:
1 <= T <= 50
1 <= N <= 103
1 <= A[i] <= 106
1 <= B[i] <= 106

Example:
Input :
1
5
1 2 4 6 10
4 5 6 9 12

Output : 
11

Explanation:
Testcase 1: After merging two arrays, sum of middle elements is 11 (5 + 6).

References: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
*/

#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

//O(log n) method--------------------
int findMedianSumLogarithmic(int a[],int b[],int n){

	// Return sum of only elements in array
	if(n==1) return a[0]+b[0];
	// Max from both at index 0 and min from index 1 to get median 2 element
	if(n==2) return max(a[0],b[0])+min(a[1],b[1]);

	// Median values
	int m1 = a[n/2];
	int m2 = b[n/2];

	// Even number of elements
	if(n%2==0){

		// m1 is smaller: go right in array 1 , left in array 2
		// m2 is smaller: go left in array 1 , right in array 2
		// Take 1 additional element in even case
		return(m1<m2)? findMedianSumLogarithmic(a + n/2 -1,b,n-(n/2)+1):
						findMedianSumLogarithmic(a,b+n/2-1,n-(n/2)+1); 
	}
	else{
	
		// m1 is smaller: go right in array 1 , left in array 2
		// m2 is smaller: go left in array 1 , right in array 2	
		return(m1<m2)? findMedianSumLogarithmic(a + n/2,b,n-n/2):
						findMedianSumLogarithmic(a,b+n/2,n-n/2); 
	}
}

//O(n) method--------------------------------
int findMedianSumLinear(int a[],int b[],int n){
	
	// Similar to picking smaller number in mergesort, smaller number is chosen and counter is incremented
	// When count reaches 
	int sum=0,i=0,j=0;
	while(i+j<=n){
		if(a[i]<=b[j]){
			i++;
			if(i+j==n) sum += a[i];
		}
		else{
			j++;
			if(i+j==n) sum += b[j];
		}
	}
	return sum;
}

int main(){
	int t;
	cin>>t;
	while(t--){

		// Take input
		int n;
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];

		// cout<<findMedianSumLinear(a,b,n)<<endl;
		cout<<findMedianSumLogarithmic(a,b,n)<<endl;
	}
}