#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define emplace_back push_back
struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(u, v, cap);
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(v, u, 0);
      g[v].emplace_back(E.size() - 1) ;
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, c = 0;
    cin >> t;
    map < string , int > mp;
    mp["XXL"] = 0;
    mp["XL"] = 1;
    mp["L"] = 2;
    mp["M"] = 3;
    mp["S"] = 4;
    mp["XS"] = 5;
    //mp["XXL"] = 0;
    //, XL, L, M, S, and XS
    while(t--)
    {
        int n, m;
        //scanf("%d %d",&n,&m);
        cin >> n >> m;
        Dinic dinic(2+n*6+m);
        int S , T ;
        int cur = 6*n;

        for(int i = 0; i < m; i++)
        {
            string a,b;
            cin >> a >> b;
            int val1 = mp[a], val2 = mp[b] ;
            for(int j = 0; j < n; j++)
            {
                dinic.AddEdge(cur,6*j + val1,1);
                dinic.AddEdge(cur,6*j + val2,1);
            }
            cur++;

        }
        S = cur;
        for(int cc = 6*n; cc < cur ; cc++)
        {
            dinic.AddEdge(S,cc,1);
        }
        T = S+1;
        for(int i = 0; i < 6*n; i++)
        {
            dinic.AddEdge(i,T,1);
        }

        LL ans = dinic.MaxFlow(S,T);

        cout << "Case " << ++c << ": " << ((ans == m)?"YES":"NO") << '\n';

    }
    return 0;
}
