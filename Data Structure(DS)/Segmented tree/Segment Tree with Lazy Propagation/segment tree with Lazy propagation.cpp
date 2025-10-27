//Segment Tree with Lazy Propagation

#include<bits/stdc++.h>
using namespace std;
//Segmented tree is the better approach => of prefix sum, difference array(update value of element)

#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mx= 100001;

ll arr[mx];

struct info{
    ll prop,sum;
} tree[mx*5];

void init(ll node,ll begin,ll end)
{
    if(begin==end)
    {
        tree[node].sum=arr[begin]; 
        return;
    }
    ll left=node*2;//left=node<<1 
    ll right=node*2+1;//right=node<<1 +1 or right =left | 1 
    ll mid=(begin+end)/2;//mid=(begin+end)>>1
    init(left,begin,mid);
    init(right,mid+1,end);

    tree[node].sum=tree[left].sum+tree[right].sum;
}

ll query(ll node,ll begin,ll end,ll l,ll r,ll carry=0)//sum of i'th index to j'th index element
{
    if(begin>r||end<l)return 0;
    if(begin>=l&&end<=r)
        return tree[node].sum+carry*(end-begin+1);

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(begin+end)/2;

    ll sum1=query(left,begin,mid,l,r,carry+tree[node].prop);
    ll sum2=query(right,mid+1,end,l,r,carry+tree[node].prop);

    return sum1+sum2;
}

void update(ll node,ll begin,ll end,ll l,ll r,ll val) // change of element of i'th index
{
    //if(l<begin||r>end)return; //or
    if(l>end||r<begin)return;//outgoing


    if(begin>=l&&end<=r)
    {
        tree[node].sum +=((end- begin+1)*val);
        tree[node].prop +=val;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(begin+end)/2;
    update(left,begin,mid,l,r,val);
    update(right,mid+1,end,l,r,val);
    tree[node].sum=tree[left].sum+tree[right].sum+((end-begin+1)*tree[node].prop);
}
int32_t main()
{
    ll n,i,t,j;
    cin>>n;
    for(i=1;i<=n;i++)cin>>arr[i];

    init(1,1,n);
    cout<<"initial sum index from begin to end before update : ";
    cout<<query(1,1,n,1,n)<<'\n';

    ll l,r;
    cin>>l>>r;
    cout<<"sum of l to r index befor update : "<<query(1,1,n,l,r)<<'\n';

    //update l to r element by val
     ll val;
     cin>>val;
    update(1,1,n,l,r,val);//add value from index l to r
    cout<<"sum of element range from 1 to n index after update : "<<query(1,1,n,1,n)<<'\n';

    cout<<"sum of element range from l to r index after update : "<<query(1,1,n,l,r)<<'\n';
    
} 
/* input:
n=7
1 2 3 4 5 6 7
l=2 r=5
val=4 

 output:

 initial sum index from begin to end before update : 28
sum of l to r index befor update : 14 =>2+3+4+5=14
sum of element range from 1 to n index after update : 44 => 28+ (5-2+1)*4 = 28+16
sum of element range from l to r index after update : 30 => 14+(5-2+1)*4 = 14+16=30
*/

