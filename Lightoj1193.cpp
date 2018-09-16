#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD = 1e8 + 7 ;

ll dp[3][15010] ;
ll csum[3][15010];
int main()
{
    int t,c =0 ;
    cin >> t ;
    while(t--){
        int n , k , s ;
        memset(dp,0 ,sizeof dp);
        memset(csum , 0 ,sizeof csum) ;
        scanf("%d%d%d",&n, &k, &s);
        dp[0][0] = 1;csum[0][0] = 1;
        for(int i = 0;i <= s; i++) csum[0][i] = 1;


        for(int i = 1;i <= n ; i++){
            for(int j = 1;j <= s; j++){
                    dp[i&1][0] = 0 ;
                    csum[i&1][0] = 0;
           //     for(int l= 1;l <= k; l++){
                    ll tmp = ( csum[(i-1)&1][j-1] - ((j-k<1)?0:csum[(i-1)&1][j-k-1])- (k*1LL*((j-k<1)?0:dp[(i-1)&1][j-k-1])) + 10000LL * MOD) % MOD;
                    dp[i&1][j] = (dp[i&1][j-1] + tmp) % MOD ;
                    csum[i&1][j] = (csum[i&1][j-1] + dp[i&1][j]) % MOD ;

           //     }
            }
            //cout << "i " << i << endl;
           // for(int j = 1 ;j <)
        }
        printf("Case %d: %lld\n",++c , dp[n&1][s]) ;
    }
    return 0 ;

}
