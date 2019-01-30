/*

GeeksForGeeks: Longest Palindrome in a String

Link to Problem: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

Difficulty: Medium

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the test cases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

References: https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

*/

#include<bits/stdc++.h>
using namespace std;
// O(n^2) time and O(1) space where n is length of string -----------------------
string findLargestPalindrome(string s){
	// Signifies start index and length of max length palindrome
	int start=0,maxL=1;
	int n= s.length();

	// Iterator variables
	int low,high;

	// Iterate over string characters
	for(int i=1;i<n;i++){

		//Find longest even length palindrome

		low=i-1;
		high = i;
		while(low>=0 and high <n and s[low]==s[high]){
			
			// Longer palindrome found
			if(high-low + 1>maxL){
				start = low;
				maxL=high-low+1;
			}
			low--;
			high++;
		}

		// Find longest odd length palindrome

		low =i-1;
		high = i+1;
		while(low>=0 and high<n and s[low]==s[high]){
			
			// Longest palindrome found
			if(high-low+1>maxL){
				start = low;
				maxL = high - low +1;
			}
			low--;
			high++;
		}
	}

	// Return palindrome
	return s.substr(start,maxL);

}

int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s;
		cin>>s;
		// Print largest palindrome
		cout<<findLargestPalindrome(s)<<endl;
	}
	return 0;
}