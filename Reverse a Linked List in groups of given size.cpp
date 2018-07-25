/*

GeeksForGeeks: Reverse a Linked List in groups of given size

Link to Problem:https://practice.geeksforgeeks.org/problems//reverse-a-linked-list-in-groups-of-given-size/1

Difficulty: Medium
Given a linked list, write a function to reverse every k nodes (where k is an input to the function).If a linked list is given as 1->2->3->4->5->6->7->8->NULL and k = 3 then output will be 3->2->1->6->5->4->8->7->NULL.

Input:
In this problem, method takes two argument: the head of the linked list and int k. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Reverse the linked list in the group of given size and return the reference of starting node(head) of the reversed Linked list .

Note: If you use "Test" or "Expected Output Button" use below example format
Example:
Input:
1
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5

*/
{
#include<stdio.h>
#include<stdlib.h>
/* Link list node */
struct node
{
    int data;
    struct node* next;
}*head;
struct node *reverse (struct node *head, int k);
/* Reverses the linked list in groups of size k and returns the
   pointer to the new head node. */
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value,i;
    scanf("%d",&n);
    struct node *temp;
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
/* Function to print linked list */
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
    int t,k,value,n;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Reverse a linked list
  The input list will have at least one element  
  Return pointer to head of reverse linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/

struct node *insertNode(struct node *head,int data);
struct node *reverse (struct node *head, int k)
{ 
  // Complete this method
	//Traversal node
    struct node* trav = head;
	//A temporary new list node
    struct node* newList = NULL;
	//Tail node of the temporary list
    struct node* tempTail = NULL;
	//Tail node of the previous temporary tail
    struct node* oldTail = NULL;
	//Final head node
    struct node* finalHead = NULL;
    int c=0;
    // Flag to check if a temporary list has been created before
    int f=0;
    // No need for reversal
    if(k==1) return head;

    while(trav!=NULL){
        
        // Insert new node in a new list
        // Create new list if it does not exist
        newList = insertNode(newList,trav->data);
        // Final node in original list
        if(trav->next == NULL && c!=k-1){
            oldTail->next = newList;
        }
        // Temporary tail to be combined with head of new tail to obtain reversal
        else if(c==0){
            tempTail = newList;
        }
        // Temp list created before. Combine head with tail of previous list. Store it as old list
        else if(c==k-1 && f){
            oldTail->next=newList;
            oldTail = tempTail;
            newList = NULL;
            c=-1;
        }
        // Temp list not created before. Store as old list.
        else if(c==k-1 && !f){
            finalHead = newList;
            oldTail = tempTail;
            newList = NULL;
            f=1;
            c=-1;
        }
        trav=trav->next;
        c++;
    }
    return finalHead;
}

// Defined function to insert node in list given as head
struct node *insertNode(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    if(head != NULL){
        temp->next = head;
    }
    head = temp;
    return head;
}