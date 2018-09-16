#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int t, c =0 ;
    cin >> t ;
    while(t--){
        string str, ans;
        cin >> str ;
        bool hasBiggerLeft = 0, hasBiggerRight = 0;
        // corner case all nine
        int nine =0 ;
        for(int i = 0; i < str.size() ; i++){
            if(str[i] == '9') nine++ ;
        }
        if(nine == str.size()){
            ans += '1' ;
            for(int i =0; i+1< str.size();i++){
                ans += '0' ;
            }
            ans += '1' ;
            printf("Case %d: ",++c) ;
            cout << ans << '\n' ;
            continue ;
        }
        int sz = str.size();
        int n = sz ;
        int idx = -1;
        for( int i = (sz / 2 + (sz % 2)) -1 ; i >=0  ; i--)
        {
            if(str[i] > str[n-i-1]){
              //  str[n-i-1] = str[i] ;
                hasBiggerLeft = 1 ;
               // idx = i;
                break ;
            }
        }
        for(int i = (sz / 2 + (sz % 2)) -1 ; i >=0  ; i--){

            if(str[i] == str[n-i-1]&& str[i] != '9' && !hasBiggerLeft)
            {
                str[i] = str[n-i-1] = str[i] + 1;
                hasBiggerRight = 1;
                idx = i ;
                break;
            }
            else if(str[i] > str[n-i-1]){
                str[n-i-1] = str[i] ;
                hasBiggerLeft = 1 ;
                idx = i;
                break ;
            }
            else if(str[i] < str[n-i-1]){
                str[i] = str[n-i-1] = str[i] + 1  ;
                hasBiggerRight = 1;
                idx = i ;
                break;

            }

        }
        for(int i = idx - 1 ;i >=0  ; i--) {
            str[n-i-1] = str[i] ;
        }
        for(int i = idx + 1;i < (sz / 2+ (sz % 2)); i++){
            if(hasBiggerLeft){
                str[n-i-1] = str[i] ;
            }
            else if(hasBiggerRight)
            {
                str[i] = str[n-i-1] = '0';

            }
        }
        printf("Case %d: ",++c);
        cout << str << '\n' ;

    }
    return 0 ;
}
