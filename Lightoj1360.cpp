#include <bits/stdc++.h>
using namespace std ;
//double prob[MX];
#define F first
#define S second 
#define pb push_back
int const MX = 3e4 + 10;

struct dat
{
	int a,b,c;
	dat(int x, int y,int z):a(x),b(y),c(z){

	}
	bool operator<(const dat &rhs)const{
		return a < rhs.a;
	}
};
int dp[MX];
vector < dat > info;

int DP(int id)
{
	if(id == info.size())
		return 0;

	int &ret = dp[id];
	if(ret != -1)
		return ret;

	ret = DP(id + 1);
	int canID = upper_bound(info.begin(),info.end(),dat(info[id].a + info[id].b - 1, (int)1e9, (int)1e9) ) - info.begin();
	ret = max(ret, info[id].c + DP(canID));
	return ret;

}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin) ;
		freopen("out.txt","w",stdout);
	#endif

	int t, c = 0 ;

	cin >> t ;
	while(t--)
	{
		int n;

		scanf("%d",&n);
		info.clear();
		memset(dp,-1,sizeof dp);

		for(int i = 0 ; i < n;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			info.pb(dat(a,b,c));
		}
		sort(info.begin(), info.end());

		printf("Case %d: %d\n",++c,DP(0));
	}
	return 0;
}
