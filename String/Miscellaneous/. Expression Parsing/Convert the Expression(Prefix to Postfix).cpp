#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

 ll N=1e6+7;
 bool isOperator(char c)
 {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
 }

 string PrefixToPostfix(string s)
 {
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--)
    {
        char c=s[i];
        if(isOperator(c))
        {
            string op1=st.top();st.pop();
            string op2=st.top();st.pop();
            string temp=op1+op2+c;
            st.push(temp);
        }
        else st.push(string(1,c));//string(size , char )
    }
    return st.top();
 }

 int32_t main()
 {
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<"Prefix To postfix : "<<PrefixToPostfix(s)<<'\n';
    }
 }
 /*
 input:
 3
+A*BC
*+AB+ZX
*+AT^-B+AC+CD
output:
Prefix To postfix : ABC*+
Prefix To postfix : AB+ZX+*
Prefix To postfix : AT+BAC+-CD+^*

*/

