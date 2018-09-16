#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const MX = (1 << 15 ) + 100;
ll dp[MX][2][2];
int match[16][16];
int n; 

ll DP(int mask,bool isSuper,bool mat){
	int cnt = __builtin_popcount(mask);
	if(cnt == n){
		return isSuper or mat;
	} 
	ll &ret = dp[mask][isSuper][mat];
	if(ret != -1)
		return ret;
	ret = 0LL;

	for(int i = 0; i < n; i++){
		if((mask & (1 << i)) == 0){
			ret += DP(mask | (1 << i),
				isSuper | (match[cnt][i] == 2),
				mat & (match[cnt][i] == 1));
		}
	}
	return ret;
}
int main()
{
	int t,c =0 ;
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	cin >> t;
	while(t--)
	{
		scanf("%d",&n);
		memset(dp,-1,sizeof dp);
		for(int i = 0; i < n;i++){
			for(int j = 0; j < n; j++)
				scanf("%d",&match[i][j]);
		}

		printf("Case %d: %lld\n",++c,DP(0,0,1));
	}
	return 0;
}