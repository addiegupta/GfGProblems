/*

GeeksForGeeks: Minimum sum partition

Link to problem: https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

Difficulty: Hard

Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11},       sum of Subset2 = 11
*/

#include<bits/stdc++.h>
using namespace std;
int minSumPartition(int n,int a[]){
	// Sum of elements of array
	int sum =0;
	for(int i=0;i<n;i++)sum+=a[i];
	int hSum = sum/2;

	// Stores the max possible sums to find minimum sum partition
	int dp[hSum+1][n+1];
	for(int i=0;i<=hSum;i++){
		for(int j=0;j<=n;j++){
			// Initialise first row and first column as 0
			if(!i||!j)dp[i][j]=0;
			// If element in array is less than sum value,set value as max possible sum 
			else if(i>=a[j-1]){
				dp[i][j] = max(dp[i][j-1],dp[i-a[j-1]][j-1]+a[j-1]);
			}
			// Use sum value without the current element included in the set
			else dp[i][j]=dp[i][j-1];
		}
	}
	return sum-2*dp[hSum][n];
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<minSumPartition(n,a)<<endl;
	}
}