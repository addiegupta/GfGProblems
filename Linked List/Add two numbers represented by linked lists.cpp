/*

GeeksForGeeks: Add two numbers represented by linked lists

Link to Problem:https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Difficulty: Easy

Given two numbers represented by two lists, write a function that returns sum list. The sum list is list representation of addition of two input numbers.

Suppose you have two linked list 5->4 ( 4 5 )and 5->4->3( 3 4 5) you have to return  a resultant linked list 0->9->3 (3 9 0).

Input:

In this problem, method takes two argument: the head of the first and second linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Add  two numbers represented by linked lists.

Note: If you use "Test" or "Expected Output Button" use below example format
Constraints:

1<=T<=100

1<=N<=100
Example:

Input:

2

2

4 5

3

3 4 5

2

6 3

1

7

Output:

0 9 3 

0 7

Explaination:

5->4 //linked link repsentation of 4 5

5->4->3// linked list representation of 3 4 5

0->9 ->3 // linked list representation of 3 9 0 resultant linked list.

*/
{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 struct Node* addTwoLists (struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {   
        temp=Node;
        Node = Node->next;
        free(temp);
    } 
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
		 res = addTwoLists(first, second);
	    printList(res);
if(first)
freeList(first);
if(second)
freeList(second);
//if(res)
//freeList(res);
   }
   return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second){
  // Code here
    Node* trav1 = first;
    Node* trav2 = second;
    int carry=0;
    Node* newList = NULL;
    Node* newHead = NULL;    
    while(trav1 || trav2){
        int t1,t2;
        // List might have finished, just use 0 in that case
        t1=(trav1)?(trav1->data):0;
        t2=(trav2)?(trav2->data):0;

        int temp = t1+ t2 + carry;
        carry = temp/10;
        temp %= 10;
        
        Node* val = new Node;
        val->data = temp;
        val->next = NULL;
        if (!newList){
            newList = val;
            newHead = newList;
        }
        else{
            newList->next = val;
            newList = newList->next;
        }
        if(trav1) trav1 = trav1->next;
        if(trav2) trav2 = trav2->next;
    }
    while(carry!=0){
        Node* val = new Node;
        val->data = carry%10;
        val->next = NULL;
        newList->next = val;
        newList = newList->next;
        carry/=10;
    }
    return newHead;
}