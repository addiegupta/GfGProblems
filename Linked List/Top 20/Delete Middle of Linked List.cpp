/*

GeeksForGeeks: Delete Middle of Linked List

Link to Problem: https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

Difficulty: Easy

Given a singly linked list, delete middle  of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5

If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.

If the input linked list is NULL, then it shoudl remain NULL.

If the input linked list has 1 node, then this node should be deleted and new head should be returned.

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return head  of the modified linked list.  If linked list is empty then it should return NULL.

Constraints:
1 <=T<= 50
1 <=N<= 1000
1 <=value<= 1000

Example:
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
1 2 4 5
2 4 6 5 1


*/

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
struct Node* deleteMid(struct Node *head);
void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "
";
}
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    head = deleteMid(head);
    printList(head);
    }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
}; */
// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node *head)
{
	// Base case
	if(!head||!head->next)return NULL;
	
	// Run one pointer slow and other fast
	// Store pointer previous to slow in order to delete slow when required
	Node* slow = head;
	Node* fast = head;
	Node* prev = head;

	// Traverse the list
	while(fast){

		// Last node in odd number of elements in list
		if(!fast->next){

			// Delete middle element
			prev->next = slow->next;
			delete slow;
			return head;
		}
		// Last pass in even number of elements in a list
		if(!fast->next->next){

			// Delete upper middle element
			Node* temp = slow->next;
			slow->next = slow->next->next;
			delete temp;
			return head;
		}
		// Fast pointer jumps 2 nodes at a time
		fast=fast->next->next;
		// Slow pointer jumps 1 node
		prev=slow;
		slow=slow->next;
	}
	return head;
}