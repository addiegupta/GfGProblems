/*

GeeksForGeeks: Power of 2

Link to problem: https://practice.geeksforgeeks.org/problems/power-of-2/0

Difficulty: Basic

Given a positive integer N, check if N is a power of 2.

Input:
The first line contains 'T' denoting the number of test cases. Then follows description of test cases.
Each test case contains a single positive integer N.


Output:
Print "YES" if it is a power of 2 else "NO". (Without the double quotes)


Constraints:
1<=T<=100
0<=N<=10^18

Example:
Input :
2
1
98

Output :
YES
​NO

Explanation:  (2^0 == 1)


*/


#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		bool ans = false;
		// While number greater than 0
		while(n){
			// If LSB is 1
			if(n&1){
				// If LSB is removed and number is still greater than 0 then it is not power of 2 for sure
				// Else it is power of 2 for sure
			    (n>>1UL)?ans=false:ans=true;
			    break;
			}
			// Shift Right 
			n=n>>1UL;
		}
		(ans)?cout<<"YES":cout<<"NO";
		cout<<endl;
	}
	return 0;
}