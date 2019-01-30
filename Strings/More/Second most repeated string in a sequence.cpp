/*

GeeksForGeeks: Second most repeated string in a sequence

Link to Problem: https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence/0

Difficulty: Easy

Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting number of strings in a sequence and the second line contains N space separated strings.

Output:
For each test case, in a new line print the second most repeated string.

Constraints:
1<=T<=100
3<=N<=103
1<=|String length|<=100

Example:
Input:
2
6
aaa bbb ccc bbb aaa  aaa
6
geeks for geeks for geeks aaa

Output:
bbb
for


*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Finds second most frequent string in vector of strings
string secondFrequent(vector<string> in){

	// Hash map to store strings as keys and their count as values
	unordered_map<string,int> map;
	for(int i=0;i<in.size();i++){
		// Store count in hash map
		map[in[i]]++;
	}

	// String with max occurence and second max occurence
	string max,max2;

	// Counts of max occurence and second max occurence
	int maxCount=0,maxCount2=0;
	
	// Traverse over map
	for(auto i=map.begin();i!=map.end();i++){
		// New max
		if(i->second>maxCount){
			
			// Update second max with previous max value
			maxCount2=maxCount;
			max2=max;

			// new max value
			max=i->first;
			maxCount=i->second;
		}
		// New second max
		else if(i->second>maxCount2 && i->second!=maxCount){
			maxCount2=i->second;
			max2=i->first;
		}
	}
	return max2;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<string> in;
		int n;
		cin>>n;
		string temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			in.push_back(temp);
		}
		cout<<secondFrequent(in)<<endl;
	}
	return 0;
}