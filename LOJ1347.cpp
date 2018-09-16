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

int const MX = 5*1e3 + 100;

ll M1 = 1e9 + 7 ;
ll M2 = 1e9 + 9;
ll B[] = {37, 41} ;
ll M[] = {M1,M2};
ll P[3][MX] ;
ll Rolling_hash[4][3][MX];

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
/* here id is the index of the string number of the strings
*/
PLL substrHash(int id, int i, int j)
{
    int len = j - i + 1;
    if(len < 0 )
        return make_pair(-1,-1) ;

    PLL tmp ;
    tmp.F = Rolling_hash[id][0][j] ;
    tmp.S = Rolling_hash[id][1][j] ;
    if(i)
    {
        tmp.F -= P[0][len]*Rolling_hash[id][0][i-1] ;
        tmp.S -= P[1][len]*Rolling_hash[id][1][i-1] ;

    }
    tmp.F = (tmp.F% M[0] + M[0]) % M[0] ;
    tmp.S = (tmp.S%M[1] + M[1]) % M[1] ;

    return tmp;
}
string s[4];

bool can(int len)
{
    vector < PLL > SET[3] ;
    for(int snum =0; snum < 3; snum++)
    {
        for(int i = 0 ; i + len <= s[snum].size(); i++)
        {
            SET[snum].pb(substrHash(snum, i,i+len-1));
        }
    }

    sort(all(SET[1])) ;
    sort(all(SET[2])) ;

    for(int i = 0; i < SET[0].size(); i++)
    {
        if(binary_search(all(SET[1]), SET[0][i]) && binary_search(all(SET[2]) ,SET[0][i]) )
            return 1;
    }

    return 0;
}

int mxlen()
{
    int ans = 0;
    int lo = 1;
    int hi = min(s[0].size(), min(s[1].size(), s[2].size()));

    while(lo <= hi)
    {
       // cout << lo << " " << hi << " " << ans << endl;
        int mid = (lo + hi) / 2;
        if(can(mid))
        {
            ans = max(ans,mid) ;
            lo = mid + 1;
        }
        else
            hi = mid - 1;

    }
    return ans;
}

int main()
{
    //clock_t z = clock() ;
    //READ;
//
//#ifndef ONLINE_JUDGE
//    freopen("in.txt","r", stdin) ;
//    //freopen("out.txt","w", stdout) ;
//#endif
    // calculates the B^k in the array, mi is the index of M[] array
    P[0][0] = P[1][0] = 1;

    for(int mi = 0; mi < 2; mi++)
    {
       for(int j = 1; j < MX; j++)
       {
           P[mi][j] = (P[mi][j-1]*B[mi]) % M[mi] ;
       }
    }
    int t, c =0 ;
    cin >> t;
    //cout << t << endl;
    while(t--)
    {

        cin >> s[0] >> s[1] >> s[2];
        /*Rolling_hash[0][0][0] = s[0][0] - 'a'+ 1;
        Rolling_hash[0][1][0] = s[1][0] - 'a' + 1;
        Rolling_hash[2][1][0] = s[2][0] - 'a' + 1; */
        for(int i =0 ; i < 3; i++)
        {
            Rolling_hash[i][0][0] = s[i][0] - 'a' + 1;
            Rolling_hash[i][1][0] = s[i][0] - 'a' + 1;
        }
        for(int id =0 ; id < 3; id++)
        {
            for(int i = 1; i < s[id].size(); i++)
            {
                for(int mi = 0; mi < 2; mi++)
                {
                    Rolling_hash[id][mi][i] = (Rolling_hash[id][mi][i-1]*B[mi] + s[id][i] -'a' + 1) % M[mi] ;

                }
            }
        }
        //mxlen() ;
        printf("Case %d: %d\n", ++c, mxlen());
    }
   // printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;

}

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

int const MX = 5*1e3 + 100;

ll M1 = 1e9 + 7 ;
ll M2 = 1e9 + 9;
ll B[] = {37, 41} ;
ll M[] = {M1,M2};
ll P[3][MX] ;
ll Rolling_hash[4][3][MX];

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
/* here id is the index of the string number of the strings
*/
PLL substrHash(int id, int i, int j)
{
    int len = j - i + 1;
    if(len < 0 )
        return make_pair(-1,-1) ;

    PLL tmp ;
    tmp.F = Rolling_hash[id][0][j] ;
    tmp.S = Rolling_hash[id][1][j] ;
    if(i)
    {
        tmp.F -= P[0][len]*Rolling_hash[id][0][i-1] ;
        tmp.S -= P[1][len]*Rolling_hash[id][1][i-1] ;

    }
    tmp.F = (tmp.F% M[0] + M[0]) % M[0] ;
    tmp.S = (tmp.S%M[1] + M[1]) % M[1] ;

    return tmp;
}
string s[4];

bool can(int len)
{
    vector < PLL > SET[3] ;
    for(int snum =0; snum < 3; snum++)
    {
        for(int i = 0 ; i + len <= s[snum].size(); i++)
        {
            SET[snum].pb(substrHash(snum, i,i+len-1));
        }
    }

    sort(all(SET[1])) ;
    sort(all(SET[2])) ;

    for(int i = 0; i < SET[0].size(); i++)
    {
        if(binary_search(all(SET[1]), SET[0][i]) && binary_search(all(SET[2]) ,SET[0][i]) )
            return 1;
    }

    return 0;
}

int mxlen()
{
    int ans = 0;
    int lo = 1;
    int hi = min(s[0].size(), min(s[1].size(), s[2].size()));

    while(lo <= hi)
    {
       // cout << lo << " " << hi << " " << ans << endl;
        int mid = (lo + hi) / 2;
        if(can(mid))
        {
            ans = max(ans,mid) ;
            lo = mid + 1;
        }
        else
            hi = mid - 1;

    }
    return ans;
}

int main()
{
    //clock_t z = clock() ;
    //READ;
//
//#ifndef ONLINE_JUDGE
//    freopen("in.txt","r", stdin) ;
//    //freopen("out.txt","w", stdout) ;
//#endif
    // calculates the B^k in the array, mi is the index of M[] array
    P[0][0] = P[1][0] = 1;

    for(int mi = 0; mi < 2; mi++)
    {
       for(int j = 1; j < MX; j++)
       {
           P[mi][j] = (P[mi][j-1]*B[mi]) % M[mi] ;
       }
    }
    int t, c =0 ;
    cin >> t;
    //cout << t << endl;
    while(t--)
    {

        cin >> s[0] >> s[1] >> s[2];
        /*Rolling_hash[0][0][0] = s[0][0] - 'a'+ 1;
        Rolling_hash[0][1][0] = s[1][0] - 'a' + 1;
        Rolling_hash[2][1][0] = s[2][0] - 'a' + 1; */
        for(int i =0 ; i < 3; i++)
        {
            Rolling_hash[i][0][0] = s[i][0] - 'a' + 1;
            Rolling_hash[i][1][0] = s[i][0] - 'a' + 1;
        }
        for(int id =0 ; id < 3; id++)
        {
            for(int i = 1; i < s[id].size(); i++)
            {
                for(int mi = 0; mi < 2; mi++)
                {
                    Rolling_hash[id][mi][i] = (Rolling_hash[id][mi][i-1]*B[mi] + s[id][i] -'a' + 1) % M[mi] ;

                }
            }
        }
        //mxlen() ;
        printf("Case %d: %d\n", ++c, mxlen());
    }
   // printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;

}

