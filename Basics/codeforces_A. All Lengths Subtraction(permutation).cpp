//https://codeforces.com/contest/2143/problem/A
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

int32_t main()
{
    fast;
    ll i,t,j,n,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vl p(n+1);
        ll dif=0;
        for(i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        ll l=1,r=n,f=1;
        for(i=1;i<=n;i++)
        {
            if(p[l]==i)l++;
            else if(p[r]==i)r--;
            else
            {
                cout<<"NO\n";
                f=0;
                break;
            }
        }
       if(f) cout<<"YES\n";
    }

    
}