/*

GeeksForGeeks: Detect Loop in linked list

Link to Problem:https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

Difficulty: Easy

Given a linked list, check if the the linked list has a loop. Linked list can contain self loop.

Input:

In this problem, method takes one argument: the head of the linked list. The function should not read any input from stdin/console.
The node structure has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:

Return 1 if linked list has a loop else 0.

Constraints:

1<=T<=50
1<=N<=300

Example:

Input:

2
3
1 3 4
2
4
1 8 3 4
0

Output:

True
False

Explaination:

In above test case N = 3

The linked list with nodes N = 3 is given. Then value of x=2 is given which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

For N = 4
x = 0 means then lastNode->next = NULL, then the Linked list does not contains any loop.


*/
{
// C program to detect loop in a linked list
#include<stdio.h>
#include<stdlib.h>
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
          (struct node*) malloc(sizeof(struct node));
    /* put in the data  */
    new_node->data  = new_data;
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
int detectloop(struct node *list);
/* Drier program to test above function*/
int main()
{
	int t,n,c,x,i;
	scanf("%d",&t);
	while(t--){
    /* Start with the empty list */
    scanf("%d",&n);
    struct node *head = NULL;
    struct node* temp;
    struct node *s;
    scanf("%d",&x);
    push(&head,x);
    s=head;
    for(i=1;i<n;i++){
		scanf("%d",&x);
    push(&head,x);}
    /* Create a loop for testing */
   scanf("%d",&c);
    if(c>0){
    c=c-1;
    temp=head;
    while(c--)
    temp=temp->next;
    s->next=temp;
	}
	int g=detectloop(head);
    if(g)
    printf("True
");
    else
    printf("False
");
	}
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct node
{
int data;
node* next;
};*/
int detectloop(struct node *list){
// your code goes here
    if(list==NULL)return 0;

    struct node *trav = list;
    struct node *trav1 = list;
    
    while(trav!=NULL && trav->next!=NULL){
        trav1 = trav1->next;
        trav = trav->next->next;
        if(trav==trav1)return 1;
    }
    return 0;
}