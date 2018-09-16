#include <bits/stdc++.h>
using namespace std ;
const int MX = 1e5 + 10 ;
int seg[4*MX] ;
int freqs[MX], freqe[MX];
int ara[MX] ;
inline int min3(int a ,int b, int c)
{
    return min(a, min(b, c));
}
inline int max3(int a, int b, int c )
{
    return max(a, max(b, c )) ;
}

void build(int pos, int ss, int se )
{
    if(ss == se)
    {
        seg[pos] = 1 ;
        return ;
    }
    int mid = (ss + se) / 2 ;
    build(pos*2, ss , mid) ;
    build(pos*2 + 1, mid + 1, se) ;
    int can = max(0, min(freqe[ara[mid]], se)-max(freqs[ara[mid]], ss)+1) ;
    seg[pos] = max(seg[pos*2], max(seg[pos*2+1], can)) ;
    //seg[pos] = max(seg[pos*2], max(seg[pos*2+1],min(freq[ara[mid]], se-ss+1))) ;

}
int query(int pos , int ss ,int se, int qs, int qe )
{
    if(qs > se or qe < ss) return 0;
    if(qs<= ss and qe >= se)
        return seg[pos] ;
    int mid = (ss + se ) / 2 ;
    int can = max(0 , min3(se,qe,freqe[ara[mid]]) - max3(ss, qs ,freqs[ara[mid]]) + 1 ) ;
    return max3(query(pos*2,ss, mid , qs , qe), query(pos*2+1 , mid+1, se,qs, qe), can) ;
}
int main()
{
    int t , caseno =0 ;
    cin >> t ;
    while(t--)
    {
        int n ,c , q;
        memset(freqs, 0 , sizeof freqs);
        memset(freqe, -1, sizeof freqe);

        scanf("%d %d %d",&n,&c,&q);//)
        for(int i = 1; i <= n; i++){
           scanf("%d",&ara[i]);
           if(!freqs[ara[i]]){
                freqs[ara[i]] = i;
           }
           freqe[ara[i]] = i ;
        }
        build(1,1,n);
      //  cout << seg[1] << endl;
        printf("Case %d:\n",++caseno);
        for(int i = 0; i< q; i++)
        {
            int l , r;
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,1,n,l,r)) ;

        }

    }
    return 0;
}
