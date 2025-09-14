//https://judge.yosupo.jp/problem/zalgorithm

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;


int32_t main()
{
    fast;
    ll i,j,n;
    string s;
    cin>>s;
     n=s.size();
    vl z(n,0);
    int l=0,r=0;
    for(i=1;i<n;i++)
    {
        if(i<=r)
        {
            z[i]=min(z[i-l],r-i+1);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    z[0]=n;
    for(i=0;i<n;i++)
    {
        if(i==n-1)cout<<z[i]<<'\n';
        else cout<<z[i]<<' ';
    }
}