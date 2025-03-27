#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vvl=vector<vl>;

bool prime(ll n)
{
	if(n<2)return false;
	if(n<=3)return true;
	if(n%2==0)return false;
	for(ll i=3;i*i<=n;i+=2)
	{
		if(n%i==0)return false;
	}
	return true;
}

int32_t main()
{
	ll n;
	cin>>n;
	bool pri=prime(n);
	if(pri)cout<<n<<" is prime"<<'\n';
	cout<<n<<" is not prime"<<'\n';
}