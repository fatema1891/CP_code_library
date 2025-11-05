#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

 ll N=1e6+7;

bool isBalanced(string s)
{
    stack<char>st;
    for(char c:s)
    {
        if(c=='('||c=='{'||c=='[')st.push(c);
        else
        {
            if(st.empty())return false;
            char top=st.top();
            if((c==')'&&top!='(')||(c=='}'&&top!='{')||(c==']'&&top!='['))
                return false;

            st.pop();
        }
        
    }
    return st.empty();
}

int32_t main()
{
    string s;//if brackets {}, () and []
    cin>>s;
    cout<<"is balanced in this string ? : ";
    cout<<(isBalanced(s)?"YES\n":"NO\n");
}