/*

GeeksForGeeks: Topological sort

Link to problem: https://practice.geeksforgeeks.org/problems/topological-sort/1

Difficulty: Medium

Given a directed graph you need to complete the function topoSort which returns an array having the topologically sorted elements of the array and takes two arguments . The first argument is the Graph graph represented as adjacency list and the second is the number of vertices N .

Note : There can be multiple topological sorts of a Graph.  The driver program that calls your function doesn't match your output element by element, but checks whether the output produced by your function is a valid topological sort or not.

Input:
The first line of input takes the no of test cases then T test cases follow . Each test case contains two lines . The first  line of each test case  contains two integers E and N representing no of edges and the no of vertices . Then in the next line are E  pairs of integers u v representing an edge from u to v in the graph.

Output:
For each test case output will be 1 if the topological sort is done correctly else it will be 0 .

Constraints:
1<=T<=50
1<=E,N<=50
0<=u,v

Example:

Input
1
6 6 
5 0 5 2 2 3 4 0 4 1 1 3

Output
1

The output 1 denotes that the order is valid.  So if you have implemented your function correctly, then output would be 1 for all test cases.


*/

#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int * topoSort(vector<int> graph[],int N);
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	    memset(graph,0,sizeof graph);
	    int N,E;
	    cin>>E>>N;
	    for(int i=0;i<E;i++)
	    {
	        int u,v;
	        cin>>u>>v;
	        graph[u].push_back(v);
	    }
	    int *res = topoSort(graph,N);
	    bool valid =true;
	    for(int i=0;i<N;i++)
	    {
	        int n=graph[res[i]].size();
	        for(int j=0;j<graph[res[i]].size();j++)
	        {
	            for(int k=i+1;k<N;k++)
	            {
	                if(res[k]==graph[res[i] ] [j] )
	                    n--;
	            }
	        }
	        if(n!=0)
	        {
	            valid =false;
	            break;
	        }
	    }
	    if(valid==false)
	        cout<<0<<endl;
	    else
	        cout<<1<<endl;
	}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You need to complete this function */

// Stack to keep reverse order of topological sort
stack<int> s;
bool visited[50];
void dfs(int val,vector<int> graph[]){

	if(!visited[val]){
		visited[val]=true;
		vector<int>::iterator i;
		for(i=graph[val].begin();i!=graph[val].end();++i){
			dfs(*i,graph);
		}
		// Add to stack after all children have been visited
		s.push(val);
	}
}

int * topoSort(vector<int> graph[], int N)
{
	memset(visited,false,sizeof visited);
    // Your code here
	for(int i=0;i<N;i++){
		dfs(i,graph);
	}
	int* res = new int[N];
	int j=0;
	// Reverse the stack to get correct topological order
	while(!s.empty()){
		int v = s.top();
		s.pop();
		res[j]=v;
		j++;
	}
	return res;
}