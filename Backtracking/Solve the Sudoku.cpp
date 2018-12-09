/*

GeeksForGeeks: Solve the Sudoku

Link to problem: https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0

Difficulty: Hard

Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) the task to print a solution of the Sudoku. For simplicity you may assume that there will be only one unique solution.

Example

*Check website for image*


For the above configuration the solution is
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9


*/


#include<bits/stdc++.h>
using namespace std;

// Checks if it is safe to assign num to a[row][col]
bool isSafe(int a[9][9],int row,int col,int num){
	// Checks for occurence of num in same row and column
	for(int i=0;i<9;i++){
		if(a[i][col]==num||a[row][i]==num)return false;
	}

	// Checks for occurence of num in 3x3 subgrid
	int startRow = row - row%3;
	int startCol = col - col%3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(a[i+startRow][j+startCol]==num)return false;
		}
	}
	return true;
}

// Find empty space in sudoku grid to fill up
bool findLocation(int a[9][9],int &row,int &col){
	// Returns true if found else false
	// If found the arguments row and col are set to the value of the empty space
	for(row=0;row<9;row++){
		for(col=0;col<9;col++){
			if(a[row][col]==0)return true;
		}
	}
	return false;
}

// Solves sudoku using backtracking
bool solveSudoku(int a[9][9]){
	int row,col;
	// Return true if no empty location found; sudoku solved
	if(!findLocation(a,row,col)){
		return true;
	}

	// Try placing numbers 1-9 one-by-one and then check if it is safe
	// If safe to place num, then continue solving for other empty spaces by calling solveSudoku recursively
	for(int num=1;num<=9;num++){
		if(isSafe(a,row,col,num)){
			// Set value to num as it is safe to place
			a[row][col]=num;
			// Continue solving
			if(solveSudoku(a)){
				// Solved completely; return true
				return true;
			}
			// Set as empty space as this code will be reached only if this value is not suitable
			// Continue with loop by trying other numbers
			// If loop is finished, then no number is suitable; backtrack to change previous number
			a[row][col]=0;
		}
	}
	// Not yet solved
	return false;

}
int main(){
	int t;
	cin>>t;
	while(t--){

		// Input partially empty sudoku
		int a[9][9];
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>a[i][j];
			}
		}
		// Solve sudoku using backtracking
		solveSudoku(a);

		// Print sudoku grid
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}