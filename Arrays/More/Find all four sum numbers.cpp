/*

GeeksForGeeks: Find all four sum numbers

Link to Problem: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0

Difficulty: Medium

Given an array A of size N, find all combination of four elements in the array whose sum is equal to a given value K. For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains two integers N and K. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print all the quadruples present in the array separated by space which sums up to value of K. Each quadruple is unique which are separated by a delimeter "$" and are in increasing order.

Constraints:
1 <= T <= 100
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100

Example:
Input:
2
5 3
0 0 2 1 1 
7 23
10 2 3 4 5 7 8

Output:
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $

*/

/*

THIS CODE CAN PROBABLY BE IMPROVED-----------------------------------------------


*/
#include<bits/stdc++.h>
using namespace std;

// Required to store the 4 number combinations so that duplicates are not printed
struct four{
	int a,b,c,d;
	// Required for comparisons in set
	bool operator==(four const& x) const {
    	return a == x.a && b == x.b && c==x.c && d==x.d;
  	}	
};
inline bool operator<(const four& x, const four& y)
{
  if(x.a<y.a)return true;
  if(x.a>y.a)return false;
  if(x.b<y.b)return true;
  if(x.b>y.b)return false;
  if(x.c<y.c)return true;
  if(x.c>y.c)return false;
  if(x.d<y.d)return true;
  if(x.d>y.d)return false;
  return false;
}

void printFourNums(int a[],int n,int k){
	
	// Only needed to store the 4 number combinations to avoid duplication 
	set<four>hash;

	// Sort the array
	sort(a,a+n);

	// To check if atleast 1 combination is present
	bool flag=false;
	
	// Fix first 2 numbers and then find other 2 in O(n) by incrementing left pointer
	// or decrementing right pointer. 
	// This can be done as array is sorted
	for(int i=0;i<n-3;i++){
		for(int j=i+1;j<n-2;j++){
			// Last 2 numbers
			int l=j+1,r=n-1;
			while(l<r){
				int sum =a[j]+a[l]+a[r]+a[i]; 
				if(sum==k){
					flag=true;

					// If does not exist in set, then insert it and print it
					// Else skip
					if(hash.find({a[i],a[j],a[l],a[r]})==hash.end()){
						hash.insert({a[i],a[j],a[l],a[r]});
						cout<<a[i]<<" "<<a[j]<<" "<<a[l]<<" "<<a[r]<<" $";
					}
					l++;
					r--;
				}
				else if(sum < k)l++;
				else r--;
			}
		}
	}
	if(!flag)cout<<-1;
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		printFourNums(a,n,k);
	}
	return 0;
}