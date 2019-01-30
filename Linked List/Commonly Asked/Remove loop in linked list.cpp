/*

GeeksForGeeks: Remove loop in Linked List

Link to Problem:https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

Difficulty: Medium

Given a linked list, remove the loop in it if present. The task is to complete the function removeTheLoop which takes only one argument the head of the linked list . The function removes the loop in the linked list if present.

Input:
The first line of input will contain an integer T denoting the no of test cases . Then T test cases follow. Each test case contains 3 lines . The first line of each test case contains an integer N denoting the no of nodes of the linked list . In the next line are N space separated values denoting the values of the linked list. The next line after it contains an integer x denoting that the last node of the linked list pointing to the xth node thus resulting in cycle. 

Output:
Your task is to remove the cycle if present output for each test case will be 1 if the loop is successfully removed from the linked list else 0.

Constraints:
1<=T<=50
1<=N<=300

Example(To be used only for expected output) :

Input:

2
3
1 3 4
2
4
1 8 3 4
0

Output:
1
1

Explanation:

In the first test case N = 3
The linked list with nodes N = 3 is given. here x=2 which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

In the second test where N = 4 and x = 0, which means lastNode->next = NULL, thus the Linked list does not contains any loop.




*/
{
{
// C program to detect loop in a linked list
#include<bits/stdc++.h>
 using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
 vector<int> _A_;
 void removeLoop(struct Node *, struct Node *);
 void removeTheLoop(Node *);
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node =
          (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_Node->data  = new_data;
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref)    = new_Node;
}
void removeTheLoop(struct Node *list);
int __detectloop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;
  	bool fA=0;
  	bool fB =0;
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
           fA=1;
        }
    }
    
    //Check for valid list
    
    
    
    if(fA)
    return 1;
    else 
    return 0;
}
/* Drier program to test above function*/
int main()
{
	int t,n,c,x,i;
	cin>>t;
	while(t--){
    /* Start with the empty list */
    cin>>n;
    _A_.clear();
    struct Node *head = NULL;
    struct Node* temp;
    struct Node *s;
    cin>>x;
    push(&head,x);
    s=head;
    
   _A_.push_back(x);
    for(i=1;i<n;i++){
		cin>>x;
		
   _A_.push_back(x);
    push(&head,x);}
    
    /* Create a loop for testing */
    cin>>c;
    if(c>0){
    c=c-1;
    temp=head;
    while(c--)
    temp=temp->next;
    s->next=temp;
	}
	removeTheLoop(head);
	
	int g = __detectloop(head);
	Node *test = head;
    int c_=0;
    int fB=0;
  reverse(_A_.begin(),_A_.end());
    while(test!=NULL)
    {
    
    	if(test->data!=_A_[c_]){
    	fB=1;
    
    	break;
    	
    	}
    	test=test->next;
    	c_++;
    }
	
	
    if(g or fB)
    cout<<"0
";
    else
    cout<<"1
";
	}
    return 0;
}

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
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
     // Something wrong with the problem. The input argument "node" 
	 // is actually the end of the list. Thus making it point to NULL will cause the loop to be removed.
     node->next = NULL;
}
