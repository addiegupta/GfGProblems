/*

GeeksForGeeks: Parenthesis Checker

Link to Problem: https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

Difficulty: Easy

Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 100

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced




*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		//Input string
		string x;
		cin>>x;
		//Stack to store parenthesis
		stack<int> s;
		// Push first bracket
		s.push(x[0]);
		// For every other bracket, remove top bracket if it is an opposite bracket to the current bracket
		// otherwise add it to stack
		for(int i=1;i<x.length();i++){
			if(!s.empty()&&abs(x[i]-s.top())<3) s.pop();
			else s.push(x[i]);
		}
		// If stack is empty, expression is balanced
		(s.empty())?cout<<"balanced":cout<<"not balanced";
		cout<<endl;
	}
	return 0;
}