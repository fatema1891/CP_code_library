//https://www.spoj.com/problems/NAJPF/

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod=1e9+7;


int32_t main()
{
    ll t,i,j,n,m;
      string s,p;
        ll prime=31;
        vl power(100005,1);
        for(i=1;i<100005;i++)
        {
            power[i]=(power[i-1]*prime)%mod;
        }
    cin>>t;
    while(t--)
    {
        cin>>s>>p;
        n=s.size(),m=p.size();
        vl hash(n+1,0);
        for(i=0;i<n;i++)
        {
            hash[i+1]=((hash[i]*prime)%mod+s[i])%mod;
        }
        vl pathash(m+1,0);
        for(i=0;i<m;i++)
        {
            pathash[i+1]=((pathash[i]*prime)%mod+p[i])%mod;
        }
        vl ans;
        
        for(i=m;i<=n;i++)
        {
            ll dif=(hash[i]-(hash[i-m]*power[m])%mod+mod)%mod;
            if(dif==pathash[m])ans.push_back(i-m+1);
        }
        if(ans.empty())cout<<"Not Found\n";
        else 
        {
            cout<<ans.size()<<'\n';
            for(i=0;i<ans.size();i++)cout<<ans[i]<<(i+1!=ans.size()? ' ' : '\n');
        }
    }       
    
}
