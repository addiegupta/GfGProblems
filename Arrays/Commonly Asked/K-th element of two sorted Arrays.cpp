/*

GeeksForGeeks: K-th element of two sorted Arrays

Link to Problem: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0

Difficulty: Easy

Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array.

Input:
First line consists of test cases T. First line of every test case consists of 3 integers N, M and K, denoting number of elements in array1, number of elements in array2 and K-th element respectively. Second and Third line of every test case consists of elements of Array1 and Array2 respectively.

Output:
Print the element at the Kth position.

Constraints:
1<=T<=200
1<=N,M<=1000
1<=Ai,Bi<=1000
1<=K<=N+M

Example:
Input:
1
5 4 5
2 3 6 7 9
1 4 8 10
Output:
6


*/

#include<iostream>
using namespace std;
int main()
{
 	int t;
 	cin>>t;

 	while(t--){
 		int i,n,j,m,k;
 		cin>>n>>m>>k;
 		int a[10000];

 		for(i=0;i<n;i++){
 			cin>>a[i];
 		}
 		int b[10000];

 		for(i=0;i<m;i++){
 			cin>>b[i];
 		}
 		int f,ptr_a=0,ptr_b=0;
 		for(i=0;i<n+m;i++){
 			if(ptr_a>=n){
 				ptr_b++;
 				f=1;
 			}
 			else if(ptr_b>=m){
 				ptr_a++;
 				f=0;
 			}
 			else if(a[ptr_a]>b[ptr_b]){
 				ptr_b++;
 				f=1;
 			}
 			else if(a[ptr_a]<=b[ptr_b]){
 				ptr_a++;
 				f=0;
 			}
 			if(ptr_a+ptr_b==k){
 				if(f){
 					cout<<b[ptr_b-1];
 				}
 				else{
 					cout<<a[ptr_a-1];
 				}
 				cout<<endl;
 				break;
 			}
 		}
	}	
	return 0;
}