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

int const MX = 1e4 + 10 ;


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
    for(int i = 3; i < MX ; i+= 2)
        if(!mark[i])
            prime.push_back(i) ;
}
vector < ll > can;
int cnt[MX];
ll nc4(ll n ) {
    return n*(n-1)*(n-2)*(n-3)/24;

}

int has[MX] ;
int ans[MX] ;
int main()
{
    sieve();
    for(int i = 0; i < prime.size(); i++){
        for(ll j = prime[i] ;j < MX ; j += prime[i]){
            cnt[j]++;
        }
    }

    for(int i =0 ; i < prime.size();i++){
        ll tmp = can.size();
        for(int j = 0; j < tmp ; j++){
           // cnt++;
            ll tmp_to_push = can[j]*prime[i] ;
            if(tmp_to_push > 1e4 )continue;
            else can.pb(tmp_to_push);
        }
        can.pb(prime[i]);
    }

    int  t, c = 0;
    cin >> t ;
    while(t--){
        int n ;
        memset(has,0 ,sizeof has);

        scanf("%d", &n) ;
        for(int i =0 ; i < n ; i++){
            int tmp;
            scanf("%d", &tmp), has[tmp]++;
        }
        ll neg = 0LL;

        for(int i =0 ; i< can.size(); i++){
            ll cc= 0;
            for(int j = can[i]; j < MX ; j += can[i]){
                if(has[j]) cc+=has[j];
            }
            neg += (cnt[can[i]] & 1)?(nc4(cc)): (-nc4(cc)) ;
        }
        printf("Case %d: %lld\n", ++c ,nc4((ll)n) - neg);
    }
    return 0;
}
