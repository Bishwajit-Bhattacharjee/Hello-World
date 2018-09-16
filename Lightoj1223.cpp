#include <bits/stdc++.h>
using namespace std;

int const MX = 1e5 + 100;

typedef long long int ll ;
ll dp[105][105][105] ;

int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif 
	memset(dp, 0,sizeof dp) ;

	int t,c =0 ;
	cin >> t;
	for(int att = 0; att <= 100; att++)
	{
		for(int l = 100; l >= 1; l--)
		{
			for(int r = 100 ; r >= 1; r--)
			{
				ll &ret = dp[att][l][r] ;
				if(l > r ){ 
					ret = 0;
					continue;
				}
				if(att == 0)
				{
					ret = (l > r )?0:INT_MAX;
					continue;
				}
				ret = INT_MAX;
				for(int mid = l; mid <= r; mid++)
				{
					ret = min(ret, mid + max(dp[att-1][l][mid-1], dp[att][mid+1][r]) );
				}	
			}
		}
	}

	while(t--){
		int k, m ;
		scanf("%d %d",&k,&m) ;
		printf("Case %d: %lld\n", ++c, dp[k][1][m]);
	}
	return 0;
}