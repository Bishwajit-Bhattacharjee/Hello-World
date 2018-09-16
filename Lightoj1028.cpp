#include <bits/stdc++.h>
#define ll long long int
#define vi vector < int >
#define pb push_back
int const up =  1e6 + 7;
using namespace std;
vector < ll > prime;
vector <bool> mark(up, true);
void seive()
{
   mark[1] = false;
   mark[2] = true;
   int i, j , limit = sqrt(up * 1.0 ) + 2;
   for(int i = 4; i <= up; i+= 2)
    mark[i] = false;
    prime.pb(2);
    for(int i = 3; i <= up; i += 2 )
    {
        if(mark[i])
        {
            prime.pb(i);
            if(i <= limit)
            for (int j = i * i; j  <= up; j += 2 * i)
            {
                mark[j] = false;
            }
        }
    }
}



int main()
{
   ll  t , n;
   seive();
   
   scanf("%lld", &t);

   for(ll x = 1 ; x <= t; x++)
   {
       scanf("%lld", &n);
       ll ret = n;ll ans = 1LL;
       for(ll i = 0; prime[i] * prime[i] <= n; i++)
       {
           ll cnt  = 0;
           if(n % prime[i] == 0)
           {
               while(n % prime[i] == 0)
               {
                   n /= prime[i];
                   cnt++;
               }
               ans *= (cnt + 1);
           }
       }
       if(n > 1)
        ans *= 2;

       printf("Case %lld: %lld\n",x,  ans - 1);
   }
    return 0;
}
