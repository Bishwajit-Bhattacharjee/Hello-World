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
int const MX = 2 * 1e3 + 10  ;
int const mod = 1000000007 ;

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

vector<int> G[MX] ;
int st[MX] ;
ll dp[MX] ;
ll fact[MX] ;
int DFS1(int i )
{
    if(G[i].size() == 0 ) {
     //   st[i] = 1LL;
        return st[i] = 1LL;
    }
    st[i] = 0;
    for(int j= 0 ; j < G[i].size() ; j++) {
        st[i] += DFS1(G[i][j]) ;
    }
    return ++st[i] ;

   // if(ret)
}

ll DFS(int i )
{
    if(G[i].size() == 0) return 1LL ;
    ll &ret = dp[i] ;
    if(ret != -1) return ret ;
    ret = 1 ;
   // ll cnt = 0;
    for(int j = 0; j < G[i].size(); j++) {
        ret *= DFS(G[i][j]) ;
        ret %= mod ;
        ret = (ret * modinverse(fact[st[G[i][j]]] , mod )) % mod ;
    }
    ret *= fact[st[i]-1] ;
    return ret %= mod ;

}
int main()
{
    fact[0] = 1 ;
    for(ll i = 1 ; i < MX ; i++)
        fact[i] = (fact[i-1] * i ) % mod ;

    int t , c = 0;
    cin >> t ;
    while(t--){
        int n ;
        scanf("%d", &n ) ;
        memset(dp , -1 , sizeof dp ) ;
        for(int i =0 ; i < MX ; i++) G[i].clear() ;
        int sum = 0;
        for(int i = 1 ; i <= n - 1 ; i++) {
            int a , b ;
            scanf("%d %d", &a ,&b ) ;
            G[a].pb(b) ;
            sum += b ;
        }

        DFS1((n*(n+1))/2 -sum) ;
//        for(int i = 1 ;i <= n ; i++) {
//            cout << st[i] << endl ;
//        }
       // cout << (n*(n+1))/2 -sum << endl ;
        printf("Case %d: %lld\n", ++c , DFS((n*(n+1))/2 -sum)) ;

    }
    return 0;
}
