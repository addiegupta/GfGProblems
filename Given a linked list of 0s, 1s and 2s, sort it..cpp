/*

GeeksForGeeks: Given a linked list of 0s, 1s and 2s, sort it.

Link to Problem:https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Difficulty: Easy

Given a linked list of 0s, 1s and 2s, sort it.

Input:

Complete the method which takes one argument: the head of the linked list. The program should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output: The function should not print any output to stdin/console.
 

Example:

Input:
1 2 2 1 2 0 2 2

Output:
0 1 1 2 2 2 2 2 

For Testing(format):

1(Test cases)
8(Number of elements in Link List)
1 2 2 1 2 0 2 2 


*/
{
#include<stdio.h>
#include<stdlib.h>
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *start = NULL;
void sortList(struct Node *head);
// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
}
/* Drier program to test above function*/
void insert(int n1)
{
    int n,value,i;
    //scanf("%d",&n);
    n=n1;
    struct Node *temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        
        if(i==0)
        {
            start=(struct Node *) malloc( sizeof(struct Node) );
            start->data=value;
            start->next=NULL;
            temp=start;
            continue;
        }
        else
        {
            temp->next= (struct Node *) malloc( sizeof(struct Node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
int main()
{
    
    int n;
    
    int t;
    scanf("%d",&t);
    
    while (t--) {
        scanf("%d",&n);
        
        insert(n);
        sortList(start);
        printList(start);
    }
    
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/
void sortList(Node *head)
{
   //Add code here
   Node* newList = new Node;
   int c0=0,c1=0,c2=0;
   Node* trav = head;
   // Count 0s,1s and 2s
   while(trav){
       switch(trav->data){
            case 0: c0++;
                    break;
            case 1: c1++;
                    break;
            case 2: c2++;
                    break;
            default: break;
            
       }
       trav=trav->next;
   }
   // Write 0s,1s and 2s to the linked list
   trav= head;
   while(c0--){
       trav->data = 0;
       trav = trav->next;
   }
   while(c1--){
       trav->data = 1;
       trav = trav->next;
   }
   while(c2--){
       trav->data = 2;
       trav = trav->next;
   }
}
