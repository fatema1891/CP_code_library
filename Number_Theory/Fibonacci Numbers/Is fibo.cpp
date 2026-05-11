//https://www.hackerrank.com/challenges/is-fibo/problem

#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
using vl=std::vector<ll>;
using vll=vector<vl>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll mod=1e8+7;// without const , ocure error
const ll MAX=1e6+7;

unordered_set<ll>fibo;

void fibonacci()
{
    ll a=0,b=1;
    fibo.insert(a);
    fibo.insert(b);

    while(b<=1e10)
    {
        ll c=a+b;
        fibo.insert(c);
        a=b;
        b=c;
    }
}

int32_t main()
{
    fast;
    ll t,n,i;
    cin>>t;
    fibonacci();
    while(t--)
    {
        cin>>n;
        if(fibo.count(n))cout<<"IsFibo\n";
        else cout<<"IsNotFibo\n";
    }
}
