#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int const MX = 5e4 + 100;
int edge[MX];
vector < int > er[MX] ;
int vis[MX];
stack < int > stk;
 
void topDFS(int node)
{
    vis[node] = 1;
    if(!vis[edge[node]])
        topDFS(edge[node]);
    stk.push(node);
}
 
int Map[MX];
int scount[MX];
int id ;
void SCC(int node)
{
    vis[node] = 1;
    Map[node] = id;
    for(int i =0; i < er[node].size();i++)
    {
        int v = er[node][i];
        if(!vis[v]){
            SCC(v);
        }
    }
}
 
int dp[MX];
 
int DP(int node)
{
    int &ret = dp[node];
    if(ret != -1)
        return ret;
    ret = 0;
 
    for(int i = 0 ; i < er[node].size();i++)
    {
        int v = er[node][i];
        ret = max(ret, DP(v));
    }
    ret = ret + scount[node];
    return ret ;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
 
    int t, c = 0;
    cin >> t;
    while(t--){
        int n;
        id = 0;
        scanf("%d",&n);
        for(int i = 0; i < MX; i++)
            er[i].clear();
 
        for(int i =0 ; i < n; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            edge[a] = b;
            er[b].pb(a);
        }
        memset(vis,0,sizeof vis);
        memset(scount,0,sizeof scount);
 
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
                topDFS(i);
        }
        memset(vis,0,sizeof vis);
        memset(dp,-1,sizeof dp);
 
        while(!stk.empty()){
            int cur = stk.top();
            stk.pop();
            if(!vis[cur]){
                ++id;
                SCC(cur);
            }
        }
 
        for(int i = 0; i < MX; i++)
            er[i].clear();
       
        for(int i = 1; i <= n;i++)
        {
            int next = edge[i] ;
            if(Map[i] != Map[next]){
                er[Map[i]].pb(Map[next]);
            }
        }
        for(int i = 1; i <= n;i++)
            scount[Map[i]]++;
 
        int ans = -1, id = -1;
        for(int i = 1; i <= n; i++)
        {
            int tmp = DP(Map[i]);
            //cout << i << " Map[id] " << Map[i] << " value " <<  tmp << endl;// <<
            if(tmp > ans){
                ans = tmp;
                id = i;
            }
        }
        printf("Case %d: %d\n",++c,id);
    }
    return 0;
}
