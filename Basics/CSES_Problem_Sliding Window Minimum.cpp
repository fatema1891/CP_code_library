//https://cses.fi/boi24/task/3221

#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

int32_t main()
{
    ll i,n,k,a,b,c,x;
    cin>>n>>k>>x>>a>>b>>c;
    vl v(n+1);
    v[0]=x;
    for(i=1;i<n;i++)
    {
        v[i]=(a*v[i-1] +b)%c;
    }
   deque<ll>dq;
   ll xsum=0;
   for(i=0;i<n;i++)
   {
    while(!dq.empty()&&v[dq.back()]>=v[i])dq.pop_back();

    dq.push_back(i);
    if(dq.front()<=i-k)dq.pop_front();
    if(i>=k-1)xsum ^= v[dq.front()];
   }
    cout<<xsum<<'\n';
}