#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vvl=vector<vl>;

void primeFact(ll n)
{
	cout<<n<<"= ";
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ll c=0;
			while(n%i==0)
			{
				c++;
				n/=i;
			}
			cout<<i<<"^"<<c<<", ";
		}
	}
	if(n>1)cout<<n<<"^"<<1<<'\n';
	else cout<<'\n';
}


int32_t main()
{
	ll n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		primeFact(n);
	}
}