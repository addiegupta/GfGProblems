/*

GeeksForGeeks: Circular tour

Link to Problem:https://practice.geeksforgeeks.org/problems/circular-tour/1

Difficulty: Medium

Suppose there is a circle. There are n petrol pumps on that circle. You will be given two sets of data.

1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Your task is to complete the function tour which returns an integer denoting the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity).

Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Input
The first line of input will be the no of test cases . Then T test cases follow . Each Test case contains 2 lines . The first line will contain an integer N denoting the no of petrol pumps and in the next line are N space separated values petrol and distance denoting the amount of petrol every petrol pump has and the distance to next petrol pump respectively .

Output
The output of each test case will be the index of the the first point from where a truck will be able to complete the circle otherwise -1 .

Constraints:
1<=T<=100
1<=N<=50
1<=petrol,distance<=100

Example (To be used only for expected output)
Input
1
4
4 6 6 5 7 3 4 5
Output
1

Explanation:
Above there are 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where truck can make a circular tour is 2nd petrol pump. Output in this case is 1 (index of 2nd petrol pump).

References:
https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

*/

{
#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
    //Your code here
    // Iterators and variables to store petrol and distance values
    int i,j,totalP=0,d;
    // Test by starting at each petrol pump
    for(i=0;i<n;i++){
        
        // Initial petrol
       totalP = p[i].petrol;
       // Distance till next pump
       d=p[i].distance;
       // Total pumps to be covered
       int m=n-1;
       // Flag to check if case is being satisfied
       int f=1;
       j=i;
       while(m--){
            j++;
            // Circular loop in array
            if(j==n) j=0;
            // Unable to cover distance
            if(d>totalP){
               f=0;
               break;
            }
            // Reduce petrol for the distance covered
            // Add petrol from current petrol pump
            totalP -= d;
            totalP += p[j].petrol;
            // New distance to be covered
            d = p[j].distance;
       }
       if(f){
       		// Final petrol pump also covered
            if(totalP>=d){
                return i;
            }
       }
   }
   return -1;
}


// Better solution copied from GFG O(n) time O(1) space

// The function returns starting point if there is a possible solution, 
    // otherwise returns -1 
    static int printTour(petrolPump arr[], int n) 
    {   
        int start = 0; 
        int end = 1; 
        int curr_petrol = arr[start].petrol - arr[start].distance; 
          
        // If current amount of petrol in truck becomes less than 0, then 
        // remove the starting petrol pump from tour 
        while(end != start || curr_petrol < 0) 
        { 
              
            // If current amount of petrol in truck becomes less than 0, then 
            // remove the starting petrol pump from tour 
            while(curr_petrol < 0 && start != end) 
            { 
                // Remove starting petrol pump. Change start 
                curr_petrol -= arr[start].petrol - arr[start].distance; 
                start = (start + 1) % n; 
                  
                // If 0 is being considered as start again, then there is no 
                // possible solution 
                if(start == 0) 
                    return -1; 
            } 
            // Add a petrol pump to current tour 
            curr_petrol += arr[end].petrol - arr[end].distance; 
              
            end = (end + 1)%n; 
        } 
          
        // Return starting point 
        return start; 
    } 
