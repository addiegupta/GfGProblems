/*

GeeksForGeeks: Longest Common Substring

Link to Problem: https://practice.geeksforgeeks.org/problems/longest-common-substring/0

Difficulty: Medium

Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.

Input : X = "zxabcdezy", y = "yzabcdezx"
Output : 6
The longest common substring is "abcdez" and is of
length 6.
 

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string X and Y respectively
The next two lines contains the 2 string X and Y.


Output:
For each test case print the length of longest  common substring of the two strings .


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100


Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1


*/

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1,string s2,int n1,int n2){

	int dp[n1][n2];
	int max=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(s1[i]==s2[j]){
				// Check for common substring till previous characters in both strings
				(i&&j)?dp[i][j]=dp[i-1][j-1]+1:dp[i][j]++;
				// Update max variable
				if(dp[i][j]>max)max=dp[i][j];
			}
		}
	}
	return max;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		int n1,n2;
		cin>>n1>>n2;
		string s1,s2;
		cin>>s1>>s2;
		cout<<longestCommonSubstring(s1,s2,n1,n2)<<endl;
	}
	return 0;
}