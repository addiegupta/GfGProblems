/*

GeeksForGeeks: Egg Dropping Puzzle

Link to problem: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

Difficulty: Medium

Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50


Example:
Input:
1
2 10

Output:
4

References: https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

*/

#include<bits/stdc++.h>
using namespace std;
int eggDrop(int n,int k){

	// Matrix to store min number of attempts to determine the correct floor in worst case
	// n is number of eggs
	// k is number of floors
	int dp[n+1][k+1];

	// 0 attempts for 0 floors
	// 1 attempt for 1 floor 
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
		dp[i][1]=1;
	}
	// 0 attempts with 0 eggs
	// i attempts with 1 egg for i floors
	for(int i=0;i<=k;i++){
		dp[0][i]=0;
		dp[1][i]=i;
	}

	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){

			// Init with max value, now determine min possible value
			dp[i][j]=INT_MAX;
			int res;
			// iterate through the floors 1 to j
			for(int x = 1;x<=j;x++){
				//1+ : throwing the egg counts as an attempt
				// dp[i-1][x-1]: egg breaks hence consider the case 
				// 				 with 1 less egg and floors remaining equal to x-1 i.e. below floors
				// dp[i][j-x]: egg doesnt break, consider the case with same number of eggs
				//				and floors equal to j-x i.e. the floors above this floor
				// Taking the max of these 2 values ensures that worst case is considered
				res = 1 + max(dp[i-1][x-1],dp[i][j-x]);

				// Keep minimum value of each iteration in dp array
				if(res<dp[i][j])dp[i][j]=res;
			}
		}
	}
	return dp[n][k];

}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<eggDrop(n,k)<<endl;
	}
}