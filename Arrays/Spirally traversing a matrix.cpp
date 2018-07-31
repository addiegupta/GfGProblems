/*

GeeksForGeeks: Spirally traversing a matrix

Link to Problem: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0

Difficulty: Easy

Traverse a 4x4 matrix of integers in spiral form.

Input: 
The first line of input contains an integer T denoting the number of test cases. First four lines of the test case will contain four elements each.

Output:
Spiral array will be displayed in a single line.

Constraints:
1 <=T<= 100

Example:
Input:
1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int t;
 	cin>>t;

 	while(t--){
 		int i,j;
 		int a[4][4];
 		for(i=0;i<4;i++){
 			for(j=0;j<4;j++){
 				cin>>a[i][j];
 			}
 		}

 		i=0;
 		j=0;
 		// Variables to keep track of lower and upper limits of i and j; c counts 16 elements
 		int iu=3,ju=3,il=0,jl=0,c=16;
 		
 		// Sort the 4x4 array as per spiral
 		while(c--){
 			cout<<a[i][j]<<" ";
 			if(i==il && j!=ju){
 				j++;
 			}
 			else if(j==ju && i!= iu){
 				il=1;
 				i++;
 			}
 			else if(i==iu && j!=jl){
 				ju=2;
 				j--;
 			}
 			else if(j==jl && i != il){
 				iu=2;
 				i--;
 			}
 		}
 		cout<<endl;
 	}	
	return 0;
}