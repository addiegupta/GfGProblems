/*

GeeksForGeeks: Find first set bit

Link to problem: https://practice.geeksforgeeks.org/problems/find-first-set-bit/0

Difficulty: Basic

Given an integer an N, write a program to print the position of first set bit found from right side in the binary representation of the number.

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. The only line of the each test case contains an integer N.

Output:
For each test case print in a single line an integer denoting the position of the first set bit found form right side of the binary representation of the number.If there is no set bit print "0".

Constraints:
1<=T<=200
0<=N<=106

Example:
Input:
2
18
12

Output:
2
3

Explanation:
Test case 1:
Binary representation of the 18 is 010010, the first set bit from the right side is at position 2.


*/


#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// No set bit present
		if(!n)cout<<0<<endl;
		else{
			// Count position
			int count=0;
			// Loop until set bit found
			while(1){
				// Increase position
				count++;
				// First bit is set
				if(n&1){
					cout<<count<<endl;
					break;
				}
				// Right Shift
				n=n>>1;
			}
		}
	}
	return 0;
}