/*

GeeksForGeeks: Reverse words in a given string

Link to Problem: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

Difficulty: Easy

Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr


*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s;
		cin>>s;
		
		// Word seperator
		string delim = ".";
		
		// Initial position
		int pos = 0;
		
		// Array to store all the words
		string ans[20];
		
		// Size of answer array
		int n=0;
		
		// Individual word
 		string word;

		while (s.length()) {
    		
    		// Find position of "."
    		pos=s.find(delim);

    		// No "." exists
    		if(pos==string::npos)pos=s.length();
    		
    		// Obtain word and add to answer array
    		word = s.substr(0, pos);
    		ans[n++]=word;
    		
    		// Remove word from string
    		s.erase(0, pos + delim.length());
		}
		// Output the string in reverse manner
		for(int i=n-1;i>=0;i--){
			cout<<ans[i];
			if(i)cout<<".";
		}
		cout<<endl;
	}
	return 0;
}