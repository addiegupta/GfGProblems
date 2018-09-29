/*

GeeksForGeeks: Implementing Dijkstra | Set 1 (Adjacency Matrix)

Link to problem: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Difficulty: Medium

Given an adjacency matrix (graph), the task is to find the shortest distance of all the vertex's from the source vertex. You are required to complete the function dijkstra which takes 3 arguments. The first argument is the adjacency matrix (graph) , the second argument is the source vertex s and the third argument is V denoting the size of the matrix. The function prints  V space separated integers where i'th integer denotes the shortest distance of the i'th vertex from source vertex.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow .The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the next line are V space separated values of the matrix (graph) .The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test case output will be V space separated integers where the ith integer denote the shortest distance of ith vertex from source vertex.

Constraints:
1<=T<=20 
1<=V<=20
0<=s 1<=graph[][]<=1000

Example:
Input
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output
0 25
7 6 0


*/

// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the grap
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int g[MAX][MAX];
void dijkstra(int graph[MAX][MAX], int ,int V);
int main()
{
   /* Let us create the example graph discussed above */
   int t;
	int V;
   cin>>t;
   while(t--){
	cin>>V;
  for(int i=0;i<V;i++)
  {
  	for(int j=0;j<V;j++)
  	{
  		cin>>g[i][j];
  	}
  }
  int s;
  cin>>s;
    dijkstra(g, s,V);
cout<<endl;
   }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
// Required for priority queue to return minimum value of distance
class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};
void dijkstra(int graph[MAX][MAX], int s,int V)
{
	// Store distance from source node; 0 or 1 depending on whether node has been included in
	// shortest path tree i.e. minimum distance for node has been determined
    int dist[V],spt[V];
    for(int i=0;i<V;i++){
    	// Initialise dist to infinite 
	    dist[i]=1001;
    	spt[i]=0;
    }
    // Distance of source from source is 0
    dist[s]=0;
    // Priority queue to store pair(index,dist of index) for obtaining minimum distance node
    priority_queue<pair<int,int>, vector<pair<int,int>>, CompareDist> q;
    // Push source in queue i.e. start traversing from source node
    pair<int,int> source;
    source = make_pair(s,dist[s]);
    q.push(source);

	while(!q.empty()){
		// Get next node from queue and dequeue it
		int vertex = q.top().first;
		q.pop();
		// Mark the node as part of SPT
		spt[vertex]=1;
		// For the current node check its immediate neighbours
		for(int i=0;i<V;i++){
			// Get distance of neighbour from current node
			int newDist = graph[vertex][i];
			// Node is not a neighbour, continue traversal
			if(!newDist) continue;
			// Distance from source via this path is less than original value 
			if(dist[vertex]+newDist<dist[i]) dist[i]=dist[vertex]+newDist;
			// Add neighbour node to queue if it is not part of SPT
			if(!spt[i]){
				pair<int,int> node;
			    node = make_pair(i,dist[i]);
			    q.push(node);
			}
		}
	}
	for(int i=0;i<V;i++) cout<<dist[i]<<" ";
}