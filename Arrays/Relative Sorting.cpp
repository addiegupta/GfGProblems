/*

GeeksForGeeks: Relative Sorting

Link to Problem: https://practice.geeksforgeeks.org/problems/relative-sorting/0

Difficulty: Medium

Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those  in A2. For the elements not present in A2. Append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}
Since 2 is present first in A2[], all occurrences of 2s should appear first in A[], then all occurrences 1s as 1 comes after 2 in A[]. Next all occurrences of 8 and then all occurrences of 3.  Finally we print all those elements of A1[] that are not present in A2[]
 

Input:

The first line of input contains an integer T denoting the number of test cases. The first line of each test case is M and N.  M is the number of elements in A1 and N is the number of elements in A2.
The second line of each test case contains M elements. The third line of each test case contains N elements.

Output:

Print the sorted array according order defined by another array.

Constraints:

1 ≤ T ≤ 50
1 ≤ M ≤ 50
1 ≤ N ≤ 10 & N ≤ M
1 ≤ A1[i], A2[i] ≤ 1000

Example:

Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9
 

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int t;
 	cin>>t;

 	while(t--){
 		int i,j,k,m,n;
 		cin>>m>>n;
 		int* a = new int[m];
 		int* b = new int[n];
 		for(i=0;i<m;i++){
 			cin>>a[i];
 		}
 		for(i=0;i<n;i++){
 			cin>>b[i];
 		}
 		// Index of a array where element is to be placed
 		int c=0;
 		for(i=0;i<n;i++){
 			for(j=c;j<m;j++){
 				//Sort relative to b array
 				if(a[j]==b[i]){
 					swap(a[j],a[c]);
 					c++;
 				}
 			}
 		}
 		//Sort remaining array
 		for(i=c;i<m-1;i++){
 			for(j=i+1;j<m;j++){
 				if(a[j]<a[i]){
 					swap(a[j],a[i]);
 				}
 			}
 		}
 		for(i=0;i<m;i++){
 			cout<<a[i]<<" ";
 		}
 		cout<<endl;
 		delete a;
 		delete b;
	}	
	return 0;
}