/*

GeeksForGeeks: Swap all odd and even bits

Link to problem: https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits/0

Difficulty: Easy

Given an unsigned integer N, swap all odd bits with even bits. For example, if the given number is 23 ( 0 0 0 1 0 1 1 1 ), it should be converted to 43 ( 0 0 1 0 1 0 1 1 ). Here every even position bit is swapped with adjacent bit on right side (even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N.

Output:

Corresponding to each test case, print in a new line, the converted number .

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input
2
23
2

Output
43
1


*/


#include<bits/stdc++.h>
using namespace std;
// Method that takes a bit at odd position and swaps it with adjacent even bit
int swapBitsMethod1(int n){
    int i=0;
	while(n>>i){
		int a,b;
		(n&(1<<i))?a=1:a=0;
		(n&(1<<(i+1)))?b=1:b=0;
		(a)?n|=(1<<(i+1)):n&=~(1<<(i+1));
		(b)?n|=(1<<i):n&=~(1<<i);
		i+=2;
	}
	return n;
}
// Method that obtains all even bits and odd bits and returns the OR result of these 2 
int swapBitsMethod2(int n){
	// A=1010 => the given number obtains all even bits in 32 bit integer
	int evenBits = n&0xAAAAAAAA;
	// 5=0101 => the given number obtains all odd bits in 32 bit integer
	int oddBits =  n&0x55555555;
	// Right shift evenbits
	evenBits >>=1;
	// Left shift odd bits
	oddBits <<=1;
	// Return OR result
	return evenBits|oddBits;
}
int main()
{	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// cout<<swapBitsMethod1(n)<<endl;
		cout<<swapBitsMethod2(n)<<endl;
	}
	return 0;
}