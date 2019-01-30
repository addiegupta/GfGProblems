/*

GeeksForGeeks: Alien Dictionary

Link to problem: https://practice.geeksforgeeks.org/problems/alien-dictionary/1

Difficulty: Hard

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary the task is to complete the function which returns a string denoting the order of characters in the language..

Note: Many orders may be possible for a particular test case, thus you may return any valid order.
 

Examples:

Input:  Dict[] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
Output: Function returns "bdac" 
Here order of characters is 'b', 'd', 'a', 'c' 
Note that words are sorted and in the given language "baa" 
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input:  Dict[] = { "caa", "aaa", "aab" }, k = 3
Output: Function returns "cab"

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N and k denoting the size of the dictionary. Then in the next line are sorted space separated values of the alien dictionary.

Output:
For each test case in a new line output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Constraints:
1<=T<=200
1<=N<=100
1<=k<=26
1<=Length of words <=1000

Example:
Input:
2
5 4
baa abcd abca cab cad
3 3
caa aaa aab

Output:
1
1


*/

//Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}



//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */

// Class for Graph
class Graph{
	list<int> *adj;
	int V;

	// Topological Sort Util function
	void topoSortUtil(int i,bool vis[],stack<int> &s);
public:
	Graph(int V);	

	void addEdge(int u,int v);

	string topoSort();
};

Graph:: Graph(int V){
	this->V=V;
	adj = new list<int>[V];
}
void Graph::topoSortUtil(int i,bool vis[],stack<int> &s){
	vis[i]= true;

	list<int>:: iterator it;
	for(it=adj[i].begin();it!=adj[i].end();++it){
		if(!vis[*it]){
			topoSortUtil(*it,vis,s);
		}
	}
	s.push(i);
}
void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
}
// Returns string with characters sorted in topological sort
string Graph::topoSort(){
	stack<int> s;

	bool *vis = new bool[V];
	memset(vis,false,V);

	for(int i=0;i<V;i++){
		if(!vis[i])topoSortUtil(i,vis,s);
	}

	string ans;
	while(!s.empty()){
		ans.append(1,char(s.top()+'a'));
		s.pop();
	}
	return ans;

}

int min(int x, int y) 
{ 
    return (x < y)? x : y; 
}
string printOrder(string dict[], int N, int k)
{
	// Construct new graph with k nodes
	Graph g(k);
	for(int i=0;i<N-1;i++){
		// Get 2 consecutive strings
		string s1 = dict[i];
		string s2 = dict[i+1];
		// Find first mismatching character and add a node in graph for it
		for(int j=0;j<min(s1.length(),s2.length());j++){
			
			if(s1[j]!=s2[j]){
				g.addEdge(s1[j]-'a',s2[j]-'a');
				break;
			}
		}
	}
	
	return g.topoSort();

}