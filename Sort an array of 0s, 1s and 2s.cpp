/*

GeeksForGeeks: Sort an array of 0s, 1s and 2s

Link to Problem: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

Write a program to sort an array of 0's,1's and 2's in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, First line is number of elements in array 'N' and second its values.

Output: 
Print the sorted array of 0's, 1's and 2's.

Constraints: 

1 <= T <= 100
1 <= N <= 105
0 <= arr[i] <= 2

Example:

Input :

2
5
0 2 1 2 0
3
0 1 0
 

Output:

0 0 1 2 2
0 0 1
*/


#include<iostream>
#define ll long long int
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		ll n,s0=0,s1=0,s2=0;
 		int a;
 		cin>>n;
 		for (ll i =0;i<n;i++){
 			cin>>a;
 			// Check whether input is 0,1 or 2 and add to count of 0,1, or 2
 			switch(a){
 				case 0:	s0++;
 						break;
 				case 1:	s1++;
 						break;
 				case 2:	s2++;
 						break;
 			}
 		}
 		// Print 0s,1s,2s according to count. No need to sort input!
 		for(ll i=0;i<s0;i++){
 			cout<<"0 ";
 		}
 		for(ll i=0;i<s1;i++){
 			cout<<"1 ";
 		}
 		for(ll i=0;i<s2;i++){
 			cout<<"2 ";
 		}
 		cout<<endl;
 	}
	return 0;
}