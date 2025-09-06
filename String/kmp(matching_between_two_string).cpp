//KMP algorithm (Knuth–Morris–Pratt algorithm
//string pattern matching with others string
#include<bits/stdc++.h>
using namespace std;
using ll =long long int;

using vl=std::vector<ll>;
using st=string;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

vl creatTempArr(string pattern)
{
    ll n=pattern.size();
    vl lps(n+1,0);
    ll index=0;// lenth

    for(ll i=1;i<n; )
    {
        if(pattern[index]==pattern[i])
        {
            lps[i]=index+1;
            index++,i++;
        }
        else
        {
            if(index!=0)index=lps[index-1];
            else lps[i]=0,i++;
        }
    }
    return lps;
}

void kmp(string text,string pattern)
{
    vl lps = creatTempArr(pattern);
    //for(ll i=0;i<pattern.size();i++)cout<<lps[i]<<' ';
    bool found=false;
    ll n=text.size(),m=pattern.size();

    ll i=0,j=0;//i->text,j-> pattern

    while(i<n)
    {
        if(text[i]==pattern[j])
            i++,j++;
        else 
        {
            if(j!=0)j=lps[j-1];
            else i++;
        }

        if(j==m)
        {
            cout<<"pattern found. index = "<<(i-m)<<'\n';
            found=true;
            j=lps[j-1];
        }
    }
    if(!found)cout<<"Not found\n";
}

int32_t main()
{
    fast;
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
   
   kmp(text,pattern);
}