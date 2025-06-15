#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main()
{
	ll n,i,m,p;

	cin>>n;
	//Q1. Find set bit in integer number
	ll c=0,x=n;
	while(x)
	{
		if(x&1)c++;
		x=x>>1;//x=x/2
	}
	cout<<"number of set bit = "<<c<<'\n';

	//Q2. Find only one set bit in integer number (first set bit position)
	x=n;
	if(x==0)cout<<-1<<'\n';//if(!x)
	else
	{
		c=0;
		while(x)
		{
			c++;
			if(x&1){x=x>>1;break;}
			x=x>>1;
		}
		if(x==0)cout<<c<<'\n';// ....8, 4 ,2 , 1 ;2^n ,only one set bit
		else cout<<-1<<'\n';
	}

	//Q3. Find how many times interger number should be divided by two to make it zero

	x=n;
	c=0;
	while(x)
	{
		c++;
		x=x>>1;//x=x/2
	}
	cout<<c<<'\n';

	//Q4. write a program to find whether a number is power of 2( so it has only one set bit)
	ll ans=n&(n-1);//if(ans==0)so it is power of two 
	if(n&&!(n&(n-1)))//if(n&!(ans)) where ans=0
	{
		cout<<n<<" is power of two"<<'\n';
		//cout<<1<<'\n';
	}
	else
	{
       cout<<n<<" is not power of two"<<'\n';
       //cout<<-1;
   }

   //Q5. Find all possible subsequence of a string using power set
   string str;
   cin>>str;
   ll len=str.size();
   m= pow(2,len);
   std::vector<string> v(m);
   for(i=1;i<m;i++)
   {
   	ll j=0;
   	string s="";
   	 x=i;
   	while(x)
   	{
   		if(x&1)s+=str[j];
   		j++;
   		x=x>>1;
   	}
   	v.push_back(s);
   }

   sort(v.begin(),v.end());
   cout<<"subsequence = ";
   for(auto it:v)
   {
   	cout<<it<<' ';
   }
   cout<<'\n';

   //Q6. Check if i'th bit is set or Not.
   cin>>i>>x;
   ll mask =1<<(i-1);
   if(x&mask)cout<<i<<"th is set of "<<x<<'\n';
   else cout<<"not set "<<'\n';

   //Q7. Delete ith bit of a given number
   cin>>x>>i;
   m=~(1<<(i-1));
   x=x&m;
   cout<<x<<'\n';

   //Q8.Delete last set bit of a given number
   cin>>x;
   x=x&(x-1);  //x=5; x=5&4=>101 & 100=100
   cout<<x<<'\n';

   //Q9. Toggle ith bit of a given number
   cin>>x>>i;
   m=1<<(i-1);
   mask=m^x;
   cout<<mask<<'\n';
   //Q10. Number of set bits
   cin>>x;
   ll cnt=0;
   while(x)
   {
   	cnt++;
   	x=x&(x-1);//if(x&1)cnt++;x=x>>1
   }
   cout<<cnt<<'\n';

   //Q11. Counting set bits for every number i in the range 0<=i<=num
   // num=5 ;ans=[0,1,1,2 1 2]
   cin>>x;
   vector<ll>vl;
   for(i=0;i<=x;i++)
   {
   	cnt=0;
   	n=i;
   	while(n)
   	{
   		cnt++;
   		n=n&(n-1);
   	}
   	vl.push_back(cnt);
   }

   for(auto it:vl)
   {
   	cout<<it<<' ';
   }
   cout<<'\n';

   /*
   1. check if a number is even or odd
      if  x & 1 ==1 : odd
      if x & 1 == 0 : even

    2. check if a number is power of 2
       if  x & (x-1) == 0 : power of 2
       if  x (x-1) >0 : not power of 2

    3. playing with the kth bit
       (1<<k)=2^k

       a. check if kth bit is set : x & (1<<k)
       b. Toggle the kth bit : x ^ (1<<k)
       c. set the kth bit : x | (1<<k)
       d.unset the kth bit : x &  ~(1<<k)

    4. Multiply or divide a number by 2^k
       =>multiplication : (x<<k) left shift
       =>division : (x>>k) right shift

    5. Find out x % 2^k
       x & ((1<<k)-1)

    6. Swapping 2 number x and y without a temporary variable
       x= x^y ;{x=x^y,y=y}
       y=x^y ;{ x=x^y,y=x^y^y=x}
       x=x^y ;{x=x^y^x=y,y=x}

    7. no. of set bits in A =x
       no. of set bits in B =y
       no. of set bits in (A^B)=z
       then
        z is even if x+y is even
        z is odd if x+y is odd

        A = 6=110 =x
        B = 7=111 =y
        A^B = x+y - 2^k ; k is number of same bits of A and B

     8. X = A^B^X
        if (X==A)X=B
        if (X==B)X=A

     9. 2 important identities useful i  some cp problem

        a. (A+B)= (A^B) + 2(A&B)
        b. (A+B)= (A|B) + (A&B)

    10. finding no. of set bits in a number x  ; O(1)
      if x is a int : __builtin_popcount(x)
      if x is a long long : __builtin_popcountll(x)

   */
   // 10. last problem solve
   ll pp=5;
   ll vv=__builtin_popcountll(pp);
   cout<<"builtin "<<vv;
}