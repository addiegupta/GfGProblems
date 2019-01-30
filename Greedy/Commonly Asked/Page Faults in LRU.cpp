/*

GeeksForGeeks: Page Faults in LRU

Link to problem: https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0

Difficulty: Medium

In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.
Given a sequence of pages and memory capacity, your task is to find the number of page faults using Least Recently Used (LRU) Algorithm.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains n number of pages and next line contains space seaprated sequence of pages. The following line consist of the capacity of the memory.
Note: Pages are referred in the order left to right from the array (i.e index 0 page is referred first then index 1 and so on). Memory is empty at thestart .

Output:
Output the number of page faults.

Constraints:
1<=T<=100
1<=n<=1000
4<=capacity<=100

Example:
Input:
2
9
5 0 1 3 2 4 1 0 5
4
8
3 1 0 2 5 4 1 2
4
Output:
8
7



*/

#include<bits/stdc++.h>
using namespace std;

// Returns the number of page faults using Least Recently Used algorithm
int lru(int a[],int n,int m){
	// Stores indices of pages
	unordered_map<int,int> map;
	// Stores recently used pages in memory
	unordered_set<int> temp;
	// Number of page faults
	int count=0;

	for(int i=0;i<n;i++){
		// Current page number
		int x = a[i];
		// Not in memory, page fault occurred
		if(temp.find(x)==temp.end()){

			// Space to insert new page
			if(temp.size()<m){
				temp.insert(x);
				count++;
			}
			// Remove least recently used and insert new page in memory
			else {
				// Find LRU page
				int lru = INT_MAX, val;
				for(auto it=temp.begin();it!=temp.end();it++){
					if(map[*it]<lru){
						lru = map[*it];
						val = *it;
					}
				}

				// Erase LRU page
				temp.erase(val);

				// Insert new page
				temp.insert(x);
				count++;
			}
		}
		// Store index of current page
		map[x]=i;

	}
	return count;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cin>>m;
		cout<<lru(a,n,m)<<endl;
	}
}