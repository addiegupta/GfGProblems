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
int elementAtK(ll n,ll m,ll k, ll a[],ll b[]){
	ll l1 = 0, l2 =0, r1 = min(n-1,k-1), r2 = min(m-1,k-1);
	ll i,j;
	while(l1-r1>=2){	
		i = (l1+r1)/2;
		j = k-i-1;
		cout<<"i is "<<i<<" a[i] is "<<a[i]<<endl;
		cout<<"j is "<<j<<" b[j] is "<<b[j]<<endl;
		if(j>=m){

			l1=2*(k-m) -r1;
			cout<<"Continuing\n";
			continue;
		}
		if(a[i]<b[j-1]){
			l1=i+1;
		}
		else if(a[i-1]>b[j]){
			r1=i-1;
		}
		else return min(a[i],b[j]);
	}
	return -1;
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
		/*if(n>m)*/cout<<elementAtK(n,m,k,a,b)<<endl;
		// else cout<<elementAtK(m,n,k,b,a)<<endl;
	}
}
