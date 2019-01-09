/*

GeeksForGeeks: Subarray with given sum

Link to Problem: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0

Difficulty: Easy

Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation : 
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15

*/
#include<bits/stdc++.h>
using namespace std;
void findSumInStringForNegativesToo(int s[],int sum,int n){
	unordered_map<int,int> map;

	int curr_sum=0;
	for(int i=0;i<n;i++){
		// Add to sum of arrays in iteration order
		curr_sum += s[i];


		// Sum satisfied from starting index: Note : this problem uses 1 based index
		if(curr_sum==sum){
			cout<<"1 "<<i<<endl;
			return;
		}

		// Found the sum to be removed from curr_sum to obtain the required sum
		if(map.find(curr_sum-sum)!=map.end()){
			cout<<map[curr_sum-sum]<<" "<<i<<endl;
			return;
		}
		// Add sum diff to map using index
		map[curr_sum-sum]=i;
	}
}
void findSumInString(int s[],int sum,int n){
	int cur_sum=0;
	int low=0,high=-1;
	
	// Iterate over array
	for(int i=0;i<n;i++){
		// Add to current sum
		cur_sum+=s[i];
		//Increment high index pointer
		high++;
		// Sum more than required remove previous elements and increase low pointer
		while(cur_sum>sum){
			cur_sum-=(s[low++]);
		}
		// Found,output the indices
		if(cur_sum==sum){
			cout<<low+1<<" "<<high+1<<endl;
			return;
		}

	}
	cout<<-1<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        int s[n];
        for(int i=0;i<n;i++)cin>>s[i];
        findSumInString(s,sum,n);
    }
}

