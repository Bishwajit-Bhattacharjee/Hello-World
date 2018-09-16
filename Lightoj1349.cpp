#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r", stdin);
	freopen("out.txt","w", stdout) ;
#endif

	int t,c=0 ;
	cin >> t;
	
	while(t--)
	{
		int m, n, q;
		scanf("%d %d %d",&m,&n,&q);
		vector < int > x(m+1,0),y (n+1,0);
		int tot = 0;
		for(int i = 0 ; i < q; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			x[a] += c;
			tot += c;
			y[b] += c;
		}				

		int i ;
	
		int so = 0;
		for(i = 0; i <= m && so * 2 <= tot; i++) 
			so += x[i];
		int a1 = i - 1;
		so = 0;
		for(i =0; i <= n and so * 2 <= tot; i++)
			so += y[i];
		int a2 = i - 1;

		printf("Case %d: %d %d\n",++c, a1,a2) ;
	}

	return 0;
}