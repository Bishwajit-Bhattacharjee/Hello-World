#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > PII ;
const int MX = 210;
string grid[MX] ;
int dist[MX][MX] ;
int r, c ;
int dx[] = {0,0,1,-1 } ;
int dy[] = {1,-1,0,0} ;
bool valid(PII x )
{
	return (x.first >= 0 and x.first < r ) and (x.second >= 0 and x.second < c ) ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r",stdin) ;
		freopen("out.txt","w", stdout) ;
	#endif
	int t, caseno = 0 ;
	cin >> t;
	while(t--){
		memset(dist, -1,sizeof dist) ;

		int ans = 0;
		cin >> r >> c;
		for(int i =0; i < r;i++)
			cin >> grid[i] ;

		PII jane ;
		for(int i = 0; i < r; i++)
			for(int j =0 ; j < c; j++)
				if(grid[i][j] == 'J')
					jane.first = i , 
					jane.second = j;
		//cout << jane.first << " " << jane.second << endl;

		queue < PII > q;
		q.push(jane);
		dist[jane.first][jane.second] = 0;
		int lvl = 0;
		bool found = 0;

		while(!q.empty() && !found ){
			PII u = q.front();
			if(dist[u.first][u.second] == lvl ) 
			{
				//cout << " level " << lvl << endl;
				lvl++;
				for(int i =0 ; i < r; i++)
				{
					for(int j =0 ; j < c; j++)
					{
						if(grid[i][j] == 'F'){
							for(int x = 0; x < 4; x++)
							{
								PII now ;
								now.first = i + dx[x] , now.second = j + dy[x] ;
								if(valid(now) and grid[now.first][now.second] != '#' && grid[now.first][now.second] != 'F')
									grid[now.first][now.second] = 'o';
							}
						}
					}
				}
				for(int i =0 ; i < r; i++)
					for(int j =0 ; j < c; j++) 
						if(grid[i][j] == 'o' ) grid[i][j] = 'F' ;

				//**// 

				/*for(int i = 0; i < r; i++)
					cout << grid[i] << endl; */
			}
			q.pop();
			for(int i =0 ; i < 4; i++)
			{
				PII now ;
				now.first = u.first + dx[i] , now.second = u.second  + dy[i] ;
				if(!valid(now)){
					ans = dist[u.first][u.second] + 1;
					found = 1;
					break;
				}
				else if(dist[now.first][now.second] == -1 and (grid[now.first][now.second] != '#' and grid[now.first][now.second] != 'F')) {
					dist[now.first][now.second] = dist[u.first][u.second] + 1;
					q.push(now);
				}
			}

		}

		while(!q.empty())
			q.pop() ;
		
		if(found){
			printf("Case %d: %d\n",++caseno,ans);
		}else {
			printf("Case %d: IMPOSSIBLE\n",++caseno);
		}
	}
	return 0;
}