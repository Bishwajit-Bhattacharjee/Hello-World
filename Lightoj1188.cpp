#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > PII ;
 
const int MX = 1e5 + 100;
struct dat
{
    int x, y, id;
    dat(){
        x = y = id = 0;
    }
    dat(int a,int b, int c):x(a),y(b),id(c){
 
    }
    bool operator<(const dat &rhs) const{
        if(y == rhs.y)
        {
            if(x == rhs.x)
                return id < rhs.id;
            return x < rhs.x ;
        }
        return y < rhs.y;
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
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r",stdin) ;
        freopen("out.txt","w", stdout) ;
    #endif
    int t, c =0;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        vector < int > ara(n+1) ;
        memset(BIT, 0 ,sizeof BIT) ;
 
        for(int i = 1; i <= n; i++)
            scanf("%d",&ara[i]) ;
       
        vector < int > ans(q+1);
        vector < dat > inputs;
 
        for(int i =0; i < q; i++)
        {
            int L, R ;
            scanf("%d %d",&L,&R) ;
            inputs.push_back(dat(L,R,i));
        }
        sort(inputs.begin(), inputs.end());
       
        vector < int > lastSeen(MX,-1);
 
        int cur = 0;
 
        for(int i = 1; i <= n; i++)
        {
            int last = lastSeen[ara[i]] ;
            update(i,1) ;
            if(last != -1)
                update(last,-1);
            lastSeen[ara[i]] = i ;
            while(cur < inputs.size() and inputs[cur].y == i ) {
                int here = query(inputs[cur].y) - query(inputs[cur].x - 1);
                ans[inputs[cur++].id] = here;
            }
        }
        printf("Case %d:\n",++c);
        for(int i =0 ; i < q; i++)
            printf("%d\n", ans[i]) ;
    }
    return 0;
}
