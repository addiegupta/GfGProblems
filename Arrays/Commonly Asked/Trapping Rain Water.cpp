/*

GeeksForGeeks: Trapping Rain Water

Link to Problem: https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

Difficulty: Medium

Given n non-negative integers in array representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example:
Input:
3
2 0 2
Output:
2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Below is another example.

		   |
|----------|<- Water level
|	   |   |
|______|___|

Bars for input{3,0,0,2,0,4}
Total trapped water = 3+3+1+3=10


Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains an integer N followed by N numbers to be stored in array.

Output:
Print trap units of water in the middle gap.

Constraints:
1<=T<=100
3<=N<=100
0<=Arr[i]<10

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
 0

*/

// See version history for previous untidy solution
#include<iostream>
using namespace std;

// Stores max on left and max on right for every element in 2 arrays
int trappedWater(int arr[],int n){

	// Store max on left and right
	int leftMax[n],rightMax[n];

	int leftMaxValue=arr[0],rightMaxValue=arr[n-1];
	for(int i=1;i<n;i++){
		if(arr[i]>leftMaxValue)leftMaxValue = arr[i];
		leftMax[i]=leftMaxValue;
	}
	for(int i=n-2;i>=0;i--){
		if(arr[i]>rightMaxValue)rightMaxValue = arr[i];
		rightMax[i]=rightMaxValue;
	}

	int ans=0;
	for(int i=1;i<n-1;i++){
		// Min on either side will be the max water stored at this point
		ans += (min(leftMax[i],rightMax[i]) - arr[i]);
	}
	// return total amount of water trapped
	return ans;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    int trapped = trappedWater(a,n);
	    cout<<trapped<<endl;
	}
	return 0;
}