//https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
//using binary indexed tree(Fenwick tree)

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;

const ll N=1000009;
ll tree[N*5];

ll query(ll ind)
{
    ll s=0;
    while(ind>0)
    {
        s+=tree[ind];
        ind-=(ind & -ind);
    }
    return s;
}
void update(ll ind,ll n)
{
    while(ind<=n)
    {
        tree[ind]+=1;
        ind+=(ind & -ind);
    }
}


int32_t main()
{
    ll t,i,j,n;
    cin>>n;
    vl p(n+1);
    for(i=1;i<=n;i++)cin>>p[i];
        vl ans(n+1,0);

    for(i=1;i<=n;i++)
    {
            ans[i]=(i-1)-query(p[i]);
            
        update(p[i],n);
    }

    for(i=1;i<=n;i++)
    {
        (i<n)?cout<<ans[i]<<' ' : cout<<ans[i]<<'\n';
    }

}
