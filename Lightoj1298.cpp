#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
//#define mp make_pair
#define F first
#define S second

int const MX = 4e3 + 10 ;
int const mod =  1000000007  ;

vector < int > prime ;
bool mark[MX] ;

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

void seive()
{
    ll lim = sqrt(1.0 * MX ) + 2 ;
    for(int i = 4 ; i < MX ; i += 2 )
        mark[i] = 1 ;

    for(ll i = 3 ; i <= lim ; i += 2) {
        if(!mark[i]){
            for(ll j = i * i ; j <= MX ; j += i )
                mark[j] = 1;
        }
    }
    for(int i = 2 ; i < MX ; i++ )
        if(!mark[i]) prime.pb(i) ;

}
ll dp[510][510] ;
ll phi[510] ;
inline ll DP(int i , int j)
{
    if(i < j ) return 0LL;
    return dp[i][j] ;
}
int main()
{
    seive();
    phi[0] = 1 ;
    for(int i = 1; i <= 500 ; i++)
    {
        phi[i] = (( phi[i-1]* (prime[i-1] -1) ) % mod  * modinverse(prime[i-1], mod) ) % mod ;
    }
    dp[0][0] = 1;
    for(int i = 1;i <= 500; i++)
        dp[i][0] = 0 ; //dp[0][i] = 0;
    for(int i = 1; i <= 500; i++){
        for(int j = 1; j <= 500 ; j++){

            dp[i][j] = prime[j-1] *( (DP(i-1, j - 1 ) + DP(i-1, j ) ) % mod ) ;
            dp[i][j] %= mod;
        }
    }

   // for(int )
    int t, c =0 ;
    cin >> t;
    int k , p ;
    while(t--)
    {
        scanf("%d %d",&k,&p);
      //  cout << "dp[k][p] " << ' ' << dp[k][p] << " " << phi[p] <<  endl;
        printf("Case %d: %lld\n", ++c , (phi[p]*dp[k][p] + mod ) % mod ) ;
    }
    return 0 ;
}
