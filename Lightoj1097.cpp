#include <bits/stdc++.h>
using namespace std;
const int MX = 1429431 + 2;
int ans[MX] ;
int ara[MX] ;
int seg[4*MX] ;

void update(int pos , int ss, int se, int us ,int ue , int val)
{
    if(se < us or ss > ue ) return ;
    if(us <= ss and ue >= se)
    {
        seg[pos] = val ;
        return ;
    }
    int mid = (ss + se ) / 2 ;
    update(pos*2, ss ,mid , us , ue , val) ;
    update(pos*2 + 1, mid+ 1, se, us, ue , val) ;
    seg[pos] = seg[pos*2] + seg[pos*2 + 1] ;
}
int query(int pos , int ss, int se , int k )
{
    if(seg[pos] < k ) return -1;
    if(seg[pos] == k and ss == se)
        return se ;
    int mid = (ss + se) / 2 ;
    if(seg[2 * pos] >=  k)
    {
        return query(pos*2, ss, mid,k);
    }
    else
        return query(pos*2 +1, mid+1,se ,k-seg[2 *pos]);

}
int main()
{
    int t, c = 0;
    cin >> t ;
    memset(seg, 0 , sizeof seg);
    memset(ara ,0 ,sizeof ara);
  //  update(1, 1 ,MX, 1, MX , 1);
    for(int i = 1; i < MX ; i++ )
        update(1, 1, MX ,i, i , i % 2  ) ;
     //   cout << seg[1] << endl;
    //    cout << "KH" << endl ;
    ans[1] = 1;
    int cnt = 0;
    for(int i = 2; i <= (int)1e5; i++)
    {
        int now = query(1,1,MX,i);
      //  cout << now << endl;
        ans[i] = now;
     //   cout << ++cnt << endl;
        for(int j = 1 ;j <= MX  ; j ++ )
        {
            int tmp = j * now - (j-1) ;
            if(j * now > MX) break;
            int q = query(1,1,MX,tmp);
            if(q == -1 ) break;
           // cout << q << endl;
           // cout << "hk" << endl;
            update(1, 1, MX , q, q, 0 ) ;

        }
    }
    FILE *ftr ;
    ftr = fopen("C:\\program.txt","w");
    for(int i = 1; i <= 1e5; i++)
    {
        fprintf(ftr,"%d,", ans[i]) ;
    }
//    while(t--)
//    {
//        int n ;
//        scanf("%d",&n) ;
//        printf("Case %d: %d\n", ++c, ans[n]) ;
//    }
    return 0;
}
