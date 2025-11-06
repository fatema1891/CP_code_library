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
    for(char c:s)// very care fully 
    {
        if(isOperator(c))
        {
            string op2=st.top();st.pop();// 2nd operand
            string op1=st.top();st.pop();// 1st operand
            string temp=c+op1+op2;
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
        cout<<"Postfix to prefix : "<<PrefixToInfix(s)<<'\n';
    }
 }
 /*
 input:
 4
AB+CD-*
ABC*+
AB+ZX+*
AT+BAC+-CD+^*

output:
Postfix to prefix : *+AB-CD
Postfix to prefix : +A*BC
Postfix to prefix : *+AB+ZX
Postfix to prefix : *+AT^-B+AC+CD

*/
