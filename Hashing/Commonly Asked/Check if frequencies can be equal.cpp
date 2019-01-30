/*

GeeksForGeeks: Check if frequencies can be equal

Link to problem: https://practice.geeksforgeeks.org/problems/check-frequencies/0

Difficulty: Easy

Given a string s which contains lower alphabetic characters, the task is to check if its possible to  remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string.
Examples:

Input  : s = “xyyz”
Output : 1
We can remove character ’y’ from above 
string to make the frequency of each 
character same. 

Input : s = “xxxxyyzz” 
Output : 0
It is not possible to make frequency of 
each character same just by removing at 
most one character from above string.


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print 1 if its possible to make frequencies of all characters equal else print 0.

Constraints:
1<=T<=1000
1<=length of strings <=10000

Example:
Input:
2
xyyz
xxxxyyzz
Output:
1
0


*/

#include<bits/stdc++.h>
#define max 26
using namespace std;
// Returns index of character
int index(char c){
	return c-'a';
}
// Checks if all non zero values are equal in an array
// The array stores count of every lowercase letter
bool sameFreq(int a[]){
	int i,same;
	// First non zero value
	for(i=0;i<max;i++){
		if(a[i]){
			same = a[i];
			break;
		}
	}
	for(int j=i+1;j<max;j++){
		if(a[j]&&a[j]!=same){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		int f=0;
		cin>>s;
		int a[max] = {0};

		// Store frequency of every letter occuring in the string
		for(int i=0;i<s.length();i++){
			a[index(s[i])]++;
		}
		// No letters need to be removed already same frequency of every letter
		if (sameFreq(a)){
			cout<<1<<endl;
			continue;
		}

		for(int i=0;i<max;i++){
			if(a[i]>0){
				// Remove this particular letter and check if frequencies are equal for every letter
				a[i]--;
				if(sameFreq(a)){
					cout<<1<<endl;
					f=1;
					break;
				}
				a[i]++;
			}
		}
		if(!f)cout<<0<<endl;
	}
	return 0;
}