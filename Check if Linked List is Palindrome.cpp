/*

GeeksForGeeks: Check if Linked List is Palindrome

Link to Problem:https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Difficulty: Easy

Given a singly linked list of integers, Your task is to complete the function isPalindrome that returns true if the given list is palindrome, else returns false.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T testcases follow. Each test case contains 2 line the first line of each test case contains an integer N denoting the size of the linked list. The next line contains N space separated integers denoting the values of the nodes of the linked list.

Output:
For each test case output will be 1 if the linked list is a palindrome else 0.

Constraints:
1<=T<=1000
1<=N<=50

Example(To be used only for expected output):
Input
2
3
1 2 1
4
1 2 3 4

Output:
1
0



*/
{
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    Node* trav = head;
    Node* rev = NULL;
    
 	// Reverse linked list and store in new list
    while(trav){
        Node* temp = new Node;
        temp->data = trav->data;
        temp->next = NULL;
        if(!rev){
            rev= temp;
        }
        else{
            temp->next = rev;
            rev = temp;
        }
        trav = trav->next;
    }
    trav = head;
    while(trav){
        if(trav->data!=rev->data) return false;
        trav=trav->next;
        rev=rev->next;
    }
    return true;
}
