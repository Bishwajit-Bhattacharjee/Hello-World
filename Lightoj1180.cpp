#include <bits/stdc++.h>
using namespace std;
 
int const MX = 100+ 5;
 
int n, m, x[MX], y[MX] ;
int dp[MX][MX] ;
bool vis[MX][MX];
 
int DP(int pos, int sub1, int time)
{
    if(pos < 0)
    {
        if(sub1 <= 0) return 0;
        return INT_MIN ;
    }
    if(vis[pos][sub1])
        return dp[pos][sub1];
 
    vis[pos][sub1] = 1;
 
    int &ret = dp[pos][sub1] ;
 
    ret = INT_MIN ;
    int can1 = time / x[pos] ;
 
    for(int i =0 ; i <= min(can1, sub1); i++)
    {
        int can2 = (time - i * x[pos] ) / y[pos] ;
        ret = max(ret, can2 + DP(pos-1,sub1 - i , time) ) ;
 
    }
 
    return ret;
}
 
bool can(int time)
{
    memset(vis,0,sizeof vis) ;
    return DP(n-1, m, time) >= m ;
}
 
 
int main()
{
    int t, c= 0;
    scanf("%d",&t) ;
 
    while(t--)
    {
        scanf("%d %d",&n,&m) ;
        for(int i = 0 ; i <n; i++)
        {
            scanf("%d %d", &x[i],&y[i]) ;
        }
 
        int ans = 1e8;
        int lo = 0 , hi = 50000;
 
        while(lo <= hi )
        {
            int mid = (lo+ hi) / 2 ;
          //  cout << lo << ' ' << mid << ' ' << hi << endl;
 
            if(can(mid))
            {
                ans = min(ans,mid) ;
                hi = mid - 1;
 
            }
            else
                lo = mid + 1;
        }
 
       // cout << ans << endl;
//        for(int i =0 ; i < 20 ;i++){
//            memset(vis,0,sizeof vis) ;
//            cout << DP(n-1,m, i) << endl;
//
//        }
        printf("Case %d: %d\n",++c , ans);
 
 
    }
    return 0;
 
}
