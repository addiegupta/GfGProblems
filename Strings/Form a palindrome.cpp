/*

GeeksForGeeks: Form a palindrome

Link to Problem: https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

Difficulty: Medium

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3



*/

#include<bits/stdc++.h>
#include<string>
using namespace std;
bool isPalindrome(string s){
	int n= s.length();
	string rev = s;
	for(int i=0;i<n/2;i++){
		char temp=rev[i];
		rev[i]=rev[n-i-1];
		rev[n-i-1]=temp;
	}
	// cout<<"S is "<<s<<" rev is "<<rev<<endl;
	return s==rev;
}
int palindromeOf(string s){
	int n=s.length();
	int max=1;
	int low,high;
	for(int i=1;i<n;i++){
		low = i-1;
		high =i;
		int count=0;
		while(low>=0 and high<n and s[low]==s[high]){
			
			if(high-low+1>max) max = high-low+1;
			low--;
			high++;
		}
		// if(max<count)max=count;

		low =i-1;
		high = i+1;
		count =1;
		while(low>=0 and high<n and s[low]==s[high]){
			if(high-low+1>max) max = high-low+1;
			low--;
			high++;
		}
		// if(max<count)max=count;
	}
	return n-max;




	for(int i=1;i<=n;i++){
		string sub = s.substr(0,i);
		if(isPalindrome(sub) and max<sub.length()) max = sub.length();
	}
	for(int i=1;i<=n;i++){
		string sub=s.substr(n-i,i);
		if(isPalindrome(sub) and max<sub.length()) max = sub.length();
	}
	return n-max;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s;
		cin>>s;
		// cout<<isPalindrome(s)<<endl;
		cout<<palindromeOf(s)<<endl;
	}
	return 0;
}