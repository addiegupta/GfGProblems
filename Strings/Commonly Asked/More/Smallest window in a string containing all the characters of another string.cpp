/*

GeeksForGeeks: Smallest window in a string containing all the characters of another string

Link to Problem: https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0

Difficulty: Easy

Given a string S and text t. Output the smallest window in the string having all characters of the text. Both the string and text contains small case letters.

Input:
First line contains T , the number of test cases and each test contains 2 lines having a string S and t.

Output:
Output the smallest window of the string containing all the characters of the text. If such window doesn`t exist or this task can not be done then print -1.

Constraints: 
1 <= T <= 100
1 <= N, X <= 1000

Example:
Input:
2
timetopractice
toc
zoomlazapzo
oza

Output:
toprac
apzo


*/

#include<bits/stdc++.h>
using namespace std;
int index(string s,int i){return s.at(i)-'a';}
string smallestWindow(string s,string x){
	int len1 = s.length();
	int len2 = x.length();

	// Contains hash for alphabets present in strings
	int hashString[26]={0},hashPattern[26]={0};

	// Create hash for pattern
	for(int i=0;i<len2;i++)hashPattern[index(x,i)]++;

	// Variables to keep track for starting index and minimum length for answer
	int start =0,startIndex = -1,minLen=INT_MAX;
	// Count the matching characters
	int count =0;

	// Traverse the string
	for(int j=0;j<len1;j++){

		// Add to string hash
		hashString[index(s,j)]++;


		// If character matches with pattern character and has not been duplicated
		if(hashPattern[index(s,j)]!=0
			&& hashPattern[index(s,j)]>=hashString[index(s,j)])	count++;

		// Required characters found
		if(count==len2){

			// Slide the string window starting index
			//
			// String has more counts of the required character i.e. which can be
			// found in remaining portion of string || character is not required
			// then slide the window
			while ( hashString[index(s,start)] > hashPattern[index(s,start)] 
                || hashPattern[index(s,start)] == 0){ 

				// Reduce count of string hash for current character
				// as start index is slid to right
                if (hashString[index(s,start)] > hashPattern[index(s,start)]) 
                    hashString[index(s,start)]--; 
                start++; 
            } 
  
            // Update sliding window size 
            int windowLen = j - start + 1; 
            if (minLen > windowLen) 
            { 
                minLen = windowLen; 
                startIndex = start; 
            }
        }
	}
	
	return (startIndex>=0)?s.substr(startIndex,minLen):"-1";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s,x;
		cin>>s>>x;
		cout<<smallestWindow(s,x)<<endl;
	}
	return 0;
}