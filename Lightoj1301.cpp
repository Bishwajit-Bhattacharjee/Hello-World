#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int const MX = 5e4 + 100;
#define PIB pair < int, bool >
#define F first
#define S second
PIB ara[2 * MX];
int n, a, b;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int t, c = 0;
	cin >> t ;
	while(t--)
	{
		
		scanf("%d",&n);
		for(int i =0 ;i < n ; i++)
			scanf("%d %d",&a,&b), ara[i*2] = (PIB(a,0)), ara[i*2+1] = (PIB(b,1));
		sort(ara, ara + 2*n );
		int ans = 0, cur = 0;
		for(int i = 0; i < 2 * n;i++)
		{
			if(ara[i].S){
				cur--;
			}
			else 
				cur++;
			ans = max(ans,cur);
		}
		printf("Case %d: %d\n",++c,ans);
	}
	return 0;
}