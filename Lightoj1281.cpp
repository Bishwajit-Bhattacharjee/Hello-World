#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define pb push_back
int const MX = 2e4 + 100;
int dist[MX][12] ;
 
struct edge
{
    int v, w, type;
    edge() {}
    edge(int a, int b, int c):v(a),w(b),type(c){
 
    }
 
    bool operator<(const edge &rhs)const
    {
        if(w == rhs.w){
            return v > rhs.v;
        }
        return w > rhs.w ;
    }
};
 
struct dat
{
    int w, v, d;
    dat(int a, int b, int c):w(a),v(b),d(c){
 
    }
 
    bool operator<(const dat &rhs)const{
        if(w == rhs.w)
            return v > rhs.v;
        return w > rhs.w ;
    }
};
 
vector < edge > g[MX] ;
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
 
    int t, c =0;
    cin >> t;
 
    while(t--)
    {
 
        int n, m , k, d;
        cin >> n >> m >> k >> d;
 
        for(int i =0 ;i <= n; i++)
            g[i].clear() ;
 
        for(int i =0; i < MX; i++)
            for(int j = 0; j <= 10 ; j++)
                dist[i][j] = 1e9 ;
 
        for(int i =0 ; i < m; i++)
        {
            int a, b, c ;
            scanf("%d %d %d",&a,&b,&c);
            g[a].pb(edge(b,c,0)) ;
        }
 
        for(int i =0 ;i < k; i++){
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            g[a].pb(edge(b,c,1));
        }
 
        priority_queue < dat > pq;
        pq.push(dat(0,0,0));
 
        dist[0][0] = 0 ;
        while(!pq.empty())
        {
            dat top = pq.top();
            pq.pop();
            assert(dist[top.v][top.d] >= 0 ) ;
            if(dist[top.v][top.d] < top.w ) continue;
 
 
 
            for(int i =0 ; i < g[top.v].size(); i++){
                edge tmp = g[top.v][i] ;
                if(top.d + tmp.type > d ) continue;
 
                //cout << dist[tmp.v] << " " << dist[top.v] + tmp.w << endl;
 
                if(dist[tmp.v][top.d + tmp.type] > dist[top.v][top.d] + tmp.w){
                    dist[tmp.v][top.d + tmp.type] = dist[top.v][top.d] + tmp.w;
                    pq.push(dat(dist[tmp.v][top.d + tmp.type],tmp.v, tmp.type + top.d)) ;
                }
            }
        }
        int ans = 1e9 ;
        for(int i =0 ; i <= d; i++)
           ans = min(ans, dist[n-1][i]) ;//, dist[n-1] + d ) ;
        if(ans >= (int)1e9 ){
            printf("Case %d: Impossible\n",++c);
        }else
            printf("Case %d: %d\n",++c, ans ) ;
    }
    return 0;
}
 
