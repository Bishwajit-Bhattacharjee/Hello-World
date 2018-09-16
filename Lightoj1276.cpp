#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define pb push_back

vector < ll > hlp[13] , v, mn;
set < ll > s ;
ll up = 1e12;
void bk(int id, ll total)
{
    if(id < 0 ) return ;
    if(total > up ) return ;
    if(total != 1 ) s.insert(total) ;
    if(total <= up / v[id] )
       bk(id , total * v[id]);
    bk(id-1, total);

}

int main()
{
   // l
    hlp[0].pb(4) ; hlp[0].pb(7);
    ll mul = 1LL;
    for(int i = 1 ; i <= 11; i++){
        int sz = hlp[i-1].size();
        mul *= 10LL;
        for(int j = 0;j < sz; j++){
            hlp[i].pb(4*mul+hlp[i-1][j]) ;
            hlp[i].pb(7*mul+hlp[i-1][j]) ;
        }
    }
    for(int i = 0; i < 12;i++){
        for(int j = 0 ; j < hlp[i].size(); j++)
            v.pb(hlp[i][j]);
    }
    bk(v.size()-1, 1LL);
    set<ll>::iterator it ;
    for(it = s.begin(); it != s.end();it++)
        mn.pb(*it);
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        ll a, b;
        scanf("%d %d",&a,&b);
        ll ans = upper_bound(mn.begin(),mn.end(), b) -
                 upper_bound(mn.begin(),mn.end(), a) ;
        printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
