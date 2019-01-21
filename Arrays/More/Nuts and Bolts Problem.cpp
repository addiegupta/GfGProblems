/*

GeeksForGeeks: Nuts and Bolts Problem

Link to Problem: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0

Difficulty: Medium

Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.

Input:

The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:
Each case begins with a single positive integer N denoting the number of nuts/bolts.

Then follows the array of nuts, each element separated by a space.

And finally the bolts array, again, each element is separated by a space here.

Array of Nuts/Bolts can only consist of the following elements:

{'@', '#', '$', '%', '^', '&', '~', '*', '!'}

And no element can be repeated.


Output:

For each test case, output the matched array of nuts and bolts in separate lines, where each element in the array is separated by a space. Print the elements in the following order ! # $ % & * @ ^ ~ 


Constraints:

1<= T <= 70
1<= N <= 9


Example:

Input:

2
5
@ % $ # ^
% @ # $ ^
9
^ & % @ # * $ ~ !
~ # @ % & * $ ^ ! 

Output:

# $ % @ ^
# $ % @ ^
! # $ % & * @ ^ ~
â€‹! # $ % & * @ ^ ~


*/



// Highly useless problem with useless test cases
// What the problem lacks is matching of elements as currently if element is present in
// one array then it is definitely present in other array also 
#include<bits/stdc++.h>
using namespace std;
void nutsAndBolts(char* a,char * b,int n,char* order){
	unordered_set<char> set;
	for(int i=0;i<n;i++){
		set.insert(a[i]);
	}
	for(int i=0;i<9;i++){
		if(set.find(order[i])!=set.end())cout<<order[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	char * order = {'!','#','$','%','&','*','@','^','~'}
	while(t--){
		int n;
		cin>>n;
		char* a = (char*)malloc(sizeof(char)*n);
		char* b = (char*)malloc(sizeof(char)*n);
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		nutsAndBolts(a,b,n,order);
	}
	return 0;
}