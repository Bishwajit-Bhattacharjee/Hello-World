#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll ;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
int cnt = 0;

struct Line
{
    int a ,b ,c ;
    // here a line is represented as aX+bY+c = 0 , where gcd(a, b , c ) and a is always +ve;

    bool operator<(const Line &rhs)const
    {
        if(a == rhs.a)
        {
            if(b == rhs.b)
            {
                return c < rhs.c ;
            }
            return b < rhs.b ;
        }
        return a < rhs.a ;
    }
    bool operator==(const Line &rhs)const{
        return (a == rhs.a)&&(b==rhs.b) &&(c == rhs.c) ;
    }

};
ll abss(ll x )
{
   return (x < 0 )? -x : x ;

}

Line creatingLine(ll x1, ll y1, ll x2, ll y2)
{
    Line tmp;
    tmp.a = y2-y1 ;
    tmp.b = x1 - x2 ;
    tmp.c = x2*y1 - x1*y2 ;

    if(tmp.a < 0 )
        tmp.a *= -1, tmp.b *= -1 , tmp.c*= -1 ;
    int g = gcd(abss(tmp.a), gcd(abss(tmp.b), abss(tmp.c))) ;
    tmp.a /= g ;
    tmp.b /= g ;
    tmp.c /= g ;
    return tmp;
}
map < Line, int > mapping;
ll x[1010];
ll y[1010];
map < ll, int > nc2 ;

int main()
{
    int t, caseno = 0 ;
    int n ;
    cin >> t;
    for(int i = 1 ; i <= 710 ; i++)
        nc2[i*1LL*(i-1)/2] = i;
    while(t--)
    {
        mapping.clear();
        scanf("%d",&n) ;
        for(int i = 0; i < n ; i++)
        {
            scanf("%lld %lld",&x[i] , &y[i]) ;
        }
        for(int i =0 ; i < n ;i++)
        {
            for(int j = i+1; j < n ; j++)
            {
                Line tmp = creatingLine(x[i],y[i], x[j] , y[j]);
                mapping[tmp]++ ;
            }
        }
        map< Line, int >::iterator it ;
        ll ans = 0 ;
        for(it = mapping.begin(); it != mapping.end(); it++)
        {
            ans = max(ans ,(ll)nc2[it->second]) ;
        }
        printf("Case %d: %lld\n",++caseno, max(ans,1LL));//max(ans,min(2LL, 1LL*n))) ;
    }
    return 0 ;
}
