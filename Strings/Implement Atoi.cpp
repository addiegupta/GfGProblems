/*

GeeksForGeeks: Implement Atoi

Link to Problem: https://practice.geeksforgeeks.org/problems/implement-atoi/1

Difficulty: Basic

Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
 
Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string str .

Output:
For each test case in a new line output will be an integer denoting the converted integer, if the input string is not a numerical string then output will be -1.
 
Constraints:
1<=T<=100
1<=length of (s,x)<=10

Example(To be used only for expected output) :
Input:
2
123
21a

Output:
123
-1



*/

#include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
int atoi(string str)
{	
	int ans=0,i=0,sign=1;
	if(str[0]=='-'){
		sign=-1;
		i++;
	}
	for(;i<str.length();i++){
		char c = str[i];
		if(c<'0'||c>'9')return -1;
		else ans=ans*10+(c-'0');
	}
	return sign * ans;
}