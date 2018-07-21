/*

GeeksForGeeks: Missing number in array

Link to Problem: https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

Given an array of size n-1 and given that there are numbers from 1 to n with one missing, the missing number is to be found.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.
The second line of each test case contains N-1 input C[i],numbers in array.

Output:

Print the missing number in array.

Constraints:

1 ≤ T ≤ 200
1 ≤ N ≤ 1000
1 ≤ C[i] ≤ 1000

Example:

Input
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output
4
9

*/


#include<iostream>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
		int n,a[1000],m=-1;
		cin>>n;
		
		for(int i=0;i<n-1;i++){
			cin>>a[i];
			// If first element is not 1, then 1 is the missing element
			if(i==0 && a[i]!=1){
				m=1;
			}
			// If a number is skipped in between
			else if(a[i]!=a[i-1] + 1){
				m = a[i]-1;
			}
		}
		// If the last number is missing
		if(m==-1){
			m=a[n-2]+1;
		}
		
		cout<<m<<endl;
 	}
	return 0;
}