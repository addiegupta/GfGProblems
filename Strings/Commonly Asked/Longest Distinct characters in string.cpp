/*

GeeksForGeeks: Longest Distinct characters in string

Link to Problem: https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0

Difficulty: Easy

Given a string S, find length of the longest substring with all distinct characters.  For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:
Print length of smallest substring with maximum number of distinct characters.
Note: The output substring should have all distinct characters.

Constraints:
1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:
Input:
2
abababcdefababcdab
geeksforgeeks

Output:
6
7


*/

#include<bits/stdc++.h>
#include<string>
using namespace std;
#define MAX 26
// Better solution--------------------------------
// Solution by creating a hash for all characters using array of fixed length i.e. 26
// This hash array stores index of the character
int longestSubstringDistinctHash(string s){
	// Prev stores the previous occurence of the current character
	int max=0,len=0,prev;
	int hash[MAX];
	memset(hash,-1,sizeof(hash));

	// Store the index for first character as 0 and init length as 1
	hash[s[0]]=0;
	len=1;

	// Iterate over string
	for(int i=1;i<s.length();i++){
		
		// Get index of the current character from hash
		// Value is -1 if char has not been encountered before
		prev = hash[s[i]];

		// Not encountered before / Past the range of current substring 
		if(prev<0||i-len>prev)len++;

		// Non distinct character; substring needs to be updated
		else{
			// Update max variable
			if(len>max)max=len;

			// Shorten substring by updating iterator values
			len = i-prev;
		}

		// Add current value to hash
		hash[s[i]]=i;
	}
	return max;
}
// Solution by creating actual substring having distinct characters
int longestSubstringDistinct(string s){

	// Stores current substring
	string sub="";
	int max=0;
	for(int i=0;i<s.length();i++){
		// Add character to end of substring
		sub.append(1,s[i]);

		// Character seen before in the substring
		if(sub.find(s[i])!=sub.length()-1){
			// Remove substring from "sub" until the current character
			// e.g. for "abcdb" the substring "ab" will be removed and result is "cdb"
			sub.erase(sub.begin(),sub.begin()+sub.find(s[i])+1);
		}
		if(max<sub.length())max=sub.length();
	}
	return max;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s;
		cin>>s;
		cout<<longestSubstringDistinct(s)<<endl;
	}
	return 0;
}