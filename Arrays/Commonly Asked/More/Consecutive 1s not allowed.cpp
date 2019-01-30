/*

GeeksForGeeks:Consecutive 1s not allowed

Link to Problem: https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0

Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer mod 10^9 + 7.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contain an integer N representing length of the binary string.

Output:
Print the count number of binary strings without consecutive 1’s of length N.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
3
2

Output:
5
3

Explanation:
Testcase 1: case 5 strings are (000, 001, 010, 100, 101)
Testcse 2:  case 3 strings are (00,01,10)

*/


/* This problem ultimately boils down to a fibonacci pattern

	for n =1, possible arrangements are 0 and 1.
	case 0: 1 or 0 can be added to left to obtain non consective in n=2
	case 1: only 0 can be added to left to obtain non consecutive in n=2

	and so on

*/
#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll dp[103];

// Fibonacci
ll fib(ll n){
	if(n<=2){
		return 1;
	}
	if(dp[n]!=-1)return dp[n];

	//                        Required modulo condition
	dp[n]=(fib(n-1)+fib(n-2))%(ll)(pow(10,9)+7);

	return dp[n];

}

int main(){
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--){
		ll n;
		cin>>n;
		cout<<fib(n+2)<<endl;
	}
}