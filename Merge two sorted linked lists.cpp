/*

GeeksForGeeks: Merge two sorted linked lists

Link to Problem:https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

Difficulty: Easy

Given two linked lists sorted in ascending order. Merge them in-place and return head of the merged list.   For example, if first list is 10->20->30 and second list is 15->17, then the result list should be 10->15->17->20->30.

It is strongly recommended to do merging in-place using O(1) extra space.

Input:
You have to complete the method which takes 2 argument: the head of the first linked list  and the head of second linked list. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the list obtained by merging the two sorted linked list passed as argument.

Constraints:
1 <=T<= 200
1 <= size of linked lists <= 1000
1 <= Data in linked list nodes <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 

Output:

2 3 5 10 15 20 40 
1 1 2 4 

*/
{
// C program to find n'th Node in linked list
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node* SortedMerge(struct Node* a, struct Node* b);
void MoveNode(struct Node** destRef, struct Node** sourceRef);
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
/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;
    cin>>T;
    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;
        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = SortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */
Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    Node* newList=NULL;
    Node* newHead=NULL;
 	// Loop traversal till one list gets finished
    while(head1 && head2){
        Node* temp = new Node;
        //Find smaller element out of the 2 lists and append it to the final list
        if(head1->data <= head2->data){
            temp->data = head1->data;
            head1=head1->next;
        }
        else{ 
            temp->data = head2->data;
            head2=head2->next;
            
        }
        if(!newList){
            newList = temp;
            newHead = newList;
        }
        else {
            newList->next=temp;
            newList = newList->next;
        }
    }
    // Add remaining elements of the 2 lists
    while(head1){
        
        Node* temp = new Node;
        temp->data = head1->data;
        newList->next = temp;
        newList = newList->next;
        head1=head1->next;
    }
    while(head2){
        Node* temp = new Node;
        temp->data = head2->data;
        newList->next = temp;
        newList = newList->next;
        head2=head2->next;
    }
    return newHead;
}