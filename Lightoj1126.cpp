#include <bits/stdc++.h>
using namespace std ;
int dp[3][500010];
int ara[51] ;
int main()
{
    int t, c =0 ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        int mx = 0;
        for(int i =1; i <= n; i++)
            scanf("%d",&ara[i]), mx += ara[i] ;
       // dp[0][0] = 0 ;
       // memset(dp,, sizeof dp);
       for(int i = 1 ; i <= mx; i++)
            dp[0][i] = -1e9 ;
        dp[0][0] = 0;

       // int mx = *max_element(ara+1,ara+ n+1) ;
       //dp[]
        for(int i = 1 ;i <= n ;i++){
            for(int diff = 0; diff <= mx ; diff++){
//                int tmp = (diff-ara[i]>=0)? diff-ara[i] : ara[i] - diff;
                dp[i&1][diff] = max(max(ara[i] + dp[(i-1)&1][diff+ara[i]] ,
                                  ara[i]+dp[(i-1)&1][abs(diff-ara[i])] ), dp[(i-1)&1][diff]) ;
            }
        }
//        cout << dp[n][0] << endl;
        if(dp[n&1][0]){
            printf("Case %d: %d\n", ++c, dp[n&1][0] / 2 ) ;
        }
        else {
            printf("Case %d: impossible\n", ++c ) ;
        }
    }

    return 0;
}
