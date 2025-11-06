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

 string PrefixToInfix(string s)
 {
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--)
    {
        char c=s[i];
        if(isOperator(c))
        {
            string op1=st.top();st.pop();
            string op2=st.top();st.pop();
            string temp="("+op1+c+op2+")";
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
        cout<<"Prefix To Infix : "<<PrefixToInfix(s)<<'\n';
    }
 }
 /*
 input:
 3
+A*BC
*+AB+ZX
*+AT^-B+AC+CD
output:
Prefix To Infix : (A+(B*C))
Prefix To Infix : ((A+B)*(Z+X))
Prefix To Infix : ((A+T)*((B-(A+C))^(C+D)))
*/
