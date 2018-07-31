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

*/


#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,a[1000],k;
 		cin>>n;
 		for(int i=0;i<n;i++){
 			cin>>a[i];
 		}
 		cin>>k;
 		// Sort array using inbuilt C++ sort function
 		sort(a,a+n);
 		// Print the kth smallest element as array is sorted
 		cout<<a[k-1]<<endl;
 		
 	}
	return 0;
}