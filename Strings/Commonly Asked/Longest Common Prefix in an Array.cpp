/*

GeeksForGeeks: Longest Common Prefix in an Array

Link to Problem: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0

Difficulty: Basic

Given a array of N strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. Each test case contains an integer N. Next line has space separated N strings.

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).

Constraints:
1 <= T <= 103
1 <= N <= 103
1 <= |S| <= 103

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

Explanation:
Testcase 1: Longest common prefix in all the given string is gee.


*/
#include<bits/stdc++.h>
using namespace std;

//TODO Also implement this using Trie DS
string longestCommonPrefix(string s[],int n){

	// Max prefix length
	int ans=0;
	// Get the shortest string to set bound on max possible answer
	int minLen=s[0].length();
	for(int i=1;i<n;i++){
		if(minLen>s[i].length())minLen=s[i].length();
	}

	// Iterate character by character columnwise; if any character mismatch is found
	// then no longer prefix can be found ; return substring 
	for(int i=0;i<minLen;i++){
		char c = s[0][i];
		for(int j=0;j<n;j++){
			if(s[j][i]!=c) return (ans>0)?s[0].substr(0,ans):"-1";
		}
		ans++;
	}
	return (ans>0)?s[0].substr(0,ans):"-1";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)cin>>s[i];
        cout<<longestCommonPrefix(s,n)<<endl;
    }
}

