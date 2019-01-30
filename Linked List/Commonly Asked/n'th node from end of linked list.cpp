/*

GeeksForGeeks: n'th node from end of linked list

Link to Problem:https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

Difficulty: Easy

Given a linked list, the task is to find the n'th node from the end.  It is needed to complete a method that takes two argument, head of linked list and an integer n. There are multiple test cases. For each test case, this method will be called individually.


Input:
The first line of input contains number of test cases.  Every test case cntains two lines.  First line of every test case contains two space separated values, number of nodes  in linked list followed by value of n.  Second line of every test case contains data items of linked list.


Output:
Corresponding to each test case, output a single integer that is the nth integer in the linked list from the end. Print -1 if the value of n is greater than the number of elements in the linked list.

Constraints:
1 <= T <= 200
1 <= No of Nodes <= 1000
0 <= Data in Nodes <= 1000


Example:
Input:
2
9 2
1 2 3 4 5 6 7 8 9
4 5
10 5 100 5 1
 

Output:
8
-1

In the first example, there are 9 nodes in linked list and we need to find 2nd node from end.  2nd node from end os 8.   In the second example, there are 4 nodes in linked list and we need to find 5th from end.  Since 'n' is more than number of nodes in linked list, output is -1.


*/
{
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    printf("%d
", getNthFromLast(head, k));
    }
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* struct Node
 {
   int data;
   Node* next;
 }; */
/* Should return data of n'th node from the end of linked list */
int getNthFromLast(Node *head, int n)
{
   	// Your code here
   	Node *trav = head;
   	int len = 0;
	// Empty list
    if(head==NULL)return -1;
    // Count elements in list
    while(1){
        if(trav->next == NULL){
           len++;
           break;
        }
        trav = trav->next;
        len++;
   	}
   	// Required node does not exist
   	if(n>len) return -1;

   	trav = head;
   	int nth = len-n;
   	// Traverse till the required node
   	while(nth--)trav=trav->next;
   	return trav->data;
}