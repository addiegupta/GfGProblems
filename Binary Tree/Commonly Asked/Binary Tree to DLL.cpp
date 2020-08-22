/*

GeeksForGeeks: Binary Tree to DLL

Link to Problem: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

Difficulty: Hard

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

		 10
	    /  \
	  12   15
	 / \   /
    25 30 36

    25 ->  12 -> 30 -> 10 -> 36 -> 15
	   <-     <-    <-    <-    <-

Input:
The task is to complete the method which takes two arguments, root of Binary Tree and reference to head of DLL.

The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should change reference of head to head of linked list. 

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:

3 1 2 
2 1 3 
40 20 60 10 30 
30 10 60 20 40 
There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3.   Second test case represents a tree with 4 edges and 5 nodes. 
The output of complete program is forward and backword traversals of modified linked list.

*/
{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void BToDLL(Node *root, Node **head_ref);
/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}
void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     Node *head = NULL;
     BToDLL(root, &head);
     printList(head);
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure for tree and linked list
struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */
// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list
void inorderTraverse(Node*);
Node* head;
Node* tail;
void BToDLL(Node *root, Node **head_ref)
{
	head = *head_ref;
	tail = *head_ref;
    inorderTraverse(root);
    root=head;
    *head_ref = head;

}
void inorderTraverse(Node *root){
    if(!root)return;
    
    if(root->left) {
        inorderTraverse(root->left);
    }

    // Create doubly linked list using the data of this root
    Node* temp = root;
    if(!head){
        head = tail = temp;
    }
    else{
        tail->right = temp;
        temp->left = tail;
        tail = tail->right;
    }
    
    if(root->right){
        inorderTraverse(root->right);
    }    
}

// Similar code 13 July 2020 in java

class GfG
{
    Node dllHead=null;
    Node bToDLL(Node root)
    {
  //  Your code here  
      dllHead=null;
      convert(root,null);
      return dllHead;
      
    }
    Node convert(Node root,Node dllTail){
        if(root==null)return dllTail;
        
        // left
        Node leftTail = convert(root.left,dllTail);
        if(leftTail==null)leftTail = dllTail;
        if(dllHead==null){
            dllHead=leftTail=root;
        }
        // center
        else {
            leftTail.right = root;
            root.left=leftTail;
            leftTail = leftTail.right;
        }
        //right
        Node rightTail = convert(root.right,leftTail);
        return rightTail;
        
    }
}