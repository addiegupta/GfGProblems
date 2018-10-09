/*

GeeksForGeeks: Minimum Spanning Tree

Link to problem: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

Difficulty: Medium

Given a weighted, undirected and connected graph. The task is to find the sum of weights of  the edges of the Minimum Spanning Tree. You need to complete the function spanningTree which takes a graph g as its argument and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case contains two integers n,e denoting the no of nodes and no of edges. Then in the next line are E*3 space separated values a b w where a,b denotes an edge from a to b and w is the weight of the edge.

Output:
For each test case in a new line print the sum of weights of  the edges of the Minimum Spanning Tree formed of the graph.

Constraints:
1<=T<=10
1<=n,e<=100
1<=w<=1000


Example(To be used only for expected output):
Input
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5
Output
4
5



*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int spanningTree(vector <pair<int,int> > g[], int n);
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
	vector <pair<int,int> > adj[MAX];
    int n,e;
    int w, mC;
    cin >> n>> e;
    for(int i = 0;i < e;++i)
    {
    	int x,y;
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
  
    mC= spanningTree(adj, MAX);
    cout << mC << endl;
	}
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Finds the sum of weights of the edges of the Minimum Spanning Tree.
    Graph is represented as adjacency list using array of vectors.  MAX 
    is an upper  limit on number of vertices.
   g[u] represents adjacency list of vertex u,  Every element of this list 
   is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
  Note : Vertex numbers start with 1 and don't need to be contiguous.   */

// Struct to store nodes and weight associated with edge
struct Edge{
	int w;
	int n1,n2;
};
// Used with priority queue to form min heap
class edgeComparator{
public:
	int operator()(Edge e1,Edge e2){return e1.w>e2.w;}
};

// Returns sum of weights of spanning tree
int spanningTree(vector <pair<int,int> > g[], int MAX)
{
	// Min heap to get edge with minimum weight
	priority_queue<Edge,vector<Edge>,edgeComparator> q;
	
	// Visited array
	bool vis[MAX];
	memset(vis,false,MAX);

	//Get minimum edge weight from graph 
	Edge min = {INT_MAX,0,0};
	for(int i=0;i<MAX;i++){
		for(int j=0;j<g[i].size();j++){		
			if(g[i].at(j).first<min.w){
				min.w = g[i].at(j).first;
				min.n1 = i;
				min.n2=g[i].at(j).second;
			}
		}
	}
	// Init visited array to false
	memset(vis,false,MAX);

	// Stores sum of weights for MST
	int sum=0;
	// Start from minimum edge
	q.push(min);

	// Traverse through graph
	while(!q.empty()){

		// Get min edge from priority queue
		Edge edge = q.top();
		q.pop();

		// Add to sum if not visited before
		if(!vis[edge.n1]||!vis[edge.n2])sum+= edge.w;
		
		// Add neighbours of both nodes if not visited yet
		int neighbours[]={edge.n1,edge.n2};
		for(int it=0;it<2;it++){
			int nb = neighbours[it];		
			// If not yet visited, mark as visited and add to queue for traversal
			if(!vis[nb]){
				vis[nb]=true;
				for(int i=0;i<g[nb].size();i++){
					pair<int,int> node = g[nb].at(i);
					if(!vis[node.second]){
						q.push({node.first,nb,node.second});
					}
				}
			}
		}
	}
	return sum;
}