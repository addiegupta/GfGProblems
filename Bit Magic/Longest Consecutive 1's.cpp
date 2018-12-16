/*

GeeksForGeeks: Longest Consecutive 1's

Link to problem: https://practice.geeksforgeeks.org/problems/longest-consecutive-1s/0

Difficulty: Basic

Given a number N, Your task is to find the  length of the longest consecutive 1's in its binary representation.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print the length of the longest consecutive 1's in N's binary representation.

Constraints:
1<=T<100
1<=N<=1000

Example:
Input
2
14
222
Output
3 
4


*/
#include<bits/stdc++.h>
using namespace std;
// The idea is that when a number is ANDed with a 1 place shifted version of itself
// one set bit is removed from every consecutive sequence
// Hence the number of such AND iterations will result in the longest 1 sequence
//
//e.g. 1101110
//   & 1011100
//   = 1001100 (1 iteration)
//   & 0011000
//   = 0001000 (2 iterations)
//   & 0010000
//   = 0000000 (3 iterations; 0 reached)
//
// => Longest sequence of 1s is 3
int andNumberWithShiftedVersionOfItself(int n){
	int i=0;
	while(n){
		n&=(n<<1);
		i++;
	}
	return i;
}
int longestConsecutiveSet(int n){
	int max=0,cur=0,i=0;
	while(n>>i){
		if(n&(1<<i)){
			cur++;
			if(max<cur)max=cur;
		}
		else cur=0;
		i++;
	}
	return max;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// cout<<longestConsecutiveSet(n)<<endl;
		cout<<andNumberWithShiftedVersionOfItself(n)<<endl;
	}
	return 0;
}