#include <bits/stdc++.h>
using namespace std;
 
int d[16][16];
int pre[(1<<14) + 10 ] ;
int dp[(1<<14) + 10 ] ;
 
 
void preCalc(int n)
{
    for(int m = 0 ; m < (1 << n) ; m++)
    {
        pre[m] = 0;
        for(int i =0 ; i < n; i++)
        {
            for(int j =0 ; j < n; j++)
            {
                if((m &(1 << i)) && (m & (1 << j )) )
                    pre[m] += d[i][j] ;
            }
        }
    }
 
}
 
int main()
{
    int c = 0, t;
    cin >> t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i =0 ;i < n;i++)
        {
            for(int j = 0; j < n;j++)
                scanf("%d", &d[i][j]);
 
        }
        preCalc(n);
 
//        for(int i =0 ; i <=n ; i++)
//        {
//            for(int m = 0 ; m < ( 1 << n) ; m++)
//            {
//                dp[i][m] = INT_MAX ;
//            }
//        }
 
//        for(int i = 0 ; i <= n;i++)
//        {
//            for(int m = 0 ; m < (1 << n ) ; m++)
//            {
//                if(i == 0 && m == 0)
//                    dp[i][m] = 0;
//                else
//                    dp[i][m] = INT_MAX;
//
//                for(int s = m;  ; s = (s - 1) & m )
//                {
//
//                    dp[i][m] = min(dp[i][m] , pre[s] + dp[i-1][m^s]) ;
//
//                    if(s == 0) break;
//                }
//
//            }
//
//        }
        dp[0] = 0;
 
        for(int m = 1; m < (1 << n) ; m++)
        {
            int tmp = INT_MAX;
            for(int s = m ; s ; s = (s - 1) & m)
            {
                tmp = min(tmp, pre[s] + dp[m ^ s] ) ;
            }
            dp[m] = tmp;
        }
        printf("Case %d: %d\n", ++c, dp[(1<<n)-1]) ;
    }
    return 0;
}
