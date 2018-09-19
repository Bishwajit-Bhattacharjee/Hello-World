#include <bits/stdc++.h>
 
using namespace std;
int const MX = 1e2 + 10;
int dp[MX][MX][MX] ;
int ara[MX];
 
int n;
 
int DP(int pos,int left,int right )
{
    if(pos > n)
        return 0;
 
    int &ret = dp[pos][left][right] ;
 
    if(ret != -1)
        return ret;
 
    ret = 0;
 
    if(ara[pos]>= ara[left] && ara[pos] <= ara[right] )
    {
        ret = max(DP(pos+1, pos, right) , DP(pos+1, left, pos) );
        ret++;
    }
   
    ret = max(ret, DP(pos+1 , left, right) ) ;
 
    return ret;
 
}
 
 
int main()
{
    int t,c =0 ;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n) ;
 
        for(int i = 1; i <= n;i++)
            scanf("%d",&ara[i] ) ;
 
        memset(dp,-1,sizeof dp) ;
 
        ara[0] = 0 , ara[n+1] = 2000000;
 
        printf("Case %d: %d\n",++c, DP(1,0 ,n+1) ) ;
    }
 
    return 0;
}
