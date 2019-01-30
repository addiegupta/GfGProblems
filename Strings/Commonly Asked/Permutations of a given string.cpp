/*

GeeksForGeeks: Permutations of a given string

Link to Problem: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

Difficulty: Basic

Given a string, print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases.
Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG
Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA 


*/

#include<bits/stdc++.h>
using namespace std;

void permute(set<char> c,string s,vector<string> &ans, string word){
	
	// Word complete; add it to vector of answers
	if (word.length()==s.length()){
		ans.push_back(word);
		return;
	}

	// Continue with creating word
	for(int i = 0;i<s.length();i++){
		// Do not include previously used character
		if(c.find(s[i])!=c.end())continue;
		c.insert(s[i]);
		permute(c,s,ans,word+s[i]);
		c.erase(s[i]);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s;
		cin>>s;
		// Vector to store all permutations
		vector<string> ans;
		// Set to store characters used up in current permutation
		set<char> c;
		// To obtain answer in lexicographically sorted manner
		sort(s.begin(),s.end());

		for(int i = 0;i<s.length();i++){
			
			// Backtracking algorithm to cover all permutations
			// Add current character to set
			c.insert(s[i]);
			// Find permutations having s[i] as first character
			string wrd(1,s[i]);
			permute(c,s,ans,wrd);
			// Remove current character from set and continue with iteration
			c.erase(s[i]);
		}
		// Print answers
		vector<string>::iterator it;
		for(it=ans.begin();it!=ans.end();it++) cout<<*it<<" ";
		cout<<endl;
	}
	return 0;
}