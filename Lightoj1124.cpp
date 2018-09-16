//HK HK HK HK HK 108 times
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second

int const mod = 1e8 + 7;

using namespace std;

 long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}

// ************************************************************** GLOBAL VARIABLES *******************************************



 //******************************************************************************************************************************
ll bigmod(ll base, ll pow){
   if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
int const MX = 2e6+ 10 ;
ll fact[MX];
PII ara[15] ;
ll ncr(ll n , ll r ){
    if(n < 0 or r < 0 or n < r ) return 0 ;
    ll tmp = fact[n-r]*fact[r] ;
    tmp %= mod;
    tmp = modinverse(tmp, mod ) ;
    tmp = (tmp * fact[n]) % mod ;
    return tmp ;
}

int main()
{
    fact[0] =1;
    for(int i = 1; i < MX ; i++) fact[i] = (fact[i-1] * i) % mod ;
    int t, c = 0 ;
    cin >> t ;
    while(t--){
        int n ,k ;
        scanf("%d%d",&k,&n) ;
        ll sum = 0;

        for(int i = 0 ; i < k ; i++){

            scanf("%d %d", &ara[i].F ,&ara[i].S) ;
            ara[i].S -= ara[i].F ;
            sum += ara[i].F ;

        }
        ll ans = 0LL;
        for(int i = 0; i < (1LL<< k); i++){
            ll total = 0, tmp_neg = 0;
            for(int j = 0; j < k ; j++){
                if(i & (1<<j)){
                    total += ara[j].S + 1;
                }
            }
            tmp_neg = ncr(n - total + k -1  ,k-1);
            ans = (ans + ( (__builtin_popcount(i) & 1 )?-tmp_neg:tmp_neg ) + mod ) % mod ;
        }
        //ans = (ans + neg + 2LL * mod) % mod ;
        printf("Case %d: %lld\n",++c , ans) ;
    }
    return 0;

}
