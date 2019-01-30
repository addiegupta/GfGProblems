/*

GeeksForGeeks: K’th smallest element

Link to Problem: https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

Difficulty: Medium

Given an array and a number k where k is smaller than size of array, the task is to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Input:

First Line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:

Corresponding to each test case, print the desired output in a new line.

Constraints:

1<=T<=200
1<=N<=1000
K

Expected Time Complexity: O(n)

Example:

INPUT
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:

7
15

References: https://practice.geeksforgeeks.org/editorial.php?pid=1301

*/


#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r){
	int p = a[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(a[j]<=p){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

int quickSelect(int a[],int l,int r,int k){
    if(k>0 && k<= r-l+1){
	    int p = partition(a,l,r);
	    if(p-l==k-1) return a[p];
	    else if(p-l>k-1) return quickSelect(a,l,p-1,k);
	    else return quickSelect(a,p+1,r,k-p+l-1);
    }
    return a[k-1];
    return -1;
}
int main()
 {
 	int t;
 	cin>>t;
 	while(t--){
 		int n,k;
 		cin>>n;
 		int a[n];
 		for(int i=0;i<n;i++)cin>>a[i];
 		cin>>k;
 		cout<<quickSelect(a,0,n-1,k)<<endl;
 	}
	return 0;
}