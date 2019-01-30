/*

GeeksForGeeks: Bit Difference

Link to problem: https://practice.geeksforgeeks.org/problems/bit-difference/0

Difficulty: Basic

You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a and b.

Output:

Print the number of bits needed to be flipped.

Constraints:

1 ≤ T ≤ 100
1 ≤ a,b ≤ 1000

Example:

Example:
Input
1
10 20

Output
4
 

Explanation:

A  = 1001001
B  = 0010101
No of bits need to flipped = set bit count i.e. 4


*/


#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int count = 0;
		while(a||b){
			// Count number of bits needed to be flipped
			if((a&1)^(b&1))count++;
			// Right shift both numbers
			a=a>>1;
			b=b>>1;
		}
		cout<<count<<endl;
	}
	return 0;
}