/*

GeeksForGeeks: Set kth bit

Link to problem: https://practice.geeksforgeeks.org/problems/set-kth-bit/0

Difficulty: Basic

Given a number N and a value K. From the right, set the Kth bit in the binary representation of N. The position of LSB(or last bit) is 0, second last bit is 1 and so on. Also, 0 <= K < X, where X is the number of bits in the binary representation of N.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains two space separated integers N and K.

Output:
For each test case, print the new number after setting the Kth bit of N.

Constraints:
1<=T<=100
1<=N<=1000


Example:
Input:
2
10 2
15 3
Output:
14
15



*/


#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		// Set kth bit
		cout<<(n|(1<<k))<<endl;
	}
	return 0;
}