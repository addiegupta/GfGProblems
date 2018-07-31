/*

GeeksForGeeks: Delete without head pointer

Link to Problem:https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1

Difficulty: Easy

You are given a pointer/reference to a node to be deleted in a linked list. The task is to delete the node.  Pointer/reference to head node is not given. 

You may assume that the node to be deleted is not the last node.

Input:

You have to complete a method which takes one argument: pointer/reference to a node to be deleted.  There are multiple test cases. For each test case, this method will be called individually.


Example:
Input
2
2
1 2
1
4
10 20 4 30
20

Output
2
10 4 30

*/
{
#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct Node
{
    int data;
    Node* next;
}*head;
Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}
void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(Node *) malloc( sizeof(Node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (Node *) malloc( sizeof(Node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
void deleteNode(Node *node_ptr);
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
        Node *del = findNode(head, k);
        if (del != NULL && del->next != NULL)
        {
            deleteNode(del);
        }
        printList(head);
    }
    return(0);
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list node 
struct Node
{
    int data;
    Node* next;
}*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{
   // Your code here
   Node* trav = node;
   while(trav->next->next){
       trav->data = trav->next->data;
       trav=trav->next;
   }
   Node* temp = trav->next;
   trav->data = temp->data;
   trav->next = NULL;
   delete temp;
}
