#include <bits/stdc++.h>
using namespace std ;
int cnt[(int)1e6+10] ;
int ara[(int)1e4 + 10 ] ;

int main()
{
    int t , c = 0 ;
    cin >> t ;
    while(t--){
        int n ;
        scanf("%d",&n) ;
        memset(cnt , 0 , sizeof cnt) ;
        for(int i = 1; i <= n ; i++){
            scanf("%d",&ara[i]) ;
        }
        for(int i = 1 ; i <= n ; i++){
            cnt[ara[i]]++;
        }
        bool f = 1 ;
        for(int i = 0; i < n ; i++){
            if(cnt[i] + cnt[n-i-1] != 2 ) {
                f = 0 ;
                break;
            }
        }
        printf("Case %d: %s\n", ++c,f?"yes":"no" ) ;
    }
    return 0;
}
