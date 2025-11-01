#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;
/*
nCr  = [ n! ] / [ (n-r)! * (r!) ]
     = [n*(n-1)*(n-2) ....(n-r+1)] / (r!)
     = this is an integer.
*/

// recursive method for pow(a,b);
int binpow(int a, int b) {
    if (b == 0) return 1;
    int x = binpow(a, b / 2);
    x = (x * x) % mod;
    if (b % 2 == 1) x = (x * a) % mod;
    return x;
}
// iterative way 
int power(int a, int b)
{
    int res = 1;
 
    while(b)
    {
        if(b & 1) res = (res * a) % mod;
 
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
// inverse 
int inverse(int x){
    return power(x,mod-2);
}
// factorial
int fact(int x){
    int ans = 1;
    for(int i=2;i<=x;i++)
    {
        ans = (ans * i) % mod;
    }
    return ans;
}
/* Limitation :   
time complexity ≈ O(n) per query — fine for a single nCr,
but too slow for many queries or large n (like n > 10^6).
mod must be prime.
*/
// Approach - 1
int nCr(int n,int r){ // O(n+r)
    if (r > n || r < 0) return 0;
    int num = fact(n);
    int den = (fact(r) * fact(n-r)) % mod;
    return ( num  * inverse(den)) % mod;
}
// Approach - 2
int single_nCr(int n,int r){ //  O(r) //  better than upper one  
    int num = 1, den = 1;
    for(int i=1;i<=r;i++)
    {
        num = num *(n-i+1) % mod;
        den = ( den * i) % mod;
    }
    return (num * inverse(den)) % mod;
}
// Approach -3
// if ( n<=40 ) and  r<=n ; till 40 as above ll  will overflow.
// simply do  [n*(n-1)*(n-2) ....(n-r+1)] / (r!) //  just divide at each step.
int basic_ncr(int n,int r)
{   //
    int ans =1;  
    for(int i=1;i<=r;i++) // O(40)
    {
        ans = ans * (n-i+1);
        ans =  ans / i; // always gives an Integer.
        // cout<<"ans "<<ans<<endl;
    }
    return ans;
}
// Approach - 4
// if you take the first item, you now need to choose the 
// remaining (r − 1)  items from the remaining (n − 1) items.
// So, number of ways = (n − 1)C(r − 1)

// You do NOT include the first item
// Then you must choose all r items
// from the remaining (n − 1) items.
// So, number of ways = (n − 1)C(r)

int mod2 = 1e9; // random modulo that is not prime.

int ncr[1001][1001];// stores pascasl's triangle

int ncr_randome_modulo(int n,int r){
    ncr[0][0] = 1;  // There's only 1 way of choosing 0 items from 0 items
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j == 0) ncr[i][j] = ncr[i-1][j]%mod2;
            else
                ncr[i][j] =( ncr[i-1][j-1] + ncr[i-1][j])%mod2;
        }
    }
    return ncr[n][r];
}

signed main(){
    int n, r;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;
    cout<<single_nCr(n,r)<<endl;
    cout<<basic_ncr(n,r)<<endl;
    cout<<ncr_randome_modulo(n,r)<<endl;
}   

