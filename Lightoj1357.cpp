#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MX = 1e5 + 10 ;
ll sub[MX] ;
ll ans ;

vector < int > G[MX] ;
void dfs(int i, int par )
{
  // vis[i] = 1;
   if(G[i].size() == 1 and i != 1 ) {
        sub[i] = 1 ; return ;
   }

   sub[i] = 0;
   for(int x = 0 ; x < G[i].size(); x++){
       if(G[i][x] != par){
           dfs(G[i][x] , i );
           sub[i] += sub[G[i][x]] ;
        }
    }
   sub[i]++ ;
   ll sum = sub[i] - 1 ;
   ll tmp = 0LL;
   for(int x = 0 ; x < G[i].size() ; x++) {
        if(G[i][x] != par) {
           tmp  += (sum - sub[G[i][x]] ) * (sub[G[i][x]]) ;

        }
   }
   tmp  /= 2 ; ans += tmp ;


}
//int dfs1(int i , int par )
//{
//
//    if(G[i].size() == 1 and i != 1)
//        return ;
//
//
//    ll sum = 0;
//    for(int x = 0; x < G[i].size(); x++){
//            if(par != G[i][x]){
//               dfs1(G[i][x], i);
//               sum += 1LL * sub[G[i][x]];
//
//            }
//
//    }
//
//    return sub[i] = sum + 1 ;
//
//}
int main()
{
    int t, c= 0;
    cin >> t ;
    while(t--)
    {
        for(int i = 0; i < MX ; i++) G[i].clear();

        int n ;
        scanf("%d",&n);
        int u , v ;
        for(int i = 1; i <= n - 1; i++){
            scanf("%d %d",&u,&v) ;
            G[u].push_back(v);
            G[v].push_back(u);


        }
        ans = 0LL ;
       // dfs1(1, -1) ;
        dfs(1, -1 ) ;

        printf("Case %d: %d %lld\n", ++c , n-1, ans) ;

    }
    return 0 ;
}
