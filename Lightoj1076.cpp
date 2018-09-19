#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up =  5 * 1e5 + 10 ;
int  const up1 = 1e9  ;
using namespace std;
 
 int c[1009], m, n;
 
int can(int mid )
{
     int sum = 0, con= 1;
    for(int i = 1; i <= n; i++)
    {
        if(sum + c[i] <= mid)
        {
            sum += c[i];
           // cout << sum << e ndl;
        }
        else
        {
            sum = c[i];
            con++;
        }
    }
    return con;
}
 
 
 
 
int main()
{
 
   int t, sum, mid, ans, hi, lo;
 
   scanf("%d", &t);
 
   for(int i = 1; i <= t; i++)
   {
       sum = 0;
       scanf("%d %d", &n, &m);
       for(int j = 1; j <= n; j++)
       {  
           scanf("%d", &c[j]);
           sum += c[j];
       }
       hi = sum;
       lo = *max_element(c+1,c+n+1);
       while(lo < hi)
        {
            mid = (lo + hi)/2;
           // printf("loop\n");
            int x = can(mid);
 
            if(x == m){ ans = mid; hi = mid;}
            else
            {
                if(x  < m)
                    hi = mid;
                else
                   lo = mid + 1;
 
            }
           // printf("can -> %d lo -> %d hi -> %d mid ->%d\n", x,lo, hi, mid);
 
        }
        printf("Case %d: %d\n", i,(ans ^ hi)?hi:ans);
 
   }
    return 0;
}