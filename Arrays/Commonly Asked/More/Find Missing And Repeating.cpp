/*

GeeksForGeeks:Find Missing And Repeating

Link to Problem: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0

Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Note: If you find multiple answers then print the Smallest number found. Also, expected solution is O(n) time and constant extra space.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print B, the repeating number followed by A which is missing in a single line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ A[i] ≤ N

Example:
Input:
2
2
2 2
3 
1 3 3

Output:
2 1
3 2

Explanation:
Testcase 1: Repeating number is 2 and smallest positive missing number is 1.
Testcase 2: Repeating number is 3 and smallest positive missing number is 2.
 
*/



#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void solveWithoutStoringNumbers(){

	ll n;
	cin>>n;
	// Repeated and missing number in 1 to n
	ll r,m;
	ll a[n+1];
	memset(a,0,sizeof(a));

	for(ll i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(a[temp]==1) r=temp;
		else a[temp]=1;
	}
	for(ll i=1;i<=n;i++){
		if(!a[i]){
			m=i;
			break;
		}
	}
	cout<<r<<" "<<m<<endl;
}
void solveByStoringNumbersAndNoExtraSpace(){
	ll n,min=INT_MAX;
	cin>>n;
	ll r,m;
	ll a[n];
	memset(a,0,sizeof(a));
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n;i++){
		// Not visited before
		if(a[abs(a[i])-1]>0){
			// Mark as visited by negating it
			a[abs(a[i])-1]= -a[abs(a[i])-1];
		}
		else{
			// Found repeated number
			ll temp = abs(a[i]);
			if(temp<min)min=temp;
		}
	}
	for(ll i=0;i<n;i++){
		// Found missing number as it has not been visited
		if(a[i]>0){
			cout<<min<<" "<<i+1<<endl;
			break;
		}
	}
}
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		// solveWithoutStoringNumbers();
 		solveByStoringNumbersAndNoExtraSpace();	
 	}
	return 0;
}