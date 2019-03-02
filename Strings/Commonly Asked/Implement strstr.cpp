/*

GeeksForGeeks: Implement strstr

Link to Problem: https://practice.geeksforgeeks.org/problems/implement-strstr/1

Difficulty: Basic

Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s.

Input Format:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case contains two strings s and x.

Output Format:
For each test case, in a new line, output will be an integer denoting the first occurrence of the x in the string s. Return -1 if no match found.

Your Task:
Since this is a function problem, you don't have to take any input. Just complete the strstr function.

Constraints:
1 <= T <= 100
1<= |s|,|x| <= 1000

Example:
Input
2
GeeksForGeeks Fr
GeeksForGeeks For
Output
-1
5



*/

#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a;
        cin>>b;
        cout<<strstr(a,b)<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */



int ZPatternSearch(string s,string x);
int naivePatternSearch(string s, string x);
int KMPPatternSearch(string s,string x);

int strstr(string s,string x){
	// return naivePatternSearch(s,x);
	// return ZPatternSearch(s,x);
	return KMPPatternSearch(s,x);
}

// Naive approach
int naivePatternSearch(string s, string x)
{
	int j=0,f=0;
	bool found = false;
	for(int i=0;i<s.length();i++){
		if(s[i]==x[j]){
			if(!found){
				f=i;
				found = true;
			}
			j++;
			if(j==x.length())return f;
		}
		else{
			if(found){
				found=false;
				i-=j;
				j=0;
			}
		}
	}
	return -1;
}

// Creates the Z Array used to find pattern
void createZArray(int z[],string s,string x){
	// Substring starting from index 0 is equal to the prefix hence it is not relevant
	z[0]=0;
	// Pattern + a character that does not appear in neither the pattern nor the text + the given text
	string a = x + '$' + s;
	int n=s.length(),m=x.length(),len=a.length();
	// Indices to keep track of a 'box' in string 'a'
	// This box extends from l to r and contains matching pattern with prefix
	int l=0,r=0;
	// Iterate over Z array
	for(int k=1;k<len;k++){
		// Iterator of string a greater than position of r
		if(k>r){
			// Set box equal to the current index only
			l=r=k;
			// Match following characters with pattern and increment r to increase the size of box
			while(r<len && a[r]==a[r-l]){
				r++;	
			}
			// Set length of box as z value
			z[k]=r-l;
			// Decrement box size
			r--;
		}
		// Index is less than position of r
		else{
			//TODO Explain this part
			int k1 = k-l;
			if(z[k1]<r-k+1){
				z[k]=z[k1];
			}
			else{
				l = k;
				while(r<len && a[r]==a[r-l]){
					r++;
				}
				z[k]=r-l;
				r--;
			}
		}
	}
}

// Uses Z array to search for pattern; z[i] contains length of longest substring starting from
// index i which is equal to the prefix of the string
int ZPatternSearch(string s,string x){
	int n = s.length(),m=x.length();
	int z[m+n+1];
	memset(z,0,sizeof(z));
	// Creates Z array
	createZArray(z,s,x);
	for(int i=m;i<=m+n;i++){
		// Length equal to length of pattern
		if(z[i]==m)return i-m-1;
	}
	return -1;
}
// Pre processes the pattern string for longest proper prefix lengths that are also suffix
void computeKmpLps(int lps[], string x){
	int i=1,m=x.length(),len=0;

	lps[0]=0;
	// Traverse through pattern
	while(i<m){
		// Matching letters
		if(x[i]==x[len]){
			
			// Increment prefix iterator and store lps value 
			len++;
			lps[i]=len;

			// Increment pattern iterator
			i++;
		}
		else{
			// Go back one index
			if(len!=0){
				len = lps[len-1];
			}
			// No matching prefix
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

// Knuth Morris Pratt Pattern Searching Algorithm
int KMPPatternSearch(string s,string x){
	int m = x.length(),n=s.length();
	if(n==0 || m ==0 )return -1;
	// Obtain lps array
	int lps[m];
	computeKmpLps(lps,x);

	// Iterators for text and pattern
	int i=0,j=0;

	// Iterate over text
	while(i<n){
		// Matching characters
		if(s[i]==x[j]){
			j++;
			i++;
		}
		// Found entire pattern, return index from where pattern begins
		if(j==m){ 
			return i-m;
		}
		// Mismatching character
		else if(i<n && x[j]!=s[i]){
			
			// Few characters had matched, check lps array and continue iteration
			if(j!=0) j=lps[j-1];

			// No matching characters, increment text iterator
			else i++;
		}
	}	
	return -1;
}