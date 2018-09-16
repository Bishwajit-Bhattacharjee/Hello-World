#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[110][110][110];
string a, b, c;
int const mod = 1e9 + 7;

//ll DP(int i ,int j,int k)
//{
//
//
//    if(k == c.size() )
//    {
//        return 1;
//    }
//    if(j >= b.size() && i >= a.size() )
//        return k >= c.size();
//    if(j >= b.size())
//    {
//        if()
//            ret =
//    }
//    ll &ret = dp[i][j][k] ;
//
//    if(ret != -1)
//        return ret;
//
//    ret = 0;
//
//    if(a[i] == c[k] && b[j] == c[k])
//    {
//        ret =  ( DP(i+1,j,k+1) + DP(i,j+1,k+1) + DP(i+1,j+1,k) ) % mod;
//    }
//    else if(a[i] == c[k])
//    {
//        ret = DP(i+1,j,k+1) + DP(i+1,j,k) ;
//        ret %= mod;
//    }
//    else if(b[i] == c[k])
//    {
//        ret = DP(i,j+1,k+1) + DP(i,j+1, k) ;
//        ret %= mod;
//    }
//    else
//    {
//        ret = DP(i+1,j,k) + DP(i,j+1, k) - DP(i+1,j+1, k) ;
//        ret = (ret + mod) % mod;
//    }
//    return ret;
//}
int main()
{
    int t,caseno =0 ;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
//        memset(dp,0,sizeof dp);
        for(int i = 0 ; i <= a.size(); i++)
        {
            for(int j = 0; j <= b.size(); j++)
                dp[i][j][0] = 1;
        }
        for(int k = 1 ; k <= c.size(); k++)
            dp[0][0][k] = 0;

        for(int i = 0; i <= a.size(); i++)
        {
            for(int j = 0; j <= b.size() ; j++)
            {
                for(int k = 1; k <= c.size(); k++)
                {
                    ll &ret = dp[i][j][k] ;
                    if(!i && !j)
                        continue;
                    else if(i && !j)
                    {
                        ret = dp[i-1][j][k] ;
                        if(a[i-1] == c[k-1])
                            ret += dp[i-1][j][k-1] ;
                        if(ret >= mod )
                            ret -= mod ;
                    }
                    else if(!i && j)
                    {
                        ret = dp[i][j-1][k] ;
                        if(b[j-1] == c[k-1])
                            ret += dp[i][j-1][k-1] ;
                        if(ret >= mod)
                            ret -= mod;
                    }
                    else if(a[i-1] == c[k-1] && b[j-1] == c[k-1])
                    {
                        ret = dp[i-1][j][k-1] ;
                        ret += dp[i][j-1][k-1];
                        if(ret >= mod)
                            ret -= mod ;
                        ret += dp[i-1][j-1][k] ;
                        if(ret >= mod)
                            ret -= mod ;
                        ret +=
                    }
                    else if(a[i-1] == c[k-1])
                    {
                        ret = dp[i-1][j][k-1] ;
                        ret += dp[i-1][j][k] ;
                        if(ret >= mod)
                            ret -= mod ;
                    }
                    else if(b[j-1] == c[k-1])
                    {
                        ret = dp[i][j-1][k-1];
                        ret += dp[i][j-1][k] ;
                        if(ret >= mod)
                            ret -= mod ;
                    }
                    else
                    {
                        ret = dp[i-1][j][k] ;
                        ret += dp[i][j-1][k] ;

                        ret = (ret + mod - dp[i-1][j-1][k] ) % mod ;
                    }

                }
            }
        }
        for(int i = 1; i <= a.size();i++)
        {
            for(int j = 1; j <= b.size(); j++)
                for(int k = 1; k <= c.size(); k++)
                    cout << i << " " << j << "  "<< k << "  " << dp[i][j][k] << endl;
        }

        printf("Case %d: %lld\n",++caseno,dp[a.size()][b.size()][c.size()]);
    }
    return 0;
}
