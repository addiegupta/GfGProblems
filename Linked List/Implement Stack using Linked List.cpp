/*

GeeksForGeeks: Implement Stack using Linked List

Link to Problem:https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

Difficulty: Basic
Implement a Stack using Linked List .

Input (To be used for Expected Output):

The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)

The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out from the stack . 
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the stack  and pop which returns a integer poped out from the stack.

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
3 4

Explanation:

In the first test case for query 
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
1 4    the stack will be {2 4}
2       poped element will be 4

*/
{
#include<bits/stdc++.h>
using namespace std;
struct StackNode
{
    int data;
    StackNode *next;
};
class Stack {
private:
StackNode *top;
public :
    
    void push(int);
    int pop();
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Stack *sq = new Stack();
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

/* 
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
};
and the structure of the class is
class Stack {
private:
  StackNode *top;
public :
    void push(int);
    int pop();
};
 */
/* The method push to push element into the stack */
void Stack :: push(int x)
{
        // Your Code
		StackNode* temp = new StackNode;
		temp->data = x;
		temp->next = NULL;
		if(top==NULL){
			top=temp;
		}
		else{
			temp->next = top;
			top = temp;
		}
}
/*The method pop which return the element poped out of the stack*/
int Stack :: pop()
{
        // Your Code  
        if(top==NULL)return -1;
        StackNode* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;     
}
