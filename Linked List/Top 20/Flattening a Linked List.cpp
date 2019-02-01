/*

GeeksForGeeks: Flattening a Linked List

Link to Problem: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Difficulty: Medium

Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which is sorted.

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
and after flattening it, the sorted linked list looks like:

 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.

The  node structure has 3 fields as mentioned. A next pointer, a bottom pointer and a data part.
There are multiple test cases. For each test case, this function will be called individually.

Input (To be used for Expected Output):
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer N denoting the number of head nodes connected to each other.
Second line of each test case contains N space separated numbers (M1, M2...Mn) denoting number of elements in linked lists starting with each head. Third line of each test case contains all the elements of the linked list starting with 1st head node and covering all the elements through its down pointer, then 2nd head node and covering all its elements through down pointer and so on till the last head node of the linked list.

Output:
Return a pointer to the flattened linked list.

Constraints:
1 <= T <= 50
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 1000

Example:
Input
1                   
4 
4 2 3 4                  
5 7 8 30 10 20 19 22 50 28 35 40 45

Output:
5 7 8 10 19 20 22 28 30 35 40 45 50


*/
#include <bits/stdc++.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
};
using namespace std;
void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}
Node* flatten (Node* root);
int main(void) {
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			temp = (struct Node*)malloc(sizeof(struct Node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			temp->bottom=NULL;
			if(flag){
				head=temp;
				pre=temp;
				flag=0;
				flag1=1;
			}
			else{
				pre->next=temp;
				pre=temp;
				flag1=1;
			}
			for(int j=0;j<m;j++){
				tempB = (struct Node*)malloc(sizeof(struct Node));
				scanf("%d",&tempB->data);
				tempB->next=tempB->bottom=NULL;
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
		   /*
		while(fun!=NULL)
            {
                cout<<fun->data<<" ";
                fun2 = fun->bottom;
                fun=fun->next;
                while(fun2){
                cout<<fun2->data<<" ";
                fun2=fun2->bottom;
                }
                cout<<endl;
            }*/
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
	}
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */

Node * merge(Node* a,Node* b){

	// If one is null return the other node
	if(!a) return b;
	if(!b) return a;

	// To store the node to be returned
	Node* ans;

	if(a->data < b->data){
		// Set answer as the lower value node
		ans=a;
		// Recursively merge remaining lists
		ans->bottom=merge(a->bottom,b);
	}
	else{
		ans=b;
		ans->bottom=merge(a,b->bottom);
	}
	return ans;
}
Node *flatten(Node *root)
{	
	// Base cases
	if(!root||!root->next)return root;

	// Recursively call merge after flattening remaining linked list
	return merge(root,flatten(root->next));
}
