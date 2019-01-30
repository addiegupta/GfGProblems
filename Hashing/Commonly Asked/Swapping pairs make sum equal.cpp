/*

GeeksForGeeks: Swapping pairs make sum equal

Link to Problem: https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal/0

Difficulty: Easy

Given two arrays of integers, write a program to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains two space separated integers N and M. Second line of each test case contains N space separated integers denoting the elements of first array. Third line of each test case contains M space separated integers denoting the elements of second array.

Output:
For each test case, print 1 if there exists any such pair otherwise print -1.

Constraints:
1<=T<=100
1<=N<=10000
1<=M<=10000

Example:
Input:
2
6 4
4 1 2 1 1 2
3 6 3 3
4 4
5 7 4 6
1 2 3 8
Output:
1
1

References: https://www.geeksforgeeks.org/find-a-pair-swapping-which-makes-sum-of-two-arrays-same/



*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,i,j,sumA=0,sumB=0;
		cin>>n>>m;
		int a[n],b[m];
		unordered_map<int,int> map;

		for(i=0;i<n;i++){
			cin>>a[i];
			sumA+=a[i];
		}
		for(j=0;j<m;j++){
			cin>>b[j];
			map[b[j]]=1;
			sumB+=b[j];
		}
		if((sumA+sumB)%2!=0){
			cout<<-1<<endl;
			continue;
		}
		int f=0;
		int esum = (sumA+sumB)/2;
		for(i=0;i<n;i++){
			int req_num = a[i]+(esum-sumA);
			if(map.find(req_num)!=map.end()){
				f=1;
				break;
			}
			if(f)break;
		}
		if(f)cout<<1<<endl;
		else cout<<-1<<endl;
		
	}
	return 0;
}