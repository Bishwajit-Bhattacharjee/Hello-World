//HK HK HK HK HK 108 times
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
using namespace std;
const int MX = 3e4 + 100;
vector < PII > G[MX] ;
int d[3][MX] ;
bool vis[MX] ;
int src ;
void  dfs(int node , int id , int tkn)
{

    vis[node] = 1 ;
    d[id][node]  = tkn;
    if(G[node].size() == 1 && node != src ) {
        return ;
    }
    for(int i = 0 ; i < G[node].size();i++){
        if(!vis[G[node][i].F]){
            dfs(G[node][i].F , id , tkn + G[node][i].S ) ;
        }
    }

}
int main()
{
    int t, c =0 ;
    cin >> t ;
    while(t--){
        for(int i =0 ; i < MX ; i++) G[i].clear() ;
        int n ;
        cin >> n ;
        for(int i = 1 ; i < n ; i++){
            int u, v, w ;//tmp ;
            scanf("%d %d %d",&u, &v , &w );// ) ;
            G[u].pb(PII(v,w)) ;
            G[v].pb(PII(u,w)) ;
        }
        memset(vis , 0 , sizeof vis) ;
        src = 0;
        dfs(0,0, 0) ;
        int nxt_id  = max_element(d[0], d[0] + n ) - d[0] ;
        memset(vis , 0 ,sizeof vis) ;
        src = nxt_id ;
        dfs(nxt_id , 1, 0 ) ;
        nxt_id = max_element(d[1] , d[1] + n ) - d[1] ;
        memset(vis , 0 , sizeof vis) ;
        src = nxt_id ;
        dfs(nxt_id , 2, 0 ) ;
        printf("Case %d:\n", ++c) ;
        for(int i = 0; i < n; i++){
            printf("%d\n", max(d[0][i],max(d[1][i] , d[2][i]) )) ;
        }

    }
    return 0;
}
