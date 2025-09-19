//https://cses.fi/problemset/task/1732

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;


vl creatTempArr(string s)
{
    ll n=s.size();
    vl lps(n);
    ll index=0;
    lps[0]=0;
    for(ll i=1;i<n;i++)
    {
        index=lps[i-1];
        while(index>0&&s[i]!=s[index])
        {
            index=lps[index-1];
        }
        if(s[i]==s[index])++index;
        lps[i]=index;
    }
    /*
    for(ll i=0;i<n;)
    {
        if(s[i]==s[index])
        {
            index++;
            lps[i]=index,i++;
        }
        else
        {
            if(index!=0)index=lps[index-1];
            else lps[i]=0,i++;
        }
    } */
    return lps;
} 
int32_t main()
{
  fast;
  ll i,t,j,n;
  string s;
  cin>>s;
  vl lps=creatTempArr(s);
  n=lps.size();
  vl ans;
  ll bound=lps[n-1];
  while(bound>0)
  {
    ans.push_back(bound);
    bound=lps[bound-1];
  }
  sort(ans.begin(),ans.end());
  for(i=0;i<ans.size();i++)cout<<ans[i]<<' ';
}
  