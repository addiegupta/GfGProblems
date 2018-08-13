/*

GeeksForGeeks: Water Overflow

Link to Problem: https://practice.geeksforgeeks.org/problems/champagne-overflow/0

Difficulty: Medium

There is a stack of water glasses in a form of pascal triangle and a person wants to pour the water at the topmost glass, but the capacity of each glass is 1 unit . Overflow takes place in such a way that after 1 unit, 1/2 of remaining unit gets into bottom left glass and other half in bottom right glass.

Now the pours K units of water in the topmost glass and wants to know how much water is there in the jth glass of the ith row.

Assume that there are enough glasses in the triangle till no glass overflows. 

Input:   First line of the input contains an integer T denoting the number of test cases and each test case consists of three lines. First line contain an integer K, second line contains an integer i and third line contains an integer j.


Output: Corresponding to each test case output the remaining amount of water in jth cup of the ith row correct to 6 decimal places.


Constraints:

T<=20
K<=1000
i <= K
j<= K
                
Example:
Input:

1
3 
2
1

Output:
1


*/
#include <bits/stdc++.h>
using namespace std;

float a[1000][1000];
void pour(int i,int j,float k){
	// Negative / zero value
	if(k<=0) return;
	// Amount of value to be poured in this glass
	float p = 1-a[i][j]; 
	// Not enough water; simply add all water to glass and stop recursion
	if(p>k){
		a[i][j]+=k;
		return;
	}
	// Add amount to be poured to glass
	else a[i][j]+=p;
	// Overflow the remaining water to glasses below
	k -= p;
	pour(i+1,j,k/2);
	pour(i+1,j+1,k/2);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
	    int ai,aj;
	    float k;
	    cin>>k>>ai>>aj;
	    // Empty the glasses
	    for(int i=0;i<=ai;i++){
	    	for(int j=0;j<=i;j++)a[i][j]=0;
	    }
		// Pour k units at index 0,0
		pour(0,0,k);
		// Print the amount of water at required glass
		cout<<a[ai-1][aj-1]<<endl;
	}
	return 0;
}