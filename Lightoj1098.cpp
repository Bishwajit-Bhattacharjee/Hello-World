#include <bits/stdc++.h>
using namespace std ;

typedef  long long int llu ;

llu csum(llu n ) {
    return  ( n * (n + 1 ) )/ 2 ;

}

int main()
{
    int t , c =0 ;
    cin >> t ;
    while(t--){
        llu n ;
        scanf("%lld",&n)  ;
        llu la , lb ;
        llu ans = 0;
        llu lim = (llu)( sqrt(n * 1.0 ) + 1e-9 )  ;
        la = lb = 0;
        for(llu i = 1 ; i <= lim ; i++){
            if(i == 1 ) {
                ans += n ;
                la = 1 , lb = n ;
            }
            else {
                ans += i * ( n / i ) ;
                  //cout << ans << ' ' << i << endl;
                ans += la * (csum(lb) - csum(n / i )) ;
               //   cout << ' ' << ans << ' ' << i << endl;
                la = i , lb = n / i ;
               // cout << la << "lb" << ' ' << lb << endl ;

            }
           // cout << i << ' ' << n / i << endl ;

        }
        if(la != lb && ( n > 3 ) ) {
            ans += la * (csum(lb) - csum(la)) ;
        }

        ans -= (n !=0) ? n - 1 : 0 ;
        ans -= (n > 3 ) ? csum(n) : (n != 0) ;

        llu ans2 = 0 ;
//        for(llu i = 1 ; i <= n ; i++)
//            ans2 += i * (n / i ) ;
//
//        ans2 -= ( n + csum(n) );

       // cout << ans << ' ' << ans2 << ' ' << (long long)ans2  - (long long)ans << endl;
        printf("Case %d: %lld\n", ++c , ans ) ;

    }
    return 0 ;

}
