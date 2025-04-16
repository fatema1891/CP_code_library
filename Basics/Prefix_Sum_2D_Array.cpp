#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)


int32_t main()
{
    fast;
    ll t,n,i,j,m,q,l,r,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll a[n+5][m+5];
        ll p[n+5][m+5];
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
              cin>>a[i][j];
              p[i][j]=a[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1]; 
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cout<<p[i][j]<<" ";
                cout<<'\n';
        }

        cin>>q;
        ll l1,r1,l2,r2;
        while(q--)
        {
            cin>>l1>>r1>>l2>>r2;   // sum of square 
            cout<<(p[l2][r2]-p[l1-1][r2]-p[l2][r1-1]+p[l1-1][r1-1])<<'\n';
        }
    }
    
}
