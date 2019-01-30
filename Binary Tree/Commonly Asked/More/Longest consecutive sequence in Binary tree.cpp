/*

GeeksForGeeks: Longest consecutive sequence in Binary tree

Link to Problem: https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1

Difficulty: Easy

Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order. Every node is considered as a path of length 1.longest-consecutive-sequence-in-Binary-tree-example


             6               
            / \              
           3   9  
              / \               
             7   10
                   \          
                    11

                    LCP: 9,10,11 Length:3

Input:

The first line of the input contains a single integer T denoting the number of test cases. For each test a root node is given to the longestConsecutive function. The only input to the function is the root of the binary Tree.

Output:

For each test case output in a single line, find the length of the longest path of the binary tree.
If no such sequence is possible return -1.

Constraints:

1<=T<=50
1<=N<=50
Example:

Input:

2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:

2
-1

Explanation:
Test case 1:

           1

        /     \

      2        3

For the above test case the longest sequence is : 1 2 

Test case 2:

            10

         /        \

     20          30

   /      \       /

40      60 90

For the above test case no sequence is possible: -1

*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int longestConsecutive(Node* root);
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
     cout<<longestConsecutive(root)<<endl;
  }
  return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
struct Node
{
    int data;
    Node *left, *right;
};
*/
// your task is tp complete this function
// function should return the length of the longestConsecutive
// sequence
int longestSequence(Node* root,int prev,int maxLen,int length){
    
    // Null node
    if(!root)return maxLen;

    // Found match for sequence; length ==1 => new sequence found; length ==0 => function invoked first time
    if(root->data == prev+1) length++;
    else length=1;

    if(maxLen<length)maxLen = length;

    // Go left and right and return max value 
    return max(longestSequence(root->left,root->data,maxLen,length),
                longestSequence(root->right,root->data,maxLen,length));


}

int longestConsecutive(Node* root)
{
    // For root node of tree, set prev value as current value-1 so that it gets
    // counted as part of sequence
    int ans = longestSequence(root,root->data-1,0,0);
    return (ans>1)?ans:-1;
}
