/*

GeeksForGeeks:Kadane's Algorithm

Link to Problem: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 
Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 1000
-100 ≤ A[i] <= 100
 
Example:
Input
2
3
1 2 3
4
-1 -2 -3 -4

Output
6
-1

References: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

*/


#include<iostream>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
		
		// max_num stores the maximum value in the array
 		int n,a[1000],max_num;
 		cin>>n;

 		for(int i=0;i<n;i++){
 			cin>>a[i];
 			if(i==0 || a[i]>max_num){
 				max_num = a[i];
 			}
 		}
 		int max_so_far=0;
 		int max_till_here=0;
 		for(int i=0;i<n;i++){
 			// The maximum_till_here value is compared to previous maximum_so_far value.
 			// If it is greater, then the maximum_so_far value is set to the maximum_till_here value
 			max_till_here += a[i];
 		
 			if (max_till_here < 0){
 				max_till_here = 0;
 			}
 		
 			// The maximum_so_far value is the sum of contiguous sub array 
 			if(max_so_far<max_till_here){
 				max_so_far=max_till_here;
 			}

 		}
 		if (max_so_far ==0){
 			cout<<max_num<<endl;
 		}
 		else{
 			cout<<max_so_far<<endl;
 		}

 	}
	return 0;
}