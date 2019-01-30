/*

GeeksForGeeks: Number is sparse or not

Link to problem: https://practice.geeksforgeeks.org/problems/number-is-sparse-or-not/0

Difficulty: Basic

Given a number, check whether it is sparse or not. A number is said to be a sparse number if in binary representation of the number no two or more consecutive bits are set.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is number 'N'.

Output:
Print '1' if the number is sparse and '0' if the number is not sparse.

Constraints:
1 <=T<= 100
1 <=n<= 100

Example:
Input:
2
2
3

Output:
1
0


*/
#include<bits/stdc++.h>
using namespace std;
// Right shifting a number and ANDing it with the original number,
// if the result is 0 then no 2 consecutive set bits exist
int checkIfSparse(int n){
	return (n&(n<<1))? 0: 1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<checkIfSparse(n)<<endl;
	}
	return 0;
}