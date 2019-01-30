/*

GeeksForGeeks: Check if string is rotated by two places

Link to Problem: https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0

Difficulty: Basic

Given two strings, the task is to find if a string ('a') can be obtained by rotating another string ('b') by two places.
Examples:
Input : a = "amazon" 
           b = "azonam" // rotated anti-clockwise 
Output : 1 
Input : a = "amazon" 
           b = "onamaz" // rotated clockwise 
Output : 1

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1<=T<=50
1<=length of a, b <100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0



*/

#include<bits/stdc++.h>
using namespace std;
int twoRotationPossible(string s1,string s2){
	// Stores clockwise and anticlockwise rotation
	string cl="",acl="";
	int len = s1.length();

	// ACW rotation
	acl=s1.substr(2)+s1.substr(0,2);
	//  CW rotation
	cl=s1.substr(len-2,2)+s1.substr(0,len-2);

	return (acl==s2||cl==s2);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s1,s2;
		cin>>s1>>s2;
		cout<<twoRotationPossible(s1,s2)<<endl;
	}
	return 0;
}