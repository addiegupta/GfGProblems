/*

GeeksForGeeks: Serialize and Deserialize a Binary Tree

Link to Problem: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

Difficulty: Easy


Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.

Note: The structure of tree must be maintained.

Input:
The task is to complete two method serialize and deSerialize.  The method serialize takes  two arguments, the first is the root of Binary Tree and second argument is an array A[ ] which stores the serialized tree. The method deSerialize takes only one argument which is the serialized array A[] and returns the deserialzed tree's root . The struct Node has a data part which stores the data, pointer to left child and pointer to right child.There are multiple test cases. For each test case, this method will be called individually.

Output:
The  output in the expected output will be the inorder traversal of the returned tree .

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 100

Example(To be used only for expected output):
Input
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
2 1 3
40 20 60 10 30



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
void serialize(Node *root,vector<int> &);
Node * deSerialize(vector<int> &);
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
     int N = n;
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
    vector<int> A;
    A.clear();
    serialize(root,A);
  //  for(int i=0;i<A.size();i++)
    //    cout<<A[i]<<" ";
      //  cout<<endl;
    // inorder(root);
     //cout<<endl;
    Node *tree_made = deSerialize(A);
    inorder(tree_made);
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
/*this  function serializes 
the binary tree and stores 
it in the vector A*/

// Global iterator to iterate the serialized tree
vector<int>::iterator it;
void traverseSerialize(Node* root, vector<int> &A);
Node* traverseDeserialize(Node* root,vector<int> &A);
void serialize(Node *root,vector<int> &A)
{
    //Your code here
    if(!root)return;
    traverseSerialize(root,A);

}
void traverseSerialize(Node* root, vector<int> &A){
	if(!root) {
		// -1 is used to check if node is null
		A.push_back(-1);
		return;
	}
	A.push_back(root->data);
	if(root->left) traverseSerialize(root->left,A);
	else A.push_back(-1);
	if(root->right) traverseSerialize(root->right,A);
	else A.push_back(-1);

}


/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    //Your code here
    it = A.begin();
    if(it==A.end())return NULL;
    Node* root = newNode(*it);
    it++;
    return traverseDeserialize(root,A);

}
Node* traverseDeserialize(Node* root,vector<int> &A){
	if(it==A.end())return root;

	if(*it==-1){
		root->left = NULL;
		it++;
	}
	else{
		Node* temp = newNode(*it);
		root->left = temp;
		it++;
		traverseDeserialize(root->left,A);
	}
	if(*it ==-1){
		root->right = NULL;
		it++;
	}
	else{
		Node* temp = newNode(*it);
		root->right = temp;
		it++;
		traverseDeserialize(root->right,A);
	}
	return root;
}