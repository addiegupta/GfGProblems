/*

GeeksForGeeks: Shortest Source to Destination Path

Link to problem: https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0

Difficulty: Medium

Given a boolean 2D matrix (0-based index), find whether there is path from (0,0) to (x,y) and if there is one path, print the minimum no of steps needed to reach it, else print -1 if the destination is not reachable. You may move in only four direction ie up, down, left and right. The path can only be created out of a cell if its value is 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines . The first line of each test case contains two integers n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix. The following line after it contains two integers x and y denoting the index of the destination.

Output:
For each test case print in a new line the min no of steps needed to reach the destination.

Constraints:
1<=T<=100
1<=n,m<=20

Example:
Input:
2
3 4
1 0 0 0 1 1 0 1 0 1 1 1
2 3
3 4
1 1 1 1 0 0 0 1 0 0 0 1
0 3
Output:
5
3

References: https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/



*/
#include<bits/stdc++.h> 
using namespace std;
// Structure to store indices of a node in a matrix
struct Point{
	int x,y;
};
// Structure to store Point along with its distance from source node
struct Node{
	Point p;
	int dist;
};
// Checks whether node is within bounds of matrix
bool isValid(int i,int j,int n,int m){
	return i<n && i>=0 && j>=0 && j<m;
}
// Used for obtaining adjacent nodes
int rowNum[] ={-1,0,0,1};
int colNum[] ={0,-1,1,0};


// BFS traversal in matrix
int BFS(int a[][21],Point dest,int n,int m){
	Point src = {0,0};

	// Check if src or dest are 0
	if(!a[src.x][src.y]||!a[dest.x][dest.y])return -1;

	// Visited matrix
	bool vis[n][m];
	memset(vis,false,sizeof vis);

	// Mark source as visited
	vis[src.x][src.y]=true;

	// Queue to contain adjacent nodes
	queue<Node> q;

	// Node for source
	Node s = {src,0};
	q.push(s);

	// Traverse through graph
	while(!q.empty()){

		// Get neighbour node
		Node n = q.front();
		q.pop();

		// If it is destination node, return distance
		if(n.p.x == dest.x && n.p.y == dest.y) return n.dist;

		// Add neighbouring nodes to queue for traversal
		for(int i=0;i<4;i++){
			int row = n.p.x + rowNum[i];
			int col = n.p.y + colNum[i];
			
			if(isValid(row,col,n,m)&&a[row][col]&&!vis[row][col]){
				// Mark neighbouring node as visited
				vis[row][col]=true;

				// Add to queue
				Node newNode = {{row,col},n.dist+1};
				q.push(newNode);
			}
		}
	}
	return -1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n][21];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		int x,y;
		cin>>x>>y;
		Point dest = {x,y};
		cout<<BFS(a,dest,n,m)<<endl;
	}
	return 0;
}