/*

GeeksForGeeks: Save Ironman

Link to Problem: https://practice.geeksforgeeks.org/problems/save-ironman/0

Difficulty: Easy

Jarvis is weak in computing palindromes for Alphanumeric characters.
While Ironman is busy fighting Thanos, he needs to activate sonic punch but Jarvis is stuck in computing palindromes.
You are given a string S containing alphanumeric characters. Find out whether the string is a palindrome or not.
If you are unable to solve it then it may result in the death of Iron Man.

Input:
The first line of the input contains T, the number of test cases. T testcases follow.  Each line of the test case contains string 'S'.

Output:
Each new line of the output contains "YES" if the string is palindrome and "NO" if the string is not a palindrome.

Constraints:
1<=T<=100
1<=|S|<=100000
Note: Consider alphabets and numbers only for palindrome check. Ignore symbols and whitespaces.

Example:
Input:
2
I am :IronnorI Ma, i
Ab?/Ba

Output:
YES
YES

*/

// Not a very useful question

#include<bits/stdc++.h>
using namespace std;
string isPalindrome(string s){
	int n = s.length();
	int halfN = n/2;
	for(int i=0,j=n-1;i<halfN;i++,j--){
		if(s[i]!=s[j])return "NO";
	}
	return "YES";
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		string s2;
		// Remove unwanted characters
		for(int i=0;i<s.length();i++){
			if(!isalnum(s.at(i)))continue;
			if(isupper(s.at(i)))s2.append(1,tolower(s.at(i)));
			else s2.append(1,s.at(i));
		}
		cout<<isPalindrome(s2)<<endl;
	}
	return 0;
}