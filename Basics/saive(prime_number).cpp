#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mx=90000001;

bool prime[mx];
vl ans;

void sieve()
{
	memset(prime,0,sizeof(prime));
	for(ll i=2;i*i<=mx;i++)
	{
		if(prime[i]==false){
		for(ll j=i*i;j<=mx;j+=i)
		{
			prime[j]=true;
		}
	  }
	}
	for(ll i=2;i<=mx;i++)
	{
		if(prime[i]==0)ans.push_back(i);
	}
}

int32_t main()
{
	ll n,t;
	sieve();
	cin>>t;
	while(t--)
	{
		cin>>n;
	//cout<<"prime number from 1 to n:\n";
	//for(ll i=0;i<=n;i++)cout<<ans[i]<<" ";
	cout<<n<<"th prime number :";
	cout<<ans[n-1]<<'\n';
    }
}