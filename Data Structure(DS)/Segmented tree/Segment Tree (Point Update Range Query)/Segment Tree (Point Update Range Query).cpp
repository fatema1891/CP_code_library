#include<bits/stdc++.h>
using namespace std;
//Segmented tree is the better approach => of prefix sum, difference array(update value of element)

#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
const ll mx= 100001;

ll arr[mx];
ll tree[mx*5];

void init(ll node,ll begin,ll end)// initial segmented tree
{
    if(begin==end)
    {
        tree[node]=arr[begin]; //value of this node
        return;
    }
    ll left=node*2;//left child of this node
    ll right=node*2+1;// right child of this node
    ll mid=(begin+end)/2;// number of mid node
    init(left,begin,mid);//left side subtree of this node
    init(right,mid+1,end);

    tree[node]=tree[left]+tree[right];// value of this node
}

ll query(ll node,ll begin,ll end,ll l,ll r)//sum of i'th index to j'th index element
{
    if(begin>r||end<l)return 0;
    if(begin>=l&&end<=r)return tree[node];
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(begin+end)/2;
    ll sum1=query(left,begin,mid,l,r);
    ll sum2=query(right,mid+1,end,l,r);
    return sum1+sum2;
}

void update(ll node,ll begin,ll end,ll ind,ll val) // change of element of i'th index
{
    if(ind<begin||ind>end)return;

    // ind<begin means index has left subtree of this node,here this begin of right subtree
    // ind>end means index has right subtree of this node,here this end of left subtree

    if(begin>=ind&&end<=ind)//if(begin==end)
    {
        tree[node]=val;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(begin+end)/2;
    update(left,begin,mid,ind,val);
    update(right,mid+1,end,ind,val);
    tree[node]=tree[left]+tree[right];
}
int32_t main()
{
    ll n,i,t,j;
    cin>>n;
    for(i=1;i<=n;i++)cin>>arr[i];

    init(1,1,n);
    cout<<"initial sum index from begin to end before update : ";
    cout<<query(1,1,n,1,n)<<'\n';
    //query(root,begin_index_node,end_index_node,left,right); 
    //sum of left to right index or node
    // here sum of index 1 to n

    ll l,r;
    cin>>l>>r;
    cout<<"sum of l to r index befor update : "<<query(1,1,n,l,r)<<'\n';

    //update m elemnt
    ll ind,val;
    cin>>ind>>val;
    update(1,1,n,ind,val);
    cout<<"sum of l to r index after update : "<<query(1,1,n,l,r)<<'\n';

    
} 
/* input:
n=7
1 2 3 4 5 6 7
l=3 r=6
ind=4 val=10 

 output:

 initial sum index from begin to end before update : 28
sum of l to r index befor update : 18
sum of l to r index after update : 24
*/
