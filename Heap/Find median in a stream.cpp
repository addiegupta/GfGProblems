#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    vector<ll> v;
    ll n;
    cin>>n;

    // Get first number of stream an insert in vector
    ll k;
    cin>>k;
    v.push_back(k);

    // Median is first element
    cout<<k<<endl;

    for (int i = 1; i < n; i++)
    {
        cin>>k;
        int f=0;
        for(int j=0;j<i;j++){
    		// Insert at correct place
            if(k<v[j]){
                v.insert(v.begin()+j,k);
                f=1;
                break;
            }
        }
        // Insert at end
        if(!f) v.push_back(k);

        int s = v.size();

        if(s%2!=0) cout<<v[s/2]<<endl;
        else cout<<floor((v[s/2-1]+v[s/2])/2)<<endl;  
    }
}