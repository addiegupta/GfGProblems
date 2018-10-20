/*

GeeksForGeeks: Coin Change

Link to problem: https://practice.geeksforgeeks.org/problems/coin-change/0

Difficulty: Medium

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:

The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:

Print number of possible ways to make change for N cents.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 1 ≤ A[i] ≤ 300

Example:

Input:

2
3
1 2 3
4
4
2 5 3 6
10

Output:

4
5


*/
#include<bits/stdc++.h>
using namespace std;
int coinChange(int n,int m,int a[]){

	// Stores number of ways to make i total amount
	int dp[m+1];
	memset(dp,0,sizeof(dp));
	// 1 way to have 0 coins
	dp[0]=1;

	// Traverse through value of coin(array 'a') and for each value, go through 0 to required amount
	// determining the number of ways to obtain a total of the particular index in array 'dp'
	// Subsequently smaller values will be looked upon to create bigger totals by subtracting
	// one unit of new coin value
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			// One unit of coin value(a[i]) can be deducted
			if(j>=a[i]){
				dp[j] += dp[j-a[i]];
			}
		}
	}
	return dp[m];
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		int a[n+1];
		a[0]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		cin>>m;
		cout<<coinChange(n,m,a)<<endl;
	}
	return 0;
}