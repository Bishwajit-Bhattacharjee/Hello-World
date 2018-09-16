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
int const MX = 2 * 1e6 + 100 ;
int const mod = 100000007 ;

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
ll fact[MX] ;

vector < ll > nd ;
bool mark[MX] ;

int main()
{
    fact[0] = 1 ;
    for(ll i = 1 ; i < MX ; i++)
        fact[i] = (fact[i-1] * i ) % mod ;

    for(ll i = 2 ; i < MX ; i++){
        if(!mark[i]) {
            for(ll j = i * i ; j < ((ll)1e10 + 100) ; j *= i ) {
                nd.pb(j) ;
                if(j < MX) mark[j] = 1;
            }
        }
    }
    sort(all(nd)) ;
    int t , c = 0;
    cin >> t ;
    while(t--){
        ll a , b ;
        scanf("%lld %lld", &a , &b ) ;
        ll cnt = upper_bound(all(nd) , b ) - nd.begin() ;
        cnt -= ( upper_bound(all(nd) , a - 1 ) - nd.begin()) ;
        ll ans = !(cnt == 0 )  ;
          //  cout << "cnt " << cnt << endl;
        ans *= fact[2 * cnt] ;
        ans %= mod ;
        ans = (ans * modinverse(fact[cnt] ,mod ) ) % mod ;
        ans = (ans * modinverse(fact[cnt] ,mod ) ) % mod ;
        ans = (ans * modinverse(cnt + 1 , mod ) ) % mod ;
        printf("Case %d: %lld\n" , ++c , ans ) ;

    }

    return 0 ;
}
