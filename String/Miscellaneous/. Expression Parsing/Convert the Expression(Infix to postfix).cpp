#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

 ll N=1e6+7;

 ll precedence(char c)
 {
    if(c=='^')return 3;
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
    return -1;
 }

string infixToPostfix(string s)
{
    stack<char>st;
    string result;

    for(char c:s)
    {
        if(isalpha(c))result+=c;
        else if(c=='(')st.push(c);
        else if(c==')')
        {
            while(!st.empty()&&st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();//remove '('
        }
        else
        {
            while(!st.empty()&&precedence(st.top()) >= precedence(c))
            {
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}
int32_t main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<"infixToPostfix : "<<infixToPostfix(s)<<'\n';
    }
}

/*input:
3
(A+(B*C))
((A+B)*(Z+X))
((A+T)*((B-(A+C))^(C+D)))
output:
infixToPostfix : ABC*+
infixToPostfix : AB+ZX+*
infixToPostfix : AT+BAC+-CD+^*
*/