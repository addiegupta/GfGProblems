/*

GeeksForGeeks: Array Pair Sum Divisibility Problem

Link to problem: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem/0

Difficulty: Medium

Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Input:
The first line of input contains an integer T denoting the number of test cases. The T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains the n space separated integers forming the array. The last line contains the value of k.

Output:
Print "True" (without quotes) if given array can be divided into pairs such that sum of every pair is divisible by k or else "False" (without quotes).

Constraints:
1<=T<=100
2<=n<=10^5
1<=a[i]<=10^5
1<=k<=10^5

Example:
Input:
2
4
9 7 5 3
6
4
91 74 66 48
10

Output:
True
False

References : https://www.geeksforgeeks.org/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k/

*/
#include <bits/stdc++.h>
using namespace std;
bool pairSumDivisible(int a[],int n,int k){
	// Pairs cannot be formed for odd element array
	if(n%2!=0) return false;

	int i;
	// Hash map to store frequencies of remainder values
	unordered_map<int,int> freq;

	for(i=0;i<n;i++){
		// Remainder when divided by k
		int temp = a[i]%k;
		// Add to map
		if(freq.find(temp)==freq.end())freq[temp]=1;
		else freq[temp]++;		
	}
	for(i=0;i<n;i++){
		int rem = a[i]%k;
		// Even occurences should exist if rem divides k in 2 parts
		if(2*rem==k){
			if(freq[rem]%2!=0){ 
				return false;
			}
		}
		// Even occurences for remainder 0
		else if(rem==0){
			if(freq[rem]&1)return false;
		}
		// Complements to form required sum
		else if(freq[rem]!=freq[k-rem]){
			return false;
		}
	} 
	return true;

}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		} 
		cin>>k;
		pairSumDivisible(a,n,k)?cout<<"True":cout<<"False";
		cout<<endl;
	}
	return 0;
}

