/*

GeeksForGeeks: Number of paths

Link to Problem: https://practice.geeksforgeeks.org/problems/number-of-paths/0

Difficulty: Basic

The problem is to count all the possible paths from top left to bottom right of a  MxN matrix with the constraints that from each cell you can either move to right or down.

Input:
The first line of input contains an integer T, denoting the number of test cases.
The first line of each test case is M and N, M is number of rows and N is number of columns.

Output:
For each test case, print the number of paths.

Constraints:

1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:
Input
2
3 3
2 8
Output
6
8


*/
#include<bits/stdc++.h>
using namespace std;
void move(int,int);
int m,n,c;
int main()
{
	int t;
	cin>>t;
	while(t--){
		c=0;
		cin>>m>>n;
		move(0,0);
		cout<<c<<endl;
	}
	return 0;
}
void move(int i,int j){
	// Reached last element of matrix
	if(i==m-1 && j==n-1){
		c++;
		return;
	}
	// Out of bounds
	if(i>=m||j>=n) return;
	// Go down
	move(i+1,j);
	// Go right
	move(i,j+1);
}
