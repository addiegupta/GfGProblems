#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string w=s;
		reverse(w.begin(),w.end());
		int n=s.size();
		int a[n+1][n+1];
		int count =0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				a[i][j]=0; 
			}
		}
		// this loops for checking longest palindrome sequence in string ...

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i-1]==w[j-1])a[i][j]=1+a[i-1][j-1];
				else a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		cout<<n-a[n][n]<<endl; 
	}
	return 0;
	}