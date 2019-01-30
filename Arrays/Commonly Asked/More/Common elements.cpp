/*

GeeksForGeeks: Common elements

Link to Problem: https://practice.geeksforgeeks.org/problems/common-elements/0

Difficulty: Easy

Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, you need to print all common elements in these arrays.

Note: Please avoid printing the same common element more than once.

Input:
First line contains a single integer T denoting the total number of test cases. T testcases follow. Each testcase contains four lines of input. First line consists of 3 integers N1, N2 and N3, denoting the sizes of arrays A, B, C respectively. The second line contains N1 elements of A array. The third lines contains N2 elements of B array. The fourth lines contains N3 elements of C array.

Output:
For each testcase, print the common elements of array. If not possible then print -1.

Constraints:
1 <= T <= 100
1 <= N1, N2, N3 <= 107
1 <= Ai, Bi, Ci <= 1018

Example:
Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
Output:
20 80

Explanation:
Testcase1:  20 and 80 are the only common elements




*/


#include<iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Binary search
bool searchInArray(ll ele,ll a[],int n){
	int l=0,r=n-1;
	if(ele<a[l]||ele>a[r])return false;
	int mid;
	while(l<=r){
		mid = (l+r)/2;
		if(a[mid]==ele)return true;
		else if(a[mid]>ele)r=mid-1;
		else l = mid +1;
	}
	return false;
}
void printCommonElements(ll a[],ll b[],ll c[],int n1,int n2,int n3){
	bool found=false;
	for(int i=0;i<n1;i++){

		ll ele = a[i];

		// Avoid duplicate elements
		if(ele==a[i-1])continue;

		// If element is found in other arrays as well, print it ans set flag to true
		// Flag checks if at least one common element is present
		if(searchInArray(ele,b,n2)&&searchInArray(ele,c,n3)){
			cout<<ele<<" ";
			found = true;
		}
	}
	if(!found)cout<<-1;
	cout<<endl;
}
// Pass smallest array as first argument to reduce computation time
void printCommonElementsForSmallest(ll a[],ll b[],ll c[],int n1,int n2,int n3){
	if(n1<n2&&n1<n3)printCommonElements(a,b,c,n1,n2,n3);
	else if(n2<n1&&n2<n3)printCommonElements(b,a,c,n2,n1,n3);
	else printCommonElements(c,a,b,n3,n1,n2);
}
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n1,n2,n3;
		cin>>n1>>n2>>n3;
		ll a[n1],b[n2],c[n3];
		for(int i=0;i<n1;i++)cin>>a[i]; 		
		for(int i=0;i<n2;i++)cin>>b[i]; 		
		for(int i=0;i<n3;i++)cin>>c[i]; 
		printCommonElementsForSmallest(a,b,c,n1,n2,n3);		

 	}
	return 0;
}