/*

GeeksForGeeks: Count the triplets

Link to Problem: https://practice.geeksforgeeks.org/problems/count-the-triplets/0

Difficulty: Easy

Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.

Output:
For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".

Constraints:
1<=T<=100
3<=N<=105
1<=A[i]<=106

Example:
Input:
2
4
1 5 3 2
3
3 2 7
Output:
2
-1


*/


#include<bits/stdc++.h>
using namespace std;

// O((n^2)*(unordered_set read operation))
// Uses hashing to store elements of array
//
// Check next method for much less time operation
// This takes 0.3 seconds for given test case ; Other method:0.04
int countTheTriplets(int a[],int n){
	int count=0;
	unordered_set<int> hash;
	int max=0;
	for(int i=0;i<n;i++){
		hash.insert(a[i]);
		// Store max element in array
		if(a[i]>max)max=a[i];
	}
	// 2 iterators to sum 2 elements
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			// Sum value
			int ele = a[i]+a[j];
			
			// No need to check in hash if sum is greater than max value
			// This step brings down the execution time within limits
			if(ele>max)continue;

			// If value is found in hash, increment count
			if(hash.find(ele)!=hash.end())count++;
		}
	}
	return (count>0) ? count : -1;

}

// O(n^2) operation
// Much faster than previous method
//
// Sorts the array, starts fixing sum element from end
// and for remaining array on left, uses 2 pointers simultaneously adjusting their value
// to find such that they sum upto the fixed element
int countTheTripletsNew(int a[],int n){
	sort(a,a+n);

	int count = 0;
	for(int i=n-1;i>=0;i--){
		int j=0,k=i-1;
		while(j<k){
			if(a[i]==a[j]+a[k]){
				count++;
				j++;
				k--;
			}
			else if(a[i]<a[j]+a[k])k--;
			else j++;
		}
	}
	return (count>0) ? count:-1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<countTheTripletsNew(a,n)<<endl;
	}
	return 0;
}