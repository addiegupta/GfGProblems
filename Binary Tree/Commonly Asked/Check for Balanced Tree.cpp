/*

GeeksForGeeks: Check for Balanced Tree

Link to Problem: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

Difficulty: Easy

Given a binary tree, find if it is height balanced or not.  A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

 

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if tree is height balanced, else false.

Constraints:
1 <=T<= 100
1 <=Number of nodes<= 100
0 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 2 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
1
 

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3.   Second test case represents a tree with 4 edges and 5 nodes.



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
bool isBalanced(struct Node *root);
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
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBalanced(root) << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node structure
struct Node {
    int data;
    Node* left, * right;
}; */
// This function should return tree if passed  tree 
// is balanced, else false.  Time complexity should
//  be O(n) where n is number of nodes in tree
int dfsBalance(Node*);
bool isBalanced(Node *root)
{
    //  Your Code here
    if(!root)return true;
    return dfsBalance(root)<=1;	
}
int dfsBalance(Node* root){
	if(!root)return 0;
	int unbalanced = 0;
	if((root->left && !root->right) || (root->right && !root->left)){
		unbalanced = 1;
	}
		return dfsBalance(root->left)+dfsBalance(root->right) + unbalanced;
}

// Somewhat cleaner code 13 july 2020 java


class Tree
{
    
     /* This function should return tree if passed  tree 
     is balanced, else false. */
    boolean isBalanced(Node root)
    {
  // Your code here
      int left = trav(root.left);
      int right = trav(root.right);
      if(left==-1||right==-1)return false;
      return Math.abs(left-right)<=1;
        
    }
    int trav(Node root){
        if(root==null)return 0;
        int left = trav(root.left);
        int right = trav(root.right);
        if(left==-1 || right==-1)return -1;
        if(Math.abs(left-right)>1)return -1;
        return Math.max(left,right)+1;
    }
}