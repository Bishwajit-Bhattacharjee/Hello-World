#include <bits/stdc++.h>
using namespace std ;
string s ;
int main()
{
    int t , c =0 ;
    cin >> t ;
    while(t--){
       int n ;
       scanf("%d",&n);
       cin >> s ;
       int ans =0 ;
       for(int i =0 ;i < s.size(); i++){
           if(s[i]=='.'){
              ans++;
           //   int cnt = 0;
              i += 2 ;
           }
       }
       printf("Case %d: %d\n", ++c , ans ) ;
    }
    return 0;
}
