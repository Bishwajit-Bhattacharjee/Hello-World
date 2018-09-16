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
int const up =   1e6 + 10 ;
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

int const MX = 1e7 + 10 ;

int main()
{
    int t , c = 0 ;
    cin >> t ;
    while(t--)
    {
        ll n , k ;
        scanf("%lld %lld", &n , &k ) ;
        ll dig = floor(k * 1.0 * log10(n * 1.0 )) + 1 ;
        //cout << dig << endl ;
        double tmp = k * 1.0 * log10(n*1.0 ) - (dig * 1.0  - 3) ;
        ll ans1 =  pow(10.0  ,tmp ) ;
      //  cout << ans1 << endl ;
        ll ans2 = bigmod(n , k , 1000 ) ;
        printf("Case %d: %03lld %03lld\n", ++c , ans1 ,ans2 ) ;

    }
    return 0 ;
}
