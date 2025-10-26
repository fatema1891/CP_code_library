#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

const ll N=100009;

ll n;
ll tree[N],arr[N];

void update(ll ind,ll val) // add value at index
{
    while(ind<=n)
    {
        tree[ind]+=val;
        ind+=(ind & -ind);
    }
}
ll query(ll ind)
{
    ll res=0;
    while(ind>0)
    {
        res+=tree[ind];
        ind-=(ind & -ind);
    }
    return res;
}

int32_t main()
{
    fast;
    ll t, i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(i,arr[i]);
    }

    cin>>t;
    while(t--)
    {
        ll type, a,b;
        cin>>type;
        if(type==1)
        {
            ll ind,val;
            cin>>ind>>val;
            update(ind,val);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<"sum of range from l to r : "<<query(r)-query(l-1)<<'\n';
        }
    }

}