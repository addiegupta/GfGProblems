/*

GeeksForGeeks: Rotate a linked list

Link to Problem:https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Difficulty: Easy

Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer smaller than or equal to length of the linked list. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40.

Input:

In this problem, complete the method which takes two argument: the head of the linked list and int k. We should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Rotate the link list from index k and return its new head pointer.


Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
1
8
1 2 3 4 5 6 7 8
4

Output:
5 6 7 8 1 2 3 4

*/
{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
}*head;
void rotate(struct node **head_ref, int k);
  void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     rotate(&head,k);
     printList(head);
     }
     return(0);
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Rotate a linked list after node k
  The input list will have at least one element  
  Return pointer to head of rotated linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
void rotate(struct node **head_ref, int k)
{ 
  // Complete this method
  
    struct node* trav = *head_ref;
    int i=0;
    // Stores original head position
    struct node* oldHead = *head_ref;
    while(trav!=NULL){
    	// (k-1)th node found and it is not last node
        if(i==k-1 && trav->next!=NULL){
            // Set this as new head
            *head_ref=trav->next;
            // List ends here
            trav->next=NULL;
            // Resume traversal from new head node
            trav=*head_ref;
        }
        else{

            if(trav->next==NULL&&i!=k-1){
            	// List ends loop around with original head
                trav->next = oldHead;
                break;
            }
            trav=trav->next;
        }
        i++;
    }
}
