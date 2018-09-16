#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r", stdin) ;
	freopen("out.txt","w", stdout);
#endif

	int t, c =0 ;
	scanf("%d",&t) ;

	while(t--)
	{
		int n;
		scanf("%d",&n) ;
		vector < int > v(n);
		map < int , int > freq;
		for(int i =0; i < n; i++)
			scanf("%d",&v[i]), freq[v[i]]++;

		int ans =0 ;
		map < int ,int >::iterator it = freq.begin();
		for( ; it != freq.end(); it++) 
		{
			if(it->second)
			{
				int tmp = (it->second + it->first ) / ( it->first + 1) ;
				ans += tmp * (it->first + 1) ;
			}
		}
		
		printf("Case %d: %d\n",++c,ans);
	}
	return 0 ;
}