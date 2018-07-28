/*

GeeksForGeeks: Rotten Oranges

Link to Problem:https://practice.geeksforgeeks.org/problems/rotten-oranges/0

Difficulty: Easy

Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges 
So we have to determine what is the minimum time required so that all the oranges become rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array a[]. Next r line contains space separated c elements each in the array a[].

Output:
Print an integer which denotes the minimum time taken to rot all the oranges.(-1 if it is impossible).

Constraints:
1<=T<=100
1<=r<=100
1<=c<=100
0<=a[i]<=2

Example:
Input:
2
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1

Output:
2
-1


*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int r,c,i,j,l,k,oc=0;
    cin>>r>>c;
    int a[r][c];
    // Get matrix
    for(i=0;i<r;i++){
      for(j=0;j<c;j++){
        cin>>a[i][j];
        // Count fresh oranges
        if(a[i][j]==1) oc++;
      }
    }
    int count=0;
    while(oc){
      // Flag to check if rotting takes place in this iteration
      int f = 1;
      for(i=0;i<r;i++){
        for(j=0;j<c;j++){
          // Rotten orange found
          if(a[i][j]==2){
            // Conditions check if there are surrounding oranges or position is at edge
            if(i>0){ 
              if(a[i-1][j]==1){
                // Rot orange
                a[i-1][j]=3;
                f=0;
                oc--;
              }
            }
            if(i<r-1){ 
              if(a[i+1][j]==1){
                a[i+1][j]=3;
                oc--;
                f=0;
              }
            }
            if(j>0){ 
              if(a[i][j-1]==1){
                a[i][j-1]=3;
                oc--;
                f=0;
              }
            }
            if(j<c-1){ 
              if(a[i][j+1]==1){
                a[i][j+1]=3;
                oc--;
                f=0;
              }
            }

            }
          }
        }
      
      for(k=0;k<r;k++){
        for(l=0;l<c;l++){
          // Update new rotten oranges
          if(a[k][l]==3){
            a[k][l]=2;
          }
        }
      }
      count++;
      // No oranges rot in this iteration
      if(f){
        count=-1;
        break;
      }
    }
    
  cout<<count<<endl;
  }
  return 0;
}