 //Difference Array technique

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {
    fast;
    ll i,n,j;
    cin>>n;
    ll a[n+5];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll query,start,end,value;
    ll dif[n+5]={0};//dif={dif[0],.......dif[n+5]}={0,0,....,0}
    cin>>query;
    while(query--)
    {
        cin>>start>>end>>value;
        dif[start]+=value;
        dif[end+1]-=value;
    }
    for(i=1;i<n;i++)dif[i]+=dif[i-1];//prefix sum

    for(i=0;i<n;i++)a[i]+=dif[i];

    for(i=0;i<n;i++)cout<<a[i]<<" ";
   
}
/*
if
n =6
a[]=1 0 2 3 0 5 (i=0......n-1) 
query =2
{
    sum  the value from  start to end index element of array 
    start ,end ,value

    *** brute force:{
  while(query--)  {
    start=2 ,end=4 ,value= 1: a[]=1 0 3 4 1 5
    start=1 z,end=4,value=3 : a[]=1 3 6 7 4 5  OUTPUT: 
    }
 }

**** Difference array techcnique:{
while(query--)
{
    dif[start]+=value, dif[end+1]-=value; because for prefix sum

    start=2 ,end=4 ,value= 1: dif[2]+=1 =>dif[2]=1;dif[4+1]-=1 =>dif[5]=-1;
     start=1 z,end=4,value=3 :dif[1]+=3 =>dif[1]=3; dif[5]-=-4

}
prefix sum of dif array:
dif[]= 0 3 4 4 4 0
final array :
a[]=1 3 6 7 4 5 OUTPUT:
}
*/