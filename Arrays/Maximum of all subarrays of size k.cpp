/*

GeeksForGeeks: Maximum of all subarrays of size k

Link to Problem: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

Difficulty:Easy

Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer 'N' denoting the size of array and the size of subarray 'k'.
The second line contains 'N' space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 100
1 ≤ k ≤ N
0 ≤A[i]<1000

Example:

Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

*/


#include<iostream>
#include<vector>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int i,n,k,a[100],b[100],max=0;
 		//Stores the current subarray
 		vector<int> v;
 		cin>>n>>k;
 		for (i=0;i<n;i++){
 			cin>>a[i];
 			// Stores the first subarray of size k
 			if(i<k){
 				v.push_back(a[i]);
 				if(a[i]>max){
 					max=a[i];
 				}
 			}
 			// b array stores max values for the subarrays
 			b[0]=max;
 		}
 		for(int i=1;i<n-k+1;i++){
 			
 			// Element to be removed is the max value. Find new max value
 			if(v.front()==max){
 				max=0;
 				for(int j=1;j<k;j++){
 					if(v.at(j)>max){
 						max=v.at(j);
 					}
 				}
 			}
 			// Remove first element
 			v.erase(v.begin());
 			// Add new element
 			int l = a[i+k-1];
 			v.push_back(l);
 			if(l>max){
 				max=l;
 			}
 			b[i]=max;
 		}
 		for(i=0;i<n-k+1;i++){
 			cout<<b[i]<<" ";
 		}
 		cout<<endl;
 	}
	return 0;
}