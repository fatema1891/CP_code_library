#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=vector<ll>;
using vvl=vector<vl>;
//const ll mod= 1e9+7;
#define mx 1e9+7

int fxor(int n)
  {
      int mod=n%4;
      if(mod==0)return n;
      else if(mod==1)return 1;
      else if(mod==2)return  n+1;
      else if(mod==3)return 0;
  }


int32_t main()
{
	fast;
	ll n,q,i,l,r;
     cin>>n>>q;
     ll a[n+5],p[n+5];
     p[0]=0;
     for(i=1;i<=n;i++)
     {
          cin>>a[i];
          p[i]=a[i]^p[i-1];
     }
     while(q--)
     {
         cin>>l>>r; 
         cout<<(p[r] ^ p[l-1])<<'\n';  
     }
    
}
     
