/*

GeeksForGeeks: Generate IP Addresses

Link to problem: https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

Difficulty: Medium

Given a string s containing only digits, Your task is to complete the function genIp which returns a vector containing all possible combination of valid IPv4 ip address and takes only a string s as its only argument . 
Note : Order doesn't matter

For string 11211 the ip address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Input:
The first line of input will contain no of test cases T. Then T test cases follow . Each test case will contains a string s . 

Output:
The output in the expected output will be 1 if successfully all the combinations were obtained in the returned vector else it will be 0.

Constraints:
1<=T<=100
1<=str<=16

Example(To be used only for expected output):
Input
1
1111

Output
1


*/


#include<bits/stdc++.h>
using namespace std;
bool ______________ok(int a,int b,int c,int d)
{
    return a<=255 and b<=255 and c<=255 and d<=255;
}
string ____________G(int a,int b,int c,int d)
{
    return to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
}
vector<string> _______________ip(string s)
{
        vector<string> res;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    for(int l=1;l<=3;l++)
                    {
                        if(i+j+k+l==s.length())
                        {
                            int a = stoi(s.substr(0,i));
                            int b = stoi(s.substr(i,j));
                            int c = stoi(s.substr(i+j,k));
                            int d = stoi(s.substr(i+j+k,l));
                            if(______________ok(a,b,c,d))
                            {
                                string str =____________G(a,b,c,d);
                                /*+3 because of 3 dots*/
                                if(str.length()==s.length()+3)
                                {
                                    res.push_back(str);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
}
vector<string> genIp(string s);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        /*generating naively*/
       vector<string> str = _______________ip(s);
       sort(str.begin(),str.end());
       vector<string> res =  genIp(s);
       sort(res.begin(),res.end());
       if(res.size()!=str.size())
        cout<<0<<endl;
       else{
       bool f=true;
       for(int i=0;i<str.size();i++)
       {
          if(res[i]!=str[i])
          {
              f=false;
              cout<<0<<endl;
              break;
          }
       }
       if(f)
        cout<<1<<endl;
       }
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/

bool ipOk(int a,int b,int c,int d){
	return a<=255 and b<=255 and c<=255 and d<=255;
}
string generateString(int a,int b,int c,int d){
	return to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
}
vector<string> genIp(string s)
{   
    vector<string> res;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    for(int l=1;l<=3;l++)
                    {
                        if(i+j+k+l==s.length())
                        {
                            int a = stoi(s.substr(0,i));
                            int b = stoi(s.substr(i,j));
                            int c = stoi(s.substr(i+j,k));
                            int d = stoi(s.substr(i+j+k,l));
                            if(ipOk(a,b,c,d))
                            {
                                string str =generateString(a,b,c,d);
                                /*+3 because of 3 dots*/
                                if(str.length()==s.length()+3)
                                {
                                    res.push_back(str);
                                }
                            }
                        }
                    }
                }
            }
        }
    return res;
}
