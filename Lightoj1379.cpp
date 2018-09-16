#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second 
#define pb push_back
int const MX = 2e4 + 100;
typedef long long int ll;
#define PLL pair < ll, ll > 
vector < PLL > g[MX], gr[MX] ;
ll dist[MX][3];

void dijkastra(int node,int id)
{
	dist[node][id] = 0;
	priority_queue < PLL,vector<PLL>,greater<PLL> > pq;

	pq.push(PLL(0,node));

	while(!pq.empty()){
		PLL top = pq.top();
		/*if(id)
			cout <<" PQ.TOP -_- "<< top.S << " " << top.F << endl;*/
		pq.pop();
		if(dist[top.S][id] < top.F)
			continue;
		if(id == 0){
			for(int i = 0; i < g[top.S].size();i++){
				PLL now = g[top.S][i];
				if(dist[now.S][id] > dist[top.S][id] + now.F ){
					dist[now.S][id] = dist[top.S][id] + now.F;
					pq.push(PLL(dist[now.S][id], now.S)) ;
				}
			}
		}
		else {
			// cout << "node " << node << " :" << endl;
			
			for(int i = 0 ; i < gr[top.S].size(); i++){
				PLL now = gr[top.S][i] ;
				// cout << now.S << endl;
			
				if(dist[now.S][id] > dist[top.S][id] + now.F){
					dist[now.S][id] = dist[top.S][id] + now.F;
					pq.push(PLL(dist[now.S][id], now.S)) ;
				}
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int test,caseno = 0;
	cin >> test;
	while(test--){
		ll n,m,s,t,p;
		scanf("%lld %lld %lld %lld %lld",&n,&m,&s,&t,&p);
		
		for(int i = 0 ; i < MX;i++)
			dist[i][0] = dist[i][1] = 1e9, g[i].clear(), gr[i].clear();

		for(int i = 0; i < m;i++)
		{
			ll u,v,c;
			scanf("%lld %lld %lld",&u,&v,&c);
			g[u].pb(PLL(c,v));
			gr[v].pb(PLL(c,u));
		} 
		dijkastra(s,0);
		dijkastra(t,1);

		/*for(int i = 1; i <= n; i++)
		{
			cout << i << " has edge with : " ;
			for(auto x : gr[i])
			{
				cout << x.S << " "  << x.F  << endl ;
			}
			cout << endl;
		}*/

		ll ans = -1;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < g[i].size(); j++){
				PLL cur = g[i][j] ;
				/*cout << "edge " << i << " " << cur.S << " " << cur.F << endl;
				cout << dist[i][0] << " " <<  dist[cur.S][1] + cur.F << endl ; // <= p*/
				if(dist[i][0] + dist[cur.S][1] + cur.F <= p )
				{
					ans = max(ans, cur.F) ;
				}
			}
		}
		printf("Case %d: %lld\n",++caseno, ans);
	}
	return 0;
}