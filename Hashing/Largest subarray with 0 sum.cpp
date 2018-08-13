/*

GeeksForGeeks: Largest subarray with 0 sum

Link to Problem: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

Difficulty: Easy

Given an array having both positive an negative integers . Your task is to complete the function maxLen which returns the length of maximum subarray with 0 sum . The function takes two arguments an array A and n where n is the size of the array A . 

Input:
The first line of input contains an element T denoting the No of test cases. Then T test cases follow. Each test case consist of 2 lines. The first line of each test case contains a number denoting the size of the array A. Then in the next line are space separated values of the array A .

Output:
For each test case output will be the length of the largest subarray which has sum 0 .

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example:
Input
1
8
15  -2  2  -8  1  7  10 23

Output
5

Explanation
In the above test case the  largest subarray with sum 0 will be -2  2  -8  1  7


*/
#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function*/
int maxLen(int a[],int n)
{
	// Hash map
	unordered_map<int,int> map; 
 	int l=0,s=0;
	for(int i=0;i<n;i++){
		// Total sum
		s+=a[i];
		// Element is 0; length is at least 1
		if(a[i]==0 && !l)l=1;
		// Array from start till end has 0 sum
		if(s==0)l=i+1;

		// If this sum is present in map, then a 0 array is present in between
		if(map.find(s) != map.end()){
			l = max(l,i-map[s]);
		}
		// Add value to map
		else{
			map[s]=i;
		}
	}
	return l;
}
