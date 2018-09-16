#include <bits/stdc++.h>
using namespace std ;
int const MX = 6 ;
//int const MOD = 1e9 + 7 ;

//typedef long long int ll ;
typedef long long  ll;
ll mod ;
ll a1, a2 , b1, b2 , c1 ,c2 ;
struct  matrix
{

    ll ara[MX][MX] ;
    void setter() {
       // cout << -q << endl ;
       memset(ara , 0 , sizeof ara ) ;

        ara[0][0] = a1 ,  ara[0][1] = b1 , ara[0][5] = c1 ;
        ara[1][0] = ara[2][1] = ara[4][3] = ara[5][4] = 1 ;
        ara[3][2] = c2, ara[3][3] = a2 , ara[3][4] = b2 ;
       // ara[1][0] = 1 ;
        //ara[1][1] = 0;

    }

    void init(int number) {
        for(int i = 0 ; i< MX ; i++)
            for(int j = 0; j < MX ; j++)
                ara[i][j] = number ;
    }
    void print()
    {
        for(int i = 0 ; i < MX ; i++) {
            for(int j = 0; j < MX ; j++) {
               cout << ara[i][j] << ' ' ; // printf("%llu ", ara[i][j] ) ;
            }
            cout << endl ;
        }
    }
    void identity()
    {
        for(int i = 0 ; i < MX ; i++){
            for(int j = 0 ; j < MX ; j++)
                ara[i][j] = (i == j ) ;

        }
    }


};

matrix mul(matrix a, matrix b )
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
    if(pow == 0 )
        return mat ;

    for(long long  i = 0 ; (1LL << i ) <= pow ; i++ ) {

        if(i == 0)
            tmp = mat ;// cout << ans.ara[0][0] << endl ;
        else
            tmp = mul(tmp , tmp ) ;

        if((1LL << i ) & pow )
            ans = mul( ans , tmp )  ;
        //tmp.print() ;
        //cout << "ans" << endl ;
        //ans.print() ;
        // cout << ans.ara[0][0] << endl ;
   // cout << "KH" << endl ;
    }

    return ans ;
}
int main()
{
    int t , c = 0;
    cin >> t ;
    while(t--){
        //ll a,  b , n , m ;
        ll n ;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 ;
        ll f0 , f1, f2 , g0, g1 , g2 ;
        cin >>f0 >> f1 >> f2 >> g0 >> g1 >> g2 ;
        int q ;
        cin >> mod >> q  ;
        printf("Case %d:\n" , ++c ) ;
        while(q--)
        {
            ll n ;
            scanf("%lld", &n ) ;
                if(n == 0 ){
                    printf("%lld %lld\n", f0 % mod , g0 % mod ) ;
                    continue ;
                }
                if(n == 1 ) {
                    printf("%lld %lld\n", f1 % mod , g1 % mod ) ;
                    continue ;
                }
                if(n == 2 ) {
                    printf("%lld %lld\n", f2 % mod , g2 % mod ) ;
                    continue ;
                }

                matrix ans, ans2  ;
                ans.setter() ;
                ans2 = bigmod(ans , n - 2 ) ;
                ll gx =0  , fx = 0;
                fx = ( ans2.ara[0][0] * f2 + ans2.ara[0][1] * f1 + ans2.ara[0][2] * f0
                     + ans2.ara[0][3] * g2 + ans2.ara[0][4] * g1 + ans2.ara[0][5] * g0 ) ;
                fx %= mod ;
                gx = ( ans2.ara[3][0] * f2 + ans2.ara[3][1] * f1 + ans2.ara[3][2] * f0
                      + ans2.ara[3][3] * g2 + ans2.ara[3][4] * g1 + ans2.ara[3][5] * g0 ) ;
                gx %= mod ;

                printf("%lld %lld\n", fx , gx ) ;
        }

     //  printf("Case %d: %lld\n" , ++c,tt ) ;
   }
   return 0 ;
}

