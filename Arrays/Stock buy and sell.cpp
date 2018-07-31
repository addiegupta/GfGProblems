/*

GeeksForGeeks: Stock buy and sell

Link to Problem: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0

Difficulty: Easy

The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. 

Input:
First line contains number of test cases T. Each test case contain the integer value 'N' denoting days followed by an array of stock prices in N days.
Output:
The maximum profit is displayed as shown below. And if there is no profit then print "No Profit".


Constraints:
1 <=T<= 100
2 <=N<= 100
1 <=arr[i]<= 10000


Example

Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:

(0 3) (4 6) 
(1 4) (5 9) 
Notice: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
 	int t;
 	cin>>t;

 	while(t--){
 		int n,i,j,m=0;
 		cin>>n;
 		int* a = new int[n];
 		int* b = new int[n];
 		for(i=0;i<n;i++){
 			cin>>a[i];
 		}
 		// c keeps the count in the reference array that stores the buy/sell indices
 		// f is flag to keep track of whether stock is bought or sold
 		// f=1 : stock sold, next step is purchase
 		// f=0 : stock bought,next step is sell
 		int c=0,f=1;
  		for(i=1;i<n-1;i++){
  			// Local minima, purchase stock
 			if (a[i]<a[i-1]&&a[i]<a[i+1]){
 				if(f){
	 				f=0;
	 				b[c]=i;
	 				c++;
 				}
 			}
 			// Local maxima,sell stock
 			else if(a[i]>a[i-1]&&a[i]>a[i+1]){
 				if(!f){

	 				f=1;
	 				b[c]=i;
	 				c++;
	 				m=i;
 				}
 				// Stock not purchased previously, buy at lowest rate
 				else{
					int min =10000,imin;
 					j=i-1;
 					while(j>=m){
 						if(a[j]<min){
 							min=a[j];
 							imin = j;
 						}
 						--j;
 					}
					b[c++]=imin;
					b[c++]=i;
					f=1;
					m=i;
 				}
 			}
 		}
 		// Last stock not sold, sell at best price
 		if(!f&&c%2!=0){
 			j=b[c-1];
 			int max =0,imax;
 			while(j<n){
 				if(a[j]>max){
 					max = a[j];
 					imax = j;
 				}
 				++j;
 			}
 			b[c++] = imax;
 			f=1;

 		}
 		for(i=0;i<c;i++){
 			if(i%2==0){
 				cout<<"("<<b[i]<<" ";
 			}
 			else{
 				cout<<b[i]<<") ";
 			}
 		}
 		if(c==0){
 			cout<<"No Profit";
 		}
 		cout<<endl;
	}	
	return 0;
}