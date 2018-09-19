#include<bits/stdc++.h>
using namespace std;
const int k = 17;
const int MX = 1e5 + 10;
int ST[MX][k + 1] ;
int val[MX];
 
 
int main()
{
//    freopen("in.txt","r", stdin) ;
//    freopen("out.txt","w",stdout);
 
    int t, caseno = 0;
    cin >> t;
    while(t--)
    {
        int n, q;
        scanf("%d %d",&n,&q) ;
        memset(ST,-1,sizeof ST);
        val[0] = 1;
        for(int i = 1; i < n;i++)
        {
            int s, p;
            scanf("%d %d",&p,&s) ;
            ST[i][0] = p;
            val[i] = s;
        }
 
        for(int j = 1; j <= k; j++)
        {
            for(int i = 0; i < n ;i++)
            {
                if(ST[i][j-1] != -1)
                    ST[i][j] = ST[ST[i][j-1]][j-1];
            }
        }
        printf("Case %d:\n",++caseno) ;
       // cout << "pre :" << ST[5][1] << endl;
        while(q--)
        {
            int node,  v;
            scanf("%d %d",&node,&v);
            int now = node;
 
            for(int i = k ; i >=0 ; i--)
            {
 
                if(ST[now][i] != -1 && val[ST[now][i]] >= v )
                    now = ST[now][i] ;
 
            }
            printf("%d\n", now) ;
        }
    }
    return 0;
}
