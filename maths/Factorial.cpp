#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;

int fact(int x){
    
    int ans = 1;
    for(int i=1;i<=x;i++)
    {
        ans*=i;
        ans%=mod;
    }
    return ans;
}
signed main(){
   int x;
   cin>>x;
   cout<<fact(x)<<endl;
   
}

