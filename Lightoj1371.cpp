#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll;
int cap[1010];
int wgt[1010] ;
const int mod = 1e9 + 7 ;

int main()
{
    int t, c = 0;
    scanf("%d" ,&t);
    while(t--){
        int n ;
        scanf("%d",&n) ;
        for(int i = 0 ; i < n; i++)
            scanf("%d",&wgt[i]) ;
        for(int i =0 ;i < n; i++)
            scanf("%d",&cap[i]);
        ll ans = 1LL;
        sort(wgt , wgt + n) ;
        sort(cap, cap + n ) ;
        for(int i = 0; i < n ; i++){
            ll tmp = (upper_bound(wgt , wgt+ n , cap[i]) - wgt )+ 1 ;
            ans = (ans *1LL* (tmp - i -1 )) % mod ;

        }

        printf("Case %d: %lld\n",++c , ans ) ;
    }

    return 0;
}
