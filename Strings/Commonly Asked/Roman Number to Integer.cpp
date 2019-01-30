/*

GeeksForGeeks: Roman Number to Integer

Link to Problem: https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0

Difficulty: Easy

Given an string in roman no format (s)  your task is to convert it to integer .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a string s denoting the roman no.

Output:
For each test case in a new line print the integer representation of roman number s. 

Constraints:
1<=T<=100
1<=roman no range<4000

Example:
Input
2
V
III 
Output
5
3


*/

#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s){
	int ans=0;
	int n= s.length();
	for(int i=0;i<n;i++){
		char c=s[i];
		switch(c){
			case 'V':ans+=5;
					break;
			case 'L': ans+=50;
						break;
			case 'D':ans+=500;
					break;
			case 'M': ans+=1000;
						break;
			case 'I': if(s[i+1]=='V'||s[i+1]=='X')ans-=1;
					  else ans+=1;
					  break;
			case 'X': if(s[i+1]=='L'||s[i+1]=='C')ans-=10;
					  else ans+=10;
					  break;
			case 'C': if(s[i+1]=='D'||s[i+1]=='M')ans-=100;
					  else ans+=100;
					  break;
		}
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string s;
		cin>>s;
		cout<<romanToInt(s)<<endl;
	}
	return 0;
}