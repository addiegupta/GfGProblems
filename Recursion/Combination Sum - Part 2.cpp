/*

GeeksForGeeks: Combination Sum - Part 2

Link to Problem: https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0

Difficulty: Medium

Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.

ach number in A may only be used once in the combination.

Note:
   All numbers will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   The combinations themselves must be sorted in ascending order.
   If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 10,1,2,7,6,1,5 and B(sum) 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

Input:
First is T , no of test cases. 1<=T<=500
Every test case has three lines.
First line is N, size of array. 1<=N<=12
Second line contains N space seperated integers(x). 1<=x<=9.
Third line is the sum B. 1<=B<=30.
 
Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
2
7
10 1 2 7 6 1 5
8
5
8 1 8 6 8
12

Output:
(1 1 6)(1 2 5)(1 7)(2 6)
Empty


*/
#include<bits/stdc++.h>
using namespace std;
void sol(vector<vector<int>>& ans,vector<int>& res,vector<int> a,int i,int s,int n){
	// Sum is 0, found a combination, push the vector to the output vector of vectors of ints
	if(s==0){
		ans.push_back(res);
		return;
	}
	// Out of bounds/Not applicable
	if(i>=n||a[i]>s)return;
	// Add current input number to res vector
	res.push_back(a[i]);
	// Recursive call to solve function, with next number of input vector
	sol(ans,res,a,i+1,s-a[i],n);
	// Remove the number and call sol without the current input number
	res.pop_back();
	// Skip through repition of the current input number
	while(i<n-1 && a[i]==a[i+1])i++;
	sol(ans,res,a,i+1,s,n);

}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int i,s,n;
		cin>>n;
		// Input array
		vector<int> a(n);
		for(i=0;i<n;i++)cin>>a[i];
		// Sum
		cin>>s;
		// Sort in increasing order
		sort(a.begin(),a.end());
		vector<vector<int>> ans;
		vector<int> res;
		// Call the solve function
		sol(ans,res,a,0,s,n);
		// Print the combinations
		for(i=0;i<ans.size();i++){
			cout<<"(";
			for(int j=0;j<ans[i].size();j++){
				if(j)cout<<" ";
				cout<<ans[i][j];
			}
			cout<<")";
		}
		// No combination found, print "Empty"
		if(ans.size()==0)cout<<"Empty";
		cout<<endl;
	}
	return 0;
}