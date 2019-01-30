/*

GeeksForGeeks:Maximum Index

Link to Problem: https://practice.geeksforgeeks.org/problems/maximum-index/0

Difficulty: Medium

Given an array A of positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
Print the maximum difference of the indexes i and j in a separtate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1018

Example:
Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6

Explanation:
Testcase 1:  In the given array A[1] < A[7] satisfying the required condition(A[i] <= A[j]) thus giving the maximum difference of j - i which is 6(7-1). 

*/


#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll findMaxRange(ll a[],ll n){
	// Corner case
	if(n==1)return 0;

	// Stores the minimum from left till index i
	ll *LMin = new ll[n];

	// Stores the maximum from right till index i
	ll *RMax = new ll[n];

	// Minimum and Maximum in array
	ll min=a[0],max=0;

	// Initialise LMin array  
	for(ll i=0;i<n;i++){
		if(a[i]<min) min = a[i];
		LMin[i]=min;
	}

	// Initialise RMax array
	for(ll i=n-1;i>=0;i--){
		if(a[i]>max) max = a[i];
		RMax[i]=max;
	}
	
	// Iterate over array a
	ll i=0,j=1;
	int maxDiff = 0;
	while(i<n && j<n){
		// Suitable match, increment j to find better solution
		if(LMin[i]<=RMax[j]){
			if(j-i>maxDiff) maxDiff = j-i;
			j++;	
		}
		// Find better minimum by going right 
		else i++;
	}
	delete LMin;
	delete RMax;
	
	return maxDiff;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll *a = new ll[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		cout<<findMaxRange(a,n)<<endl;
		delete a;
	}
	return 0;
}