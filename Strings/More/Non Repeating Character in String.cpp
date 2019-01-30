/*

GeeksForGeeks: Non Repeating Character

Link to Problem: https://practice.geeksforgeeks.org/problems/non-repeating-character/0

Difficulty: Easy

Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single integer N denoting the length of string. The next line contains the string S.

Output:
For each testcase, print the first non repeating character present in string. Print -1 if there is no non repeating character.

Constraints:
1 <= T <= 900
1 <= N <= 104

Example:
Input : 
3
5  
hello
12
zxvczbtxyzvy
6
xxyyzz

Output :
h
c
-1




*/

#include<bits/stdc++.h>
#define BASE 26
using namespace std;
char firstNonRepeating(string s){
	int hash[BASE] = {0};
	for(int i=0;i<s.length();i++){
		hash[s.at(i)-'a']++;
	}
	for(int i=0;i<s.length();i++){
		if(hash[s.at(i)-'a']==1)return s.at(i);
	}
	cout<<-1;
	return ' ';
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		cout<<firstNonRepeating(s)<<endl;
	}
	return 0;
}