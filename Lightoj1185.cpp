#include <bits/stdc++.h>
using namespace std;
 
int const MX = 110 ;
#define pb push_back
typedef long long int ll ;
 
vector < int > g[MX];
bool hasOddCycle;
int even, odd ;
bool vis[MX] ;
int clr[MX];
int tot;
void dfs(int node, int color, int lvl)
{
   
    if(clr[node] != -1 and color != clr[node])
        hasOddCycle = 1;
    if(vis[node])
        return ;
    clr[node] = color;
    vis[node] = 1;
    tot++;
    even += !(lvl & 1) ;
    for(int i =0 ; i < g[node].size(); i++)
    {
        int x = g[node][i] ;
        dfs(x,color ^ 1, lvl + 1) ;
       
    }
   
}
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin) ;
    freopen("out.txt","w",stdout) ;
    #endif
 
    int t, c = 0;
    cin >> t;
    while(t--){
        memset(vis, 0, sizeof vis) ;
        memset(clr, -1,sizeof clr) ;
        for(int i = 0; i < MX; i++)
            g[i].clear();
 
        int n, m ;
        scanf("%d %d",&n, &m) ;
        for(int i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d %d", &a,&b);
            g[a].pb(b) ;
            g[b].pb(a) ;
        }
        hasOddCycle = 0;
       
        even = odd = 0;
        tot =0 ;
        dfs(1,0, 0);
        int ans ;
 
        if(hasOddCycle)
        {
            ans = tot;
        }
        else{
            ans = even ;
            int cnt =0 ;
            for(int i = 1; i <= n; i++)
            	cnt += vis[i] ;
            ans -= (cnt <= 1) ;
        }

        printf("Case %d: %d\n",++c, ans);
    }
    return 0;
}