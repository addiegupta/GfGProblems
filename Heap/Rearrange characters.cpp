/*

GeeksForGeeks: Rearrange characters

Link to Problem: https://practice.geeksforgeeks.org/problems/rearrange-characters/0

Difficulty: Medium

Given a string with repeated characters, task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.


Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print 1 if the generated sting doesn't contains any same adjacent characters, else if no such string is possible to be made print 0.
Constraints:
1<=T<=100
1<=length of string<=600

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int i,a[26];
		for(i=0;i<26;i++)a[i]=0;
		// Store the count of each character in array
		for(i=0;i<s.length();i++){
			char c = s.at(i);
			a[c-97]++;
		}
		// Flag to check if desired rearrange is possible or not
		int f=0;
		for(i=0;i<26;i++){
			if(a[i]>s.length()-a[i]){
				f=1;
				break;
			}
		}
		if(f)cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}