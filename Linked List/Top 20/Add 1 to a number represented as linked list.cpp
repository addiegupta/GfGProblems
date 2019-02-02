/*

GeeksForGeeks: Add 1 to a number represented as linked list

Link to Problem: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

Difficulty: Easy

A number (n) is represented in Linked List such that each digit corresponds to a node in linked list. Add 1 to it.

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually

Output:
Your function should return pointer to head of the modified list.

Constraints:
1 <=T<= 50
1 <=n<= 10000

Example:

Input:
4
456
123
999
1879

Output:
457 
124 
1000 
1880
 

*/
{
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
Node* addOne(Node *head);
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
Node *ZZZZZZZZZZ(Node *head)
{
    Node * prev   = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void print(struct Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
// This function mainly uses addOneUtil().
int main() {
	// your code goes here
	int T;
	cin>>T;
	int no;
	while(T--)
	{
		struct Node *head = NULL;
        struct Node *temp = head;
        
		cin>>no;
		while(no!=0)
			{
			if(head==NULL)
			head=temp=newNode(no%10);
			else
			{
				temp->next = newNode(no%10);
				temp=temp->next;
			}
			no/=10;
		}
		head = ZZZZZZZZZZ(head);
		
		head=addOne(head);
		print(head);
		cout<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Node structure
struct Node
{
    int data;
    Node* next;
}; */
// Add one else send carry by returning true
bool handleAddOne(Node* head){
	if(head->data==9){
		head->data=0;
		return true;
	}
	else{
		head->data+=1;
		return false;
	}
}
bool addOneRecursive(Node* head){
	// Base case
	if(!head)return false;
	// End reached start add one procedure recursively
	if(!head->next){
		return handleAddOne(head);	
	}
	// Carry being forwarded due to recursion, add one here else return false
	return (addOneRecursive(head->next))?handleAddOne(head):false;
}
Node *addOne(Node *head)
{
	// Call the recursive method
	// New 1 needs to be created at start of list
	if(addOneRecursive(head)){
		Node* newHead = new Node;
		newHead->data = 1;
		newHead->next = head;
		return newHead;
	}
	// Else recursive method has added 1, return original head
	return head;
}