#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long int ll ;
ll dp[55][55][5] ;
ll ans[55][55] ;
bool vis1[55][55] ;
bool vis[55][55][5] ;
int n , m ;
ll DP(int cur , int ls , bool isUp )
{
       // isUp means is the last one was an upper move
    int up = n - cur+1 - ls ;
    if(cur == n ){
        //if(ls > 1 ) return 1;
        //else
        return (isUp and up == 0 and ls == 1) or (!isUp and ls == 0 and up == 1 );
    }

    ll &ret = dp[cur][ls][isUp] ;
    if(vis[cur][ls][isUp]) return ret ;
    vis[cur][ls][isUp] = 1;
    if(isUp){
        //if(ls == 0 and cur == n) return 1 ;

            ret = 0 ;
            for(int i = 1 ; i <= ls ; i++){
                ret += DP(cur+1, i-1 ,!isUp) ;
            }
    }
    else {
        ret = 0;
        if(up < 0 ) return 0;
        for(int i = 1; i <= up ; i++){
            ret += DP(cur+1 ,ls+i-1 ,!isUp) ;
        }
    }

    return ret ;
}
int main()
{
    int t, c =0 ;

    cin >> t ;
    while(t--){

        scanf("%d %d", &n ,&m) ;
        if(vis1[n][m]){
           printf("Case %d: %llu\n", ++c, ans[n][m]);
           continue ;
        }
        memset(vis ,0 , sizeof vis);
        if(m==1){
            if(n < 3){printf("Case %d: 1\n",++c);continue ;
            }

            printf("Case %d: %llu\n", ++c, ans[n][m] = DP(3,1,1));
            vis1[n][m] = 1;
            continue ;
        }
        printf("Case %d: %llu\n", ++c,ans[n][m]= DP(2,m-1,1));
        vis1[n][m] = 1;
//        for(int i = 1 ; i <= n ;i++){
//            for(int j = 1 ; j <= n; j++){
//                printf("i %d j %d : %llu\n",i, j ,dp[i][j][1]) ;
//            }
//        }

    }
    return 0;
}
