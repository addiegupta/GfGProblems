/*

GeeksForGeeks: Flood fill algorithm

Link to Problem: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0

Difficulty: Easy

Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

                     {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };

                        x=4, y=4, color=3 

                    {{1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1, 1, 0, 0},
                     {1, 0, 0, 1, 1, 0, 1, 1}, 
                     {1, 3, 3, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 3, 3, 0},
                     {1, 1, 1, 1, 1, 3, 1, 1},
                     {1, 1, 1, 1, 1, 3, 3, 1}, };


Note: Use zero based indexing.


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1<=T<=100
1<=M[][]<=100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4


*/
#include<bits/stdc++.h>
using namespace std;
int a[100][100],m,n;
void color(int,int,int,int);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int i,j;
		cin>>n>>m;
		//Input array for pixels
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		int x,y,k;
		cin>>x>>y>>k;
		// Fill the pixel with new value recursively spreading in all directions(except diagonal)
		color(a[x][y],x,y,k);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++) cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
void color(int b,int x,int y,int k){
	
	// Return if index not in matrix
	if(x<0 || x>=n || y<0 || y>=m) return;
	// Return if value is not equal to required value
	if(a[x][y]!=b) return;

	// Fill pixel with new value
	a[x][y]=k;
	// Spread the new value recursively 
	color(b,x-1,y,k);
	color(b,x+1,y,k);
	color(b,x,y-1,k);
	color(b,x,y+1,k);
}