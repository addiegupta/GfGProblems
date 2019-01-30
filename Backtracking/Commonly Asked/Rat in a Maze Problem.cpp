/*

GeeksForGeeks: Rat in a Maze Problem

Link to problem: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Difficulty: Medium

Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). Your task is to complete the function which returns a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

For example
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer n denoting the size of the square matrix. The next line contains n*n space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination.

Constraints:
1<=T<=10
2<=n<=10
0<=m[][]<=1

Example(To be used only for expected output):
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR 

*/
{
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */

// Recursive function to find multiple possible paths from 0,0 to i-1,j-1 through 1s
// using backtracking

void findPath(int i,int j,int m[][MAX],int n,string path,vector<string> &ans){
	
	// Out of bounds / 0 value reached / 100 value reached
	// Backtrack
	if(i<0||j<0||i>=n||j>=n||m[i][j]==0||m[i][j]==100)return;
	// Destination reached, add path string to vector of strings
	// Backtrack 
	else if(i==n-1&&j==n-1){
		ans.push_back(path);
		return;
	}
	else{
		// Set value to 100 so as to mark it visited
		// As a result if a path reached this node again, it will backtrack
		m[i][j]=100;
		// Go down,right,up and left recursively
		findPath(i+1,j,m,n,path+'D',ans);
		findPath(i,j+1,m,n,path+'R',ans);
		findPath(i-1,j,m,n,path+'U',ans);
		findPath(i,j-1,m,n,path+'L',ans);
		// All directions explored, set value back to 1
		m[i][j]=1;
	}
}
vector<string> printPath(int m[MAX][MAX], int n)
{
	// Vector to store strings
    vector<string> ans;
    // Recursive function to find paths
    findPath(0,0,m,n,"",ans);
    // Sort 
    sort(ans.begin(),ans.end());
    return ans;
}
