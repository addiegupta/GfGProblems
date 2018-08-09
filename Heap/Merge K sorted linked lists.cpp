/*

GeeksForGeeks: Merge K sorted linked lists

Link to Problem: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

Difficulty: Medium

Given K sorted linked list your task is to merge them. You need to complete mergeKList  method that takes 2 arguments the arr[] that represents an array of  sorted linked lists and an integer N denoting the no. of sorted linked lists. The method needs to return  head of the obtained linked list. There are multiple test cases. For each test case, this method will be called individually. 

Input:
The first line of input will denote the no of Test cases then T test cases will follow . Each test cases will contain an integer N denoting the no of sorted linked list. Then in the next line all of the nodes of the linked list are fed to the input in a fashion where first integer will denote no of nodes of one of the sorted linked list and then all the elements of the linked list separated by space.

Output:
The output will be the nodes of the merged linked list .

Constraints
1<=T<=50
1<=N<=10

Example:

Input
1
4
3 1 2 3 2 4 5 2 5 6 2 7 8 

Output:
1 2 3 4 5 5 6 7 8

Explanation 
above test case has 4 sorted linked list of size 3, 2, 2, 2
1st      list     1 -> 2-> 3
2nd    list      4->5
3rd     list      5->6
4th     list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8




*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref)    = new_Node;
}
 
 
// A utility function to print a linked list
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {
        
        temp=Node;
        Node = Node->next;
        free(temp);
    }
  
}
Node * mergeKList(Node *arr[],int );
/* Driver program to test above function */
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	  
	   int N;
	   cin>>N;
       struct Node **arr = new Node *[N];
       for(int j=0;j<N;j++){
	    cin>>n; 
		    for(i=0;i<n;i++)
	    	{
			cin>>x;
			push(&arr[j], x);
			}
			reverse(&arr[j]);
		   // printList(arr[j]);
   		}
   		
   		Node *res = mergeKList(arr,N);
		printList(res);
		
	 
   }
   return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Linked list Node structure
struct Node
{
    int data;
    Node* next;
};*/ 

class Heap{
	int h[20];
	int size;

	// Helper functions
	int getParent(int index){return h[getParentIndex(index)];}
	int getLeftChild(int index){return h[getLeftChildIndex(index)];}
	int getRightChild(int index){return h[getRightChildIndex(index)];}
	int getLeftChildIndex(int parentIndex){return (parentIndex * 2) + 1;}
	int getRightChildIndex(int parentIndex){return (parentIndex * 2) + 2;}
	int getParentIndex(int childIndex){return (childIndex - 1) /2;}
	bool hasLeftChild(int index){return getLeftChildIndex(index)<size;}
	bool hasRightChild(int index){return getRightChildIndex(index)<size;}
	bool hasParent(int index){return getParentIndex(index)>=0;}
	// Pushes the topmost node to its designated place
	void heapifyDown();
	// Pushes the bottom node to its designated place
	void heapifyUp();
	
	public:
		Heap(){size = 0;}
		void insert(int k);
	    int extractMin();
        bool empty(){return size==0;}
};
// Inserts the given int in the array and then calls heapifyUp
void Heap :: insert(int k){
	h[size]=k;
	size++;
	heapifyUp();
}
// Extracts the min element from the heap(i.e. the topmost node)
int Heap::extractMin(){
	if(!size)return -1;
	int temp = h[0];
	swap(h[0],h[size-1]);
	size--;
	heapifyDown();
	return temp;
}

void Heap::heapifyUp(){
	if(!size)return;
	int i = size-1;
	while(hasParent(i)&&getParent(i)>h[i]){
		swap(h[getParentIndex(i)],h[i]);
		i = getParentIndex(i);
	}
}
void Heap::heapifyDown(){
	int i = 0;

	while(hasLeftChild(i)){
		int smallChildIndex = getLeftChildIndex(i);
		if(hasRightChild(i)&&getRightChild(i)<getLeftChild(i)){
			smallChildIndex = getRightChildIndex(i);
		}
		if(h[smallChildIndex]<h[i]){
			swap(h[smallChildIndex],h[i]);
		}
		else break;

		i = smallChildIndex;
	}
}

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKList(Node *arr[], int n)
{
    // Your code here
    Heap h = Heap();
    int i;
    // Insert the first element of every sorted list in the min heap
    for(i=0;i<n;i++){
    	h.insert(arr[i]->data);
    }
    Node* list=NULL;
    Node* tail = NULL;
    // Extract min element, add it to new list, add next element (from the source list 
    // of the element) to the min heap
    while(!h.empty()){
    	Node* node = new Node();
    	int temp = h.extractMin();
    	node->data = temp;
    	node->next = NULL;
    	if(!tail&&!list){
    		list=tail=node;
    	}
    	else{
    		tail->next = node;
    		tail = node;
    	}
    	for(i=0;i<n;i++){
    		if(arr[i]&&arr[i]->data==temp){
    			Node* tempNode = arr[i];
    			arr[i]=arr[i]->next;
    			delete tempNode;
    			if(arr[i]){
    				h.insert(arr[i]->data);
    			}
    			break;
    		}
    	}
    }
    return list;
}