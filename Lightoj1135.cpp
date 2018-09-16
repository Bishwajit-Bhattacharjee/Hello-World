#include <bits/stdc++.h>
using namespace std ;
const int MX = 1e5 + 10 ;
struct three
{
    int ara[3] ;
    three operator+(three rhs)
    {
        three tmp ;
        tmp.ara[0] = ara[0] + rhs.ara[0] ;
        tmp.ara[1] = ara[1] + rhs.ara[1] ;
        tmp.ara[2] = ara[2] + rhs.ara[2] ;
        return tmp;
    }
};

three seg[MX * 4] ;
int lazy[MX * 4] ;

void build(int pos, int ss ,int se )
{
    if(ss == se )
    {
      seg[pos].ara[0] = 1, seg[pos].ara[1] = seg[pos].ara[2] = 0 ;
      return ;
    }
    int mid = (ss + se) / 2 ;
    build(pos*2 , ss, mid ) ;
    build(2*pos + 1, mid +1 , se) ;
    seg[pos] = seg[pos*2] + seg[pos*2 +1] ;

}


void update(int pos , int ss, int se , int us , int ue , int val)
{
    if(lazy[pos])
    {
        if(se != ss)
            lazy[2*pos] += lazy[pos],
            lazy[2*pos + 1 ] += lazy[pos] ;

        three tmp ;
        tmp.ara[(0+lazy[pos]) % 3] = seg[pos].ara[0] ;
        tmp.ara[(1+lazy[pos]) % 3] = seg[pos].ara[1] ;
        tmp.ara[(2+lazy[pos]) % 3] = seg[pos].ara[2] ;
        lazy[pos] = 0 ;
        seg[pos] = tmp ;
    }

    if(us > se or ue < ss  ) return ;
    if(us <= ss and ue >= se ) {
        if(se != ss)
            lazy[2*pos] += val,
            lazy[2*pos + 1 ] += val ;
        three tmp ;
        tmp.ara[(0+val) % 3] = seg[pos].ara[0] ;
        tmp.ara[(1+val) % 3] = seg[pos].ara[1] ;
        tmp.ara[(2+val) % 3] = seg[pos].ara[2] ;
        lazy[pos] = 0 ;
        seg[pos] = tmp ;
        return ;
    }
    int mid = (ss + se) / 2 ;
    update(pos* 2, ss, mid , us , ue, val ) ;
    update(pos * 2 + 1 , mid + 1, se , us , ue, val ) ;
    seg[pos] = seg[pos *2 ] + seg[pos*2 + 1] ;
  //  (seg[pos] = seg[pos* 2] | seg[pos*2 + 1]) : (seg[pos]  = seg[pos * 2 ] ^ seg[pos* 2 + 1 ] );

}

int query(int pos , int ss ,int se, int qs ,int qe )
{
    if(lazy[pos])
    {
        if(ss != se)
            lazy[2*pos] += lazy[pos],
            lazy[2*pos + 1 ] += lazy[pos] ;

        three tmp ;
        tmp.ara[(0+lazy[pos]) % 3] = seg[pos].ara[0] ;
        tmp.ara[(1+lazy[pos]) % 3] = seg[pos].ara[1] ;
        tmp.ara[(2+lazy[pos]) % 3] = seg[pos].ara[2] ;
        lazy[pos] = 0 ;
        seg[pos] = tmp ;
    }
    if(qs > se or qe < ss )
        return 0;

    if(qs <= ss and qe >= se)
    {
        return seg[pos].ara[0] ;
    }
    int mid = (ss + se) / 2 ;
    return query(pos*2,ss, mid , qs, qe) + query(2*pos+1, mid +1, se , qs, qe );
}

int main()
{
    int t, caseno = 0;
    cin >> t ;
    while(t--)
    {
        memset(lazy,0 ,sizeof lazy);
       //, 0 , 0 } ;
        int n , m ;
        scanf("%d %d",&n,&m) ;
        build(1, 1, n);
        printf("Case %d: ", ++caseno) ;
        for(int i = 1; i <= m ;i++)
        {
            int type ;
            scanf("%d", &type);
            if(!type)
            {
               int i ,j ;
               scanf("%d %d",&i, &j) ;
               update(1,1, n , i+1,j+1,1);
            }
            else{
                int i , j ;
                scanf("%d %d",&i,&j);
                printf("%d\n", query(1,1,n,i+1,j+1));
            }
        }
    }
    return 0;
}
