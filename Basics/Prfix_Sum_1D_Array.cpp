#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=vector<ll>;
using vvl=vector<vl>;
//const ll mod= 1e9+7;
#define mx 1e9+7


int32_t main()
{
	fast;
	ll n,w,v,i,j;
     cin>>n;
     ll a[n+5],p[n+5];
     p[0]=0;
     for(i=1;i<=n;i++)
     {
          cin>>a[i];
          p[i]=a[i]+p[i-1];
     }
     for(i=1;i<=n;i++)
     {
          cout<<p[i]<<" ";
     }
     cout<<'\n';
     
     ll l,r,q;
     cin>>q;
     while(q--)
     {
          cin>>l>>r;
          if(l==1)cout<<p[r]<<'\n';
          else cout<<p[r]-p[l-1]<<'\n';
     }
     
}