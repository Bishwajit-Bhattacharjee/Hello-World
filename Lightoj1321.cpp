#include <bits/stdc++.h>
using namespace std ;
int const MX = 120;
double prob[MX];
#define F first
#define S second
#define pb push_back
#define PDD pair < double , int >  
vector < PDD > g[MX] ;
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin) ;
        freopen("out.txt","w",stdout);
    #endif
 
    int t, c = 0 ;
 
    cin >> t ;
    while(t--)
    {
        int n, m ;
        double s, k ;
        fill(prob , prob + MX, 0.0) ;
        cin >> n >> m >> s >> k;
       
        for(int i =0 ; i < MX; i++)
            g[i].clear();
 
        for(int i = 0; i < m; i++){
            int u, v;
            double p;
            cin >> u >> v >> p ;
            g[u].pb(PDD(p/100, v));
            g[v].pb(PDD(p/100,u));
        }
 
        priority_queue < PDD > pq;
        pq.push(PDD(1.0, 0));
        prob[0] = 1.0;
 
        while(!pq.empty())
        {
            PDD top = pq.top();
            pq.pop();
 
            if(prob[top.S] > top.F ) continue;
 
            for(int i = 0; i < g[top.S].size(); i++)
            {
                PDD now = g[top.S][i] ;
 
                if(prob[now.S] < prob[top.S] * now.F )
                {
                    prob[now.S] = prob[top.S] * now.F ;
                    pq.push(PDD(prob[now.S],now.S));
                }
            }
        }
       
 
        printf("Case %d: %.9f\n",++c, 2 * k * s / prob[n-1]);
    }
    return 0;
}
