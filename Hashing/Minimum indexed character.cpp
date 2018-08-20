/*

GeeksForGeeks: Minimum indexed character

Link to problem: https://practice.geeksforgeeks.org/problems/minimum-indexed-character/0

Difficulty: Easy 

Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Print the character in patt that is present at the minimum index in str.
Print "No character present" (without quotes) if no character of patt is present in str.

Constraints:
1<=T<=10^5
1<=length of string<=10^5

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
No character present


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int i;
		string s,p;
		cin>>s>>p;
		int prev=0;
		// Store the occurence of a character in an integer by flipping a bit
		for(i =0;i<p.length();i++){
			int temp = p.at(i)-'a';
			prev |= (1<<temp);
		}
		int f=0;
		for(i=0;i<s.length();i++){
			int ch = s.at(i)-'a';
			// Check if bit for current character has been flipped before or not
			if((prev & (1<<ch))>0){
				f=1;
				cout<<s.at(i)<<endl;
				break;
			}
		}
		if(!f)cout<<"No character present"<<endl;
	}

	return 0;
}

