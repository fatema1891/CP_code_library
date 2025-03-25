#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=vector<ll>;
using vvl=vector<vl>;
#define mx 100001

const ll mod= 1e9+7;

ll power(ll x,ll n)
{
	ll ans=1%mod;
	while(n>0)
	{
		if(n&1)
		{
			ans=(1LL*ans*x )%mod;
		}
		x=(1LL*x*x) % mod;
		n=n>>1;
	}
	return ans;
}


int32_t main()
{
	fast;
	ll t,i,x,y,a,b;
	cout<<power(2,1000000000)<<'\n';
}