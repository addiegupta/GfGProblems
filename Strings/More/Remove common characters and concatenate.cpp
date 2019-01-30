/*

GeeksForGeeks: Remove common characters and concatenate

Link to Problem: https://practice.geeksforgeeks.org/problems/remove-common-characters-and-concatenate/0

Difficulty: Basic

Two strings are given. Modify 1st string such that all the common characters of the 2nd strings have to be removed and the uncommon characters of the 2nd string have to be concatenated with uncommon characters of the 1st string.

Note: If the modified string is empty then print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case consists of a string s1.The next line consists of a string s2. 

Output:
Print the required output.

Constraints: 
1<=T<=200
1<=|Length of Strings|<=100

Example:
Input:
2
aacdb
gafd
abcs
cxzca

Output:
cbgf
bsxz

*/

#include<bits/stdc++.h>
using namespace std;

// Another simple problem involving creating hashes of the strings
string removeCommon(string s1,string s2){
	int hash1[26]={0},hash2[26]={0};
	int n1=s1.length(),n2=s2.length();
	for(int i=0;i<n1;i++){
		hash1[s1[i]-'a']++;
	}
	for(int i=0;i<n2;i++){
		hash2[s2[i]-'a']++;
	}
	string ans;
	for(int i=0;i<n1;i++){
		if(hash2[s1[i]-'a']==0)ans.append(1,s1[i]);
	}
	for(int i=0;i<n2;i++){
		if(hash1[s2[i]-'a']==0)ans.append(1,s2[i]);
	}
	return (ans.empty())?"-1":ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<removeCommon(s1,s2)<<endl;
	}
	return 0;
}