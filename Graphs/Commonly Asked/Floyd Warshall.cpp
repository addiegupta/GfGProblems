/*

GeeksForGeeks: Floyd Warshall

Link to problem: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0

Difficulty: Medium

The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the next line are V*V space separated values of the matrix (graph) .

Output:
For each test case output will be V*V space separated integers where the i-jth integer denote the shortest distance of ith vertex from jth vertex.

Constraints:
1<=T<=20 
1<=V<=20
-1000<=graph[][]<=1000

Example:
Input
2
2
0 25 25 0
3
0 1 43 1 0 6 43 6 0

Output
0 25 25 0 
0 1 7 1 0 6 7 6 0 

References: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

*/
#include<bits/stdc++.h> 
using namespace std;
void floydWarshall(int graph[][21],int n){

	// For every intermediate vertex compare and compute minimum distances
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(graph[i][k]+ graph[k][j]<graph[i][j]){
					graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<graph[i][j]<<" ";
		}
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int graph[n][21];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>graph[i][j];
			}
		}
		floydWarshall(graph,n);
	}
	return 0;
}
