/*

GeeksForGeeks: Longest consecutive subsequence

Link to problem: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

Difficulty: Medium

Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:

The first line of input contains T, number of test cases.

First line of line each test case contains a single integer N.

Next line contains N integer array.

Output:

Print the output of each test case in a seprate line.

Constraints:

1<=T<=100
1<=N<=100
0<=a[i]<=500

Example:

Input:

2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:

6
4
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int i,n;
		cin>>n;
		int a[n];
		// For hashing the array
		unordered_set<int> s;
		int ans=0;

		for(i=0;i<n;i++){
			cin>>a[i];
			s.insert(a[i]);
		}
		for(i=0;i<n;i++){
			// checks if this element starts a new subsequence
			if(s.find(a[i]-1)==s.end()){
				int j = a[i];
				// Count the number of elements following a[i] i.e. length of subsequence
				while(s.find(j)!=s.end())j++;


				ans = max(ans,j-a[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

