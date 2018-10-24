/*

GeeksForGeeks: Path in Matrix

Link to problem: https://practice.geeksforgeeks.org/problems/path-in-matrix/0

Difficulty: Medium

Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.

Input:
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the order of matrix. Next line contains N*N integers denoting the elements of the matrix in row-major form.

Output:
Output the largest sum of any of the paths starting from any cell of row 0 to any cell of row N-1. Print the output of each test case in a new line.

Constraints:
1<=T<=20
2<=N<=20
1<=Matrix[i][j]<=1000 (for all 1<=i<=N && 1<=j<=N)

Example:

Input:
1
2
348 391 618 193

Output:
1009

Explanation: In the sample test case, the path leading to maximum possible sum is 391->618.  (391 + 618 = 1009)

*/

#include<bits/stdc++.h>
using namespace std;

// Find longest sum path in matrix from top row to bottom row
int matrixPath(int n,int a[][20]){
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			int max=-1;
			// For element above, diagonally left above and diagonally right above
			// find the maximum element and add it to the current element
			// This value represents path sum till this point
			for(int k=j-1;k<=j+1;k++){
				if(k>=0&&k<n && a[i-1][k]>max)max=a[i-1][k];
			}
			a[i][j]+=max;
		}
	}
	int max =-1;
	for(int i=0;i<n;i++){
		// Find maximum value in bottom row
		if(max<a[n-1][i])max=a[n-1][i];
	}
	return max;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][20];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		cout<<matrixPath(n,a)<<endl;
	}
}