/*

GeeksForGeeks:Search in a rotated Array

Link to Problem: https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0


*/

#include<iostream>
#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

/*
  Returns the index at which the array is rotated
  i.e the last index till where array is sorted and in order after which the rotated elements occur

  e.g. 4 5 6 7 1 2 3

  Index of element 7 will be returned
*/
int findPivot(int a[],int n){
	int l=0,r=n-1;
	// Binary search for pivot
	while(l<r){
		int mid = (l+r)/2;
		// Found pivot
		if(a[mid-1]>a[mid])return mid-1;
		// Found pivot
		if(r-l==1&&a[0]>a[1]){
			return a[0];
		}
		// Elements on left are sorted, search right side
		if(a[mid]>a[l]){
			l = mid;
		}
		// Elements on right are sorted, search left side
		else r = mid;
	}
	// No rotation in array
	return 0;
}
// 
int getOriginalIndex(int i,int k,int n){
	// 				 		Pivot
	//				 		  |	
	// Array : 			4 5 6 7 1 2 3
	//
	// Original Index:  0 1 2 3 4 5 6
	//
	// New Index:		3 4 5 6 0 1 2
	return (i<(n-k-1))? i+k+1:i-(n-k)+1;
}

// Returns the position of element f in array
// The idea is to create new index system so that array with new indices is sorted without rotation
int findPosition(int a[],int n,int f){
	// First find position of pivot
	int k = findPivot(a,n);

	// Indices for non rotated array
	int newL =0,newR = n-1;
	
	// Binary search in new index system
	while(newL<=newR){
	
		int newMid = (newL + newR)/2;
	
		// Get index in original system to find element
		int oldMid = getOriginalIndex(newMid,k,n);

		// Found element
		if(a[oldMid]==f) return oldMid;	

		// Required element greater than current; search in right half
		else if(a[oldMid]<f) newL = newMid+1;
		
		// Required element less than current; search in left half
		else newR = newMid-1;
	}

	// Not found return -1
	return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		int f;
		cin>>f;
 		cout<<findPosition(a,n,f)<<endl;
	}
}