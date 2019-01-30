/*

GeeksForGeeks: Design a tiny URL or URL shortener

Link to Problem: https://practice.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener/0

Difficulty: Medium

Design a system that takes big URLs like “http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” and converts them into a short 6 character URL. It is given that URLs are stored in database and every URL has an associated integer id.  So your program should take an integer id and generate a 6 character long URL. 

A URL character can be one of the following
1) A lower case alphabet [‘a’ to ‘z’], total 26 characters
2) An upper case alphabet [‘A’ to ‘Z’], total 26 characters
3) A digit [‘0′ to ‘9’], total 10 characters

There are total 26 + 26 + 10 = 62 possible characters.

So the task is to convert an integer (database id) to a base 62 number where digits of 62 base are "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

Input:

The first line of input contains an integer T denoting the number of test cases.

And the second line consists of a long integer.


Output:

Print the shortened string in the first line and convert the shortened string back to ID (to make sure that your conversion works fine) and print that in the second line.

Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 4,294,967,295


Example:

Input:

1
12345

Output:

dnh
12345



*/

#include<bits/stdc++.h>
#define ll long long int
#define BASE 62
using namespace std;

// This basically converts given integer in a number system of base 62
// digits go from a-z for 0-25
//				  A-Z for 26-51
//				  0-9 for 52-61
void tinyUrl(ll n){
	string ans;
	while(n>0){
		int rem = n%BASE;
		n/=BASE;
		char c;
		if(rem<26)c=rem+'a';
		else if(rem<52)c=rem-26 + 'A';
		else c=rem-52 +'0';
		ans.append(1,c);
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	ll revAns =0;
	for(int i=ans.length()-1;i>=0;i--){
		char c =ans.at(i);
		int add;
		if('a'<=c&&c<='z')add = c-'a';
		else if('A'<=c && c<= 'Z')add = c-'A'+26;
		else add = c-'0'+52;
		revAns += add * pow(BASE,ans.length()-i-1);
	}
	cout<<revAns<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		tinyUrl(n);
	}
	return 0;
}