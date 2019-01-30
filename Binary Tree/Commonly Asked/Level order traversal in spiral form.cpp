/*

GeeksForGeeks: Level order traversal in spiral form

Link to Problem: https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

Difficulty: Easy

Write a function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7.

			   1
			  / \
			2	  3
		   / \   / \
		  7   6 5   4 


Input:
The task is to complete the method which takes one argument, root of the Tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print level order traversal in spiral form .

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 3000
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 2
10 20 30 60 40

There are two test cases.First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.


*/
{
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
                        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void printSpiral(struct Node *root);
/* Driver program to test above functions*/
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
    printSpiral(root);
    cout<<endl;
  }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void traverse(stack<Node*>,bool);
void printSpiral(Node *root)
{
	stack<Node*> s;
	// Stack stores parent nodes
    bool goLeft = true;
    s.push(root);
    cout<<root->data<<" ";
	traverse(s,goLeft);
}
void traverse(stack<Node*> s,bool goLeft){
	// This stack will store nodes of current level which will become parent nodes
	// for the next recursion
	stack<Node*> newS;
	while(!s.empty()){
		Node* temp = s.top();
		s.pop();
		if(!temp) continue;
		// Left to right traversal of nodes
		if(goLeft){
			if(temp->left){
				newS.push(temp->left);
				cout<<temp->left->data<<" ";
			}
			if(temp->right){	
				newS.push(temp->right);
				cout<<temp->right->data<<" ";
			}
		}
		// Right to left traversal of nodes
		else{
			if(temp->right){	
				newS.push(temp->right);
				cout<<temp->right->data<<" ";
			}
			if(temp->left){
				newS.push(temp->left);
				cout<<temp->left->data<<" ";
			}
		}
	}
	goLeft = !goLeft;
	if(!newS.empty()) traverse(newS,goLeft);
}