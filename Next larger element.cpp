/*

GeeksForGeeks: Next larger element

Link to Problem:https://practice.geeksforgeeks.org/problems/next-larger-element/0

Difficulty: Easy

Given an array A [ ] having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A[ ].
 
Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1<=T<=200
1<=N<=1000
1<=A[i]<=1000

Example:
Input
1
4
1 3 2 4 

Output
3 4 4 -1

Explanation
In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i,j;
		cin>>n;

		vector<int> a(n);
		for(i=0;i<n;i++){
			cin>>a[i];
		}

		vector<int> b(n);
		stack<int> s;

		// Push first index
		s.push(0);

		for(i=1;i<n;i++){
			int v = a[i];

			// Check if current value is greater than value of any previous index
			while(!s.empty() && v >a[s.top()] ){
				b[s.top()] = v;
				s.pop();
			}
			// Add current index to stack so that greater value can be found for this
			s.push(i);

		}
		// No value found for these hence -1
		while(!s.empty()){
			b[s.top()] = -1;
			s.pop();
		}
		for(i=0;i<n;i++){
			cout<<b[i]<<" ";
		}

		cout<<endl;
	}
	return 0;
}