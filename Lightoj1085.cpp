#include<bits/stdc++.h>
using namespace std ;
int const mod = 1e9 + 7;
int const MX = 2e5 + 10 ;
typedef long long int ll ;

struct pr
{
    ll val ; int id ;
//    bool operator<(const pr rhs){
//        if(val == rhs.val) return (id > rhs.id) ;
//        return (val < rhs.val) ;
//    }
};
bool operator<(pr l , pr rhs){
        if(l.val == rhs.val) return (l.id > rhs.id) ;
        return (l.val < rhs.val) ;
    }
ll tree[MX] ;
pr ara[MX] ;

void update(int id , int n , ll val )
{
   // ll ret =0 ;
    for(int i = id ; i <= n ; i += (i & -i))
        tree[i] += val, tree[i] %= mod ;
    //return ret ;
}
ll query(int id)
{
    ll ret = 0LL ;
    for(int i = id ; i > 0; i -= (i & -i))
        ret += tree[i] , ret %= mod ;
    return ret ;
}
int main()
{
    int c =0  , t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        //pr tmp;
        for(int i = 1 ; i <= n; i++)scanf("%lld",&ara[i].val),ara[i].id = i;
        sort(ara + 1 , ara + n + 1 ) ;
        memset(tree , 0 , sizeof (tree)) ;
        ll ans = 0LL;
        for(int i = 1; i <= n; i++){
            int idx = ara[i].id ;
            ll tmp = 0 ;
            tmp = query(idx-1) ;
           // ans = (ans + 1 + tmp) % mod ;
            update(idx , n , 1 + tmp ) ;
        }
        ans = query(n);
        printf("Case %d: %lld\n", ++c , ans ) ;
    }
    return 0 ;
}
