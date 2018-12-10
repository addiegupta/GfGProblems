/*

GeeksForGeeks: Rotate Bits

Link to problem: https://practice.geeksforgeeks.org/problems/rotate-bits/0

Difficulty: Basic

Given an integer N and an integer D, you are required to write a program to rotate the binary representation of the integer N by D digits to the left as well as right and print the results in decimal values after each of the rotation.

Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000.....001100.

Input:
First line of input contains a single integer T which denotes the number of test cases. Each test case contains two space separated integers N and D where N denotes the number to be rotated and D denotes the number of digits by which the number is required to be rotated.

Output:
For first line of each test case prints the value of number N after rotating it to left by D digits and  second line prints the value of number N after rotating it to the right by D digits.

Constraints:
1<=T<=100
1<=N< 216
1<=D<=105

Example:
Input:
2
229 3
28 2
Output:
1832
40988
112
7


*/


#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		// Left rotated and right rotated numbers
		int nl=n,nr=n;
		// 16 bit integer; remove multiple useless rotations
		d%=16;
		// Count down rotations
		while(d--){
			// Store msb and lsb for left rotation and right rotation respectively
			int msb = nl&(1<<15);
			int lsb = nr&1;
			// Left shift and rotate
			nl=nl<<1;
			nl|=msb;
			// Right shift and rotate
			nr=nr>>1;
			nr|=(lsb<<15);
		}
		cout<<nl<<endl<<nr<<endl;
	}
	return 0;
}