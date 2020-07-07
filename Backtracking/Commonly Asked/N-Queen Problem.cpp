/*

GeeksForGeeks: N-Queen Problem

Link to problem: https://practice.geeksforgeeks.org/problems/n-queen-problem/0

Difficulty: Hard

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens
 attack each other. Given an integer n, print all distinct solutions to the n-queens puzzle.
  Each solution contains distinct board configurations of the n-queens’ placement,
   where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in 
   the ith place denotes that the ith-column queen is placed in the row with that number. 
   For eg below figure represents a chessboard [3 1 4 2].

   x	Q   x	x
   x	x	x	Q
   Q    x	x	x
   x	x	Q   x


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution is enclosed in square brackets '[', ']' separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order where the number in the ith place denotes the ith-column queen is placed in the row with that number, if no solution exists print -1.

Constraints:
1<=T<=10
1<=n<=10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]

*/

// Have interchanged rows and columns for this problem
// Answer remains same

#include<bits/stdc++.h>
using namespace std;
#define MAX 10

bool isConsistent(int n,int row,int col,int board[][MAX]){
	// Check if this column contains any other queen
	for(int i=0;i<n;i++){
		if(board[i][col]==1){
			// Inconsistent solution
			return false;
		}
	}
	// Check diagonals for queen
	int colI[] = {-1,1};
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			int rI = row-i;
			int cI = col + colI[j]*i;
			// Check if index within bounds and then check for queen
			if(rI>=0&&cI>=0&&rI<n&&cI<n&&board[rI][cI]==1){
				// Inconsistent solution
				return false;
			}
		}
	}
	// Consistent solution
	return true;
}
void nQueens(int n,int row,int board[][MAX]){
	// For given row number find appropriate column number to place queen 
	// by trying every column one by one
	// If no column is found then backtrack. Column for previous row will be changed 
	for(int j=0;j<n;j++){
		if(isConsistent(n,row,j,board)){
			// Mark queen
			board[row][j]=1;
			// Last row; all queens places succesfully
			if(row==n-1){
				// Print queen positions
				cout<<"[";
				for(int k=0;k<n;k++){
					for(int l=0;l<n;l++){
						if(board[k][l]==1){
							cout<<l+1<<" ";
						}
					}
				}
				cout<<"] ";
			}
			// Find positions of remaining queens
			else{
				nQueens(n,row+1,board);
			}
			// If control reaches here then it is not a correct solution
			// Remove queen and continue loop to place queen in some other column
			// If loop terminates without finding solution, then loop is run in recursive parent function 
			board[row][j]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		// No solution exists for n=2 and n=3
		if(n==2||n==3){cout<<"-1"<<endl;}
		else{
			// Initialise board
			int board[MAX][MAX];
			// Clear board of queens
			for(int i=0;i<MAX;i++){
				for(int j=0;j<MAX;j++){
					board[i][j]=0;
				}
			}
			nQueens(n,0,board);
			cout<<endl;
		}
	}
	return 0;
}


//Improved (?) code on 7 July 2020 in Java in O(n) space
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    private static void recur(ArrayList<ArrayList<Integer>> ans,ArrayList<Integer> board,int pos,int n){
        if(pos==n){
            ans.add(new ArrayList<Integer>(board));
            return;
        }
        for(int i=0;i<n;i++){
            // If a valid position, place it and recur    
            // check if pos,i is a valid location
            boolean isValid = true;
            for(int j=0;j<pos;j++){
                // Check column
                if(board.get(j)==i+1){
                    isValid=false;
                    break;
                }
                // Check diagonal
                if(pos-i == j-board.get(j)+1){
                    isValid = false;
                    break;
                }
                // Check other diagonal
                if(pos+i == j+board.get(j)-1){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                // Recur
                board.add(i+1);
                recur(ans,board,pos+1,n);
                board.remove(board.size()-1);
            // Else remove it and next iteration will continue
            }
        }
        
    }
	public static void main (String[] args) {
	    
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    while(t--!=0){
	        
    	    int n = sc.nextInt();
    	    ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
    	    ArrayList<Integer> board = new ArrayList<Integer>();
    	    recur(ans,board,0,n);
    	    for(int i=0;i<ans.size();i++){
    	        System.out.print("[");
    	        for(int j=0;j<ans.get(i).size();j++){
    	            System.out.print(ans.get(i).get(j)+" ");
    	            
    	        }
    	        System.out.print("] ");
    	    }
    	    if(ans.size()==0)System.out.print("-1");
    	    System.out.println();
	    }
		//code
	}
}