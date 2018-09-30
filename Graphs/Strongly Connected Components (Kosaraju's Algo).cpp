/*

GeeksForGeeks: Strongly Connected Components (Kosaraju's Algo)

Link to problem: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

Difficulty: Medium

Given a graph with N nodes and M directed edges. Your task is to complete the function kosaraju which returns an integer denoting the no of strongly connected components in the graph.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers N and M . In the next line are N space separated values u,v denoting an edge from u to v.

Output:
For each test case in a new line output will an integer denoting the no of strongly connected components present in the graph.

Constraints:
1<=T<=100
1<=N,M<=20
1<=u,v<=N

Example(To be used only for expected output):
Input:
2
5 5
2 1 1 3 3 2 1 4 4 5
3 3
1 2 2 3 3 1
Output:
3
1


*/
#include<bits/stdc++.h>
 
using namespace std;
#define MAX 10001
int kosaraju(vector<int> v[100001],int ,int );
int main()
{ 
   int t;
   cin>>t;
  while(t--)
   {   vector<int> v[100001];
        int a,b ;
   	cin>>a>>b;
       for(int i=0;i<b;i++)
           {  int m,n;
               cin>>m>>n;
               v[m].push_back(n);
           }
      
         
         int ans=kosaraju(v,a,b); 
         cout<<ans<<endl;
         for(int i=0;i<=a+1;i++)
        {    v[i].clear();   
         }
           
   }
return 0;
}

// DFS Recursive traversal on the original graph
void dfs(vector<int> v[],int i,stack<int>& s,bool vis[]){
	if(!vis[i]){
		vis[i]=true;
		for(int j=0;j<v[i].size();j++){
			dfs(v,v[i].at(j),s,vis);
		}
		// Once dfs is complete for a particular node, push it to the stack
		s.push(i);
	}
}
// DFS Recursive traversal on transposed graph to mark the nodes as visited
void dfsT(vector<int> v[],int i,bool vis[]){
	if(!vis[i]){
		vis[i]=true;
		for(int j=0;j<v[i].size();j++){
			dfsT(v,v[i].at(j),vis);
		}
	}
}
// Generates transpose of the given graph 
void transpose(vector<int> v[],vector<int> vt[],int N){
	for(int i=1;i<=N;i++){
		for(int j=0;j<v[i].size();j++){
			int neighbour = v[i].at(j);
			vt[neighbour].push_back(i);
		}
	}
}
int kosaraju(vector<int> v[100001], int N, int M)
{
	// visited arrays for graph and graph transpose
	bool vis[N+1];
	bool visT[N+1];
	memset(vis,false,sizeof vis);
	memset(visT,false,sizeof visT);

	// Stack to store nodes in order of their dfs completion
	stack<int> s;
	for(int i=1;i<=N;i++){
		dfs(v,i,s,vis);
	}

	// Transposed graph
	vector<int> vt[N+1];
	transpose(v,vt,N);
	    
	// Strongly connected components count
	int scc=0;
	while(!s.empty()){
		
		// Fetch top most node from stack
		int top = s.top();
		s.pop();
		// Not visited yet, perform dfs , when dfs ends one Strongly connected component has been visited
		if(!visT[top]){	
			dfsT(vt,top,visT);
			scc++;
		}
	}
	return scc;
}