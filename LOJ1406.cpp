#include<bits/stdc++.h>
using namespace std;
int n,m;
vector < int > adj[17];
int dp[(1<<16) + 10 ];
int dp1[17][(1<<16) + 10];

bool is_pos[(1<<16) + 10 ];

bool vis[17];

bool dfs(int now, int mask)
{

    for(int i =0 ; i < adj[now].size(); i++)
    {
        int v = adj[now][i] ;
        if(!vis[v] and (mask & (1 << v)))
            dfs(v, mask);

    }
}
void precalculation()
{
    for(int mask = 0; mask < (1 << n) ; mask++)
    {
        is_pos[mask] = 0;
        for(int i =0 ; i < n ; i++)
        {
            if(mask & (1 << i))
            {
                memset(vis,0,sizeof vis);
                dfs(i, mask);
                bool f = true;

                for(int x = 0; x < n; x++)
                {
                    if(mask & (1 << x))
                    {
                        if(!vis[x])
                        {
                            f = false;
                            break;
                        }
                    }
                }
                is_pos[mask] |= f ;
            }
        }

    }
}

int DP(int mask)
{
    if(mask == 0)
        return 0;
    int &ret = dp[mask] ;
    if(ret != -1)
        return ret;
    ret = INT_MAX;

    for(int s = mask; s ; s = (s-1) & mask)
    {
        if(is_pos[s])
        {
            ret = min(ret, 1 + DP(mask ^ s) ) ;
        }
    }
    return ret;

}

int main()
{
    int t, c = 0 ;
    cin >> t;
    while(t--)
    {
//        int n,m;
        for(int i = 0; i < 17; i++)
            adj[i].clear();
        memset(dp,-1,sizeof dp);
        memset(dp1, -1,sizeof dp1);
        memset(is_pos, 0, sizeof is_pos);

        scanf("%d %d",&n,&m) ;
        for(int i = 0; i < m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            u--;
            v--;
            adj[u].push_back(v);
        }

        precalculation();
       // cout << "75 " << is_pos[75] << endl;

        printf("Case %d: %d\n",++c, DP((1<<n) - 1 ) );
    }
    return 0;
}
