/*

GeeksForGeeks: Array Subset of another array

Link to problem: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0

Difficulty: Easy

Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an two integers m and n denoting the size of arr1 and arr2 respectively. The following two lines contains the space separated elements of arr1 and arr2 respectively.

Output:
Print "Yes"(without quotes) if arr2 is subset of arr1.
Print "No"(without quotes) if arr2 is not subset of arr1.

Constraints:
1<=T<=10^5
1<=m,n<=10^5
1<=arr1[i],arr2[j]<=10^5

Example:
Input:
3
6 4
11 1 13 21 3 7
11 3 7 1
6 3
1 2 3 4 5 6
1 2 4
5 3
10 5 2 23 19
19 5 3

Output:
Yes
Yes
No



*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int i,n,m;
		cin>>n>>m;
		int a[n],b[m];
		unordered_set<int> s;
		for(i=0;i<n;i++){
			cin>>a[i];
			// Hash elements of first array
			s.insert(a[i]);
		}
		for(i=0;i<m;i++){
			cin>>b[i];
		}
		int f=1;
		for(i=0;i<m;i++){
			// First array does not contain the element of the second array
			if(s.find(b[i])==s.end()){
				f=0;
			}
		}
		(f)?cout<<"Yes":cout<<"No";
		cout<<endl;
		
	}
	return 0;
}

