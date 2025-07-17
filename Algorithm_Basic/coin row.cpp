// find the maximum sum of coins that no two adjacent coins can be selected.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define maxsum 10000
vl f;

ll coin_row(ll coin[],ll n)
{
    if(n==0)return 0;
    if(n==1)return coin[0];
    if(n==2)return max(coin[0],coin[1]);
    f.resize(n+3,0);

    f[0]=0,f[1]=coin[0];
    for(ll i=2;i<n;i++)
    {
        f[i]=max(coin[i]+f[i-2],f[i-1]);
    }

    return f[n-1];
}

int32_t main() 
{
    fast;
    ll coin[]={10, 2, 4, 6, 3, 9, 5};
    ll n=sizeof(coin)/sizeof(coin[0]);

    cout<<"maximum sum of coin without no two  coins adjacent = ";
    cout<<coin_row(coin,n)<<'\n';
    
   
}
    
