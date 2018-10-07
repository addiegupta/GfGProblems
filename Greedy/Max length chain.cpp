/*

GeeksForGeeks: Max length chain

Link to problem: https://practice.geeksforgeeks.org/problems/max-length-chain/1

Difficulty: Medium

You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Your task is to complete the function maxChainLen which returns an integer denoting the longest chain which can be formed from a given set of pairs. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow .Then T test cases follow . The first line of input contains an integer N denoting the no of pairs . In the next line are 2*N space separated values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 

Output
3
1
​
Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
(ii) The max length chain possible is only of length one.



*/

#include <bits/stdc++.h>
using namespace std;
struct val{
	int first;
	int second;
};
int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/

// Used to sort array on basis of second element of structure
bool structCompare(val v1, val v2){return v1.second<v2.second;}

// Similar to activity selection
int maxChainLen(struct val p[],int n)
{	

	sort(p,p+n,structCompare);
	
	// First pair will be selected
	int count =1;
	// Next pair in chain is selected only if its first element is greater than second element
	// of previous pair; hence store second element of previous pair
	int prev = p[0].second;
	for(int i=1;i<n;i++){

		val x = p[i];
		// Eligible for chain
		if(x.first>prev){
			// Increase chain count
			count++;
			// Set this element as previous element
			prev = x.second;
		}
	}
	return count;

}