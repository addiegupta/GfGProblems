/*

GeeksForGeeks: Check if strings are rotations of each other or not

Link to Problem: https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not/0

Difficulty: Basic

Given strings s1 and s2, you need to find if s2 is a rotated version of the string s1. The strings are lowercase.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines for s1 and s2.

Output:
For each testcase, in a new line, you need to print 1 if s2 is a rotated version of s1; else print 0.

Constraints:
1 <= T <= 100
1 <= |s1|,|s2| <= 100

Example:
Input:
4
geeksforgeeks
forgeeksgeeks
mightandmagic
andmagicmigth
mushroomkingdom
itsamemario
geekofgeeks
geeksgeekof
Output:
1
0
0
1

Explanation:
Testcase 1: s1 is geeksforgeeks, s2 is forgeeksgeeks. Clearly, s2 is a rotated version of s1 as s2 can be obtained by left-rotating s1 by 5 units.


*/

#include<bits/stdc++.h>
using namespace std;
int isRotatedLibrary(string s1,string s2){
	return (s1.length()==s2.length() && (s1+s1).find(s2)!=string::npos);
}
int isRotated(string s1,string s2){

	// Check if lengths are equal
	int n1=s1.length(),n2=s2.length();
	if(n1!=n2)return 0;
	
	// Iterate over 1st string to find first matching character
	int j=0;
	for(int i=0;i<n1;i++){
		if(s1[i]==s2[j]){
			// Match following characters
			int k = i+1;
			j++;
			while(j<n2){
				if(k>=n1)k=0;
				if(s1[k]==s2[j]){
					j++;
					k++;
				}
				else break;
			}
			if(j==n2)return 1;
			j=0;
		}
	}
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<isRotated(s1,s2)<<endl;
	}
	return 0;
}