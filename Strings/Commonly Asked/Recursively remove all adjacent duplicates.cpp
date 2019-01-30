/*

GeeksForGeeks: Recursively remove all adjacent duplicates

Link to Problem: https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0

Difficulty: Easy

Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should not have any adjacent duplicates.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac

*/

#include<bits/stdc++.h>
using namespace std;

// Remove characters that are found more than once adjacently in a string
// This does not leave any instance of the recurring character
// e.g. "collapse" will be converted to "coapse"
//      "attack" will be converted to  "ck" as the "a" also becomes adjacently recurring

string removeDuplicates(string s){
	
	//Stores length of string s
	int n;
	
	// Initialise answer string to input string
	string ans=s;
	
	// Stores adjacently recurring character
	char c=NULL;
	
	// Var for requirement of checking the string again for recurring characters
	bool repeat=true;
	while(repeat){
	
		// No need to repeat again unless this is changed to "true"
		repeat = false;
		s=ans;
	
		// Make answer string empty; Only non recurring characters will be appended to "ans"
		ans="";
	
		// Length of new "s" in the while loop
		n=s.length();
		for(int i=0;i<n;i++){

			// Adjacent recurring characters found
	 		if(s[i]==s[i+1]){
				c=s[i];

				// Recurring character found; repeat while loop again
				repeat=true;	
				continue;
			}

			// Make c NULL as chain of recurring character has ended		
			if(c){
				c=NULL;
			}

			// Add character to ans string
			else{
				ans.append(1,s[i]);
			}
		}
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s;
		cin>>s;

		cout<<removeDuplicates(s)<<endl;
	}
	return 0;
}