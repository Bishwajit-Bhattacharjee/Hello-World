#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const MX = 52;
int const MOD = 1000000007;
ll dp1[21*21][MX];
ll dp2[21*21][21*21] ;

ll com(int n,int r)
{
	if(n < r or n < 0 or r < 0) return 0;
	if(n == 0 or r == 0)
		return 1;

	ll &ret = dp2[n][r] ;
	if(ret != -1)
		return ret;

	ret = 0;
	ret = ( com(n-1,r-1) + com(n-1,r) ) % MOD ;
	return ret;

}

ll ways(int grid,int color)
{
	if(color == 0)
	{
		return grid == 0;
	}

	ll &ret = dp1[grid][color];
	if(ret != -1)
		return ret;
	ret = 0;

	for(int now = 1; now <= grid; now++)
	{
		ret = (ret + com(grid,now)*ways(grid-now,color-1)) % MOD ;
	}
	return ret;

}
int dpAns[21][21][52];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,c = 0;
    cin >> t;
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    memset(dpAns,-1,sizeof dpAns);

    while(t--)
    {
    	int n,m,k;
    	scanf("%d %d %d",&n,&m,&k);
    	ll ans = 0;
    	if((n+m) == 0){
    		printf("Case %d: %d\n",++c,k);
    	}
	    else if(dpAns[n][m][k] != -1){
    		printf("Case %d: %d\n",++c,dpAns[n][m][k] );
    	}
    	else {
    		
    		int tot = (n+1)*(m+1);
    		int first = tot / 2 ;
    		int sec = tot - tot / 2 ;
    		//cout << first << " " << sec << endl;

    		for(int i = 1; i <= k; i++)
    		{	
    			ll tmp = com(k,i)*ways(first,i);
    			tmp %= MOD;
    			//cout <<" i :"<< i << " " << com(k,i) << " " << ways(first,i) << endl;
    			for(int j = 1; j <= k - i; j++)
    			{
    				ll tmp2 = ways(sec,j)*com(k-i,j) ;
    				tmp2 %= MOD ;
    				ans = (ans + (tmp * tmp2)) % MOD ;
    			}
    		}
    	
	    	dpAns[n][m][k] = ans;
	    	printf("Case %d: %d\n",++c,dpAns[n][m][k] );
	    }
    }
    return 0;
}