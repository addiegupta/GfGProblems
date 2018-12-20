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