/*

GeeksForGeeks: Word Boggle

Link to problem: https://practice.geeksforgeeks.org/problems/word-boggle/0

Difficulty: Medium

Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer x denoting the no of words in the dictionary. Then in the next line are x space separated strings denoting the contents of the dictinory. In the next line are two integers N and M denoting the size of the boggle. The last line of each test case contains NxM space separated values of the boggle.

Output:
For each test case in a new line print the space separated sorted distinct words of the dictionary which could be formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ



*/
#include<bits/stdc++.h>
#include<string.h>
#define MAX 7
using namespace std;
vector<string> ans;
char boggle[MAX][MAX];
int n,m;
int x[]={1,-1,1,-1,0,0,1,-1};
int y[]={1,-1,0,0,1,-1,-1,1};

void findBoggle(int i,int j,string path,vector<string> subDict){

	// Out of bounds/ No matching possible words left in sub dictionary
	// Backtrack
	if(i<0||j<0||i>=n||j>=m||!subDict.size())return;

	// Not an alphabet i.e. current character has been visited before
	if(!isalpha(boggle[i][j]))return;

	// Add current letter to the boggle word being formed
	path += boggle[i][j];

	// Iterate over subdictionary for the current path
	vector<string>::iterator it;
	for(it=subDict.begin();it!=subDict.end();it++){
		// Not a possible matching word
		if((*it).substr(0,path.length())!=path){
			
			// Remove from subdictionary
			it = subDict.erase(it);
			it--;
		}
		// Complete dictionary word found
		else if(path.length()==(*it).length()){
			// Check if already exists in answer
			int flag=0;
			for(auto iter = ans.begin();iter!=ans.end();iter++){
				if((*iter)==path){
					flag =1;
					break;
				}
			}
			// If does not exist already, add to answer
			if(!flag)ans.push_back(path);
		}
	}
	// Change character to a non alphabet ascii so that it can be seen as visited before
	boggle[i][j]-=26;
	// Go in all directions to search matching words
	for(int l=0;l<8;l++)findBoggle(i+x[l],j+y[l],path,subDict);
	// Mark unvisited by restoring character
	boggle[i][j]+=26;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		// Clear global variable for answer
		ans.clear();

		// Input dictionary
 		int s;
		cin>>s;
		vector<string> dictionary;
		for(int i=0;i<s;i++){
		    string word;
			cin>>word;
			dictionary.push_back(word);
		}
		//Input boggle matrix
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>boggle[i][j];
			}
		}

		// Find words from dictionary in boggle
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				findBoggle(i,j,"",dictionary);
			}
		}
		// Empty ; print -1
		if(ans.empty())cout<<"-1"<<endl;
		else{
			// Sort in ascending order and print
		    sort(ans.begin(),ans.end());
			vector<string>::iterator it;
			for(it=ans.begin();it!=ans.end();it++)cout<<*it<<" ";
		    cout<<endl;
		    
		}
	}
	return 0;
}