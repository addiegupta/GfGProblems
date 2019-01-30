/*

GeeksForGeeks: Geek and its Colored Strings

Link to Problem: https://practice.geeksforgeeks.org/problems/geek-and-its-colored-strings/0

Difficulty: Easy

Geek loves to play with toys a lot. Once his parents bought him a new toy, that 'R', ‘B’ and ‘G’ characters. His parents gave him a task, that was to make a string of size 'n'. Each character of the string is either ‘R’, ‘B’ or ‘G’. In the final string there needs to be at least 'r' number of ‘R’, at least 'b' number of ‘B’ and at least 'g' number of ‘G’ (such that r + g + b <= n). Geek being busy with some other work requested for your help to find the count of all possible strings that can be formed using the given number of characters.

Examples:

Input : n = 4, r = 1, 
        b = 1, g = 1.
Output: 36 
No. of 'R' >= 1, 
No. of ‘G’ >= 1, 
No. of ‘B’ >= 1 and 
(No. of ‘R’) + (No. of ‘B’) + (No. of ‘G’) = n
then following cases are possible:
1. RBGR and its 12 permutation
2. RBGB and its 12 permutation
3. RBGG and its 12 permutation
Hence answer is 36.
Input:
First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. The only line of each test case contains four space separated integers denoting the values of 'n', 'r', 'g' & 'b' respectively.
Output:
For each test print a single line containg an integer denoting the count of number of all possible strings.
Constraints:
1<=T<=100
1<=N<=20
1<=r+g+b<=N
Example:
Input:
2
4 1 1 1
4 2 0 1
Output:
36
22

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[20];

ll fact(int n){
	if(n<=1)return 1;
	if(dp[n]==0) dp[n] = fact(n-1)*n;
	return dp[n];
}

ll rgbPermutations(int n,int r,int g ,int b){
	
	// Incorrect input
	if(r+g+b>n)return 0;

	// Number of characters that need to be chosen
	// i.e. not specified as r, b or g
	int left = n-r-b-g;

	// Total permutations
	ll sum =0;

	// Different possible arrangements for selecting r, g and b for the characters
	// that need to be chosen
	//
	// i is for red
	for (int i = 0; i <= left; i++){	 
        // j is for blue
        for (int j = 0; j<= left-i; j++){

        	//k is for green
            int k = left - (i+j); 
  
            // Compute permutation of each combination 
            // one by one and add them. 
            sum += fact(n) /
                       (fact(i+r)*fact(j+b)*fact(k+g)); 
        } 
    } 
	return sum;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,r,g,b;
		cin>>n>>r>>g>>b;
		cout<<rgbPermutations(n,r,g,b)<<endl;
	}
	return 0;
}