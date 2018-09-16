#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 1e5 + 5  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;
vi prime;
bool mark[110];
void sieve()
{
   for(int i = 0; i < 101; i++)
        mark[i] = true;
   mark[0] = false, mark[1] = false;
   for(int i = 4; i < 101;i+= 2)
       mark[i] = false;
   prime.pb(2);
   for(int i = 3; i < 101; i++){
     if(mark[i]){
        prime.pb(i);
        for(int j = i * i; j < 101; j += 2 * i)
        {
            mark[j] = false;
        }
     }

   }
}


int main(){
    int t, n;
    int a[101];
    sieve();
    cin >> t;
    for(int x = 1; x <= t; x++)
    {
        memset(a, 0, sizeof a);
        cin >> n;
        int cnt = 0, cnt1 = 0;
        for(int j = 2; j <= n; j++){
        int tmp = j;
        for(int k = 0; k < prime.size(); k++)
            if((tmp % prime[k] ==0))
            {

                while(tmp % prime[k] == 0)
            {
            tmp /= prime[k];
            a[prime[k]]++;
          }
         }
        }
        for(int i = 2; i < 101; i++)
           if(a[i])cnt++;
        printf("Case %d: %d =", x, n);
        for(int i = 2; i < 101;i++){
            if(a[i]){
            printf(" %d (%d)", i, a[i]);cnt1++;

            if(cnt != cnt1)
             printf(" *");
            }
        }
        printf("\n");
    }
   return 0;
}