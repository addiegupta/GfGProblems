/*

GeeksForGeeks: Determine if Two Trees are Identical

Link to Problem: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

Difficulty: Easy

Given  two  binary trees, your task is to find if both of them are identical or not .  

Input:
The task is to complete the method which takes 2 argument, the  roots r1 and r2  of the  Binary Trees. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if both trees are identical  else false.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input
2
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 3 L 1 2 R

Output
1
0

In above example there is one  test case which represent two trees with 3 nodes and 2 edges where in first test case both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3 where as in second test case both trees are not identical .

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
bool isIdentical(Node *,Node *);
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
     }
  //  inorder(root);
    //sec tree
     map<int, Node*> mm;
     int nn;
     scanf("%d
",&nn);
     struct Node *roott = NULL;
     if(nn==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (nn--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (mm.find(n1) == mm.end())
        {
           parent = newNode(n1);
           mm[n1] = parent;
           if (roott == NULL)
             roott = parent;
        }
        else
           parent = mm[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        mm[n2]  = child;
     }
  }
  cout<<isIdentical(root,roott)<<endl;
  }
  return 0;
}

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
/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool traverse(Node*,Node*);
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here

	bool ret = traverse(r1,r2);

    return ret;
}
bool traverse(Node* r1,Node* r2){
	if(!r1&&!r2) return true;
	else if(!r1||!r2) return false;
	if(r1->data!=r2->data) return false;
	if(!traverse(r1->left,r2->left))return false;
	if(!traverse(r1->right,r2->right))return false;
	return true;
}