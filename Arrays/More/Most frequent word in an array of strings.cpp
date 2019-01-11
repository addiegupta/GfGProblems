/*

GeeksForGeeks: Most frequent word in an array of strings

Link to Problem: https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings/0

Given an array containing N words consisting of lowercase characters. Your task is to find the most frequent word in the array. If multiple words have same frequency, then print the word that comes first in lexicographical order.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each test case contains 2 lines, the size of array N and N words separated by spaces.

Output:
For each testcase, output the most frequent word.

Constraints:
1 <= T <= 100
1 <= N <= 1000

Example:
Input:
3
3
geeks for geeks
2
hello world
3
world wide fund

Output:
geeks
hello
fund

Explanation:
Testcase 1: "geeks" comes 2 times.
Testcase 2: "hello" and "world" both have 1 frequency. We print hello as it comes first in lexicographical order.

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,max=0,count;
 		string str,ans;
 		cin>>n;	
 		
 		unordered_map<string,int> map;
 		unordered_map<string,int>::iterator it;

 		while(n--){
 			cin>>str;
 			it = map.find(str);

 			// String exists in map, increment count
 			if(it!=map.end()){
 				count = ++(it->second);
 			}
 			// Insert in map
 			else{
 				count = 1;
 				map.insert(pair<string,int>(str,1));
 			}
 			// Found better answer
 			if(count>max || count == max && ans.compare(str)>0){
 				ans = str;
 				max =count;
 			}
 		}
 		cout<<ans<<endl;

 	}
	return 0;
}