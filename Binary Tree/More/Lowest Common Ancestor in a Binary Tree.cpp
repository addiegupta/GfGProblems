/*

GeeksForGeeks: Lowest Common Ancestor in a Binary Tree

Link to Problem: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

Difficulty: Easy

Given a Binary Tree and 2 nodes value n1 and n2  , your task is to find the lowest common ancestor of the two nodes . You are required to complete the function LCA . You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Input:
The task is to complete the method LCA which takes 3 arguments, root of the Tree and two nodes value  n1 and n2 . The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return the node which is the least common ancestor of the two nodes n1 and n2 .

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:

Input
1
2
1 2 L 1 3 R
2 3 

Output 
1

In above example there is one  test case which represent a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3.  


*/


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
Node * LCA(Node* ,int ,int );
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
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
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
     int a,b;
     cin>>a>>b;
     Node * k = LCA(root,a,b);
     cout<<k->data<<endl;
  }
  }
  return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
Node * LCA(Node* root ,int n1 ,int n2 )
{   
   // Leaf found 
   if(!root)return NULL;

   // One number match
   if(root->data == n1 || root->data == n2)return root;

   // Check left and righ subtrees
   Node * leftLca = LCA(root->left,n1,n2);
   Node * rightLca = LCA(root->right,n1,n2);

   // If both subtrees return a node => both contain one element
   // Hence current root node is required LCA
   if(leftLca && rightLca)return root;

   // Else find in either left subtree or right subtree depending on 
   // where the values are
   return (!leftLca)?rightLca:leftLca;
}