//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;

const ll N=1000009;
pair<ll,ll>tree[N*5];
ll arr[N];

void build(ll node,ll begin,ll end)
{
    if(begin==end)
    {
        tree[node]={arr[begin],1};
        return ;
    }
    ll left=node<<1,right=left | 1;
    ll mid=(begin+end)>>1;
    build(left,begin,mid);
    build(right,mid+1,end);

    if(tree[left].first==tree[right].first)
    {
        tree[node]={tree[left].first,tree[left].second+tree[right].second};
    }
    else if(tree[left].first<tree[right].first)tree[node]=tree[left];
    else tree[node]=tree[right];
}

void update(ll node,ll begin,ll end,ll ind,ll val)
{
   // if(ind>end||ind<begin)return;
    if(begin==end)
    {
        tree[node]={val,1};
        return;
    }
    ll left=node<<1,right=left | 1;
    ll mid=(begin+end)>>1;
    if(ind<=mid)update(left,begin,mid,ind,val);
    else update(right,mid+1,end,ind,val);
    if(tree[left].first==tree[right].first)
    {
        tree[node]={tree[left].first,tree[left].second+tree[right].second};
    }
    else tree[node]=(tree[left].first<tree[right].first)? tree[left]:tree[right];
}

 pair<ll,ll> query(ll node,ll begin,ll end,ll l,ll r)
 {
    if(r<begin||l>end)return {INT_MAX,0};
    if(l<=begin&&r>=end)
    {
        return tree[node];
    }
    ll left=node<<1,right=left|1;
    ll mid=(begin+end)>>1;
    pair<ll,ll>mn1=query(left,begin,mid,l,r);
    pair<ll,ll>mn2=query(right,mid+1,end,l,r);
    if(mn1.first==mn2.first)return {mn1.first, mn1.second+mn2.second};
     return (mn1.first<mn2.first)? mn1:mn2;
 }

int32_t main() {
    fast;
    ll t,i,n,m,j;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>arr[i];
        build(1,0,n-1);
    while(m--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll ind,val;
            cin>>ind>>val;
            update(1,0,n-1,ind,val);
            
        }

        else{
        ll l,r;
        cin>>l>>r;
        pair<ll,ll>ans=query(1,0,n-1,l,r-1);
        cout<<ans.first<<' '<<ans.second<<'\n';
    }

    }

}
