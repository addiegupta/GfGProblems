/*

GeeksForGeeks: Get minimum element from stack

Link to Problem:https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

Difficulty: Easy

Implement a Stack in which you can get min element in O(1) time and O(1) space.

Input (To be used for Expected Output):
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 3 Types
(i)   1 x (a query of this type means  pushing 'x' into the stack)
(ii)  2 (a query of this type means to pop element from stack and print the poped element)
(iii) 3 (a query of this type means to print the minimum element from the stack)

The second line of each test case contains Q queries seperated by space.

Output:

The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out  or min element from the stack .
You are required to complete the three methods push which take one argument an integer 'x' to be pushed into the stack , pop which returns a integer poped out from the stack and getMin which returns the min element from the stack.

Constraints:
1<=T<=100
1<=Q<=100
1<=x<=100

Example:
Input
1
6
1 2 1 3 2 3 1 1 3    

Output
3 2 1

Explanation:
In the first test case for query 
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
3       min element will be 2 
1 1    the stack will be {2 1}
3       min element will be 1


References: https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

*/

{
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty()) return -1;
   else return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
    //Your code here
    if(s.empty())return -1;
    int temp = s.top();
    s.pop();
 	// This value is less than minEle. Which means it contains the previous value too.
 	// Extract that value
    if(temp<minEle){
        int ret = minEle;
        minEle = 2*minEle - temp;
        return ret;
    }
    return temp;
    
   
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
    if(s.empty()){
        minEle = x;
        s.push(x);
        return;
    } 
    // Store 2*x - minEle ( which will always be less than x ) so that previous minEle can be stored too
    if (x<minEle){
       s.push(2*x-minEle);
       minEle = x;
   }
   else s.push(x);
}
