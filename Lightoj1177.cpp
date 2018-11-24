#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
      g[v].emplace_back(E.size() - 1);
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

// BEGIN CUT
// The following code solves SPOJ problem #4110: Fast Maximum Flow (FASTFLOW)

int main()
{
    int t, c = 0;
    cin >> t;
    while(t--)
    {
        int m,w;
        scanf("%d %d",&m,&w);
        //cout << m << endl;
        Dinic dinic(m+m-1);
        vector < int > in(m+2), out(m+2), cap(m+2);
        in[1] = 1, in[m] = m;
        out[1] = 1, out[m] = m;
        //vector < Edge > vv;
        for(int i = 2; i <= m - 1; i++)
        {
            scanf("%d",&cap[i]);
        //    scanf("%d %d",)
        }
//        dinic.AddEdge(0,0,1e9);
//        dinic.AddEdge(m,m,1e9);
        for(int i = 2; i <= m - 1; i++)
        {
            in[i] = i;
            out[i] = m + i;
            dinic.AddEdge(in[i]-1,out[i]-1,cap[i]);
//            vv.emplace_back(in[i]-1,out[i]-1,cap[i]);
//            vv.emplace_back(out[i]-1,in[i] - 1,cap[i]);
            dinic.AddEdge(out[i]-1, in[i] - 1,cap[i]);
        }

        for(int i = 1; i <= w; i++)
        {
            int a,b,cc;
            scanf("%d %d %d",&a,&b,&cc);
            dinic.AddEdge(out[a]-1,in[b]-1,cc);
            dinic.AddEdge(out[b]-1,in[a]-1,cc);
//            vv.emplace_back(out[a]-1,in[b]-1,cc);
//            vv.emplace_back(out[b]-1,in[a]-1,cc);
        }

        printf("Case %d: %lld\n",++c,dinic.MaxFlow(0,m-1)) ;
    }
    return 0;
}
