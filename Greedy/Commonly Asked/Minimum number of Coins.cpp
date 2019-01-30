/*

GeeksForGeeks: Minimum number of Coins

Link to problem: https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

Difficulty: Easy

Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, Find the minimum number of coins and/or notes needed to make the change for Rs N.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of an Integer value N denoting the amount to get change for.

Output:
Print all the denominations needed to make the change in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106

Example:
Input:
1
43

Output:
20 20 2 1

Explanation:
Testcase 1: Sum of Rs 43 can be changed with minimum of 4 coins/ notes 20, 20, 2, 1.


*/

#include<bits/stdc++.h>
using namespace std;

void change(int n){

	int currency[] ={2000,500,200,100,50,20,10,5,2,1};
	int i=0;
	while(i<(sizeof currency/sizeof *currency)){
		if(currency[i]<=n){
			cout<<currency[i]<<" ";
			n-=currency[i];
		}
		else{
			i++;
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
		change(n);
	}
}