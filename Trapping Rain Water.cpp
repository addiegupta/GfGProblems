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


#include<iostream>
using namespace std;
int max(int,int);
int min(int,int);
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		// Array b stores the water level at given position
		int a[100],n,b[100],i,j;
		cin>>n;

		for(i=0;i<n;i++){
			cin>>a[i];
		}
		// The smaller out of the first and last value in the array
		int minFirstLast = min(a[0],a[n-1]);
		// Initialise the water level to minimum bar height
		for(i=0;i<n;i++){
			b[i]=minFirstLast;
		} 		
		// Index of largest bar height and second largest bar height
		int im1=0,im2=0;

		for(i =1;i<n;i++){

			// New largest bar height found
			if(a[i]>a[im1]){
				// Update largest and second largest bar heights
				im2=im1;
				im1=i;

				// Set water level to second largest level on the positions between largest and second largest value
				int li = min(im1,im2);
				int ui = max(im1,im2);
				for(j=li;j<=ui;j++){
					b[j]=a[im2];
				}
				// Set current level to current height
				b[i]=a[i];
			}
			// Level found which is not equal to maximum but is larger than current water level
			else if(a[i]<=a[im1]&&a[i]>b[i]){
				im2 =i;
				j=i;

				// Set water level of previous positions to current level till a higher value is found
				while(b[j]<a[im2]){
					b[j]=a[im2];
					j--;
				}
			}
		}
		// Count the total amount of water
		int w=0;
		for(i=1;i<n-1;i++){
			if(b[i]>a[i]){
				w+=b[i]-a[i];
			}
		}
		cout<<w<<endl;
	}	
 	
	return 0;
}

// Returns the larger value out of 2 given numbers
int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
// Returns the smaller value out of 2 given numbers
int min(int a,int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}