/*

GeeksForGeeks: Subset Sum Problem

Link to problem: https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

Difficulty: Easy

Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output: Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
Constraints: 

1 <= T<= 100
1 <= N<= 100
0 <= arr[i]<= 1000

                   
Example:

Input:
2
4
1 5 11 5
3
1 3 5 

Output:

YES
NO

References: https://www.geeksforgeeks.org/partition-problem-dp-18/


*/
#include<bits/stdc++.h>
using namespace std;
bool subsetPartition(int n,int a[]){
	
	int sum =0;
	int i,j;
	for(int i=0;i<n;i++)sum+=a[i];
	if(sum%2!=0)return false;

	bool dp[sum/2 + 1][n+1];

	for(i=0;i<=n;i++)dp[0][i]=true;
	for(i=1;i<=sum/2;i++)dp[i][0]=false;

	for(i=1;i<=sum/2;i++){
		for(j=1;j<=n;j++){
			dp[i][j]=dp[i][j-1];
			if(i>=a[j-1]){
				dp[i][j] = dp[i][j]||dp[i-a[j-1]][j-1];
			}
		}
	}
	return dp[sum/2][n];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		(subsetPartition(n,a))?cout<<"YES":cout<<"NO";
		cout<<endl;
	}
	return 0;
}