/*

GeeksForGeeks: Count number of hops

Link to problem: https://practice.geeksforgeeks.org/problems/count-number-of-hops/0

Difficulty: Easy

Frog steps either 1, 2 or 3 steps to go to top. In how many ways it reaches the top?

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N. Where is the number of steps it has to hop.

Output:

Print the number of ways.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 50

Example:

Input:
2
1
5

Output:
1
13
*/

#include<bits/stdc++.h>
using namespace std;
void init(int dp[]){
	// Number of ways of reaching a number by 1,2,3 steps can be found 
	// by adding number of ways to reach the previous 3 numbers
	// Starting point :
	// 		ways to reach 1 = 1	 => 1
	//		ways to reach 2 = 2: =>1 1, 2 
	//		ways to reach 3 = 4: =>1 1 1, 1 2, 2 1,3 
	
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for(int i=4;i<=50;i++)dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
}

int main()
{
	int t;
	cin>>t;
	int dp[51];
	init(dp);
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
}