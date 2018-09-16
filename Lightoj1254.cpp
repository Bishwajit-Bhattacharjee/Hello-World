#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
int const MX = 200 ;

int fuel[MX];
int dist[MX][MX] ;

struct edge
{
	int node, cost;
	edge() {}
	edge(int a, int b):node(a),cost(b){

	}
};

struct dat
{
	int cost, node, fuel ;
	dat(int a, int b, int c):cost(a),node(b),fuel(c){

	}

	bool operator<(const dat &rhs)const{
		if(cost == rhs.cost)
			return fuel > rhs.fuel;
		return cost > rhs.cost ;
	}
};

vector < edge > g[MX] ;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int test, caseno =0;
	cin >> test;

	while(test--)
	{
		int n, m ;
		scanf("%d %d",&n,&m) ;
	
		for(int i =0 ; i < MX; i++)
			g[i].clear();

		for(int i = 0; i < n; i++)
			scanf("%d",&fuel[i]);

		for(int i =0 ; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d %d",&a,&b,&c);
			g[a].pb(edge(b,c)) ;
			g[b].pb(edge(a,c)) ;
		}
		printf("Case %d:\n",++caseno);

		int q;
		cin >> q;
		while(q--)
		{
			int c, s, t;
			scanf("%d %d %d",&c,&s,&t);
			for(int i =0 ; i <= n; i++)
				for(int j = 0 ; j <= c + 10; j++)
					dist[i][j] = 1e9 ;

			priority_queue < dat > pq ;
			pq.push(dat(0,s,0));
			dist[s][0] = 0;

			while(!pq.empty()){

				dat top = pq.top(); 
				pq.pop();

				if(dist[top.node][top.fuel] < top.cost) continue;
				//cout << top.node << " " << top.fuel << endl;
				if(top.fuel < c ){
					if(dist[top.node][top.fuel + 1 ] > dist[top.node][top.fuel] + fuel[top.node]){
						dist[top.node][top.fuel + 1 ] = dist[top.node][top.fuel] + fuel[top.node] ;

						pq.push(dat(dist[top.node][top.fuel + 1 ], top.node, top.fuel + 1)) ;
					}
				}

				for(int i = 0 ; i < g[top.node].size(); i++)
				{
					edge now = g[top.node][i] ;
					
					if(now.cost > top.fuel) continue;

					int &ref = dist[now.node][top.fuel-now.cost] ;
					if(ref > dist[top.node][top.fuel]){
						ref = dist[top.node][top.fuel];
						pq.push(dat(ref, now.node , top.fuel - now.cost));
					}
				}
			}
			int ans = INT_MAX;
			for(int i = 0; i <= c; i++)
			{
				//cout << ans << endl;
				ans = min(ans, dist[t][i]);
			}
			if(ans > (int) 8e8)
			{
				printf("impossible\n");
			}
			else 
				printf("%d\n",ans);
		}
	}	
	return 0;
}