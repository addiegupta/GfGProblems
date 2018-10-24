/*

GeeksForGeeks: Longest Increasing Subsequence

Link to problem: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

Difficulty: Medium

Given a sequence, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest
to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

For example:
 length of LIS for 
{ 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.


Output:

Print the Max length of the subsequence in a separate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300

Example:

Input
1
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
Output
6

*/
#include<bits/stdc++.h>
using namespace std;

// O(n^2) solution---------------------------
int longestIncSubsequenceNSquared(int a[],int n){
	
	// Store subproblem values i.e. longest inc subsequence length till all numbers
	map<int,int> dp;
	// Longest length
	int overallMax=0;
	// Iterate over array
	for(int i=0;i<n;i++){
		// To obtain max till this particular number in array
		int max = 0;
		// Find max subsequence till here
		for(int j=0;j<=i;j++){
			if(a[j]<a[i]&&dp[a[j]]>max){
				max=dp[a[j]];
			}
		}
		// Store updated for this number
		dp[a[i]]=max+1;
		if(dp[a[i]]>overallMax)overallMax=dp[a[i]];
	}
	return overallMax;
}

// O(n logn) solution---------------------------
int longestIncSubsequence(int a[],int n){
	// Stores longest increasing subsequence
	int b[n];
	// Size of longest inc subsequence
	int size=0;
	// Initialise with first element
	b[0]=a[0];

	// Iterate over array
	for(int i=1;i<n;i++){
		// Append to end of increasing subsequence
		if(a[i]>b[size]){
			size++;
			b[size]=a[i];
		}
		// Apply binary search to find the position to insert this element in subsequence
		// This is required to reduce the values of elements in subsequence to find optimal solution
		else{
			int low = 0;
			int high = size;
			while(low<=high){
				int mid = (low+high)/2;
				if(b[mid]<a[i])low = mid+1;
				else high = mid-1;
			}
			// Insert element at its position
			b[low] = a[i];
		}
	}
	// Size was index based so return size + 1
	return size+1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<longestIncSubsequence(a,n)<<endl;
	}
	return 0;
}