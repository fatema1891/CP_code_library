#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long int 

void extraLongFactorials(ll  n)
{
    std::vector<ll> digit;
    digit.push_back(1);//0!=1!=1

    for(ll i=2;i<=n;i++)
    {
        ll carry=0;
        for(ll j=0;j<digit.size();j++)//general product(multiplication)
        {
            ll product=digit[j]*i+carry;

            digit[j]=product%10;
            carry=product/10;
        }

        while(carry>0)
        {
            digit.push_back(carry%10);
            carry/=10;
        }
    }

    for(ll i=digit.size()-1;i>=0;i--)
    {
        cout<<digit[i];
    }
    cout<<'\n';
}

int32_t main()
{
    fast;
    ll n;
    cin>>n;
    extraLongFactorials(n);
}