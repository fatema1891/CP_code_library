
#include<bits/stdc++.h>
using namespace std;

void AllSubseq(int i,vector<int>&v,vector<int>&cur)
{
    if(i==v.size())
    {
        for(int x:cur)
        {
            cout<<x<<" ";
        }
        cout<<'\n';
        return;
    }
    AllSubseq(i+1,v,cur);
    cur.push_back(v[i]);

    AllSubseq(i+1,v,cur);
    cur.pop_back();
}
int main()
{
    int n;
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int >cur;
        
   AllSubseq(0,v,cur);
}

/*explain
n=4 
array:5 6 3 1
output:all subsequence

1 
3 
3 1 
6 
6 1 
6 3 
6 3 1 
5 
5 1 
5 3 
5 3 1 
5 6 
5 6 1 
5 6 3 
5 6 3 1 
