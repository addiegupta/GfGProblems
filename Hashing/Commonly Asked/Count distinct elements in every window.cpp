/*

GeeksForGeeks: Count distinct elements in every window

Link to problem: https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

Difficulty: Easy

Given an array A[] of size n and an integer k, your task is to complete the function countDistinct which prints the count of distinct numbers in all windows of size k in the array A[].

Example

Input:  A[] = {1, 2, 1, 3, 4, 2, 3};
            k = 4
Output:
3 4 4 3
Explanation:
First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two integers n and k. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the space separated values denoting counts of distinct numbers in all windows of size k in the array A[].

Constraints:
1<=T<=100
1<=n,k<=100
1<=A[]<=100

Example(To be used only for expected output):
Input:
2
7 4
1 2 1 3 4 2 3
3 2
4 1 1
Output:
3 4 4 3
2 1

*/
#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete below method */
void countDistinct(int a[], int k, int n)
{
	// Hash map to store the current window of elements
	map<int,int> valueMap;
	int i,j;
	// Count of distinct elements
	int c=0;
	// Compute for first window
	for(i=0;i<k;i++){
		// Element does not exist in window
		if(valueMap.find(a[i])==valueMap.end()){
			valueMap[a[i]]=1;
			c++;
		}		
		// Increment count of element as it already exists in window
		else valueMap[a[i]]++;
	}
	cout<<c<<" ";
	// Sliding window. Remove first element, add new element at end
	for(i=k;i<n;i++){
		int first = a[i-k];
		// First element (to be removed) was distinct
		if(valueMap[first]==1){
			c--;
			valueMap.erase(first);
		}
		// Decrement count of element to be removed in map
		else{
			valueMap[first]--;
		}
		// Check for occurence in window of new element to be inserted
		if(valueMap.find(a[i])==valueMap.end()){
			valueMap[a[i]]=1;
			c++;
		}
		else valueMap[a[i]]++;
		cout<<c<<" ";
	}
}