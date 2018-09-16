#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
typedef long long ll ;
//int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;

int const mod = 10000019 ;
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

int const MX = 2 * 1e5 + 10 ;


vector < int > prime ;
bool mark[MX] ;
int  t;
bool f  ;
void sieve()
{
    ll lim = sqrt(MX * 1.0 ) + 100 ;
    prime.pb(2) ;
    for(ll i = 3; i <= lim ; i+= 2 )
        if(!mark[i])
            for(ll j = i * i ;j < MX ; j += i )
                mark[j] = 1 ;
    for(int i = 3; i < MX ; i+= 2)
        if(!mark[i])
            prime.push_back(i) ;
}

ll number(ll pr , ll num )
{
    ll ret = 1 ;
    int cnt =0 ;
    ll pr_k = pr ;
    while((num / pr )) {
        cnt += (num / pr ) ;
        pr *= pr_k ;
    }
    if(cnt >= t ) f = 1 ;
   // cout << cnt << endl ;
    return bigmod(pr_k , cnt / t , mod ) ;
    //for(int i = )
}

int main()
{
    sieve() ;
    int test , c = 0;
    cin >> test ;
    while(test--)
    {
        int n ;

        scanf("%d %d", &n , &t ) ;
        if(n <= )
        f = 0;
        ll ans = 1 ;
        int sz = prime.size() ;
        for(int i = 0 ; i < sz && prime[i] <= n ; i++){
            ll tmp = number((ll)prime[i] , (ll)n ) ;
          //  if(tmp != 1 ) f = 1 ;
            ans = (ans * tmp ) % mod ;


        }
        (f)?printf("Case %d: %lld\n", ++c , ans ):printf("Case %d: -1\n", ++c ) ;
    }
    return 0 ;
}

