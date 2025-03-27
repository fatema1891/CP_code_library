#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vvl=vector<vl>;

void primeFact(ll n)
{
	cout<<n<<"=> ";
	ll c=0;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			 c++;
			while(n%i==0)
			{
				n/=i;
			}
			//cout<<i<<", ";
		}
	}
	if(n>1)c++; //cout<<n<<" ,"
	cout<<"the number of difference prime factor = "<<c<<'\n';
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