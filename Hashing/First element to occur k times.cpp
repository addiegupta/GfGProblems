/*

GeeksForGeeks: First element to occur k times

Link to problem: https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times/0

Difficulty: Basic

Given an array of n integers. The task is to find the first element that occurs k number of times. If no element occurs k times the print -1. The distribution of integer elements could be in any range.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of an array and the number K. The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:
For each test case in a new line print the required answer.


Constraints:
1<= T <=100
1<= N,K <=100000
1<= A<=1000000


Example:

Input :
1
7 2
1 7 4 3 4 8 7

Output :
7

Explanation:
Both 7 and 4 occur 2 times. But 7 is the first that occurs 2 times.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		unordered_map<int,int> countMap;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++){
			countMap[a[i]]++;
		}
		int f=0;
		for(int i=0;i<n;i++){
			if(countMap[a[i]]==k){
				f=1;
				cout<<a[i]<<endl;
				break;
			}
		}
		if(!f)cout<<-1<<endl;
	}
	return 0;
}