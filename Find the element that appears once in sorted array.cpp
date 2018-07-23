/*

GeeksForGeeks: Find the element that appears once in sorted array

Link to Problem: https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0

Difficulty: Easy

Given a sorted array of integers, every element appears twice except for one. Find that single one in linear time complexity and without using extra memory.


Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.

 

Output:

In each separate line print the number that appears only once in the array.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100000


Example:

Input:

1
11
1 1 2 2 3 3 4 50 50 65 65

Output:

4


*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int t;
 	cin>>t;

 	while(t--){
 		int i,n,flag=0;
 		cin>>n;
 		int* a = new int[n];

 		for(i=0;i<n;i++){
 			cin>>a[i];
 		}
 		// If current element is not equal to next element, then it is present only once
 		for(i=0;i<n;i+=2){
 			if(a[i]!=a[i+1]){
 				cout<<a[i]<<endl;
 				break;
 			}
 		}
	}	
	return 0;
}