#include <bits/stdc++.h>
using namespace std ;
const int MX = 2*1e5 + 10 ;
int seg[4* MX ] ;
int lazy[MX*4 ] ;
int cnt ;
//int ara[MX];
vector < pair < int , int > > v ;
void update(int pos , int ss, int se, int us , int ue)
{
    if(lazy[pos] != -1)
    {
        seg[pos] = 0 ;
        lazy[pos] = -1;
        if(ss != se){

            lazy[pos*2] = 1 ;
            lazy[pos*2 + 1] = 1 ;
        }

    }
    if(us > se or ue < ss ) return ;
    if(ss >= us and se <= ue) {
        seg[pos] = 0 ;
     //   cout << pos <<" " <<" " << ss << " " << se<< " " << seg[pos] << "  " << cnt << endl;
        lazy[pos] = -1;
        if(ss != se){

            lazy[pos*2] = 1 ;
            lazy[pos*2 + 1] = 1 ;
        }
        return ;
    }

    int mid = (ss + se) / 2;
    update(pos*2 , ss, mid , us , ue) ;
    update(pos*2 + 1, mid+1, se ,us, ue) ;
    seg[pos] = seg[pos*2] | seg[pos*2 + 1] ;

}
int query(int pos, int ss, int se , int qs , int qe)
{
    if(lazy[pos] != -1) {
        lazy[pos] = -1 ;
        if(ss != se){

            lazy[pos*2] = 1 ;
            lazy[pos*2 + 1] = 1 ;
        }
        seg[pos] = 0;
    }
    if(qe < ss or qs > se ) return 0;

    if(qs <= ss and qe >= se) return seg[pos] ;
    int mid = (ss + se) / 2 ;
    return (query(pos*2 , ss , mid , qs, qe) | query(pos*2 +1, mid+1 , se , qs, qe )) ;

}
int main()
{
    int t, c = 0 ;
    cin >> t ;
    while(t--)
    {

        v.clear();
        for(int i = 0; i < MX * 4 ; i++) seg[i] = 1 ;
        memset(lazy, -1, sizeof lazy) ;
        int n ;
        scanf("%d", &n) ;
        int l , r ;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d",&l, &r) ;
            v.push_back(make_pair(l,r));
        }
        for(int i = v.size()- 1 ; i >= 0; i--){
            ans += query(1, 1, n*2 , v[i].first , v[i].second) ;

            update(1, 1, n*2, v[i].first , v[i].second) ;

        }
        printf("Case %d: %d\n", ++c , ans ) ;

    }
    return 0 ;
}

