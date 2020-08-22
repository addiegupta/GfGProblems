/*

GeeksForGeeks: Kth largest element in a stream

Link to Problem: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0

Difficulty: Medium

Given an input stream of n integers the task is to insert integers to stream and print the kth largest element in the stream at each insertion.

Example:

Input:
stream[] = {10, 20, 11, 70, 50, 40, 100, 5, ...}
k = 3

Output:    {-1,   -1, 10, 11, 20, 40, 50,  50, ...}

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers k and n . Then in the next line are n space separated values of the array.

Output:
For each test case in a new line print the space separated values denoting the kth largest element at each insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

Constraints:
1<=T<=100
1<=n,k<=1000
1<=stream[]<=100000

Example:
Input:
2
4 6
1 2 3 4 5 6
1 2
3 4 

Output:
-1 -1 -1 1 2 3
3 4 


*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int t;
 	cin>>t;

 	while(t--){
 		int i,j,k,n;
 		cin>>k>>n;
 		int* a = new int[n];
 		for(i=0;i<n;i++){
 			cin>>a[i];
 		}
 		int* b = new int[n];
 		for(i=0;i<n;i++){
 			b[i]=a[i];
 			if(i<k-1){
 				cout<<"-1 ";
 			}
 			else{
	 			sort(b,b+i+1,greater<int>());
	 			cout<<b[k-1]<<" ";
 			}
 		}
 		cout<<endl;
	}	
	return 0;
}

// Solution with priority queue java on 13 july 2020


import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t--!=0){
		    int k = sc.nextInt();
		    int n = sc.nextInt();
		    PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
		    while(n--!=0){
		        int a = sc.nextInt();
		        heap.offer(a);
		        if(heap.size()>k)heap.poll();
		        int ans = (heap.size()==k)?heap.peek():-1;
		        System.out.print(ans+" ");
		    }
		    System.out.println();
		}
	}
}