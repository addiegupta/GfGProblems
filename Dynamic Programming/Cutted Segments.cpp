/*

GeeksForGeeks: Cutted Segments

Link to problem: https://practice.geeksforgeeks.org/problems/cutted-segments/0

Difficulty: Easy

Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1. In secon test case, we can make two segments of lengths 3 and 2.



*/

#include<bits/stdc++.h>
using namespace std;
int rodCutting(int a[],int n){

	// Obtain minimum cutting length
	int min =INT_MAX;
	for(int i=0;i<3;i++){
		if(a[i]<min)min=a[i];
	}

	// Array to store maximum pieces obtained for length of rod = index in array
	int dp[n+1];
	memset(dp,-1,sizeof(dp));
	// Cost for 0 is 0
	dp[0]=0;
	int i=min;
	int j;
	for(;i<=n;i++){
		int max =-1;
		for(j=0;j<3;j++){
			
			// More number of cuts obtained
			if(a[j]<=i && dp[i-a[j]]!=-1 && dp[i-a[j]]+1>max ){
				max = dp[i-a[j]]+1;
			}
		}
		dp[i]=max;
	}
	return dp[n];
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// Input the lengths in which rod can be cut
		int a[3];
		for(int i=0;i<3;i++)cin>>a[i];
		cout<<rodCutting(a,n)<<endl;

	}
}