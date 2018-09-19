#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a % b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 1e3 + 1;
int const EPS = 1e-9;
int  const MOD = 10056;
 
using namespace std;
 
int dp[MX][MX];
 
int way(int n, int r){
    if(n < r)
        return 0;
    if(r == 1){
        return 1;
    }
    if(dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = (r *(way(n-1 , r) + way(n - 1 , r-1))) % MOD ;
}
 
 
 
int main()
{
   int t, n, c = 0;
   cin >> t;
   memset(dp, -1, sizeof dp);
   while(t--){
    scanf("%d", &n);
    int ans  = 0;
    for(int i = 1; i <= n ; i++){
         ans = (ans  + way(n, i) ) % MOD ;
    }
    printf("Case %d: %d\n", ++c, ans);
   }
   return 0;
}
