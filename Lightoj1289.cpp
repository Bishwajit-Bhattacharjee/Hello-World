#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
const int prime_cnt = 5761456;
 
int const N = 1e8 + 10;
int prime[prime_cnt + 5];
bitset <N> bs;
const int base = 1000;
typedef pair < int,int > PII;
 
vector < PII > active;
//ui prime_mul[N/base] ;
ui dp[prime_cnt];
 
void sieve()
{
    int pid =0 ;
    bs.set();
    bs[0] = bs[1] = 0;
    bs[2] = 1;
    prime[pid++] = 2;
 
    for(int i = 4; i < N; i += 2 )
        bs[i] = 0;
 
    for(ll i = 3; i < N; i += 2)
    {
        if(!bs[i]) continue;
        prime[pid++] = i;
        for(ll j = i*i ; j < N; j += 2*i){
            bs[j] = 0;
        }
    }
    int lim = 1e4 + 5;
    for(int i = 0; i < pid; i++)
    {
        ll num = prime[i] ;
        if(num > lim) continue;
 
        while(num < N )
        {
            active.push_back(PII(num,prime[i]));
            num *= prime[i];
        }
    }
    sort(active.begin(),active.end()) ;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    //clock_t z = clock();
 
    int t,c = 0;
    sieve();
 
    //cout << active.size() << endl;
    //printf("Time Needed %lf\n",(double)(clock()-z)/CLOCKS_PER_SEC );
    cin >> t;
    ll lim = 1e4 + 5;
    int id = 0;
    int offset = 0;
    while(prime[id] <= lim) id++;
    offset = id;
 
    dp[0] = prime[id++];
    for(int i = 1; id < prime_cnt; i++,id++){
        dp[i] = dp[i-1] * prime[id] ;
    }
 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ui ans = 1;
        for(int i = 0; i < active.size();i++)
        {
            if(active[i].first > n)
                break;
            ans *= active[i].second;
        }  
        /*int up = upper_bound(prime,prime + prime_cnt,n) - prime;
        cout << up << endl;
        cout << prime[up] << endl;*/
        if(n > lim)
        {
            int up = upper_bound(prime,prime + prime_cnt,n) - prime;
            //cout << up << endl;
            up--;
            up -= offset;
            if(up >= 0)
                ans *= dp[up]; 
        }
 
        printf("Case %d: %u\n", ++c,ans);
    }
 
    return 0;
}