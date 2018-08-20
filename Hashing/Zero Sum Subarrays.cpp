/*

GeeksForGeeks: Zero Sum Subarrays

Link to problem: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0

Difficulty: Easy 

Given an array of size N , print the total count of sub-arrays having their sum equal to 0

Input: First line of the input contains an integer T denoting the number of test cases. Each test case consists of two lines. First line of each test case contains an Integer N denoting the size of the array and the second line contains N space separated integers.

Output: Corresponding to each test case, print the total number of subarrays whose sum is equal to 0.

Constraints:    
1<= N <= 10000
-100 <= A[i] <= 100 where i <= N

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7

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
		unordered_map<int,int> map;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		int c=0,sum=0;
		map[0]++;
		for(i=0;i<n;i++){
			sum+=a[i];
			if(map.find(sum)!=map.end()){
				c+=map[sum];
			}
			map[sum]++;	
		}
		cout<<c<<endl;
	}

	return 0;
}

