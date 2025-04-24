
#include<bits/stdc++.h>
using namespace std;
//#define ll long long int
using ll =long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=vector<ll>;
using vvl=vector<vl>;
const ll mod= 1e9+7;
#define mx 1e9+7
bool product(ll w,ll h,ll n,ll x)
{
     ll rec1=x/w;
     ll rec2=x/h;
     ll c=rec1*rec2;
     return c>=n;
}

int32_t main()
{
	fast;
	ll n,w,h,i,x;
     cin>>w>>h>>n;
     ll l=0,r=1,mid,ans=r;
     while(product(w,h,n,r)==false) r*=2;

     while(l<=r)
     {
          mid=l+(r-l)/2;
           if(product(w,h,n,mid))ans=mid,r=mid-1;
            else l=mid+1;
     }
     cout<<ans<<'\n';
    
}
     
