#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=vector<ll>;
using vvl=vector<vl>;
const ll mod= 1e9+7;

ll power(ll a,ll n)
{
	ll ans=1;
	while(n)
	{
		if(n%2!=0)ans=(ans*a)%10;
		 a=(a*a)%10;
		n=n>>1;
	}
	return ans;
}


int32_t main()
{
	fast;
	ll t,i,x,y,a,n,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>n;
		cout<<power(a,n)<<'\n';//last digit of a^n 
	}
}