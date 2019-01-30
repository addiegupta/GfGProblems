/*

GeeksForGeeks: DFS of Graph

Link to problem: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Difficulty: Easy

Write a function to print the depth first traversal for a undirected graph from a given source s.

Input:
The task is to complete the function DFS which takes 3 arguments an integer denoting the starting node (s) of the dfs travel , a  graph (g)  and an array of visited nodes (vis)  which are initially all set to false . 
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print the depth first traversal for the graph from the given source.

Note : The expected output button always produces DFS starting from node 1.

Constraints:
1 <=T<= 100
1 <=Number of  edges<= 100

Example:
Input:
1
4
1 2 1 3 1 4 3 5

Output:
1 2 3 5 4    //dfs from node 1
 

There is  one test cases.  First line of each test case represent an integer N denoting no of edges and then in the next line N pairs of values a and b are fed which denotes there is an edge from a to b .

*/

#include<bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int> g[],bool vis[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        bool vis[100001];
        vector<int> g[100001];
        memset(g,0,sizeof g);
        memset(vis,false,sizeof vis);
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,g,vis);
        cout<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You have to complete this function
which prints out the depth first level traversal of the 
graph starting from node s
the vector<int> g[i] represent the adjacency 
list of the ith node of the graph
 */
void dfs(int s, vector<int> g[], bool vis[])
{	
	if(!vis[s]){
		vis[s]=true;
		cout<<s<<" ";
		for(int i=0;i<g[s].size();i++){
			dfs(g[s].at(i),g,vis);
		}
	}

}