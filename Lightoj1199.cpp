#include <bits/stdc++.h>
using namespace std ;
const int MX = 1e4 + 10;
int G[MX];
int ara[101] ;


int Grundy(int num)
{
    if(num <= 2 ) return G[num] = 0 ;
    if(G[num] != -1){
        return G[num] ;
    }
    int can = 0;
    set < int > s ;
    for(int i = 1 ; i <= num / 2 ; i++){
        if(2 * i != num ) {
            s.insert(Grundy(i) ^ Grundy(num-i))  ;
        }
    }
    int ret = 0;

   // vector<int>::iterator ptr;
    set<int>::iterator it ;
    for(it = s.begin(); it != s.end(); it++){
        if(s.find(ret) != s.end())
            ret++;
    }
    return G[num] = ret;
}
int main()
{
    int t, c =0 ;
    cin >> t ;
    int n ;
    memset(G, -1 , sizeof G);
    while(t--)
    {
        scanf("%d",&n);
        int tmp = 0LL;
        int x ;
        for(int i = 0; i < n ; i++)
            scanf("%d",&x),
            tmp ^= Grundy(x)  ;
        printf("Case %d: %s\n",++c, tmp?"Alice":"Bob") ;

    }
    return 0;
}
