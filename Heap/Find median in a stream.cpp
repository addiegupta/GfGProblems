/*

GeeksForGeeks: Find median in a stream

Link to Problem: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

Difficulty: Hard

Given an input stream of n integers the task is to insert integers to stream and print the median of the new stream formed by each insertion of x to the stream.

Example

Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

Input:
The first line of input contains an integer N denoting the no of elements of the stream. Then the next N lines contains integer x denoting the no to be inserted to the stream.

Output:
For each element added to the stream print the floor of the new median in a new line.

Constraints:
1<=N<=105 + 7
1<=x<=105 + 7

Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4

*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    vector<ll> v;
    ll n;
    cin>>n;

    // Get first number of stream an insert in vector
    ll k;
    cin>>k;
    v.push_back(k);

    // Median is first element
    cout<<k<<endl;

    for (int i = 1; i < n; i++)
    {
        cin>>k;
        int f=0;
        for(int j=0;j<i;j++){
    		// Insert at correct place
            if(k<v[j]){
                v.insert(v.begin()+j,k);
                f=1;
                break;
            }
        }
        // Insert at end
        if(!f) v.push_back(k);

        int s = v.size();

        if(s%2!=0) cout<<v[s/2]<<endl;
        else cout<<floor((v[s/2-1]+v[s/2])/2)<<endl;  
    }
}