/*

GeeksForGeeks: Boolean Matrix Problem

Link to Problem: https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0

Difficulty: Medium

Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The second line of each test case contains all the elements of the matrix in a single line separated by a single space.

Output:
Print the modified array.

Constraints:
1 ≤ T ≤ 102
1 ≤ r, c ≤ 103
0 ≤ A[i][j] ≤ 1

Example:
Input:
3
2 2
1 0 
0 0
2 3
0 0 0 
0 0 1
3 4
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1
1 0
0 0 1 
1 1 1
1 1 1 1 
1 1 1 1 
1 0 1 1

Explanation:
Testcase1: Since only rist element of matrix has 1 (at index 1,1) as value, so first row and first column are modified to 1.


*/


#include<bits/stdc++.h>
using namespace std;

// Use first row and first column as auxilary space to store if 
// this row/column contains a 1
//
// Time O(n^2) Space O(1)
void boolMatrix(int a[][1000],int r,int c){
	int rowFlag=0,colFlag=0;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			// Store if first row/column need to contain all 1s
			if(i==0 && a[i][j]==1)rowFlag =1;
			if(j==0 && a[i][j]==1)colFlag =1;

			// Store presence of 1 in this row and column using first row and column
			// instead of additional space
			if(a[i][j]==1){
				a[i][0]=1;
				a[0][j]=1;
			}
		}
	}
	// Traverse through rest of array (except first row and column)
	// and mark 1s if there is another 1 in this row / column
	for(int i=1;i<r;i++){
		for(int j=1;j<c;j++){
			if(a[0][j]==1||a[i][0]==1){
				a[i][j]=1;
			}
		}
	}

	// Set first row and column if flags are set
	if(rowFlag==1){
		for(int i=0;i<c;i++){
			a[0][i]=1;
		}	
	}
	if(colFlag==1){
		for(int i=0;i<r;i++){
			a[i][0]=1;
		}	
	}

	// Output matrix
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		int a[r][1000];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)cin>>a[i][j];
		}
		boolMatrix(a,r,c);

	}
	return 0;
}