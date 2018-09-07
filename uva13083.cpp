#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;

int const MX = 1e7 + 10;
bitset<MX>bs;
vector < ll > prime;

void sieve()
{
	bs.reset();

	for(ll i = 2; i * i < MX; i++)
	{
		if(!bs[i]){
			for(ll j = 2*i ; j < MX; j += i )
				bs[j] = 1;
		}
	}
	for(int i = 2; i < MX; i++)
	{
		if(!bs[i]) prime.pb(i) ;
	}
}
 
void factorize(ll num, vector < pair < ll, ll > >& fact)
{
	vector < ll > divi;
	for(auto x : prime)
	{
		if(x*x > num) break;
		if(num % x == 0) {
			while(num % x == 0)
				divi.pb(x), num /= x;

		}

	}
	if(num > 1 ) 
		divi.pb(num);
	sort(divi.begin(), divi.end());
	
	fact.clear();

	ll now = divi[0], cnt = 1;
	for(int i = 1 ; i < divi.size(); i++)
	{
		if(divi[i] == divi[i-1] ) 
			cnt++;
		else {
			fact.pb({now,cnt});
			now = divi[i] ;
			cnt = 1;
		}
	}
	fact.pb({now,cnt});

}
vector < pair < ll,ll > > matha;
ll ans;

void solve(int pos, ll gcd, ll cnt)
{
	if(pos == matha.size() ) 
	{
		ans += gcd * cnt;
		return;
	}
	ll tmp = 1;
	ll con = 0;
	for(int i = 0; i <= matha[pos].second; i++)
	{
		con = matha[pos].second - i;
		con = (con << 1 ) + 1;
		//gcd *= tmp ;
		solve(pos+1, gcd * tmp, cnt * con);

		tmp *= matha[pos].first;
		//cnt *= con;

	}
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    sieve();
    int t, c = 0;
    cin >> t;
    while(t--)
    {
    	ll n;
    	cin >> n;

    	ans = 0;
    	if(n != 1)
    		factorize(n, matha);
    	if(n != 1)
    		solve(0,1,1) ;
    	else 
    		ans = 1;
    	cout << "Case "<< ++c << ": " << ans << '\n' ;

    }


    return 0;
}