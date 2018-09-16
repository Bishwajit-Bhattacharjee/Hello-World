#include <bits/stdc++.h>
using namespace std ;
typedef  long long ull;
ull fact[21] ;
int main()
{
    fact[0] = 1;
    for(int i = 1; i<=20 ; i++)
        fact[i] = fact[i-1] * (ull)i;
    int t , c= 0;
    vector < ull > ans ;
    cin >> t ;
    ull n ;
    while(t--)
    {
        scanf("%lld", &n) ;
        ans.clear() ;
        for(int i = 20 ; i >= 0; i--){
            if(n - fact[i] >= 0 ){
                ans.push_back(i) ;
                n -= fact[i] ;
               // cout << n << endl;
            }
        }
      //  for(auto i : ans) cout << i << endl;
        if(n){
            printf("Case %d: impossible\n",++c) ;
        }else {
            printf("Case %d: ", ++c );
            for(int i = (int)ans.size() - 1; i >= 0; i--)
            {


                if(i){
                    printf("%d!+",ans[i] ) ;
                }
                else {
                    printf("%d!\n",ans[i]);
                }
            }
        }
       // cout << "1!+2!+3!" << endl;
    }
    return 0 ;
}
