#include<bits/stdc++.h>
using namespace std ;
const int MOD = 1e4 ;
typedef long long int ll ;
int main()
{
    int t , c = 0;
    cin >> t ;
    while(t--)
    {
        ll k ;
        int ans = 1LL;
        ll chk = 0;
        bool done = 0;
        scanf("%lld",&k);//)
        for(int i = 1; i <= min(21LL,k); i++)
        {
            ll tmp = 1LL, tmp1 = 1LL;
            for(int j = 0 ; j < i ; j++){
                tmp = (tmp * (k-j)) % MOD;
                tmp1 = tmp1 *(k-j) ;
            }
            chk += tmp1 ;
            if(chk > 9999 and !done) done = 1;
           // cout << done << endl;
            ans = (ans + tmp) % MOD;
        }
        if(done)
        printf("Case %d: %0.4d\n",++c, ans);
        else
            printf("Case %d: %d\n", ++c, ans) ;
    }
    return 0;
}
