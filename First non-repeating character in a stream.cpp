/*

GeeksForGeeks: First non-repeating character in a stream

Link to Problem:https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

Difficulty: Medium

Given an input stream of n characters consisting only of small case alphabets the task is to find the first non repeating character each time a character is inserted to the stream. If no non repeating element is found print -1.

Example

Flow in stream : a, a, b, c
a goes to stream : 1st non repeating element a (a)
a goes to stream : no non repeating element -1 (a, a)
b goes to stream : 1st non repeating element is b (a, a, b)
c goes to stream : 1st non repeating element is b (a, a, b, c)

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the stream. Then in the next line are x characters which are inserted to the stream.

Output:
For each test case in a new line print the first non repeating elements separated by spaces present in the stream at every instinct when a character is added to the stream, if no such element is present print -1.

Constraints:
1<=T<=200
1<=N<=500

Example:
Input:
2
4
a a b c
3
a a c 
Output:
a -1 b b
a -1 c

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
  char data;
  int count;
  Node* next;
};
// Custom queue class with additional function to traverse queue and return required first non recurring char

class Queue{
  Node* front;
  Node* rear;
  public:
    void push(char c){
      Node* temp = new Node;
      temp->data = c;
      temp->count = 1;
      temp->next = NULL;
      if(rear==NULL){
        front = temp;
        rear = temp;
      }
      else{
        rear->next = temp;
        rear = temp;
      }
    }  
    char pop(){
      if(front == NULL){
        return '\0';
      }
      if(front==rear){
        char temp = front->data;
        front = NULL;
        rear = NULL;
        return temp;
      }
      Node* temp = front;
      front = front->next;
      char c = temp->data;
      // delete temp;
      return c;
    }
    // Insert char or update count of char if exists
    // Return the first non recurring char
    char updateQueue(char c){
      Node* trav = front;
      char ret = '\0';
      int f=1,g=1;
      while(trav){
        if(trav->data == c){
          f=0;
          trav->count++;
        }
        else{
          if(trav->count==1&&g){
            ret = trav->data;
            g=0; 
          }
        }
        trav = trav->next;
      }    
      if(front==NULL||(g&&f)) ret = c;
      if(f) push(c);
      return ret;
    }
};
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,i;
    cin>>n;
    Queue *q = new Queue();
    vector<char> a(n);
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    for(i=0;i<n;i++){
      char c = q->updateQueue(a[i]);
      if(c=='\0'){
        cout<<-1;
      }
      else{
        cout<<c;
      }
      cout<<" ";
    }
    cout<<endl;

  }
}