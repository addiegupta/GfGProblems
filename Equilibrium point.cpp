/*

GeeksForGeeks: Equilibrium point

Link to Problem: https://practice.geeksforgeeks.org/problems/equilibrium-point/0

Given an array A your task is to tell at which position the equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements below it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
1. Since its the only element hence its the only equilibrium point
2. For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2)
 
*/


#include<iostream>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,a[100],sum_prev=0,sum_after=0,f=0;
 		cin>>n;
 		// Take input and store sum of all elements in sum_after
 		for (int i=0;i<n;i++){
 			cin>>a[i];
 			sum_after += a[i];
 		}
 		for(int i=0;i<n;i++){
 			if(i!=0){
 				// Add prev value to previous sum
 				sum_prev += a[i-1];
 			}
 			// Subtract current value from after sum
 			sum_after -= a[i];
 			// Compare the sums to check if point is equilibrium point
 			if (sum_prev==sum_after){
 				f=1;
 				cout<<i+1<<endl;
 			}
 		}
 		if(!f){
 			cout<<"-1"<<endl;
 		}
 	}
	return 0;
}