//https://www.geeksforgeeks.org/problems/search-pattern-z-algorithm--141631/1

#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;


int32_t main()
{
    string txt,pat,str;
    cin>>txt>>pat;
    str=pat+"#"+txt;
    ll n=str.size(),m=pat.size();
    vl z(n,0);
    ll i,R=0,L=0;
    for(i=1;i<n;i++)
    {
        if(i<=R)  // if(i<R) Then will come time limit execeded.
        {
            z[i]=min(z[i-L],R-i+1);
        }
        while(i+z[i]<n && str[z[i]]==str[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]-1>R)
        {
            L=i,R=i+z[i]-1;
        }
    }
    vl ans;
    for(i=0;i<n;i++)
    {
        if(z[i]==m)ans.push_back(i-m-1);
    }

    for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}
/*
pat="geek",txt="geeksforgeeks"
str=geek#geeksforgeeks
   => g e e k # g e e k s f  o  r  g  e  e  k  s
index=0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
*/

