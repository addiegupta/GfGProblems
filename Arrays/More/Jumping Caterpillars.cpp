/*

GeeksForGeeks: Jumping Caterpillars

Link to Problem: https://practice.geeksforgeeks.org/problems/jumping-caterpillars/0

Difficulty: Easy

Given N leaves numbered from 1 to N . A caterpillar at leaf 1, jumps from leaf to leaf in multiples of Aj (Aj, 2Aj, 3Aj).
j is specific to the caterpillar. Whenever a caterpillar reaches a leaf, it eats it a little bit.. You have to find out how many leaves, from 1 to N, are left uneaten after all K caterpillars have reached the end. Each caterpillar has its own jump factor denoted by Aj, and each caterpillar starts at leaf number 1.

Input:
The first line consists of a integer T denoting the number of testcases. T test cases follow. Each test case consists of two lines of input. The first line consists of two integers: N, which denotes the number of leaves; and K, which denotes the number of caterpillars. Second line of each test case consists of K space seperated integers denoting the jumping factor of caterpillars.

Output:
For each testcase, in a new line, print a  single integer denoting the number of uneaten leaves.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= K <= 107
1 <= Aj <= 100

Example:
Input:
1
10 3
2 3 5
Output:
2

Explanation:
Testcase1: The leaves eaten by the first caterpillar are (2, 4, 6, 8, 10).
The leaves eaten by the second caterpilllar are (3, 6, 9)
The leaves eaten by the third caterpilllar are (5, 10)
Ultimately, the uneaten leaves are 1, 7 and their number is 2

*/


#include<bits/stdc++.h>
using namespace std;

int jumpingCaterpillars(int a[],int n,int k){
	int count = 0;
	for(int i=1;i<=n;i++){
		bool eaten = false;
		for(int j=0;j<k;j++){

			// This number will be visited by caterpillar having jumping factor of
			// a[j]
			if(i%a[j]==0){
				eaten=true;
				break;
			}
		}
		if(!eaten)count++;
	}
 	return count;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[k];
		for(int i=0;i<k;i++)cin>>a[i];
		cout<<jumpingCaterpillars(a,n,k)<<endl;
	}
	return 0;
}