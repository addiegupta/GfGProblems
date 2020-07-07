/*

GeeksForGeeks: Subarray with given sum

Link to Problem: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

Given an unsorted array of non-negative integers, find a continuous sub-array which adds to a given number.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:

Corresponding to each test case, in a new line, print the starting and ending positions of first such occuring subarray if sum equals to subarray, else print -1.

Note: Position of 1st element of the array should be considered as 1.

Expected Time Complexity: O(n)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ an array element ≤ 200

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
In first test case, sum of elements from 2nd position to 4th position is 12
In second test case, sum of elements from 1st position to 5th position is 15
*/


#include<iostream>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,s,a[100];
 		cin>>n>>s;
 		for(int i=0;i<n;i++){
 			cin>>a[i];
 		}
 		int sum=0,x=0,y=0,f=0;
 		for (int i=0;i<n;i++){
 			// New sum will be less than required, add anyway
 			if(sum+a[i]<s){
 				sum +=a[i];
 				y=i;
 			}
 			// New sum will be equal or greater than required
 			else{
 				// Remove elements from start of subarray so that new element
 				// at end can be added
 				while(sum + a[i]>s){
 					sum -= a[x];
 					x++;
 				}
 				sum += a[i];
 				// Required sum found
 				if(sum==s&&!f){
 					y=i;
 					cout<<x+1<<" "<<y+1<<endl;
 					f=1;
 				}
 			}
 		}
 		if(!f){
 			cout<<"-1"<<endl;
 		}
		
 	}
	return 0;
}
//Cleaner code 6 July 2020
int main()
 {  
    int t;
 	cin>>t;

 	while(t--){
 		int n,s;
 		cin>>n>>s;
 		int a[n];
 		for(int i=0;i<n;i++){
 			cin>>a[i];
 		}
 		int start=0,end=0,sum=0;
 		
 		while(start<=n &&end<=n){
 		    
 		    if(sum==s)break;
 		    if(sum<s){
 		        if(end==n)break;
 		        sum+=a[end++];
 		    }
 		    else if(sum>s){
 		        if(start==n)break;
 		        sum -=a[start++];
 		    }
 		}
 		if(sum==s){
 		    cout<<start+1<<" "<<end;
 		}
 		else cout<<-1;
 		cout<<endl;
 	}
 }