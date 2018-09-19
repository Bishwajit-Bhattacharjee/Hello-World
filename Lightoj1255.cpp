/// HK 108 Times
#include <bits/stdc++.h>
 
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
 
// Order Statistic Tree
 
/* Special functions:
 
        find_by_order(k) --> returns iterator to the elements
                            //that has k elements less in the set
 
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
const int mod = 1e9 + 7 ;
 
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
 
int const MX = 1e6 + 100;
 
ll M1 = 1e9 + 7 ;
ll M2 = 1e9 + 9;
ll B[] = {37, 41} ;
ll M[] = {M1,M2};
ll P[2][MX] ;
ll Rolling_hash[2][MX];
 
//Calculates the prefix hashes for the string
 
PLL Hash(const string &s)
{
    PLL ret = make_pair(0,0);
 
    for(int i = 0; i < s.size() ; i++)
    {
        ret.first = (ret.first * B[0] + s[i] - 'a'+1) % M[0] ;
        ret.second = (ret.second * B[1] + s[i] - 'a'+ 1) % M[1] ;
    }
    return ret;
 
}
 
PLL substrHash(int i, int j)
{
    int len = j - i + 1;
    if(len < 0 )
        return make_pair(-1,-1) ;
 
    PLL tmp ;
    tmp.F = Rolling_hash[0][j] ;
    tmp.S = Rolling_hash[1][j] ;
    if(i)
    {
        tmp.F -= P[0][len]*Rolling_hash[0][i-1] ;
        tmp.S -= P[1][len]*Rolling_hash[1][i-1] ;
 
    }
    tmp.F = (tmp.F% M[0] + M[0]) % M[0] ;
    tmp.S = (tmp.S%M[1] + M[1]) % M[1] ;
 
    return tmp;
}
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin) ;
    freopen("out.txt","w", stdout) ;
#endif
   
 
    // calculates the B^k in the array, mi is the index of M[] array
    P[0][0] = P[1][0] = 1;
    for(int mi = 0; mi < 2; mi++)
    {
        for(int j = 1; j < MX; j++)
        {
            P[mi][j] = (P[mi][j-1]*B[mi]) % M[mi] ;
        }
    }
    int t, c = 0;
    cin >> t;
    while(t--)
    {
        string s, a, b;
        cin >> a >> b;
        s = a;
       
        Rolling_hash[0][0] = s[0] - 'a'+ 1;
        Rolling_hash[1][0] = s[0] - 'a' + 1;
 
        for(int i = 1; i < s.size(); i++)
        {
            for(int mi = 0; mi < 2; mi++)
            {
                Rolling_hash[mi][i] = (Rolling_hash[mi][i-1]*B[mi] + s[i] -'a' + 1) % M[mi] ;
 
            }
        }
 
        PLL hb = Hash(b) ;
        ll cnt = 0;
        for(int i =0 ; i + b.size() <= a.size();i++)
        {
            if(hb == substrHash(i,i + (int)b.size()-1) )
            {
                cnt++;
            }
        }  
 
        printf("Case %d: %lld\n",++c,cnt) ;
    }
 
   
 
 
    return 0;
 
}
 
