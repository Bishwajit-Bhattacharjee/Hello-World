#include <bits/stdc++.h>
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin) ;
    freopen("out.txt","w", stdout);
#endif
 
    int t, c =0 ;
    scanf("%d",&t) ;
 
    while(t--)
    {
        int n;
        scanf("%d",&n) ;
        vector < int > v(n);
        vector < int > freq(1000010, 0) ;
 
        for(int i =0; i < n; i++)
            scanf("%d",&v[i]), freq[v[i]]++;
 
        int ans =0 ;
        for(int i = 0; i < 1000010; i++)
        {
            if(freq[i])
            {
                int tmp = (freq[i] + i ) / ( i + 1) ;
                ans += tmp * (i + 1) ;
            }
        }
       
        printf("Case %d: %d\n",++c,ans);
    }
    return 0 ;
}
