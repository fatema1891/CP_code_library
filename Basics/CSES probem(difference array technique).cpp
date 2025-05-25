 //Difference Array technique
//https://cses.fi/problemset/result/13038556/
//CSES Problem Set :Restaurant Customers

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 10000000009

int32_t main() {
    fast;
    ll i,n,j,t;
    cin>>n;
    map<ll,ll>dif;
    ll mx=0;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        dif[a]+=1;
        dif[b]-=1;
        mx=max(mx,max(a,b));
    }
    ll ans=0,current=0;
    for(auto it:dif)
        {
            current+=it.second;
            ans=max(ans,current);
        }
        cout<<ans<<'\n';
}
