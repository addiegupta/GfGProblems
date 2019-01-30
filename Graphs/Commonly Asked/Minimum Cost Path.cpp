/*

GeeksForGeeks: Minimum Cost Path

Link to problem: https://practice.geeksforgeeks.org/problems/minimum-cost-path/0

Difficulty: Hard

Given a square grid of size n, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum.

Note : It is assumed that negative cost cycles do not exist in input matrix.

Input:

The first line of input will contain number of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of each test case contains an integer n denoting the size of the grid. Next line of each test contains a single line containing N*N space separated integers depecting cost of respective cell from (0,0) to (n,n).


Output:

For each test case output a single integer depecting the minimum cost to reach the destination.


Constraints:

1<=T<=50
1<= n<= 50


Example:

Input

2
5
31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
2
42 93 7 14
 

Output
327
63

Explanation:

Test Case 1:

Grid is:
31, 100, 65, 12, 18,
10, 13, 47, 157, 6,
100. 113, 174, 11, 33,
88, 124, 41, 20, 140,
99, 32, 111, 41, 20

A cost grid is given in below diagram, minimum 
cost to reach bottom right from top left 
is 327 (= 31 + 10 + 13 + 47 + 65 + 12 + 18 + 
6 + 33 + 11 + 20 + 41 + 20)


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
// Used to implement priority queue as min heap
struct compare{
	bool operator()(const Node &a,const Node &b){
		return a.dist>b.dist;
	}
};
// Checks whether node is within bounds of matrix
bool isValid(int i,int j,int n){
	return i<n && i>=0 && j>=0 && j<n;
}
// Used for obtaining adjacent nodes
int rowNum[] ={-1,0,0,1};
int colNum[] ={0,-1,1,0};

// BFS traversal in matrix
int BFS(int a[][51],int n){

	// Matrix to store distance of node from source
	int dist[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			// Initialise distance to infinity for all nodes
			dist[i][j]=INT_MAX;
		}
	}

	// Min heap for traversal of graph	
	priority_queue<Node,vector<Node>,compare> q;
	
	// Initialise source cost and add it to min heap to start traversal
	dist[0][0] = a[0][0];
	q.push({{0,0},a[0][0]});
	
	// Traverse through graph
	while(!q.empty()){

		// Get neighbour node
		Node node = q.top();
		q.pop();

		// Row and col indices of current node
		int rootRow = node.p.x;
		int rootCol = node.p.y;
		
		// Traverse through neighbour nodes
		for(int i=0;i<4;i++){

			// indices of current neighbour node
			int row = rootRow + rowNum[i];
			int col = rootCol + colNum[i];
			
			// If lies within matrix
			if(isValid(row,col,n)){
				// get cost of current node
				int newDist = a[row][col];
				// Cost is more than current cost till destination
				if(dist[rootRow][rootCol] + newDist >= dist[n-1][n-1])continue;
				// Cost till this node via new path is less than existing cost
				if(dist[rootRow][rootCol] + newDist < dist[row][col]) {
					// Update cost and add node to queue for further traversal
					dist[row][col] = dist[rootRow][rootCol] + newDist;
					q.push({{row,col},dist[row][col]});
				}
			}
		}
	}
	return dist[n-1][n-1];
}
int main(){
	int t;
	cin>>t;
	int a[51][51];
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		cout<<BFS(a,n)<<endl;
	}
	return 0;
}
