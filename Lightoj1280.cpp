#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll const MOD = 1e9 + 7;
int const MX = 2e4 + 10;
typedef pair < double, double > PDD;
 
PDD ara[MX];
double temp[MX];
 
bool can(double val, int n, int d)
{
    for(int i = 0; i < n; i++)
    {
        temp[i] = ara[i].first - val * ara[i].second;
 
    }
    sort(temp, temp + n, greater< double >());
    double tot = 0.0;
    for(int i =0; i < n - d ;i++)
        tot += temp[i] ;
    return tot >= 0.0;
 
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,c = 0;
    cin >> t;
    while(t--)
    {
        int n, d;
        scanf("%d %d",&n,&d);
        for(int i = 0; i < n;i++)
        {
            scanf("%lf %lf",&ara[i].first,&ara[i].second);
 
        }
        double lo = 0,hi = 100;
        int cnt = 60;
        while(cnt--)
        {
            double mid = (lo + hi) / 2;
            if(can(mid/100,n,d)) lo = mid;
            else
                hi = mid;
        }  
        printf("Case %d: %.9lf\n",++c,lo);
    }  
    return 0;
}
