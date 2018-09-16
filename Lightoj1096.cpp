#include <bits/stdc++.h>
using namespace std ;
int const MX =  4 ;
//int const MOD = 1e9 + 7 ;

typedef long long int ll ;
ll mod ;
ll a , b , c ;

struct  matrix
{

    ll ara[MX][MX] ;

    void setter() {
        memset(ara , 0 , sizeof ara) ;
        ara[0][0] = a , ara[0][2] = b;
        ara[1][0] = ara[2][1] = ara[3][3] = ara[0][3] =  1 ;

        //ara[0][0] = ara[1][0] = ara[0][1] = 1 ;
        //ara[1][1] = 0;

    }

    void init(int number) {
        for(int i = 0 ; i< MX ; i++)
            for(int j = 0; j < MX ; j++)
                ara[i][j] = number ;
    }

    void identity()
    {
        for(int i = 0 ; i < MX ; i++){
            for(int j = 0 ; j < MX ; j++)
                ara[i][j] = (i == j ) ;

        }
    }


};

matrix mul(matrix &a, matrix &b )
{

        matrix tmp ;
        for(int i = 0 ; i < MX  ; i++){
            for(int j = 0 ; j < MX ; j++){
                tmp.ara[i][j] = 0 ;
                for(int k = 0 ; k < MX ; k++){
                    tmp.ara[i][j] += a.ara[i][k]  * b.ara[k][j] ;
                    tmp.ara[i][j] %= mod ;


                }
            }
        }
        return tmp ;


}

matrix bigmod(matrix mat , ll pow )
{
    matrix ans ;
    ans.identity() ;
    matrix tmp ;
    tmp.identity() ;
    //cout << "HK" << endl;

    for(ll i = 0 ; (1LL << i ) <= pow ; i++ ) {

        if(i == 0)
            tmp = mat ;// cout << ans.ara[0][0] << endl ;
        else
            tmp = mul(tmp , tmp ) ;

        if((1LL << i ) & pow )
            ans = mul( ans , tmp )  ;
        // cout << ans.ara[0][0] << endl ;
   // cout << "KH" << endl ;
    }

    return ans ;
}
int main()
{
    int t , caseno = 0;
    cin >> t ;
    while(t--){
            ll n ;

//        ll n , a, b , c ;

        scanf("%lld %lld %lld %lld", &n, &a , &b , &c ) ;
        matrix ans, ans2  ;

        ans.setter() ;
       // cout << ans.ara[0][0] << endl ;
        mod = 10007;
       // while(m--) mod *= 10 ;
      //  cout << mod << endl ;

       // cout << ans.ara[0][0] << endl ;
       if(n < 3 ) {
         printf("Case %d: 0\n", ++caseno ) ;
         continue ;
       }
        ans2 = bigmod(ans , n - 2  ) ;
//        for(int i = 0 ; i < MX ; i++ )
//            for(int j = 0 ; j < MX ; j++)
//                cout << ans2.ara[i][j] << endl ;
      //  cout << ans2.ara[0][3] << endl ;
        printf("Case %d: %lld\n" , ++caseno ,(c * ans2.ara[0][3] ) % mod ) ;

   }
   return 0 ;
}
