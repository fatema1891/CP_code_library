//https://www.spoj.com/problems/NAJPF/
#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mod = 1e9+7;

vl creatTemp(string p)
{
    ll n=p.size();
    vl lps(n,0);
    ll index=0;
    for(ll i=1;i<n;)
    {
        if(p[index]==p[i])index++,lps[i]=index,i++;
        else
        {
            if(index!=0)index=lps[index-1];
            else lps[i]=0,i++;
        }
    }
    return lps;
}


void kmp(string s,string p)
{
    vl lps=creatTemp(p);

    ll n=s.size(),m=p.size();
    ll i=0,j=0,index=0,c=0;
    //or(i=0;i<m;i++)cout<<lps[i]<<' ';
    vl v;
    while(i<n)
    {
        if(s[i]==p[j])i++,j++;
        else
        {
            if(j!=0)j=lps[j-1];
            else i++;
        }
        if(j==m)
            {
                c++;
                v.push_back(i-j+1);
                j=lps[j-1];
            }
    }
    if(v.size()==0)cout<<"Not Found\n";
    else{
    cout<<c<<'\n';
    for(i=0;i<v.size();i++)
        {
            if(i!=v.size()-1)
            cout<<v[i]<<' ';
        else cout<<v[i]<<'\n';
    }
}
}

int32_t main()
{
    fast;
    ll i,t,j,n,b,m;
    cin>>t;
    while(t--)
    {
        string s,p;
        //getline(cin,s);
        //getline(cin,p);
        cin>>s>>p;
        kmp(s,p);
    }
}
