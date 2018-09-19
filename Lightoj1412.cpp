#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 100;
 
vector < int >  g[MX] ;
//int dist[MX] ;
int vis[MX] ;
 
int nf ;
int df;
vector < int > visited;
int ans[MX] ;
 
int dfs(int node, int dist)
{
    int sub = 1;
    vis[node] = 1;
    for(int i = 0; i < g[node].size(); i++)
    {
        int x = g[node][i] ;
        if(!vis[x])
        {
            sub += dfs(x, dist + 1) ;
        }
    }
    if(dist > df)
    {
        df = dist ;
        nf = node;
    }
    visited.push_back(node) ;
    return sub;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r",stdin) ;
        freopen("out.txt","w", stdout) ;
    #endif
 
    int t ,c = 0;
    cin >> t;
   
 
    while(t--)
    {
        for(int i = 0; i < MX; i++)
            g[i].clear();
        memset(vis, 0,sizeof vis) ;
 
        int n , m ;
        scanf("%d %d",&n,&m) ;
        for(int i = 0 ; i < m; i++)
        {
            int a, b;
            scanf("%d %d",&a,&b) ;
            g[a].push_back(b) ;
            g[b].push_back(a) ;
 
        }
        vector < pair < int , int > > help ;
 
        for(int cunt = 1; cunt <= n; cunt++)
        {
            if(!vis[cunt]){
                df = -1e9 ;
                nf = -1;
                int sub = dfs(cunt, 0) ;
                for(int i = 0; i < visited.size(); i++){
                    int cur = visited[i] ;
                    vis[cur] = 0;
                }
                df = -1e9 ;
                visited.clear();
                dfs(nf, 0) ;
                help.push_back(make_pair(df, sub));
            }
        }
 
        sort(help.begin(), help.end(), greater < pair < int, int > > ()) ;
 
        /*for(auto x : help )
        {
            cout << "help" << endl;
            cout << x.first << " " << x.second << endl;
        }*/
 
        int id = 0;
        for(int i = 1; i < MX; i++)
        {
 
            while(id < help.size() and help[id].second < i )
                id++;
            if(id == help.size())
                ans[i] = -1;
            else{
                if(i <= help[id].first + 1 )
                    ans[i] = i - 1;
                else
                    ans[i] = 2 * (i - 1 ) - help[id].first ;
            }
           
        }
        printf("Case %d:\n",++c);
        int k;
        cin >> k;
        while(k--){
            int x;
            scanf("%d", &x) ;
            if(ans[x] != -1)
            {
                printf("%d\n",ans[x]);
            }else{
                printf("%s\n","impossible");
            }
        }
    }
    return 0 ;
}
