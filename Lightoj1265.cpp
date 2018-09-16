#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,c =0 ;
    int T, D ;
    cin >> t;
    while(t--)
    {
        scanf("%d %d",&T,&D);
        double ans = (T % 2 == 1) ? 0 : 1.0/(T+1) ;
        printf("Case %d: %0.10f\n", ++c,(T==1)?0 : ans ) ;
    }
    return 0;
}
