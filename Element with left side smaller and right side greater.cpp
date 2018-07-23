/*

GeeksForGeeks: Element with left side smaller and right side greater

Link to Problem: https://practice.geeksforgeeks.org/problems//unsorted-array/0

Difficulty: Easy

Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1<=T<=100
3<=N<=106
1<=A[i]<=106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
 	int t;
 	cin>>t;

 	while(t--){
 		ll n,i,j,m=0;
 		cin>>n;
 		ll* a = new ll[n];
 		for(i=0;i<n;i++){
 			cin>>a[i];
 		}
 		// Flag to check if element was found or not
 		int f=0;
 		for(i=1;i<n-1;i++){
 			int f1=1,f2=1;
 			// Check left side for larger elements than current element
 			for(j=0;j<i;j++){
 				if(a[j]>a[i]){
 					f1=0;
 					break;
 				}
 			}
 			// Check right side only if left side elements are smaller
 			if(f1){

	 			for(j=i+1;j<n;j++){
	 				if(a[j]<a[i]){
	 					f2=0;
	 					break;
	 				}
	 			}
 				if(f2){
 					cout<<a[i]<<endl;
 					f=1;
 					break;
 				}
 			}
 		}
 		if(!f){
 			cout<<"-1"<<endl;
 		}
	}	
	return 0;
}