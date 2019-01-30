/*

GeeksForGeeks: Box Stacking

Link to problem: https://practice.geeksforgeeks.org/problems/box-stacking/1

Difficulty: Medium

You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow . Each test case contains an integer N denoting the total no of boxes available. In the next line are 3*N space separated values denoting the height width and length of the N boxes.

Output:
For each test case in a new line output will be the highest possible stack height which could be formed.

Constraints:
1<=T<=100
1<=N<=100
1<=l,w,h<=100

Example (To be used for expected output) :
Input:
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1

Output
60
15



*/

#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

// Box structure to hold length, width and height
struct box{
	int l,w,h;
};

// Function to compare areas of boxes to sort in order of decreasing base area
bool compareBox(box b1,box b2){
	return (b1.l * b1.w)>(b2.l*b2.w);
}

// Computes the maximum possible height for the given problem
int maxHeight(int height[],int width[],int length[],int n)
{
	// Array to store all rotations of the boxes
	box boxes[3*n];
	int i;
	int j=-1;
	for(i=0;i<n;i++){

		// Original box
		boxes[++j] = {max(length[i],width[i]),min(length[i],width[i]),height[i]};
		
		// First rotation of box
		boxes[++j] = {max(height[i],width[i]),min(height[i],width[i]),length[i]};
		
		// Second rotation of box
		boxes[++j] = {max(height[i],length[i]),min(height[i],length[i]),width[i]};
	}
	// Now number of boxes has been tripled
	n=3*n;

	// Sort in order of decreasing base area
	sort(boxes,boxes + n,compareBox);
	
	// Array to store maximum heights for particular box
	int dp[n];
	
	// Initialise with heights of boxes
    for(i=0;i<n;i++)dp[i]=boxes[i].h;

    for(i=1;i<n;i++){
    	// Box to be placed on top
		box b1 = boxes[i];
		for(j=0;j<i;j++){
			// Box to be placed below
			box b2 = boxes[j];

			// Check if box1 can be placed on top of box2 and if it results in larger height
			if(b1.l<b2.l && 
				b1.w<b2.w && 
				dp[i]<b1.h+dp[j]){
					dp[i]=dp[j]+b1.h;
			}
		}
	}	
	int max=0;
	for(i=0;i<n;i++){
		if(dp[i]>max)max=dp[i];
	}
	return max;
}