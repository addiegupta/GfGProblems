/*

GeeksForGeeks: Convert array into Zig-Zag fashion

Link to Problem: https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0

Difficulty: Easy

Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f.The relative order of elements is same in the output i.e you have to iterate on the original array only.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the array in Zig-Zag fashion.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
0 ≤A[i]<=10000

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3


*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int t;
 	cin>>t;

 	while(t--){
 		int i,n,flag=0;
 		cin>>n;
 		int* a = new int[n];
 		for(i=0;i<n;i++){
 			cin>>a[i];
 		}
 		for(i=0;i<n-1;i++){
          	if(!flag){
          		if(a[i]>a[i+1]){
          		 	swap(a[i],a[i+1]);
          		}
          	}
          	if(flag){
          		if(a[i]<a[i+1]){
          			swap(a[i],a[i+1]);
          		}
          	}
          	flag=!flag;
    }
    for(i=0;i<n;i++){
          cout<<a[i]<<" "; 
 	}
      cout<<endl;
	}	
	return 0;
}