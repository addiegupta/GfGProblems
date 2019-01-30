/*

GeeksForGeeks: Uncommon characters

Link to problem: https://practice.geeksforgeeks.org/problems/uncommon-characters/0

Difficulty: Basic 

Find and print the uncommon characters of the two given strings. Here uncommon character means that either the character is present in one string or it is present in other string but not in both. The strings contain only lowercase characters and can contain duplicates.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two strings.

Output:
Print the uncommon characters of the two given strings in sorted order.

Constraints:
1<=T<=10^5
1<=length of two strings<=10^5

Example:
Input:
1
characters
alphabets

Output:
bclpr


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,ans;
		cin>>a>>b;
		int i;
		// Store character presence by flipping bits
		int bitA=0,bitB=0;
		for(i=0;i<a.length();i++){
			char c = a.at(i);
			bitA |= (1<<(c-'a'));
		}
		for(i=0;i<b.length();i++){
			char c = b.at(i);
			bitB |= (1<<(c-'a'));
		}
		// XOR operation will ensure only characters not appearing in one but present in other are included in ansBit
		int ansBit = bitA^bitB;
		for(int i=0;i<26;i++){
			int b = ansBit & (1<<i);
			if(b){
				ans.append(1,(char)(i+'a'));
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

