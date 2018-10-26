/*

GeeksForGeeks: K-th element of two sorted Arrays

Link to problem: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0

Difficulty: Easy

Given two sorted arrays A and B of size M and N respectively and an element k. The task is to find the element that would be at the k’th position of the final sorted array.

Input:
First line consists of test cases T. First line of every test case consists of 3 integers N, M and K, denoting M number of elements in A, N number of elements in B and kth position element. Second and Third line of every test case consists of elements of A and B respectively.

Output:
Print the element at the Kth position.

Constraints:
1 <= T <= 200
1 <= N, M <= 106
1 <= Ai, Bi <= 106
1 <= K <= N+M

Example:
Input:
1
5 4 5
2 3 6 7 9
1 4 8 10

Output:
6

Explanation:
Testcase 1: Element at 5th position after merging both arrays will be 6.

*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll elementAtK(ll n,ll m,ll k, ll a[],ll b[]){

	// Keep first array smaller
	if(n>m) return elementAtK(m,n,k,b,a);

	// Smaller array is empty
	if(!n) return b[k-1];

	// First element required, return minimum of first in both arrays
	if(k==1)return min(a[0],b[0]);

	// Divide and Conquer iteration variables
	ll i = min(n,k/2),j = min(m,k/2);

	// Lowest j found, find k-jth element
	if(a[i-1]>b[j-1]) return elementAtK(n,m-j,k-j,a,b+j);

	// Lowest i found, find k-ith element
	else return elementAtK(n-i,m,k-i,a+i,b);


}
int main()
{
	int t;
	cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll a[n],b[m];
		for(ll i=0;i<n;i++)cin>>a[i];
		for(ll i=0;i<m;i++)cin>>b[i];
		cout<<elementAtK(n,m,k,a,b)<<endl;
	}
}
