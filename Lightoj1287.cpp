#include <bits/stdc++.h>
using namespace std;
int const MX = 15;
int edge[MX][MX];
bool vis[MX][1<<MX] ;
double dp[MX][1<<MX] ;
 
int n, w;
 
double DP(int pos, int mask)
{
    if(mask == (1<<n) - 1)
        return 0.0;
    int cnt = 0;
 
    if(vis[pos][mask])
        return dp[pos][mask] ;
 
    vis[pos][mask] = 1;
 
//    for(int i =0;i < n;i++)
//    {
//        if( !(mask & (1<<i) ) && edge[pos][i])
//            cnt++;
//    }
//
//    if(cnt == 0 )
//        return dp[pos][mask] = (double)INT_MIN;
 
    double sum = 0.0;
    cnt = 0;
    for(int i = 0; i < n;i++)
    {
        if(!(mask & (1 << i ) ) && edge[pos][i] )
        {
            double tmp =  ( DP(i , mask | (1<<i)) ) ;
            if(tmp >= 0.0 )
                sum += (tmp + edge[pos][i]),cnt++;
//            else
//                return dp[pos][mask] = (double)INT_MIN;
        }
    }
 
    sum += 5;
   // cout<< "mask " << mask << "     " << sum / cnt << endl;
    if(cnt == 0 ) return dp[pos][mask] = (double)INT_MIN;
 
    return dp[pos][mask] = sum / cnt ;
 
}
int main()
{
    int t,c = 0;
    cin >> t ;
    while(t--)
    {
        memset(edge,0,sizeof edge);
        memset(vis,0,sizeof vis);
 
        cin >> n >> w;
        for(int  i=0 ; i < w; i++)
        {
            int a,b,time;
            scanf("%d %d %d",&a,&b,&time);
            edge[a][b] = time;
            edge[b][a] = time;
 
        }
        printf("Case %d: %.10f\n",++c, max( DP(0,1) , 0.0)) ;
    }
    return 0;
}
