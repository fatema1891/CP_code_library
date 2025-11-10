 
 // CSES problem https://cses.fi/problemset/task/1620

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=vector<ll>;
using vvl=vector<vl>;
const ll mod= 1e9+7;
#define mx 1e9+7

int32_t main()
{
	fast;
	ll n,t,k,q,i,x;
     cin>>n>>t;
     ll a[n];

     for(i=0;i<n;i++)
     {
          cin>>a[i];
     }
     ll l=0,r=1e18,mid,ans=0;//sort(a,a+n); ll l=0,r=a[0]*t*2,mid,ans=0;  avabe likhleo accepted hobe     //1st a mid jeno mid=a[0]*t hoi
     while(l<=r)
     {
          mid=l+(r-l)/2;  
          ll sum=0;
          for(i=0;i<n;i++)
          {
               sum+=mid/a[i];
               if(sum>=t){break;}
          }
          if(sum>=t)ans=mid,r=mid-1;
          else l=mid+1;
     }
     cout<<ans<<'\n';
    
}
     


