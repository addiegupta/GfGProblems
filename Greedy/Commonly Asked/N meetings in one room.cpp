/*

GeeksForGeeks: N meetings in one room

Link to problem: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

Difficulty: Easy

There is one meeting room in Flipkart. There are n meetings in the form of (S [ i ], F [ i ]) where S [ i ] is start time of meeting i and F [ i ] is finish time of meeting i

What is the maximum number of meetings that can be accommodated in the meeting room ?

 

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].


Output:

In each separate line print the order in which the meetings take place separated by a space.


Constraints:

1 ≤ T ≤ 70

1 ≤ N ≤ 100

1 ≤ S[ i ], F[ i ] ≤ 100000


Example:

Input:

2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:

1 2 4 5
6 7 1



*/

#include<bits/stdc++.h>
using namespace std;
// Custom structure to store start time , finish time and original order of the meeting in
// the input array
struct meeting{
	int start,finish,order;
};

// Used in sorting the array of meetings so that it is sorted in order of finish time
bool meetingCompare(meeting m1, meeting m2){return m1.finish<m2.finish;}

//  Print the order of the meetings that are executed
void maxMeeting(int n,meeting m[]){
 
 	// Sort the array as per finish times
	sort(m,m+n,meetingCompare);

	// First meeting is always selected as it will not coincide with any previous meeting
	int prev = m[0].finish;
	cout<<m[0].order<<" ";

	// From the remaining meetings, select a meeting only if its start time
	// comes after the finish time of the last selected meeting
	for(int j=1;j<n;j++){
		if(m[j].start>=prev){
			prev = m[j].finish;
			cout<<m[j].order<<" ";
		}
	}
	cout<<endl;
}		
			
int main(){				
	int t;						
	cin>>t;						
	while(t--){					
		int n;				
		cin>>n;				
		meeting m[n];

		// Start times of meetings
		for(int i=0;i<n;i++){	
			cin>>m[i].start;
			m[i].order = i+1;
		}			
		// Finish times of meetings
		for(int i=0;i<n;i++){	
			cin>>m[i].finish;
		}		
		//  Print the order of the meetings that are executed
		maxMeeting(n,m);				
	}									
	return 0;						
}					