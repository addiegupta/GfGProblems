/*

GeeksForGeeks: Find whether path exist

Link to problem: https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0

Difficulty: Medium

Given a N X N matrix (M) filled with 1 , 0 , 2 , 3 . Your task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note : there is only single source and single destination.
 

Examples:

Input : M[3][3] = {{ 0 , 3 , 2 },
                   { 3 , 3 , 0 },
                   { 1 , 3 , 0 }};
Output : Yes

Input : M[4][4] = {{ 0 , 3 , 1 , 0 },
                   { 3 , 0 , 3 , 3 },
                   { 2 , 3 , 0 , 3 },
                   { 0 , 3 , 3 , 3 }};
Output : Yes


Input:
The first line of input is an integer T denoting the no of test cases. Then T test cases follow. Each test case consists of 2 lines . The first line of each test case contains an integer N denoting the size of the square matrix . Then in the next line are N*N space separated values of the matrix (M) .

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0
Output:
1
0


*/
#include<bits/stdc++.h> 
using namespace std;
// Structure to store indices of a node in a matrix
struct Point{
	int x,y;
};
// Checks whether node is within bounds of matrix
bool isValid(int i,int j,int n){
	return i<n && i>=0 && j>=0 && j<n;
}
// Used for obtaining adjacent nodes
int rowNum[] ={-1,0,0,1};
int colNum[] ={0,-1,1,0};


// BFS traversal in matrix
int BFS(int a[][21],Point src,int n){

	// Visited matrix
	bool vis[n][n];
	memset(vis,false,sizeof vis);

	// Mark source as visited
	vis[src.x][src.y]=true;

	// Queue to contain adjacent nodes
	queue<Point> q;

	q.push(src);

	// Traverse through graph
	while(!q.empty()){

		// Get neighbour node
		Point p = q.front();
		q.pop();
		// If it is destination node, return true
		if(a[p.x][p.y]==2) return 1;

		// Add neighbouring nodes to queue for traversal
		for(int i=0;i<4;i++){
			int row = p.x + rowNum[i];
			int col = p.y + colNum[i];
			
			if(isValid(row,col,n)&&a[row][col]&&!vis[row][col]){
				// Mark neighbouring node as visited
				vis[row][col]=true;

				// Add to queue
				Point newNode = {row,col};
				q.push(newNode);
			}
		}
	}
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][21];
		int x,y;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j]==1){
					x=i;
					y=j;
				}
			}
		}
		Point src = {x,y};
		cout<<BFS(a,src,n)<<endl;
	}
	return 0;
}