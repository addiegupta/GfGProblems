/*

GeeksForGeeks: Pythagorean Triplet

Link to Problem: https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0

Difficulty: Easy

Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array.
The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whtether it is Pythagorean Triplet or not.

Constraints:
1<=T<=50
 1<=N<=100
 1<=A[i]<=100

Example:
Input:
1
5
3 2 4 6 5
Output:
Yes

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,i,j,k;
 		cin>>n;

 		int* a = new int[n];
 		int in;

 		for(i=0;i<n;i++){
 			cin>>in;
 			// Store the squared value directly
 			a[i]=pow(in,2);
 		}
 		// Sort in increasing order
 		sort(a,a+n);
 		// Flag to check if triplet has been found
 		int f=0;
 		for(int i=n-1;i>1;--i){
 			// One pointer at first index and other at second last element initially
            int ptr1=0,ptr2=i-1;
            while(ptr1<ptr2){
            	// Triplet found
                if(a[ptr1]+a[ptr2]==a[i]){
                    f=1;
                    break;
                }
                // Value is exceeding required sum, reduce sum by moving second pointer to left
                else if((a[ptr1]+a[ptr2])>a[i]) 
                    ptr2--;
                // Value is less than required sum, increase sum by moving first pointer to right
                else 
                    ptr1++;
            }
            if(f){
                break;
            }
        }
 		delete a;
 		if (f)
 		{
			cout<<"Yes"<<endl;
 		}
 		else{
 			cout<<"No"<<endl;
 		}
	}	
	return 0;
}