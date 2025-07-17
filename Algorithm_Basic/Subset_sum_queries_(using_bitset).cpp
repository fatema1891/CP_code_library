

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = long long;
using vl=vector<ll>;
using vll =vector<vl>;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define maxsum 10000

void processQueries(bitset<maxsum>bit,ll query[],ll mq)
{
    for(ll i=0;i<mq;i++)
    {
        ll x=query[i];
        if(x>maxsum)
            {
                cout<<"Empossible , ";
                continue;
            }

        bit[x] ? cout<<"YES, " : cout<<"NO, ";

    }
}

void preProcess(bitset<maxsum>&bit,ll arr[],ll n)
{
    bit.reset();//set all the bits 0
    bit[0]=1;

    for(ll i=0;i<n;i++)
    {
        bit=bit | (bit<<arr[i]);
    }
}

int32_t main() 
{
    fast;
    ll arr[]={4,1,5};
    ll query[]={7,10,9};
    ll n=sizeof(arr)/sizeof(arr[0]);
    ll m=sizeof(query)/sizeof(query[0]);

    bitset<maxsum>bit;
    preProcess(bit,arr,n);
    processQueries(bit,query,m);
}
    
/*
arr[]={4, 1, 5}
query[]={7,9}

output: NO ,YES
the subset of arr (with sum) is not make 7, then output:NO
the subset (4+5=9) is make 9, then output :YES


### how to work of bitset:
bitset<N> ; N bits 0s or 1s
bitset<N>bit =>bit= ....0000000000, there bit[0]=1 so bit=...0000000001

1st step:  formula , bit=bit |(bit<<arr[i])

    bit<<4 means (0000000001)<<4 = 00000010000
    so, bit =bit |(bit<<4)means bit=(00000000001) | (000000010000)=0000000010001
    so had ,bit[0]=1 and bit[4]=1

    so assign bit=000000010001

2nd step:
          (bit<<1) = (000000010001<<1)=000000100010
           bit =bit | (000000100010)=(00000010001) | (0000000100010)
          so bit=0000000110011
          so bit[0]=1,bit[1]=1,bit[4]=1,bit[5]=1

3rd step :
 (bit<<5) = (0000000110011<<5)=0011001100000
           bit =bit | (0011001100000)=(0000000110011) | (0011001100000)
          so bit=0011001110011
          so bit[0]=1,bit[1]=1,bit[4]=1,bit[5]=1,bit[6]=1,bit[9]=1,bit[10]=1


input: query[]={7,9}
bit[7]=0 , so subset is not sum of 7; output :NO
bit[9]=1, so subset is sum ; output : YES


*/

