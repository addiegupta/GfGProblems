/*

GeeksForGeeks: 0 - 1 Knapsack Problem

Link to problem: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

Difficulty: Easy

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item, In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of four lines. The first line consists of N the number of items. The second line consists of W, the maximum capacity of the knapsack. In the next  line are N space separated positive integers denoting the values of the N items and in the fourth line are N space separated positive integers denoting the weights of the corresponding items.
 

Output:

Print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.
 

Constraints:

1≤T≤100

1≤N≤100

1≤W≤100

1≤wt[i]≤100

1≤v[i]≤100


Example:

Input:
1
3
4
1 2 3
4 5 1
Output:
3


*/
#include<bits/stdc++.h>
using namespace std;
// 0/1 Knapsack problem
int knapsack(int n,int w,int val[],int wt[]){
	// Max possible sum array for each element
	int dp[w+1];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++){
		// Iterating through total weight of knapsack i.e. keeping possible values 
		// between w and 1
		for(int j=w;j>0;j--){
			// This item can be inserted in knapsack
			if(wt[i]<=j){
				// Choose between inserting and not inserting item in knapsack
				// dp[j]::Dont choose item
				// val[i]+dp[j-wt[i]]:: Choose item and add sum of other possible items
				dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
			}
		}
	}
	// Max possible sum
	return dp[w];

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,w;
		cin>>n>>w;
		int wt[n],val[n];
		for(int i=0;i<n;i++)cin>>val[i];
		for(int i=0;i<n;i++)cin>>wt[i];
		cout<<knapsack(n,w,val,wt)<<endl;
	}
	return 0;
}