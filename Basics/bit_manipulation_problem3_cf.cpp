//https://codeforces.com/problemset/problem/1514/B

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define  mod 1000000007

ll power(ll n,ll k)
{
    ll ans=1;
    while(k)
    {
        if(k&1)ans=(ans*n)%mod,k--;
        else n=(n*n)%mod,k=k>>1;//k=k/2
    }
    return ans;
}

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    ll n,k,t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll ans=power(n,k);
        cout<<ans<<'\n';

        /* n=3,k=4
        x=1 1 1 0
        y=1 1 0 1
        z=0 0 1 1 

         = 3c1 * 3c1....
         n * n *n.....kth=pow(n,k)
        */
    }
    return 0;
}
