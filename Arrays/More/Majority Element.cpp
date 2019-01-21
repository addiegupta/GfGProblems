/*

GeeksForGeeks:Majority Element

Link to Problem: https://practice.geeksforgeeks.org/problems/majority-element/0

Difficulty: Basic

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1

Explanation:
Testcase 1: Since, 3 is present more than N/2 times, so it is the majority element.
*/



#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000001
using namespace std;

/* Moore's voting algorithm
 
 The idea is to cancel every other element for every occurence of the majority element.

 Method is to start counting occurences of current selected element and decreasing count for every element
 not equal to selected element. If count is 0, set current element as selected element. 
 Then with the final selected element, count its occurences in the array and see if its greater than n/2.


*/
int findMajorityElement(ll a[],ll n){
	// Count occurences; Selected element
	int count = 0,ele;
	for(ll i=0;i<n;i++){
		// New selected element
		if(count==0)ele=a[i];
		
		// Increment/decrement counter depending on whether the current element is same as 
		// selected element
		(a[i]==ele)?count++:count--;

	}

	// Count all occurences of the majority element to see if its actually a majority element
	count=0;
	for(ll i=0;i<n;i++){
		if(a[i]==ele)count++;
	}
	return (count>n/2) ? ele : -1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		cout<<findMajorityElement(a,n)<<endl;
	}
	return 0;
}