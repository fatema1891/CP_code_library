//https://www.spoj.com/problems/NAJPF/
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using vl=std::vector<ll>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)


void z_alg(string s,string p)
{
    string str=p+"#"+s;
    ll n=str.size(),m=p.size(),i,j;
    vl z(n+1,0);
    ll l=0,r=0;
    for(i=1;i<n;i++)
    {
        if(r>=i)z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n&&str[z[i]]==str[i+z[i]])z[i]++;
        if(z[i]+i-1>r)r=z[i]+i-1,l=i;
    }
    vl ans;
    for(i=1;i<n;i++)
    {
        if(z[i]==m)ans.push_back(i-m);
    }
    if(ans.empty())cout<<"Not Found\n";
    else 
    {
        cout<<ans.size()<<'\n';
        for(i=0;i<ans.size();i++)
        {
            if(i==ans.size()-1)cout<<ans[i]<<'\n';
            else cout<<ans[i]<<' ';
        }
    }
}

int32_t main()
{
  fast;
  ll t,i,j,n,m;
  cin>>t;
  string s,p;
 for(i=1;i<=t;i++)
  {
    cin>>s>>p;
    z_alg(s,p);
  }
  
}