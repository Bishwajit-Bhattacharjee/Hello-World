#include <bits/stdc++.h>
using namespace std ;
const int MX = 1000;
int G[MX][MX] ;
int dx[] = {-2, -2,-3, -1 , 1 , -1} ;
int dy[] = {1, -1 , -1,-2 ,-2, -3 } ;

int Grundy(int x, int y )
{
    if(x < 0 or y < 0 ) return INT_MAX ;
    if(x < 2 and y < 2 ) return G[x][y] = 0 ;
    if(G[x][y] != -1) return G[x][y] ;
    set < int > s ;
    for(int i = 0 ; i < 6; i++){
        //for(int j = 0; j < 6; j++){
            s.insert(Grundy(x + dx[i], y+ dy[i])) ;
       // }
    }
    int ret = 0;
    set < int >::iterator it ;
    for(it = s.begin(); it != s.end(); it++)
    {
        if(*it == ret ) ret++;
    }

    return G[x][y] = ret ;
}
int main()
{
    int t , c= 0 ;
    cin >> t ;
    memset(G, -1, sizeof G) ;
    while(t--)
    {
        int n ;
        int tmp = 0;
        scanf("%d",&n) ;
        for(int i = 0 ; i < n ; i++){
            int x ,y ;
            scanf("%d %d", &x , &y ) ;
            tmp ^= Grundy(x, y) ;
        }
        printf("Case %d: %s\n",++c ,(tmp==0)?"Bob":"Alice");

    }
    return 0;
}
