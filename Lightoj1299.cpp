#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll const MOD = 1e9 + 7;
int const MX = 1010;
int dp[MX][MX];
 
string s;
 
ll DP(int pos,int cntD)
{
    if(cntD < 0 )
        return 0;
 
    if(pos == s.size())
        return cntD == 0;
 
    int &ret = dp[pos][cntD];
    if(ret != -1)
        return ret;
 
    ret = 0;
    if(s[pos] == 'E')
        ret = DP(pos+1,cntD);
 
    else if(s[pos] == 'U'){
        ret = (1LL*cntD * DP(pos+1,cntD) + DP(pos+1,cntD + 1 ) ) % MOD ;
        //ret %= MOD;
    }
    else{
        ret = (cntD * ( 1LL*cntD * DP(pos + 1,cntD-1) + DP(pos+1,cntD ) )) % MOD ;
 
        //;
    }
    return ret;
 
}
char ara[MX] ;
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,c = 0;
    cin >> t;
    gets(ara);
    while(t--)
    {
        gets(ara);
        memset(dp,-1,sizeof dp);
        s = ara;
   
        printf("Case %d: %d\n",++c, DP(0,0));
 
    }  
 
    return 0;
}
