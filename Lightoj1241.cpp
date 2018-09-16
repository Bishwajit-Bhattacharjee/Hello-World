#include <bits/stdc++.h>
using namespace std ;
#define cil(a, b) ((a) % (b) == 0)? (a) / (b) : (a) / (b) + 1

int main()
{
    int c= 0 , t ;
    scanf("%d",&t) ;
    int last ;
    int now ;
    int ans;
    int n ;
    while(t--)
    {
         scanf("%d",&n);
         last = 2 ;
        // now ;
         ans = 0;
        for(int i = 1 ; i <= n; i++){
            scanf("%d",&now);
             ans += (now - last)?cil(now - last, 5): 0 ;
            last = now ;
        }


//        for(int i = 1; i <= n ; i++)
//        {
//
//        }
        printf("Case %d: %d\n",++c , ans) ;
    }
    return 0;
}
