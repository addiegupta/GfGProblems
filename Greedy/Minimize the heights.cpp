/*

GeeksForGeeks: Minimize the heights

Link to problem: https://practice.geeksforgeeks.org/problems/minimize-the-heights/0

Difficulty: Medium

Given an array A[ ] denoting heights of N towers and a positive integer K, modify the heights of each tower either by increasing or decreasing them by K only once and then find out the minimum difference of the heights of shortest and longest towers.

Example

Input  : A[] = {1, 15, 10}, k = 6
Output : 5
Explanation : We change 1 to 6, 15 to 
9 and 10 to 4. Maximum difference is 5
(between 4 and 9). We can't get a lower
difference.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains a positive integer K. The second line of each test case contains a positive integer N, denoting number of towers. The third line of the test cases contains N integers denoting the heights of N towers.

Output
For each test case in new line print out the minimum difference of heights possible.

Constraints
1 <= T <= 100
0 <   K <= 30
0 <   N <= 30
0 <= A[i] <= 500


Examples 
Input
3
2
4
1 5 8 10
3
5
3 9 12 16 20
4
6
100 150 200 250 300 400

Output
5
11
292



*/

#include<bits/stdc++.h>
using namespace std;

int minimizeHeights(int a[],int n,int k){
	if(n==1)return 0;
	
	// Sort array
	sort(a,a+n);

	// Initialise answer as last term - first term
	int ans = a[n-1]-a[0];
	// Small and big variables to store minimum and maximum
	int small = a[0]+k;
	int big = a[n-1]-k;
	if(small>big)swap(small,big);

	// For every element check if 
	// a) either by subtracting or adding k, it can be contained within min and max , if yes then continue
	// b) if it cant be contained within min and max, then assign it as min or max depending on optimal value
	for(int i=1;i<n-1;i++){
		int subtract = a[i]-k;
		int add = a[i]+k;
		if(subtract>=small || add<=big)continue;

		if(big-subtract <= add -small)small = subtract;
		else big = add;

	}
	return min(ans,big-small);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>k>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<minimizeHeights(a,n,k)<<endl;
	}
}