/*

GeeksForGeeks: Remove duplicate element from sorted Linked List

Link to Problem: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

Difficulty: Easy

Given a linked list of N nodes. The task is to remove duplicates from the given list (if exists).

For example if the linked list is 11->11->11->21->43->43->60, then linked list should be converted to 11->21->43->60.

Note: Try not to use extra space. Expected time complexity is O(N).

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains the linked list data.

Output:
For each testcase, there will be a single line of output which contains linked list with no duplicates.

User Task:
The task is to complete the function removeDuplicates() which should remove the duplicates from linked list.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input
2
4
2 2 4 5
5
2 2 2 2 2

Output
2 4 5
2

Explanation:
Testcase 1: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time.


*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
                Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next;
};*/

Node *removeDuplicates(Node *root)
{	
	Node* prev = root;
	Node* trav =prev->next;
	
	// Traverse the list
	while(trav){
		// Duplicate found
		if(trav->data==prev->data){
			// Remove duplicate
			prev->next = trav->next;
			delete trav;
		}
		else prev=trav;
		
		// Continue traversal
		trav=prev->next;
	}
	return root;
}