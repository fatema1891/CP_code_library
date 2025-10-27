
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;

const ll N=1007;
 
ll tree[N],arr[N];

void init(ll node,ll begin,ll end)
{
    if(begin==end)
    {
        tree[node]=arr[begin];
        return;
    }
    ll left=node<<1, right=left |1;// left=node*2,right=node*2 +1
    ll mid=(begin+end)/2;
    init(left,begin,mid);
    init(right,mid+1,end);
    tree[node]=max(tree[left],tree[right]);
}
 
 ll query(ll node ,ll begin,ll end,ll l,ll r)
{
    if(begin>r||end<l)return INT_MIN;
    if(begin>=l&&end<=r)return tree[node];

    ll left=node<<1,right=left |1;
    ll mid=(begin+end)>>1;//mid=(begin+end)/2
    ll mn1=query(left,begin,mid,l,r);
    ll mn2=query(right,mid+1,end,l,r);
    return max(mn1,mn2);
}

void update(ll node,ll begin,ll end,ll ind,ll val)
{
    if(ind>end||ind<begin)return ;
    if(ind<=begin&&ind>=end)
    {
        tree[node]=val;
        return;
    }
    ll left=node<<1, right=left |1;
    ll mid=(begin+end)>>1;
    update(left,begin,mid,ind,val);
    update(right,mid+1,end,ind,val);
    tree[node]=max(tree[left],tree[right]);
}
 
int main() {
    fast;
  int t,i,j,n,m;
 cin>>n;
 for(i=1;i<=n;i++)cin>>arr[i];

init(1,1,n);

ll l, r;
cin>>l>>r;
cout<<"Range Max Query(RMq) before update : "<<query(1,1,n,l,r)<<'\n';

ll ind,val;
cin>>ind>>val;
update(1,1,n,ind,val);
cout<<"Range Max Query(RMq) after update : "<<query(1,1,n,l,r)<<'\n';
   
  return 0;
} 
/*
input: 8 
3 4 6 9 2 1 2 8

 2 7
 4 71
 output:
 Range Max Query(RMq) before update : 9
Range Max Query(RMq) after update : 71
*/