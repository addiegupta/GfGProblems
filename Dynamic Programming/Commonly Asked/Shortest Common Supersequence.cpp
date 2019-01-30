/*

GeeksForGeeks: Shortest Common Supersequence

Link to problem: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0

Difficulty: Easy


Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.

Input:
The first line of input contains an integer T denoting the number of test cases.Each test case contains two space separated strings.

Output:
Output the length of the required string.

Constraints:
1<=T<=100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6

*/

#include<bits/stdc++.h>
using namespace std;
// Very similar to Longest Common Subsequence Problem
// Find LCS and then required answer is (length of string 1)+(length of string 2)-(LCS)
int shortestCommonSuperseq(string a,string b){
	int n1,n2;
	n1=a.length();
	n2=b.length();


	// Matrix to store longest common subsequence upto the selected index
	//
	// String a is mapped over the rows of matrix while b mapped over columns
	// Values in matrix will store length of longest common subsequence till selected element
	// e.g. string a = BCD, string b= CDFG
	// Matrix is 
	// 	    C D F G
	//	  0 0 0 0 0
	// B  0
	// C  0	
	// D  0
	int dp[n1+1][n2+1];

	// Initialise first row and column as 0, no subsequence as no character is selected
	for(int i=0;i<=n1;i++)dp[i][0]=0;
	for(int j=0;j<=n2;j++)dp[0][j]=0;

	for(int i=1;i<=n1;i++){
		int c1=a.at(i-1);
		for(int j=1;j<=n2;j++){
			int c2=b.at(j-1);

			// Same char in both strings, increase length of LCS by adding 1 to the (LCS without this char)
			if(c1==c2){
				dp[i][j]= 1+ dp[i-1][j-1];
			}

			// Choose maximum of left and above elements
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	// Return required shortest common supersequence length
	return n1+n2-dp[n1][n2];
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;	
		cout<<shortestCommonSuperseq(a,b)<<endl;
	}
}