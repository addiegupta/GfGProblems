/*

GeeksForGeeks: Maximum subset XOR

Link to problem: https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1

Difficulty: Medium

Given a set of positive integers. The task is to complete the function  maxSubarrayXOR which returns an integer denoting the maximum XOR subset value in the given set. 

Examples:

Input: set[] = {2, 4, 5}
Output: 7
The subset {2, 5} has maximum XOR value

Input: set[] = {9, 8, 5}
Output: 13
The subset {8, 5} has maximum XOR value


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the size of the array A[]. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line output will be the maximum XOR subset value in the given set.

Constraints:
1<=T<=100
1<=N<=50

Example(To be used only for expected output):
Input:
2
3
2 4 5
3
9 8 5
Output:
7
13


*/

#include<bits/stdc++.h>
using namespace std;
 
// Number of bits to represent int
#define INT_BITS 32
int maxSubarrayXOR(int [], int n);
int main()
{
    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
      scanf("%d",&n);
        for(int i=0;i<n;i++)
            {
            scanf("%d",&a[i]);
            }
   
printf("%d
",maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// Function to return maximum XOR subset in set[]
int maxSubarrayXOR(int A[], int n)
{
	
}