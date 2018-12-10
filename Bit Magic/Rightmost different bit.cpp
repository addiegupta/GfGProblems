/*

GeeksForGeeks: Rightmost different bit

Link to problem: https://practice.geeksforgeeks.org/problems/rightmost-different-bit/0

Difficulty: Basic

Given two numbers M and N. Write a program to find the position of rightmost different bit in binary representation of numbers.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains two space separated integers M and N.

Output:
For each test case print the position of rightmost different bit in binary representation of numbers. If both M and N are same then print -1 in this case.

Constraints:
1<=T<=100
1<=M<=1000
1<=N<=1000

Example:
Input:
2
11 9
52 4
Output:
2
5

*/


#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		// Same numbers no different bit exists
		if(n==m)cout<<-1<<endl;
		else{
			// Count position
			int count = 0;
			// While at least one is nonzero
			while(n||m){
				// Increment position
				count++;
				// XOR operator on rightmost bits of m and n; XOR will detect if bits are different
				if((n&1)^(m&1)){
					cout<<count<<endl;
					break;
				}
				// Right shift to get next bit at 0 position
				n=n>>1;
				m=m>>1;
			}
		}

	}
	return 0;
}