/*

GeeksForGeeks: Check For BST

Link to Problem:https://practice.geeksforgeeks.org/problems/check-for-bst/1

Difficulty: Medium

Given a binary tree, return true if it is BST, else false. For example, the following tree is not BST, because 11 is in left subtree of 10.

      10
     /  \
    7   39
     \
      11

 

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return 1 if BST else return 0.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
0

Both of the given trees are not BST.

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.


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
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
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
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
        /  \ 
      10   30
  and return value should be 0 for following tree.
         10
        /  \ 
      20    30 */
bool bst;
void checkLeft(Node* root, int min, int max);
void checkRight(Node* root, int min, int max);
bool isBST(Node* root) {
    // Your code here
    bst = true;
    int min = -1, max =1001;
    if(!root) return true;
    checkLeft(root->left,min,root->data);
    checkRight(root->right,root->data,max);
    return bst;
}
void checkLeft(Node* root,int min,int max){
  if(!root) return;
  if(root->data <=max && root->data >= min){
    checkLeft(root->left,min,root->data);
    checkRight(root->right,root->data,max);
  }
  else {
    bst = false;
  }
}
void checkRight(Node* root,int min,int max){
  if(!root) return;
  if(root->data >= min && root->data <=max){
    checkLeft(root->left,min,root->data);
    checkRight(root->right,root->data,max);
  }
  else {
    bst = false;
  }
}