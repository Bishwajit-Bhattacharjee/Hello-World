#include <bits/stdc++.h>
using namespace std;
 
int const MX = 50000 + 100;
 
vector < int > adj[MX] ;
 
int par[MX] ;
 
int strt ,last;
 
void print(int n)
{
//    if(par[n] == strt)
//    {
//        printf("%d ",strt) ;return;
//
//    }
    if(n == -1) {
        return ;
    }
 
    print(par[n]);
  //  cout << last << endl;
    if(n == last)
        printf("%d\n", n) ;
    else
        printf("%d ", n) ;
 
}
 
int main()
{
    int t, c = 0;
    cin >> t;
    while(t--)
    {
        int n;
        scanf("%d",&n) ;
        printf("Case %d:\n",++c) ;
 
        vector < int > v(n) ;
        for(int i =0 ; i < MX;i++)
            adj[i].clear();
 
        for(int i =0 ; i < n; i++)
            scanf("%d",&v[i]) ;
 
        for(int i = 0 ; i + 1 < n; i++)
        {
            adj[v[i]].push_back(v[i+1]);
            adj[v[i+1]].push_back(v[i]);
 
        }
         strt = v[0];
         last = v[n-1];
 
        memset(par, -1, sizeof par);
 
        queue<int> q;
        for(int i =0 ;i < MX; i++)
        {
            sort(adj[i].begin(),adj[i].end()) ;
 
        }
        q.push(strt);
 
        while(!q.empty())
        {
            int now = q.front();
            if(now == last)
            {
                break;
            }
            q.pop();
            for(int i =0 ; i < adj[now].size(); i++)
            {
                int v = adj[now][i] ;
                if(v != strt and par[v] == -1)
                {
                    q.push(v) ;
                    par[v] = now;
 
                }
            }
 
        }
 
       // cout << par[2] << endl;
        print(last);
 
    }
    return 0;
}
