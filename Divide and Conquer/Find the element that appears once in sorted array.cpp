/*

GeeksForGeeks: Find the element that appears once in sorted array

Link to problem: https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0

Difficulty: Basic

Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element in linear time complexity and without using extra memory.

Input:
The first line of input consists of T, the number of the test cases. T testcases follow. Each testcase contains two lines of input.
The first line of each test case contains the size of the array, and the second line has the elements of the array.

Output:
For each testcase, in a new line, print the number that appears only once in the array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1017

Example:
Input:
1
11
1 1 2 2 3 3 4 50 50 65 65
Output:
4

*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll singleElement(ll a[],ll n){
	for(ll i=0;i<n;i+=2){
		if(a[i]!=a[i+1]) return a[i];
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		cout<<singleElement(a,n)<<endl;
	}
}
