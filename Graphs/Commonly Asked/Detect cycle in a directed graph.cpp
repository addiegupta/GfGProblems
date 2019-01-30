/*

GeeksForGeeks: Detect cycle in a directed graph

Link to problem: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Difficulty: Medium

Given a directed graph  your task is to complete the method isCycle  to detect if there is a cycle in the graph or not. You should not read any input from stdin/console.
There are multiple test cases. For each test case, this method will be called individually.
 

Input (only to be used for Expected Output):
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. 
Description of  test cases is as follows:
The First line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and no of edges respectively.
The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is an unidirected  edge from u to v .

Output:
The method should return true if there is a cycle else it should return false.

Constraints:
1 <=T<= 100
1<=N,M<=100
0 <=u,v<= N-1

Example:
Input:
2
2 2
0 1 0 0
4 3
0 1 1 2 2 3

Output:
1
0


*/


#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int _size,N;
        cin>>_size>>N;
        Graph *g = new Graph(_size);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        cout<<g->isCyclic()<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
*/
/*You are required to complete this method*/

//Recursive dfs function for graph traversal
bool isCyclicUtil(int n,bool* visited,bool* recStack,list<int> *adj){
	// Execute if vertex not visited
	if(!visited[n]){
		visited[n]=true;
		recStack[n]=true;
		list<int>::iterator i;
		for(i=adj[n].begin();i!=adj[n].end();++i){
			// For neighbours, check if cycle exists
			if(!visited[*i]&& isCyclicUtil(*i,visited,recStack,adj))return true;
			// Neighbour is on recursion stack, cycle exists
			else if(recStack[*i])return true;
		}
	}
	// Remove from recursion stack as all children have been visited
	recStack[n]=false;
	return false;

}

bool Graph::isCyclic(){
	bool *visited = new bool[V]; 
	bool *recStack = new bool[V]; 
	memset(visited,false,sizeof visited);
	memset(recStack,false,sizeof recStack);
	for(int i=0;i<V;i++){
		if(isCyclicUtil(i,visited,recStack,adj)) return true;
	}
	return false;
}