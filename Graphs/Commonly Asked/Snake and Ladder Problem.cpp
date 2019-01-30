/*

GeeksForGeeks: Snake and Ladder Problem

Link to problem: https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0

Difficulty: Medium

Given a snake and ladder board of order 5x6 , find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 

25 26 27 28 29 30

24 23 22 21 20 19

13 14 15 16 17 18 

12 11 10 9  8  7 

1  2  3  4  5  6


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1<=T<=100
1<=N<=10
1<=a<30
1<=b<=30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30
Output:
3
1


*/


#include<bits/stdc++.h>
using namespace std;
// Structure to store vertex number and die rolls required to reach this vertex
struct node{
	int v;
	int dist;
};

// Computes min number of die rolls to reach destination vertex i.e. 30
int shortest(int moves[],int n){
	// Visited array for all nodes
	bool *vis = new bool[n];
	memset(vis,false,n);

	// Queue for BFS traversal
	queue<node> q;

	// Insert starting point in queue
	node src = {1,0};
	vis[1]=true;
	q.push(src);

	// Node for traversal
	node a;
	while(!q.empty()){
		a = q.front();
		q.pop();
		int v = a.v;

		// Reached destination
		if (v == n-1){
			break;
		}

		// Push subsequent possible die roll moves to queue;
		for(int j=v+1;j<=v+6 && j<n;j++){
			// Visit unvisited nodes
			if(!vis[j]){
				// Next node to be reached
				node newNode;
				newNode.dist = a.dist+1;
				vis[j]=true;
				// No snake or ladder
				if(moves[j]==-1){
					newNode.v = j; 
				}
				// Snake/ladder; go to end point of snake/ladder
				else{
					newNode.v = moves[j];
				}
				// Add node to queue
				q.push(newNode);
			}
		}
	}
	// This is the shortest distance as it takes least iterations to reach destination
	return a.dist;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		// Extra space to avoid using 0 index as starting point
		int n=31;
		int moves[n];
		// No snake or ladder present at i
		for(int i=1;i<n;i++)moves[i]=-1;
		// Number of snakes/ladders
		int k;
		cin>>k;
		// Get start and end nodes of snakes/ladders
		for(int i=0;i<k;i++){
			int a ,b;
			cin>>a>>b;
			moves[a]=b;
		}
		cout<<shortest(moves,n)<<endl;
	}
}