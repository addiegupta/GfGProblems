/*

GeeksForGeeks: Edit Distance

Link to problem: https://practice.geeksforgeeks.org/problems/edit-distance/0

Difficulty: Medium

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.


Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1<=T<=50
1<= Length(str1) <= 100
1<= Length(str2) <= 100
 

Example:
Input:
1
4 5
geek gesek

Output:
1


*/
#include<bits/stdc++.h>
using namespace std;
int minEdit(int n1,int n2,string s1,string s2){
	
	// Taking matrix with rows representing letters of s1 ( including a 0 for no character)
	// and columns representing letters of s2( including 0 )
	int dp[n1+1][n2+1];


	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			// If either string is empty, insertions will be equal to number of characters
			// in other string
			if(!i) dp[i][j]=j;
			else if(!j) dp[i][j]=i;
			// If character is same, no operation required on this character
			else if(s1.at(i-1)==s2.at(j-1)) dp[i][j]=dp[i-1][j-1];
			// Characters not same, take minimum number of operations
			// from top,left and top-left and add 1 to it(for replace operation)
			else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	return dp[n1][n2];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n1,n2;
		cin>>n1>>n2;
		string s1,s2;
		cin>>s1>>s2;
		cout<<minEdit(n1,n2,s1,s2)<<endl;
	}
	return 0;
}