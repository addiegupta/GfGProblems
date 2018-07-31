/*

GeeksForGeeks: Top View of Binary Tree

Link to Problem:https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Difficulty: Medium

Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. You are required to complete the function topView, which should print the top view of the given binary tree.

       1
     /   \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

Note: For the problem the printing should be level wise, i.e. starting node should be root.

Input:
The first line of the input contains a single integer T denoting the number of test cases. For each test a root node is given to the topView function. The only input to the function is the root of the binary Tree.

Output:
For each test case output in a single line, top view of the binary tree.

Constraints:
1<=T<=100
1<=N<=50

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:
1 2 3
10 20 30 40
 

Explanation:
Test case 1:

           1
         /  \
        2    3

For the above test case the top view is: 1 2 3

Test case 2:

          10
         /   \
        20    30
       /  \    /
      40   60 90

TopView is: 10 20 30 40


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
void topView(struct Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
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
     topView(root);
     cout << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//Structure of binary tree
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// function should print the topView of the binary tree
//
//
// TODO:CORRECT USING HORIZONTAL HEIGHT
//
//
//
void traverseNode(Node*,int);
int a[100];
void topView(struct Node *root)
{
    if(!root)return;
    int i,j;
    for(i=0;i<100;i++)a[i]=-1;
    // Your code here
    int m = 49;
    a[m] = root->data;
    traverseNode(root->left,m-1);
    traverseNode(root->right,m+1);
    cout<<a[49]<<" ";
    for(i=48,j=50;i>=0&&j<100;i--,j++){
      if(a[i]!=-1)cout<<a[i]<<" is at "<<i<<" ";
      if(a[j]!=-1)cout<<a[j]<<" is at "<<j<<" ";
    }
}
void traverseNode(Node* root,int h){
  if(!root) return;
  if(a[h]==-1) a[h]= root->data;
  traverseNode(root->left,h-1);
  traverseNode(root->right,h+1);

}