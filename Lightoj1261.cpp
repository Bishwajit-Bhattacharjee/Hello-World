#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,c = 0;
    cin >> t;

    while(t--)
    {
    	int n,m,k;
    	cin >> n >> m >> k;
    	vector < int > v[n];
    	for(int i =0 ; i < n; i++)
    	{
    		for(int j = 0 ; j < k ; j++){
    			int tmp ;
    			cin >> tmp ;
    			v[i].push_back(tmp);
    		}
    	}
    	int bs[m+10];
    	memset(bs,0,sizeof bs);
    	int tmp;
    	int cnt;
    	cin >> cnt;
    	for(int i =0 ; i < cnt ; i++)
    		cin >> tmp, bs[tmp] = 1;

    	bool f = 1;
    	for(int i = 0; i < n; i++)
    	{
    		bool tmp = 0;
    		for(int j = 0; j < k; j++){
    			if(v[i][j] > 0 and bs[v[i][j]]){
    				tmp = 1;
    			}
    			else if(v[i][j] < 0 and !bs[-v[i][j]]){
    				tmp = 1;
    			}
    		}
    		f &= tmp;
    	}
    	printf("Case %d: %s\n",++c,f?"Yes":"No" );

    }
    return 0;
}