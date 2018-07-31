/*

GeeksForGeeks: Intersection Point in Y Shapped Linked Lists

Link to Problem:https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

Difficulty: Medium

There are two singly linked lists in a system. By some programming error the end node of one of the linked list got linked into the second list, forming a inverted Y shaped list. Write a program to get the point where two linked lists merge.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.

Expected time complexity is O(m + n) where m and n are lengths of two linked lists

Input:

You have to complete the method which takes two arguments as heads of two linked lists. 


Output:
The function should return data value of a node where two linked lists merge.  If linked list do not merge at any point, then it shoudl return -1.

Constraints:
1 <=T<= 50
1 <=N<= 100
1 <=value<= 1000

Example:
Input:
2
2 3 2
10 20
30 40 50
5 10
2 3 0
10 20
30 40 50
First line is number of test cases. Every test case has four lines. First line of every test case contains three numbers, x (number of nodes before merge point in 1st list), y(number of nodes before merge point in 11nd list) and z (number of nodes after merge point).  Next three lines contain x, y and z values.

Output:
5
-1

References: https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
*/
{
// C program to find n'th Node in linked list
{
#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
int intersectPoint(struct Node* head1, struct Node* head2);
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
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* trav1 = head1;
    Node* trav2 = head2;
    //Traverse through first list
    while(trav1){
        trav2=head2;
        //Traverse through second list
        while(trav2){
        	// Found
            if(trav1==trav2){
                return trav1->data;
            }
            trav2 = trav2->next;
        }
        trav1 = trav1->next;
    }
    return -1;
    
}