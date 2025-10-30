//https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
//using segment tree

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;

const ll N=1000009;
ll tree[N*5];
ll n;

ll query(ll node,ll begin,ll end,ll l,ll r)
{
    if(r<begin||l>end)return 0;
    if(l<=begin&&r>=end)return tree[node];
    ll left=node<<1,right=left|1;
    ll mid=(begin+end)>>1;
    ll s1=query(left,begin,mid,l,r);
    ll s2=query(right,mid+1,end,l,r);
    return s1+s2;
}

void update(ll node,ll begin,ll end,ll ind)
{
    if(begin==end)
    {
        tree[node]+=1;
        return;
    }
    ll left=node<<1,right=left|1;
    ll mid=(begin+end)>>1;
    if(ind<=mid)
        update(left,begin,mid,ind);
    else update(right,mid+1,end,ind);
    tree[node]=tree[left]+tree[right];
}

int32_t main()
{
    ll t,i,j,n;
    cin>>n;
    vl p(n+1);
    for(i=1;i<=n;i++)cin>>p[i];
        vl ans(n+1);

    for(i=1;i<=n;i++)
    {
        if(p[i]<n)
            ans[i]=query(1,1,n,p[i]+1,n);
            
        else ans[i]=0;

        update(1,1,n,p[i]);
    }

    for(i=1;i<=n;i++)
    {
        (i<n)?cout<<ans[i]<<' ' : cout<<ans[i]<<'\n';
    }

}
