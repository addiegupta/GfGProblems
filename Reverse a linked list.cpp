/*

GeeksForGeeks: Reverse a linked list

Link to Problem:https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Difficulty: Easy

Given pointer to the head node of a linked list, the task is to reverse the linked list.

Input:
You need to complete a method reverse() that takes head as argument and returns new head.
There are multiple test cases. For each test case, this method will be called individually.  The first line of input contains number of test cases.  Every test case has two lines, number of nodes first line and data values in next line.

Output:
Reverse the linked list and return head of the modified list.


Example:
Input:
1
6
1 2 3 4 5 6

Output:
6 5 4 3 2 1
*/
{
//Initial Template for C++
//to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stack>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
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
/* Function to get the middle of the linked list*/
struct Node *reverse(struct Node *head);
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}
/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
       head = reverse(head);
       printList(head);
       cout << endl;
    }
    return 0;
}
}
Node* addNode(Node *head,int data);

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/
// Should reverse list and return new head.
Node* reverse(Node *head)
{
  // Your code here
  Node* newList = NULL;
  Node* trav = head;
  while(trav!=NULL){
      newList = addNode(newList,trav->data);
      trav = trav->next;
  }
  return newList;
    
}

Node* addNode(Node *head,int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (head != NULL){
        temp->next = head;
    }
    head = temp;
    return head;
}