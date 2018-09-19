#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > PII ;
#define F first
#define S second
 
const int MX = 3e5 + 100;
struct dat
{
    int x, y, type;
    int id;
    dat(){}
    dat(int a,int b, int c, int d):x(a),y(b),type(c),id(d){
 
    }  
};
 
int BIT[MX] ;
 
void update(int id , int val)
{
    for(int x = id ; x < MX; x += (x & -x))
        BIT[x] += val;
}
int query(int id)
{
    int ans =0 ;
    for(int x = id ; x > 0 ; x -= ( x & -x) )
        ans += BIT[x] ;
    return ans ;
}
 
bool compX(dat a, dat b)
{
    if(a.x == b.x){
        return a.type < b.type;
    }
    return a.x < b.x ;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r",stdin) ;
        freopen("out.txt","w", stdout) ;
    #endif
    int t,c = 0;
    cin >> t;
    while(t--)
    {
        int p,q;
        cin >> p >> q;
        vector < PII > point(p);
        vector < dat > merge;
        set < int > X ;
        map < int , int > mp;
        memset(BIT, 0 , sizeof BIT) ;
        for(int i = 0; i < p; i++)
        {
            int a, b;
            scanf("%d %d",&a,&b) ;
            //merge.push_back(dat(a,b,-1,i)) ;
            point[i] = PII(a,b) ;
            X.insert(a);
            X.insert(b);
        }
        vector < dat > rec;
        for(int i = 0; i < q; i++)
        {
            int a, b, c, d;
            scanf("%d %d %d %d",
                &a,&b,&c,&d);
            X.insert(a);
            X.insert(c);
            X.insert(b);
            X.insert(d);
            //rec.push_back
            rec.push_back(dat(a,b,-1,i) );
            rec.push_back(dat(c,d,1,i) );
 
        }
 
/*
        for(auto x : X) {
            cout << x << endl;
        }
*/
        int id = 1;
        for(set < int >::iterator it = X.begin() ; it != X.end() ; it++)
        {
            mp[*it] = id++;
            //cout << *it << " " <<  mp[*it] << endl;
        }
 
        /*dat.type means the type and
        -1 => for recbegin , 0 => point and 1 => recend  */
        for(int i =0 ; i < point.size(); i++)
        {
            merge.push_back(dat(mp[point[i].F], mp[point[i].S], 0, i ));
        }
 
        for(int i =0 ;i < rec.size(); i++){
            rec[i].x = mp[rec[i].x] ;
            rec[i].y = mp[rec[i].y] ;
            merge.push_back(rec[i]);
        }
 
        sort(merge.begin(), merge.end(), compX) ;
 
        /*cout << merge.size() << endl;
 
        for(int i =0 ; i < merge.size(); i++)
        {
            printf("%d %d %d %d\n", merge[i].x, merge[i].y, merge[i].type, merge[i].id);
        }*/
        vector < int > ans(q+1) ;
 
        for(int i =0 ; i < merge.size(); i++)
        {
            int type = merge[i].type ;
 
            if(type == -1){
                int bara = merge[i].id ;
                //cout << rec[bara* 2  + 1].y  << " " << rec[bara* 2  ].y  - 1 << endl;
                int ans1 = query(rec[bara*2 +1].y) - query(rec[bara*2].y - 1) ;
                //cout << ans1 << endl ;
                ans[merge[i].id] = -ans1;
                //cout << ans[merge[i].id] << endl;
            }
            else if(type == 0)
            {
                update(merge[i].y, 1) ;
                //cout << query(12) << endl;
            }
            else {
                int bara = merge[i].id;
                //cout << rec[bara* 2  + 1].y  << " " << rec[bara* 2  ].y  - 1 << endl;
                int ans2 = query(rec[bara* 2  + 1].y) - query(rec[bara*2].y - 1 ) ;
               
                //cout << ans2 << endl;
                ans[merge[i].id] = ans[merge[i].id] + ans2 ;
                //cout << ans[merge[i].id] << endl;
 
            }
        }
        printf("Case %d:\n",++c) ;
 
        for(int i = 0; i < q; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
