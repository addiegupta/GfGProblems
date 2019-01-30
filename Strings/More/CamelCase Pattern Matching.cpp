/*

GeeksForGeeks: CamelCase Pattern Matching

Link to Problem: https://practice.geeksforgeeks.org/problems/camelcase-pattern-matching/0

Difficulty: Medium

Given a dictionary of words where each word follows CamelCase notation, print all words in the dictionary that match with a given pattern consisting of uppercase characters only.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include: “PowerPoint” and “WikiPedia”, “GeeksForGeeks”, “CodeBlocks”, etc.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains an integer n denoting the number of words in the dictionary. The next line contains the vector of strings in the dictionary. The last line contains the pattern.

Output:
Print all words in the dictionary that match with a given pattern consisting of uppercase characters only. If the pattern is not found, print "No match found" (without quotes).

Constraints:
1<=T<=100
1<=n<=100
1<=length of string<=100
1<=length of patter<=length of string<=100

Example:
Input:
2
8
Hi Hello HelloWorld HiTech HiGeek HiTechWorld HiTechCity HiTechLab
HA
3
WelcomeGeek WelcomeToGeeksForGeeks GeeksForGeeks
WTG

Output:
No match found
WelcomeToGeeksForGeeks



*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s[n],x;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		cin>>x;
		int matchLength=x.size();
		bool flag = false;
		vector<string> ans;
		for(int i=0;i<n;i++){
			string temp=s[i];
			int k=0;
			for(int j=0;j<temp.length();j++){
				if(isupper(temp.at(j))){
					if(temp.at(j)==x.at(k)){
						k++;
						if(k==matchLength){
							flag = true;
							ans.push_back(temp);
							// cout<<temp<<" ";
							break;
						}
					}
					else k=0;
				}
			}
		}
		// if(!flag)cout<<"No match found";
		if(ans.empty())cout<<"No match found";
		else{
			sort(ans.begin(),ans.end());
			for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}