/*

GeeksForGeeks: Delete N nodes after M nodes of a linked list

Link to Problem: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

Difficulty: Easy

Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Input:

Complete the method which takes three argument: the head of the linked list,M an N. Function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.
 

Output:

Function should not print any output to stdin/console
 

Example:

M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
After 2 nodes 2 nodes will be deleted.Deleted Nodes 3->4 and 7->8
Output: Linked List: 1->2->5->6

For Testing use this format:
1 (Test case)
8 (Number of elements in linked list)
2 1(M and N)
9 1 3 5 9 4 10 1 (8 Number)
output : 9 1 5 9 10 1 

 

*/

#include<stdio.h>
#include<stdlib.h>
//using namespace std;
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void linkdelete(struct node  *head, int M, int N);
/* Function to print nodes in a given linked list */
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
void insert(int n1)
{
    int n,value,i;
    //scanf("%d",&n);
    n=n1;
    struct node *temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            start=(struct node *) malloc( sizeof(struct node) );
            start->data=value;
            start->next=NULL;
            temp=start;
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
int main()
{
    
     int m,n;
    
    int t,n1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n1);
        scanf("%d",&m);
        scanf("%d",&n);
        insert(n1);
        
       
        
        
  
        linkdelete(start,m,n);
        
        
        printList(start);
    }
    
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
void linkdelete(struct node  *head, int M, int N)
{	
	// Skip M-1 nodes at start, delete N nodes
	int i=M-1,j=N;

	// Traverse list
	while(head){

		// Count M nodes (M-1 for first iteration)
		while(i--&&head) head = head->next;

		// Delete N nodes
		j=N;
		while(j--&&head&&head->next){
			node* temp=head->next;
			head->next= head->next->next;
			delete temp;
		}
	
		i=M;
	}
}
