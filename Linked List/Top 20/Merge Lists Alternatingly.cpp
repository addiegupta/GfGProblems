/*

GeeksForGeeks: Merge Lists Alternatingly

Link to Problem: https://practice.geeksforgeeks.org/problems/merge-list-alternatingly/1

Difficulty: Easy

Given two linked lists, your task is to complete the function mergeList() which insert's nodes of second list into first list at alternate positions of first list.

For example:
Input:
List1- 5->7->17->13->11
List2- 12->10->2->4->6
Output:
List1- 5->12->7->10->17->2->13->4->11->6
List2- (empty)
The nodes of second list should only be inserted when there are positions available.

For example:
Input:
List1- 1->2->3
List2- 4->5->6->7->8
Output:
List1- 1->4->2->5->3->6
List2- 7->8
Input:
The function takes 2 arguments as input, the reference pointer to the head of the two linked list's(head1 & head2).
There will be T test cases and for each test case the function will be called separately.

Output:
For each test case first print space separated vales of the first linked list, then in the next line print space separated values of the second linked list.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
9 10
6
5 4 3 2 1 6
5
99 88 77 66 55
5
55 44 33 22 11
Output:
10 6 9 1 
2 3 4 5 
55 11 66 22 77 33 88 44 99 55
  

*/

{
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
void push(struct Node ** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<' ';
		temp = temp->next;
	}
	cout<<'
';
}
void mergeList(struct Node **head1, struct Node **head2);
// Driver program to test above functions
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n1, n2, tmp;
        struct Node *a = NULL;
        struct Node *b = NULL;
        cin>>n1;
        while(n1--){
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>n2;
        while(n2--){
            cin>>tmp;
            push(&b, tmp);
        }
        mergeList(&a, &b);
        printList(a);
        printList(b);
    }
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of the node of the linked list is
struct Node
{
	int data;
	struct Node *next;
};
*/
// complete this function
void mergeList(struct Node **p, struct Node **q)
{
	Node* trav1 = *p;
	Node* trav2 = *q;
	while(trav1&&trav2){
		Node* tempList1 = trav1->next;
		*q=trav2->next;
		trav1->next=trav2;
		trav2->next = tempList1;
		trav2=*q;
		trav1=trav1->next->next;
	} 
}