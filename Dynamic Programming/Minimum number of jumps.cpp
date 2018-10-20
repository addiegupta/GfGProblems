/*

GeeksForGeeks: Minimum number of jumps

Link to problem: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

Difficulty: Medium

Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains a number n denoting the size of the array.
Next line contains the sequence of integers a1, a2, ..., an.

Output:
Each seperate line showing the minimum number of jumps. If answer is not possible print -1.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
0<=a[N]<=100

Example:

Input:

1
11
1 3 5 8 9 2 6 7 6 8 9

Output:

3


*/
#include<bits/stdc++.h>
using namespace std;
// O(n^2) solution-------------------------------
int minJumpNSquared(int a[],int n){
	// Store number of jumps required from position to reach last element
	int dp[n];
	memset(dp,0,sizeof(dp));
	// Start adding values to dp from second last element
	for(int i=n-2;i>=0;i--){

		int distToEnd = n-1-i;
		// One jump is required
		if(a[i]>=distToEnd)dp[i]=1;
		// Invalid element
		else if(!a[i]){
			dp[i]=-1;
		}
		// Find the best possible element for shortest path by iterating through
		// elements within range of this element i.e. 0-a[i]
		else{	
			int min=INT_MAX;
			for(int j=i+1;j<n-1&&j-i<=a[i];j++){
				if(dp[j]<min&&dp[j]>0)min = dp[j];				
			}
			// Set -1 if invalid route otherwise the minimum number of jumps
			(min==INT_MAX)?dp[i]=-1:dp[i]=min+1;
		}
	}
	return dp[0];
}
// O(n) solution ---------------------------------
int minJump(int a[],int n){
	// Ladder is the max number of steps available without jump
	int ladder = a[0];
	// Steps is the number of steps left on the ladder
	int steps = a[0];
	// Initialise jump count to 1 as at least 1 jump will be required
	int jump =1;
	// No possible solution
	if(!a[0])return -1;
	// Iterate through array
	for(int i=1;i<n-1;i++){
		// Bigger ladder found, use it 
		if(i+a[i]>ladder){
			ladder = i + a[i];
		}
		// Decrement steps as iteration takes place
		steps--;
		// No possible route
		if(!a[i]&&!steps)return -1;
		// End of steps ;add more steps from updated ladder; increment jump counter
		if(!steps){
			jump++;
			steps = ladder-i;
		}
	}
	return jump;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<minJump(a,n)<<endl;
	}
	return 0;
}