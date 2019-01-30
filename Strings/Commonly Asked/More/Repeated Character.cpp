/*

GeeksForGeeks: Repeated Character

Link to Problem: https://practice.geeksforgeeks.org/problems/repeated-character/0

Difficulty: Basic

Given a string - "str", find the repeated character present first in the string.

Example : 
Input  :  geeksforgeeks
Output :  g
          (mind that it will be g, not e.)

Input : 
The first line of input contains an integer T denoting the Test cases. Then T test cases follow. 
Second line contains the string - "str"

Output : 
repeated character present first in the string, if present
otherwise print "-1"


Input : 
3
hello
fg
geeksforgeeks

Output : 
l
-1
g


*/

#include<bits/stdc++.h>
using namespace std;

char firstRepeatedChar(string s){

	// Create hash for occurence of lower case letters
	int hash[26]={0};
	for(int i=0;i<s.length();i++){
		hash[s[i]-'a']++;
	}
	// Find first character whose hash value is greater than 1
	for(int i=0;i<s.length();i++){
		if(hash[s[i]-'a']!=1)return s[i];
	}
	cout<<-1;
	return ' ';
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<firstRepeatedChar(s)<<endl;
	}
	return 0;
}