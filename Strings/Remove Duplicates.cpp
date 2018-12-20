/*

GeeksForGeeks: Remove Duplicates

Link to Problem: https://practice.geeksforgeeks.org/problems/remove-duplicates/0

Difficulty: Easy

Given a string, remove duplicates from it. Note that original order of characters must be kept same.  Expected time complexity O(n) where n is length of input string and extra space O(1) under the assumption that there are total 256 possible characters in a string.

Input: First line of the input is the number of test cases T. And first line of test case contains a string.

Output:  Modified string without duplicates and same order of characters.

Constraints:  Input String Length <= 1000

Example:
Input:
2
geeksforgeeks
geeks for geeks

Output:
geksfor
geks for


*/

#include<bits/stdc++.h>
#include<string>
using namespace std;
// Removes duplicates and returns string
string removeDuplicates(string s){
	// Hash to keep track if character has been seen before
	bool hash[256];
	memset(hash,0,sizeof(hash));
	string ans="";
	for(int i=0;i<s.length();i++){
		// Append char to ans string if not seen before
		// Add to hash to represent that this character has been seen 
		if(!hash[s[i]]){
			hash[s[i]]=true;
			ans.append(1,s[i]);
		}
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	// Used to ignore the '\n' after entering number of test cases
	// This ignore is required before using getline otherwise '\n' gets in buffer for getline
	cin.ignore();
	while(t--){
		//Input string
		string s;
		getline(cin,s);
		cout<<removeDuplicates(s)<<endl;

	}
	return 0;
}