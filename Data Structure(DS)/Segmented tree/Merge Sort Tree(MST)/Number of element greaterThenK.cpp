//Merge sort tree(prepaid)
//https://www.spoj.com/problems/KQUERY/

#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

const ll N=100009;

ll n;
vl tree[N*5];
//tree will be take vector ,because this form : tree[left].begin(),tree[left].end()  is vector form 
ll arr[N];

void build(ll node,ll begin,ll end)
{
    if(begin==end)
    {
        tree[node]={arr[begin]};
        return ;
    }
    ll left=node<<1,right=left|1,mid=(begin+end)>>1;
    build(left,begin,mid);
    build(right,mid+1,end);

    merge(tree[left].begin(),tree[left].end(),  tree[right].begin(),tree[right].end(),  back_inserter(tree[node]));
}


//count numbers >x in range [l,r]
ll query(ll node,ll begin,ll end,ll l,ll r,ll x)
{
    if(l>end||r<begin)return 0;
    if(l<=begin&&r>=end)
    {
        return upper_bound(tree[node].begin(),tree[node].end(),x)-tree[node].begin();
    }
    ll left=node<<1,right=left|1,mid=(begin+end)>>1;
    ll count1=query(left,begin,mid,l,r,x);
    ll count2=query(right,mid+1,end,l,r,x);
    return count1+count2;
}

int32_t main()
{
    fast;
    ll t, i,q;
        cin>>n;
        for(i=0;i<n;i++)cin>>arr[i];
            build(1,0,n-1);
        cin>>q;
        while(q--)
        {
            ll l,r,x;
            cin>>l>>r>>x;
            l--,r--;//convert to 0-index
            ll ans=query(1,0,n-1,l,r,x);//count_number <=k
            
             cout<<(r-l+1)-ans<<'\n';//count_greater(>k) = total_elements_in_range - count_less_equal_k
            
        }
}


