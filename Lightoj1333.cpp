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
//#define ceiling((a), (b)) ((a) %(b) == 0)?((a)/(b)):((a)/(b))+1
#define F first
#define S second

int const mod = 1e9 ;

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
map < int , vector<int> > row;
vector < PII > block ;
int main()
{
    int t, c= 0;
    cin >> t ;
    while(t--)
    {
        row.clear();
        block.clear();
        ll n ,m ,k , b ;
        scanf("%lld%lld%lld%lld",&m,&n,&k,&b) ;
        for(int i = 0;i < b; i++)
        {
            PII tmp ;
            scanf("%d %d",&tmp.F , &tmp.S) ;
            block.pb(tmp) ;
        }
        sort(all(block)) ;
        for(int i =0; i< b; i++)
        {
            row[block[i].S].pb(block[i].F) ;
        }
        ll tmp = ( k*( (m>1)?bigmod(k-1,m-1):1LL)) % mod;
        ll ans = 1LL;
        for(int i = 1; i <= n;i++)
        {
            ll tmp1 = 1LL;
            ll prev = 0;
            if(row.count(i)){
                row[i].pb(m+1);
               for(int j = 0 ;j < row[i].size();j++)
               {
                   ll now = row[i][j];
                   if(now - prev == 2)
                   {
                       tmp1 = (tmp1*k) % mod ;
                   }
                   else if(now - prev != 1){
                       tmp1 = (tmp1*k) % mod ;
                       tmp1 = (tmp1 *bigmod(k-1,now-prev-2)) % mod ;
                     //  cout << tmp1 << endl;
                   }
                   prev = now ;
               }
               ans = (ans * tmp1) % mod ;

            }

            else {
               ans = (ans * tmp) % mod ;
            }
          //  cout << ans << endl;
        }
        if(ans==1) ans = !(n*m == b) ;

        printf("Case %d: %lld\n",++c, ans);

    }
    return 0;
}
