//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;

const ll N=100006;
 
ll tree[N*5],arr[N];

void build(ll node,ll begin,ll end)
{
    if(begin==end)
    {
        tree[node]=arr[begin];
        return;
    }
    ll left=node<<1, right=left | 1;
    ll mid=(begin+end)>>1;
    build(left,begin,mid);
    build(right,mid+1,end);
    tree[node]=min(tree[left],tree[right]);
}
void update(ll node,ll begin,ll end,ll ind,ll val)
{
    if(ind>end||ind<begin)return ;
    if(ind>=end&&ind<=begin)
    {
        tree[node]=val;
        return;
    }
    ll left=node<<1,right=left |1;
    ll mid=(begin+end)>>1;
    update(left,begin,mid,ind,val);
    update(right,mid+1,end,ind,val);
     tree[node]=min(tree[left],tree[right]);
}
ll query(ll node,ll begin,ll end,ll l,ll r)
{
    if(l>end||r<begin)return INT_MAX;
    if(l<=begin&&r>=end)
    {
        return tree[node];
    }
    ll left=node<<1,right=left |1;
    ll mid=(begin+end)>>1;
    ll mn1=query(left,begin,mid,l,r);
    ll mn2=query(right,mid+1,end,l,r);
    return min(mn1,mn2);
}

int32_t main()
{
    ll n,m,i,j,k,a,b;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>arr[i];

        build(1,0,n-1);
    while(m--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll ind,val;//i, u
            cin>>ind>>val;
            update(1,0,n-1,ind,val);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r-1)<<'\n';
        }
    }
}