/*

GeeksForGeeks: Minimum Operations

Link to problem: https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

Difficulty: Easy

Given a number N the task is to find an optimal solution to reach N from 0 using 2 operations ie
1. Double the number 
2. Add one to the number

Example

Input  : N = 8
Output : 4
0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8

Input  : N = 7
Output : 5
0 + 1 = 1, 1 + 1 = 2, 1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print an integer denoting the min no of operation to be performed to reach N from 0.

Constraints:
1<=T<=100
1<=N<=10000

Example:
Input:
2
8
7
Input:
4
5



*/
#include<bits/stdc++.h>
using namespace std;
// Initially stores values for all numbers 
void initMinOperations(int a[]){
	for(int i=1;i<10001;i++){
		if(i==1)a[i]=1;
		else if(i%2==0)a[i]=a[i/2]+1;
		else a[i]=a[i-1]+1;
	}
}
int main(){
	int t;
	cin>>t;
	int a[10001];
	initMinOperations(a);
	while(t--){
		int n;
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}