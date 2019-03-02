/*
GeeksForGeeks: Form a palindrome

Link to Problem: https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

Difficulty: Medium

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3



*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string w=s;
		reverse(w.begin(),w.end());
		int n=s.size();
		int a[n+1][n+1];
		int count =0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				a[i][j]=0; 
			}
		}
		// this loops for checking longest palindrome sequence in string ...

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i-1]==w[j-1])a[i][j]=1+a[i-1][j-1];
				else a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		cout<<n-a[n][n]<<endl; 
	}
	return 0;
	}