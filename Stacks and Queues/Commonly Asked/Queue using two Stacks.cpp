/*

GeeksForGeeks: Queue using two Stacks

Link to Problem:https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

Difficulty: Easy

Implement a Queue using 2 stacks s1 and s2 .

Input (To be used for Expected Output):

The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)

The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the queue is empty else the element poped out from the queue . 
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the quee  and pop which returns a integer poped out from othe queue.

Constraints:
1<=T<=100
1<=Q<=100
1<=x<=100

Example:
Input
1
5
1 2 1 3 2 1 4 2   

Output
2 3

Explanation:

In the first test case for query 
1 2    the quee will be {2}
1 3    the queue will be {2 3}
2       poped element will be 2 the queue will be {3}
1 4    the queue will be {3 4}
2       poped element will be 3 

References: https://www.geeksforgeeks.org/queue-using-stacks/
*/

{
#include<bits/stdc++.h>
using namespace std;
class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        // Your Code
 		// Push everything from stack 1 to stack 2
        while(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        // Push given value to stack 1 so that it is placed at the bottom 
        s1.push(x);
        // Push everything back to stack 1 from stack 2
        while(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
 }
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code
		// Underflow
        if(s1.empty()) return -1;
        
        // Simply pop from stack 1
        int temp = s1.top();
        s1.pop();
        return temp;
}
