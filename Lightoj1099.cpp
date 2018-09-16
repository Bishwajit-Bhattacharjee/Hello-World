#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > PII ;
#define F first 
#define S second 
#define pb push_back

const int MX = 1e5 + 100;
int dist[MX][3] ;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r",stdin) ;
		freopen("out.txt","w", stdout) ;
	#endif

	int t, c =0 ;
	cin >> t;
	while(t--)
	{
		int n, r;
		scanf("%d %d",&n,&r);
		//vector < PII > edge(r) ;
		vector < PII > edge[MX];
		for(int i =0; i < r; i++)
		{
			int u, v, w;
			scanf("%d %d %d",&u,&v,&w);
			edge[u].pb(PII(w,v));
			edge[v].pb(PII(w,u));

		}

		for(int i = 1; i <= n; i++)
			dist[i][1] = dist[i][2] = 1e9;

		priority_queue< PII , vector < PII > , greater<PII> > pq;

		pq.push(PII(0, 1));
		dist[1][1] = 0;
		while(!pq.empty()){
			PII top = pq.top(); 
			pq.pop();

			if(top.F > dist[top.S][2]){
				continue;
			}

			for(int i =0 ; i < edge[top.S].size(); i++)
			{
				PII next = edge[top.S][i] ;

				if(dist[next.S][1] > top.F + next.F ) {
					dist[next.S][2] = dist[next.S][1] ; //= top.F + next.F ;
					dist[next.S][1] = top.F + next.F ;
					pq.push(PII(dist[next.S][1], next.S));

				}
				else if(dist[next.S][2] > top.F + next.F and dist[next.S][1] != (top.F + next.F)){
					dist[next.S][2] =  top.F + next.F;
					pq.push(PII(dist[next.S][2], next.S));
				}
			}
		}
		printf("Case %d: %d\n",++c, dist[n][2]) ;

	}
	return 0;
}