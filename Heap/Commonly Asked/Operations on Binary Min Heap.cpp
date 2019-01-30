/*

GeeksForGeeks: Operations on Binary Min Heap

Link to Problem: https://practice.geeksforgeeks.org/problems/operations-on-binary-min-heap/1

Difficulty: Medium

Your task is to implement the three methods insertKey,  deleteKey,  and extractMin on a Binary Min Heap

Example

The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 

A Query Q is of 3 Types
1.  1  x  (a query of this type means to insert an element in the min heap with value x )
2.  2  x  (a query of this type means to remove an element at position x from the min heap)
3. 3  (a query like this removes the min element from the min heap and prints it ).

The second line of each test case contains Q queries seperated by space.


Output:
The output for each test case will  be space separated integers having -1  if the heap is empty else the min element of the heap from the stack. 
You are required to complete the 3 methods insertKey which takes one argument the value to be inserted , deleteKey which takes one argument the position from where element is to be deleted and extractMin which returns the minimum element in the heap .

Constraints:
1<=T<=100
1<=Q<=100
1<=x<=100

Example:
Input
1
7
1 4 1 2 3 1 6 2 0 3 3

Output
2 6 - 1

Explanation:
In the first test case for query 
1 4      the heap will have  {4}  
1 2      the heap will be { 2 4 }
3         removes min element from heap ie 2 and prints it now heap is {4} 
1 6      inserts 6 to heap now heap is {4 6}
2 0      delete element at position 0 of heap now heap is {6}
3         remove min element from heap ie 6 and prints it  now the heap is empty {}
3         since heap is empty thus no min element exist so -1 is printed .





*/

//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void swap(int *x, int *y);
 
class MinHeap
{ public:
    int *harr; 
    int capacity;
    int heap_size;
  
    MinHeap(int capacity);
 
    
    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
  
    int left(int i) { return (2*i + 1); }
 
 
    int right(int i) { return (2*i + 2); }
 
 
    int extractMin();
 
    
    void decreaseKey(int i, int new_val);
 
   
    int getMin() ;
 
   
    void deleteKey(int i);
 
    
    void insertKey(int k);
};
//Position this line where user code will be pasted.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     ll a;
     cin>>a;
     MinHeap h(a);
    for(ll i=0;i<a;i++)
      {
        int c;
        int  n;
        cin>>c;
        if(c==1)
            {  cin>>n;
            
               h.insertKey(n);
             }
        if(c==2)
           {  cin>>n;
              h.deleteKey(n);
	    } 
        if(c==3)
              { 
               cout<<h.extractMin()<<" ";
               }
     
      }
       cout<<endl;
    delete h.harr;
     h.harr=NULL;
       
   }
  return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is
class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};*/
/* Removes min element from min heap and returns it */
void heapifyUp(int* arr,int size);
void heapifyDown(int* arr,int size,int index);
MinHeap :: MinHeap(int c){heap_size=0;capacity = c;harr=new int[capacity];}
int MinHeap ::  extractMin()
{
    // Your code here
    if(!heap_size) return -1;
    int temp = harr[0];
    swap(harr[0],harr[heap_size-1]);
    heap_size--;
    heapifyDown(harr,heap_size,0);
    return temp;
}
/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int i)
{
    // Your code here
    if(i >= heap_size || i<0) return;
    swap(harr[i],harr[heap_size-1]);
    heap_size--;
    heapifyDown(harr,heap_size,i);
}
/* Inserts an element at position x into the min heap*/
void MinHeap ::insertKey(int k)
{
    // Your code here
	harr[heap_size] = k;
	heap_size++;
	heapifyUp(harr,heap_size);
}
// Helper functions
int getLeftChildIndex(int parentIndex){return (parentIndex * 2) + 1;}
int getRightChildIndex(int parentIndex){return (parentIndex * 2) + 2;}
int getParentIndex(int childIndex){return (childIndex - 1) /2;}
bool hasLeftChild(int index, int size){return getLeftChildIndex(index)<size;}
bool hasRightChild(int index, int size){return getRightChildIndex(index)<size;}
bool hasParent(int index){return getParentIndex(index)>=0;}

// Go up from last node, creating min heap
void heapifyUp(int* arr,int size){
    if(!size)return;
	int index = size-1;
	// Parent element is greater than selected element
	while(hasParent(index) && arr[getParentIndex(index)]>arr[index]){
		swap(arr[index],arr[getParentIndex(index)]);
		index = getParentIndex(index);
	}
}
// Go down from the given index, swapping elements to achieve min heap
void heapifyDown(int* arr,int size,int index){
	
    if(index >= size) return;
    // Till bottom is reached
	while(hasLeftChild(index,size)){
		// Determine if smaller child if on left or right
		int smallerChildIndex = getLeftChildIndex(index);
		if(hasRightChild(index,size) && arr[getRightChildIndex(index)]<arr[getLeftChildIndex(index)]){
			smallerChildIndex = getRightChildIndex(index);
		}
		// Swap if current is larger or else break as min heap is created
		if(arr[smallerChildIndex]<arr[index]){
			swap(arr[index],arr[smallerChildIndex]);
		}
		else break;
		index = smallerChildIndex;
	}
}
