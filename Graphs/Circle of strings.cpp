/*

GeeksForGeeks: Circle of strings

Link to problem: https://practice.geeksforgeeks.org/problems/circle-of-strings/0

Difficulty: Medium

Given an array of strings A[ ], determine if the strings can be chained together to form a circle. A
string X can be chained together with another string Y if the last character of X is same as first
character of Y. If every string of the array can be chained, it will form a circle.

For eg for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"
 

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. 
The first line of each test case contains a positive integer N, denoting the size of the array.
The second line of each test case contains a N space seprated strings, denoting the elements of the
array A[ ].
 

Output
If chain can be formed, then print 1, else print 0.


Constraints
1 <= T <= 100
0 <   N  <= 30
0 <  A[i] <= 10
 

Examples 

Input
2
3
abc bcd cdf
4
ab bc cd da


Output
0
1
 

Reference: https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/

*/
#include<bits/stdc++.h> 
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	int *in; // Stores the in degree of the nodes
public:
	Graph(int V);
	~Graph(){delete [] adj;delete [] in;}

	// Add edge in graph
	void addEdge(int u,int v){
		adj[u].push_back(v);
		(in[v])++; // Add in degree count for node to which edge is directed
	}

	bool isEulerianCycle();// Checks if the graph is an Eulerian Cycle

	bool isSC(); // Checks if graph is strongly connected

	void DFSUtil(int v,bool visited[]);// DFS Traversal util

	Graph getTranspose(); // Returns transpose; used in kosaraju algorithm for determining if graph is SC
}

Graph:: Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	in = new int[V];
	for(int i=0;i<V;i++)in[i]=0;
}

bool Graph::isEulerianCycle(){

	// Checks if graph is strongly connected or not
	if(!isSC())return false;

	// Checks if in degree == out degree
	for(int i=0;i<V;i++){
		if(adj[i].size()!=in[i])return false;
	}
	return true;
}

void Graph::DFSUtil(int v,bool visited[]){
	visited[v]=true;

	list<int>::iterator i;
	for(i = adj[v].begin();i!=adj[v].end();i++){
		if(!visited[*i])DFSUtil(*i,visited);
	}
}

Graph Graph::getTranspose(){
	Graph g(V);
	for(int v=0;v<V;v++){
		list<int>::iterator i;
		for(i=adj[v].begin;i<adj[v].end();i++){
			g.addEdge(*i,v);
		}
	}
	return g;
}
bool Graph::isSC(){
	bool visited[V];
	memset(visited,false,sizeof visited);

	int n;
	for(n=0;n<V;n++){
		if(adj[n].size())break;
	}
	DFSUtil(n,visited);

	for(int i=0;i<V;i++){
		if(adj[i].size() && !visited[i]) return false;
	}
	Graph gr = getTranspose();

	memset(visited,false,sizeof visited);
	
	gr.DFSUtil(n,visited);
	for(int i=0;i<V;i++){
		if(adj[i].size() && !visited[i])return false;
	}
	return true;

}

bool isChain(string s[], int n){
	Graph g(26);

	for(int i=0;i<n;i++){
		string str = s[i];
		g.addEdge(s[0]-'a',s[s.length()-1]-'a');
	}
	// Graph is chain if it is an eulerian cycle
	return g.isEulerianCycle();
}


int main(){
	int t;
	cin>>t;
	while(t--){
		string s[30];
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		cout<<isChain(s,n)<<endl;

	}
	return 0;
}
