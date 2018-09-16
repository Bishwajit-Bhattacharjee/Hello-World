#include <bits/stdc++.h>
using namespace std;

int const MX = 1e5 + 100;

int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif 
	
	int t,c =0 ;
	cin >> t;
	

	while(t--)
	{
		int n, m;
		scanf("%d %d",&n,&m) ;
		vector < int > coin(n), cnt(n) ;
		for(int i =0 ; i < n; i++)
			scanf("%d",&coin[i]);
		for(int i =0 ; i < n; i++)
			scanf("%d",&cnt[i]);

		vector < bool > done(m + 1,0) ;
		done[0] = 1;
		vector < int > needcoin(m + 1);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j <= m; j++)
				if(done[j])
					needcoin[j] = 0;
				else 
					needcoin[j] = 1e9 ;

			for(int j = 0; j <= m ; j++)
			{
				if(!done[j]) 
					continue;

				int k = j + coin[i] ;
				if(k <= m and !done[k] and needcoin[k] > needcoin[j] + 1 and needcoin[j] < cnt[i])
				{
					done[k] = 1;
					needcoin[k] = needcoin[j] + 1 ;
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= m ; i++)
			ans += done[i] ;

		printf("Case %d: %d\n",++c, ans);
	}
	return 0;
}
