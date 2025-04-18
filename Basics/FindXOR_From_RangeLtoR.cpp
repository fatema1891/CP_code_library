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
	ll t, n,w,i,l,r;
     cin>>l>>r; //find the xor from the range l to r
        cout<<  (fxor(l-1) ^ fxor(r))<<'\n';//ans=l ^ l+1 ^...^r-1 ^ r;
}
     
