/*

GeeksForGeeks: Anagram

Link to Problem: https://practice.geeksforgeeks.org/problems/anagram/0

Difficulty: Easy

Given two strings, check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, only the order of characters can be different. For example, “act” and “tac” are anagram of each other.

Input: 
The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:
1 ≤ T ≤ 30
1 ≤ |s| ≤ 1016

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic

Output:
YES
NO

*/

#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s1,string s2){
	if(s1.length()!=s2.length())return false;
	long long int l1[26],l2[26];
	memset(l1,0,sizeof(l1));
	memset(l2,0,sizeof(l2));
	for(long long int i=0;i<s1.length();i++){
		l1[s1[i]-'a']++;
		l2[s2[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		cout<<l1[i]<<" "<<l2[i]<<endl;
	}
	for(int i=0;i<26;i++){
		if(l1[i]!=l2[i])return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s1,s2;
		cin>>s1>>s2;
		(isAnagram(s1,s2))?cout<<"YES":cout<<"NO";
		cout<<endl;
	}
	return 0;
}