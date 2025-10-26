#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

const ll N=1000;

ll n;
ll tree[N][N],arr[N][N];


void update(ll x,ll y,ll val) // add value at index
{
    for(ll i=x ;i<=n;i+=(i & -i))
    {
        for(ll j=y ;j<=n;j+=(j & -j))
        {
            tree[i][j]+=val;
        }
    }
}
ll query(ll x,ll y)
{
    ll res=0;
    for(ll i=x ;i>0;i-=(i & -i))
    {
        for(ll j=y ;j>0;j-=(j & -j))
        {
            res+=tree[i][j];
        }
    }
    return res;
}

ll querySum(ll x1,ll y1,ll x2,ll y2)
{
    return query(x2,y2)
            - query(x2,y1-1)
            - query(x1-1,y2)
            + query(x1-1,y1-1);
}

int32_t main()
{
    fast;
    ll t, i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++){
        cin>>arr[i][j];
        update(i,j,arr[i][j]);
        }
    }

    cin>>t;
    while(t--)
    {
        ll type, a,b;
        cin>>type;
        if(type==1)
        {
            ll x,y,val;
            cin>>x>>y>>val;
            update(x,y,val);
        }
        else
        {
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<querySum(x1,y1,x2,y2)<<'\n';
        }
    }

}
/*input:
5
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5
3
2 1 1 4 4
1 3 3 10
2 1 1 4 4
  
output:
80
90
*/