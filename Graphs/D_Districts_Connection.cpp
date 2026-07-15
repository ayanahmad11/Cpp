#include <bits/stdc++.h>
// #include"debug.h"
#define ff first
#define ss second 
#define int long long 
using namespace std;

void solve(){
    int n;
    cin>>n;
    int x;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        mp[x].push_back(i+1);
    }
    if(mp.size() == 1)
    {
        cout<<"NO"<<endl;
        return;
    }
    int mn = 1e9,cand = -1;
    for(auto x:mp)
    {
        int sz = x.ss.size();
        mn = min(mn,sz);
        if(mn == sz)
        {
            cand = x.ff;
        }
    }
    // debug(mn);
    // debug(cand);
    // debug(mp);
    cout<<"YES"<<endl;
    // cout<<"cand"<<cand<<endl;
    for(auto z:mp)
    {
        if(z.ff != cand)
        {
            for(int i=0;i<z.ss.size();i++)
            {
                cout<<mp[cand][0]<<" "<<mp[z.ff][i]<<endl; 
            }
        }
    }
   int other = -1;

    for(auto z:mp)
    {
        if(z.ff != cand)
        {
            other = z.ss[0];
            break;
        }
    }

    for(int i=1;i<mp[cand].size();i++)
    {
        cout<<mp[cand][i]<<" "<<other<<endl;
    }
    // cout<<endl;

}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        solve();
    }

}