/*

GeeksForGeeks: Smallest Positive missing number

Link to Problem: https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0

Difficulty: Easy

You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.

References: https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/

*/

// Basic idea is 
// If required number is bigger than size of array then ans must be size of array
// Else the required number is in range 0-size of array(i.e. n)
// Hence use indices to mark number negative so as to mark it as visited
// First position to have positive number on second iteration must be required number

#include<bits/stdc++.h>
using namespace std;
// Puts all negative and 0 elements at start of array so that they do not interfere
// with operation on positive elements
int segregate(int a[],int n){
	int i=0;
	for(int j=0;j<n;j++){
		if(a[j]<=0){
			swap(a[i],a[j]);
			i++;
		}
	}
	return i;
}

// Returns the smallest positive missing number in array
int findSmallestPositiveMissing(int a[],int n){

	for(int i=0;i<n;i++){
		// If number is within index range and value is positive
		// Then mark the number at index equal to value of current number as negative
		if(abs(a[i])-1<n && a[abs(a[i])-1]>0)a[abs(a[i])-1]=-a[abs(a[i])-1];
	}
	// First positive number is answer
	for(int i=0;i<n;i++){
		if(a[i]>0)return i+1;	
	}
	// Else answer is size of array 
	// i.e. array has all elements from 1 to n
	return n+1;
}

int smallestPositiveMissing(int a[],int n){
	// Negative numbers are not needed in array
	int shift = segregate(a,n);
	return findSmallestPositiveMissing(a+shift,n-shift);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<smallestPositiveMissing(a,n)<<endl;
	}
	return 0;
}