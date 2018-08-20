/*

GeeksForGeeks: Find first repeated character

Link to problem: https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0

Difficulty: Basic

Given a string s, the task is to find the first repeated character in it. We need to find the character that occurs more than once and whose index of first occurrence is smallest.

Examples:

Input:  s = "geeksforgeeks"
Output: e 
e is the first element that repeats

Input:  s = "hellogeeks"
Output: l 
l is the first element that repeats

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the first repeating character in the string. If no such character exist print -1.

Constraints:
1<=T<=100
1<=Length of string <=1000

Example:
Input:
2
geeksforgeeks
hellogeeks
Output:
e
l

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		unordered_set<char> prev;
		int i;
		for(i=0;i<s.length();i++){
			char c = s.at(i);
			// First occurence; store in hash
			if(prev.find(c)==prev.end()) prev.insert(c);
			// Second occurence
			else break;
		}
		(i==s.length())?cout<<-1<<endl:cout<<s.at(i)<<endl;
	}
	return 0;
}

