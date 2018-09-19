/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
vector < pair < int , PII >  >  edge  ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'
#define DEBUG(x) cout << '>' << #x << ':' << x << endl
 
// Order Statistic Tree
 
/* Special functions:
 
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
const int mod = 1e9 + 7 ;
 
typedef tree<
int,                    // type long long
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}
ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
const int MX = 50;
 
ll ara[MX] ;
ll cum[MX] ;
 
ll zero[MX] ;
ll one[MX] ;
 
void solve(ll len, ll baki,bool f)
{
    if(len == 0) return ;
    if(f){
        f ^= 1 ;
        printf("1");
        solve(len - 1,baki,f) ;
    }
 
    else if(zero[len] >= baki) {
        printf("0");
        solve(len -1 , baki,f);
    }
    else {
        printf("1");
        solve(len - 1,baki - zero[len],f);
 
    }
 
//    for(int i = len; i > 0 ; i--)
//    {
//
//        cout << "baki " << baki << endl;
//        if(i == len) {
//            printf("1");
//        }
//        else if(baki <= zero[i-1]){
//            printf("0");
//            baki = zero[i-1];
//        }
//        else {
//            printf("1");
//            baki -= zero[i-1];
//        }
//    }
 
}
 
int main()
{
    ara[0] = 0;
    ara[1] = 1;
 
    cum[0] = 0;
    cum[1] = 1;
 
    ll lim = 1e9 + 100;
    int up = -1;
 
 
    for(int i = 2; cum[i-1] < lim; i++){
        cum[i] = cum[i-1] + ( ara[i] = ara[i- 1] + ara[i-2] );
        up = i;
       // printf("%lld\n", cum[i]);
    }
 
    zero[1] = one[1] = 1;
    for(int i = 2; i < 50 ;i++)
    {
        one[i] = zero[i-1] ;
        zero[i] = one[i-1] + zero[i-1] ;
      //  printf("%lld %lld\n", one[i] , zero[i]) ;
 
    }
 
    int t,c = 0;
    cin >> t;
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
 
        int len = lower_bound(cum,cum + up, n) - cum ;
        printf("Case %d: ",++c);
     //   cout << len << endl;
        solve(len, n - cum[len-1],1);
        printf("\n");
 
    }
 
    return 0;
}
