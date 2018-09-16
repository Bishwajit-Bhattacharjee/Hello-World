#include <bits/stdc++.h>
using namespace std ;
long long f[17] ;

int main()
{
    int t  , c =0 ;
    cin >> t ;
    f[0] = 1 ;
    for(long long i = 1; i <= 17 ; i++) f[i] = f[i-1] *i;
    while(t--){
        int n, m , k  ;
        double p ;
        cin >> n >> m >> k >> p ;
        double ans = 0;
        for(int i = 1 ;i <= n; i++){
            double tmp = 1.0 ;
            tmp = tmp * f[n]/f[i]/f[n-i] * pow(p,1.0* i)* pow(1.0-p,1.0*(n-i)) * i ;
            ans += tmp ;
        }
        printf("Case %d: %.15f\n",++c ,  ans*k);

    }
    return 0;
}
