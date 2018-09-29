/*

GeeksForGeeks: Minimum Swaps to Sort

Link to problem: https://practice.geeksforgeeks.org/problems/minimum-swaps/1

Difficulty: Medium

Given an array of N distinct elementsA[ ], find the minimum number of swaps required to sort the array.Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.

Examples:

Input : {4, 3, 2, 1}
Output : 2
Explanation : Swap index 0 with 3 and 1 with 2 to 
              form the sorted array {1, 2, 3, 4}.

Input : {1, 5, 4, 3, 2}
Output : 2

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1<=T<=100
1<=N<=100
1<=A[] <=1000

Example(To be used only for expected output):
Input:
2
4
4 3 2 1
5
1 5 4 3 2
Output:
2
2



*/
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);
// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

//Used selection sort and counted the number of swaps
//Not sure why this is a part of the Graphs section
int minSwaps(int A[], int N){
    /*Your code here */
    int count =0;
	for(int i=0;i<N;i++){
		int min=A[i];
		int minIndex=i;
		for(int j=i;j<N;j++){
			if(A[j]<min){
			    min=A[j];
			    minIndex=j;
			}
		}
		if(i!=minIndex){
			swap(A[i],A[minIndex]);
			count++;
		}
	}
	return count;

}
