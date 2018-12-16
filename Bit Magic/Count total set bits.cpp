/*

GeeksForGeeks: Count total set bits

Link to problem: https://practice.geeksforgeeks.org/problems/count-total-set-bits/0

Difficulty: Basic

Find the sum of all bits from numbers 1 to N.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the sum of all bits.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000

Example:

Input:
2
4
17

Output:
5
35

Explanation:
An easy way to look at it is to consider the number, n = 4:
0 0 0 = 0
0 0 1 = 1
0 1 0 = 1
0 1 1 = 2
1 0 0 = 1
Therefore , the total number of bits is 5


----------------------------------------------------------------

References: https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
			https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/

--------------------------------------------------------------------

*/
#include<bits/stdc++.h>
using namespace std;
// This works on the principle that the bit at i'th position changes after every
// 2^i iterations vertically down.
int verticalCount(int n){
	int ans=0;
	int i=0;


	while((1<<i)<=n){
	
		// Set or not
		bool k=0;

		// Change value of k
		int change = 1<<i;

		// Vertically iterate over bit i for numbers 1 to n
		for(int j=0;j<=n;j++){
			// Add value i.e. if k=1, bit is set=> count bit
			ans+=k;
			// Toggle
			if(change==1){
				k=!k;
				change = 1<<i;
			}
			else{
				// Decrement counter
				change--;
			}
		}
		i++;
	}
	return ans;
}
int brianKernighansBitCount(int);
void computeAnswer(int ans[]){
	ans[0]=0;
	for(int i=1;i<1001;i++){
		// Using Brian Kernighans Bit Count Algorithm
		ans[i]=ans[i-1]+brianKernighansBitCount(i);
		// Using Built in function
		// ans[i]=ans[i-1]+ __builtin_popcount(i);
	}
}
int brianKernighansBitCount(int n){
	int count =0;
	while(n){
		// Taking AND with n-1 results in removing of 1 set bit
		// e.g. 9      :1001
		// 		9-1 =8 :1000 (1 removed)
		//		9&8    :1000
		// 		7	   :0111
		//		8&7    :0000 (1 removed)
		// Total 2 counted
		n&=(n-1);
		count++;
	}
	return count;
}
int main(){
	int t;
	cin>>t;
	int ans[1001];
	computeAnswer(ans);
	while(t--){
		int n;
		cin>>n;
		//Multiple ways to compute;check references
		cout<<verticalCount(n)<<endl;
		// cout<<ans[n]<<endl;
	}
	return 0;
}