#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;

const ll mod=1e9+9;
const ll N=3162;
bitset<N+1>prime;

ll numberOfDivisor(ll n)
{
    ll total=1;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll c=0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            total*=(c+1);
        }
    }
    if(n>1)total*=2;
    return total;
}
/*

ll numberOfDivisor(ll n)
{
    ll c=0;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            c++;
            if(i != n/i)c++; //count the pair
        }
    }
    return c;
}*/

ll sumOfDivisor(ll n)
{
    ll totalSum=1;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll c=0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            //geometric serics sum=1+p^1 + p^2 +....+ p^c
            ll sum=1,power=1;
            for(ll j=0;j<c;j++)
            {
                power*=i;
                sum+=power;
            }
            totalSum*=sum;
        }
    }
    if(n>1)totalSum*=(n+1);
    return totalSum;
}

ll sumOfNumOfDivOfDivOfN(ll n)
{
    ll sum=0;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            sum+=numberOfDivisor(i);
            if(i!=n/i)
                sum+=numberOfDivisor(n/i);
        }
    }
    return sum;
}

ll productOfDivisor(ll n)
{
    ll numDiv=numberOfDivisor(n);
    //use long double to hundle large power
    return ceil(double(pow((long double)n, numDiv/2.0)));

    //others any power function also return wrong answer
   
}


int32_t main()
{
    ll t,i,j,n,m;
    cin>>n;
    //1. number of divisor of n////n=12⇒"divisors "{1,2,3,4,6,12},numDiv(12)=6
    cout<<"numDiv("<<n<<") = "<<numberOfDivisor(n)<<'\n';

    //2. sum of divisor of n //σ(12)=1+2+3+4+6+12=28
    cout<<"sumOfDiv("<<n<<") = "<<sumOfDivisor(n)<<'\n';

    //3. sum of (number of divisor(divisor of n))
    cout<<"sumOfNumOfDivOfDivOfN("<<n<<") = "<<sumOfNumOfDivOfDivOfN(n)<<'\n';
    /* n=12
    divisor of 12={1,2,3,4,6,12}
    number of divisor of (divisor of n)=>numDiv(d); numDiv(1)=1,numDiv(2)=2,numDiv(3)=2,numDiv(4)=3,numDiv(6)=4,numDiv(12)=6
    sum of (number of divisor(divisor of n)) =>totalSum= sum of numDiv(d)
    totalSum= numDiv(1) + numDiv(2) + numDiv(3) + numDiv(4) + numDiv(6) + numDiv(12)
            = 1+2+2+3+4+6
            =18 ,ans:
    */

    //4. product of divisor
    cout<<"product of divisors("<<n<<") = "<<productOfDivisor(n)<<'\n';
    /*product of divisor of 12=1*2*3*4*6*12 =1728    or
    number of divisor of 12=6
    so product of divisor of 12=pow(12,6/2)= pow(12,3)=1728
    */



}
