/*

GeeksForGeeks:Two numbers with sum closest to zero

Difficulty: Medium

Link to Problem: https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero/0

Given an integer array A of N elements. You need to find the sum of two elements such that sum is closest to zero.

Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N, denoting the size of array. Each test case consist of a N integers which are the array elements.

Output:
Print the requiired sum which is closest to zero.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
-106 ≤ a[i] ≤ 106

Example:
Input:
3
3
-8 -66 -60  
6
-21 -67 -37 -18 4 -65  
2
-24 -73

Output:
-68
-14
-97

Explanation:
Testcase 1: Sum of two elements closest to zero is -68 using numbers -60 and -8.



References: https://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/

*/



#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll sumClosestToZero(ll a[],ll n){

	// Sort the array
	sort(a,a+n);
	// 2 pointers on array: left and right
	ll l=0,r=n-1;
	ll minSum=INT_MAX;
	while(l<r){

		if(abs(a[l]+a[r])<abs(minSum))minSum = a[l]+a[r];
		
		// If the sum is positive, decrement the right pointer
		// If the sum is negative, increment the left pointer
		// In this way the sum closest to 0 can be obtained
		(a[l]+a[r]>0) ? r-- : l++;
	}
	return minSum;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		cout<<sumClosestToZero(a,n)<<endl;
	}
	return 0;
}