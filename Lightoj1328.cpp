#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000007;
typedef long long ll ;
int a[(int)1e5 + 10];
int main()
{
    int t ,cs = 0;
    cin >> t ;
    while(t--){
        int k ,c, n;
        scanf("%d%d%d%d",&k,&c,&n,&a[0]);
        for(int i=1 ; i< n; i++)
            a[i] =(1LL*k*a[i-1]+c)%MOD ;
        sort(a , a + n );
        ll ans = 0LL;
        for(int i = 0;i < n ; i++)
            ans +=  i*(ll)a[i] - (ll)(n-i-1) * a[i] ;

        printf("Case %d: %lld\n",++cs , ans);

    }
    return 0;
}
