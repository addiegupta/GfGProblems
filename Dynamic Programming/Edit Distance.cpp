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
	int cost = 0;
	int a[n1][n2];
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			
		}
	}
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