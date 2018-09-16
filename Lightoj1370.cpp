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

int const MX = 1e6 + 1000 ;


vector < int > prime ;
bool mark[MX] ;
void sieve()
{
    ll lim = sqrt(MX * 1.0 ) + 100 ;
    prime.pb(2) ;
    for(ll i = 3; i <= lim ; i+= 2 )
        if(!mark[i])
            for(ll j = i * i ;j < MX ; j += i )
                mark[j] = 1 ;
    for(int i = 3; i < MX ; i += 2)
        if(!mark[i])
            prime.push_back(i) ;
}
int ara[(int)1e4 + 100];
int main()
{
    sieve();
    int t , c = 0;
    cin >> t ;

    while(t--){
        int n ;
        cin >> n ;
        for(int i =0 ;i < n; i++){
            scanf("%d", &ara[i]);
        }
        ll ans = 0LL;
        for(int i = 0; i < n; i++){
            ans += *upper_bound(all(prime) ,ara[i]);
        }
        printf("Case %d: %lld Xukha\n", ++c , ans);
    }
    return 0;
}
