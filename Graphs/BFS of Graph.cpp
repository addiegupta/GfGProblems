/*

GeeksForGeeks: BFS of Graph

Link to problem: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Difficulty: Easy

Write a function to print the bredth first traversal for a graph from a given source s.

Input:
The task is to complete the function BFS which takes 3 arguments an integer denoting the starting node (s) of the bfs travel , a  graph (g)  and an array of visited nodes (vis)  which are initially all set to false . 
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print the breath first traversal for the graph from the given source.

Note : The expected output button always produces BFS starting from node 1.

Constraints:
1 <=T<= 100
1 <=Number of  edges<= 100

Example:
Input:
1
4
1 2 1 3 1 4 3 5

Output:
1 2 3 4 5    //bfs from node 1
 

There is  one test cases.  First line of each test case represent an integer N denoting no of edges and then in the next line N pairs of values a and b are fed which denotes there is a unidirectional edge from a to b 


*/


#include<bits/stdc++.h>
using namespace std;
bool vis[1001];
vector<int> g[1001];
void bfs(int s,vector<int> adj[],bool vis[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(g,0,sizeof g);
        memset(vis,false,sizeof vis);
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        bfs(1,g,vis);
        cout<<endl;
    }

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You have to complete this function*/
void bfs(int s,vector<int> adj[],bool vis[])
{
	// To store the immediate children elements for BFS
	queue<int> q;
	// Add first element
	q.push(s);
	vis[s]=true;

	// Till end of connected graph
	while(!q.empty()){
		// Print an element
		int n = q.front();
		cout<<n<<" ";
		q.pop();
		// Add children of element to queue
		for(int i=0;i<adj[n].size();i++){
			if(!vis[adj[n][i]]){
				q.push(adj[n][i]);
				vis[adj[n][i]]=true;
			} 
		}
	}
}