/*

GeeksForGeeks: Reverse array in groups

Link to Problem: https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0

Difficulty:School

Given an array, reverse every sub-array formed by consecutive k elements.

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.The second line of each test case contains N space separated integers denoting array elements.The third line of each test case consists of an integer K.

Output:
Corresponding to each test case, in a new line, print the modified array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ A[i] ≤ 500

Example:

Input
1
5
1 2 3 4 5
3

Output
3 2 1 5 4
*/


#include<iostream>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,a[500],k;
 		cin>>n;
 		for(int i=0;i<n;i++){
 			cin>>a[i];
 		}
 		cin>>k;
 		int m=(n/k)+1;
 		if(n%k==0){
 			m--;
 		}
 		for(int i=0;i<m;i++){
 			for(int j=k;j>0;j--){
 				if(((i*k)+j-1)>=n){	
 					j-=(((i*k)+j-1)-(n-1));
 				}
 				cout<<a[(i*k)+j-1]<<" ";	
 			}
 		}
 		cout<<endl;
 		
 	}
	return 0;
}