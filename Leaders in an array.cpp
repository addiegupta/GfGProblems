/*

GeeksForGeeks: Leaders in an array

Link to Problem: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

Difficulty:Basic

Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. The rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= A[i]<=100

Example:
Input:
2
6
16 17 4 3 5 2
5
1 2 3 4 0
Output:
17 5 2
4 0

*/


#include<iostream>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int i,n,a[100],b[100],max,j=0;
 		cin>>n;
 		for (i=0;i<n;i++){
 			cin>>a[i];
 		}
 		// Rightmost element has to be leader.
 		// Setting max to a lesser value so that the rightmost element will be counted as leader in the loop
 		max=a[n-1]-1;
 		// Reverse iteration of the array
 		for(i=n-1;i>=0;i--){
 			// Greater than all elements to right
 			if(a[i]>max){
 				b[j++]=a[i];
 				max = a[i];
 			}
 		}
 		// Reverse iteration so that elements appear in expected order
 		for(int k=j-1;k>=0;k--){
 			cout<<b[k]<<" ";
 		}
 		cout<<endl;

 	}
	return 0;
}