/*

GeeksForGeeks: Longest Common Subsequence

Link to problem: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

Difficulty: Medium

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .


Output:
For each test case print the length of longest  common subsequence of the two strings .


Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100


Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2

References: https://www.youtube.com/watch?v=NnD96abizww

*/
#include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(int n1,int n2,string a,string b){
	// Matrix to store longest common subsequence upto the selected index
	int dp[n1+1][n2+1];
	// Initialise first row and column as 0, no subsequence as no character is selected
	for(int i=0;i<=n1;i++)dp[i][0]=0;
	for(int i=0;i<=n2;i++)dp[0][i]=0;

	// String a is mapped over the rows of matrix while b mapped over columns
	// Values in matrix will store length of longest common subsequence till selected element
	// e.g. a = BCD b= CDFG
	// Matrix is 
	// 	    C D F G
	//	  0 0 0 0 0
	// B  0
	// C  0	
	// D  0
	char col[n1+1],row[n2+1];
	for(int i=1;i<=n1;i++)col[i]=a[i-1];
	for(int i=1;i<=n2;i++)row[i]=b[i-1];
	
	// Store values for longest common subsequence	
	int length=0;
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			// Same char in both strings, increase length of LCS by adding 1 to LCS without this char
			if(col[i]==row[j]){
				dp[i][j]=dp[i-1][j-1]+1;	
			}
			// Choose maximum of left and above elements
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			if(length<dp[i][j])length = dp[i][j];
		}
	}
	return length;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n1,n2;
		cin>>n1>>n2;
		string a,b;
		cin>>a>>b;
		cout<<longestCommonSubsequence(n1,n2,a,b)<<endl;
	}
	return 0;
}