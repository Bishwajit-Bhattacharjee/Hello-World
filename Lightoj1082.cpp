#include <bits/stdc++.h>
using namespace std;
 
int const MX = 1e5 + 10;
int ara[MX];
int const k = 17 ;
int ST[MX][k+1];
int const ZERO = (int)(1e5 + 10) ;
int main()
{
    int t , c =0 ;
    cin >> t;
    while(t--)
    {
        int n, q;
        scanf("%d %d",&n,&q);
        for(int i = 1; i <= n;i++) //)
        {
            scanf("%d",&ara[i]) ;
 
        }
        // initializing the array for the 2^0 row with the element itselt
        for(int i = 1; i <= n;i++)
            ST[i][0] = ara[i] ;
 
        for(int j = 1;j <= k ;j++)
        {
            for(int i = 1; i - 1 <= n - (1 << (j)); i++)
            {
                ST[i][j] = min(ST[i][j-1] , ST[i+(1<<(j-1))][j-1] ) ;
            }
        }
        printf("Case %d:\n", ++c) ;
 
        while(q--)
        {
            int ans = ZERO ;
            int l, r;
            scanf("%d %d",&l,&r) ;
            int L = l;
 
            for(int i = k ; i >= 0; i--)
            {
                if(L + (1 << i) - 1 <= r )
                {
                    ans = min(ans, ST[L][i] ) ;
                    L += (1 << i) ;
                }
 
            }
            printf("%d\n",ans) ;
        }
 
 
    }
    return 0 ;
}
