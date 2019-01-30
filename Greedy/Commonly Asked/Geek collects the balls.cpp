/*

GeeksForGeeks: Geek collects the balls

Link to problem: https://practice.geeksforgeeks.org/problems/geek-collects-the-balls/0

Difficulty: Medium

There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end of the road which has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).
The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads). Now you need to help Geek to collect the maximum number of balls.

Input:
The first line of input contains T denoting the number of test cases. The first line of each test case contains two integers N and M, denoting the number of buckets on road1 and road2 respectively. 2nd line of each test case contains N integers, number of balls in buckets on the first road. 3rd line of each test case contains M integers, number of balls in buckets on the second road.

Output:
For each test case output a single line containing the maximum possible balls that Geek can collect.

Constraints:
1<= T <= 1000
1<= N <= 10^3
1<= M <=10^3
0<= A[i],B[i]<=10^6

Example:
Input:
1
5 5
1 4 5 6 8
2 3 4 6 9

Output:
29

Explanation:

The path with maximum sum is (2,3,4)[5,6](9). Integers in [] are the buckets of first road and in () are the buckets of second road. So, max balls geek can collect is 29.


*/
#include<bits/stdc++.h>
using namespace std;

int collectBalls(int a[],int n,int b[],int m){
	// Total sum, sum for array A,sum for array B
	int sum = 0,sumA=0,sumB=0;
	int i,j;
	for(i=0,j=0;i<n&&j<m;){
		//find equal elements to swap paths

		// Travers through b to find equal element in a 
		if(a[i]>b[j]){
			sumB+=b[j];
			j++;
		}
		// Traverse through a to find equal element in b
		else if(a[i]<b[j]){
			sumA+=a[i];
			i++;
		}

		//Equal element found; Choose maximum sum till here
		else{
			sumA+=a[i];
			sumB+=b[j];
			// Next number might be equal; another swap possible
			if(i+1<n&&a[i+1]==b[j]){
			    i++;
			}
			else if(j+1<m&&b[j+1]==a[i]){
			    j++;
			}
			else{
			    i++;
			    j++;
			}
			if(sumA>sumB){
			    sum+=sumA;
			}
			else{
			    sum+=sumB;
			}
			sumA=sumB=0;
		}
	}
	// Remaining elements
	for(;i<n;i++)sumA+=a[i];
	for(;j<m;j++)sumB+=b[j];
	if(sumA>sumB) sum+=sumA;
	else sum += sumB;
	

	return sum;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n],b[m];
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<m;i++)cin>>b[i];
		cout<<collectBalls(a,n,b,m)<<endl;
	}
	return 0;
}